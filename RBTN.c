//#include <pthread.h>
#include "TNlib.h"
#include <time.h>

//gcc -Ofast -shared -fPIC -o pypiRBTN.so RBTN.c TNlib.c
FST pypifst;
RULES pypirul;
FLAGS pypiflags;

void pypiloadrules(char *rules_config_path);
void pypiconversion(char **intext, char *output);
void run(FILE *frul, /* FILE *flpe,*/ FILE *fin, FILE *fout, FILE *fnswm);
void convservation(FST *fst, TEXT *text_in, TEXT *text_out, FLAGS *flags, TRANSFORMATION *tra, FILE *fnswm);
void output_non_standard_word_marks(FILE *fnswm, char *line, NSW_TOKEN *nsw);
int main(int argc, char **argv)
{
	//pthread_t thread1, thread2;
	clock_t start_time, end_time;
	FILE *frul, *fin = stdin, *fout = stdout;
	FILE *fnswm = NULL;
	float total_time = 0;

	if (argc != 2 && argc != 3)
	{
		printf("Usage: execution rules_config < stdin > stdout\n");
		printf("[option]:\n");
		printf("-ONSWM\t:output non-standard word marks\n");
		exit(1);
	}
	if (argc == 3)
	{
		if (strcmp(argv[1], "-ONSWM") == 0 ||
			strcmp(argv[2], "-ONSWM") == 0 ||
			strcmp(argv[3], "-ONSWM") == 0)
		{
			if (!(fnswm = fopen("non_standard_word_marks.txt", "w")))
			{
				printf("can not open file: \'%s\'\n", "non_standard_word_marks.txt");
				exit(1);
			}
		}
	}

	if (!(frul = fopen(argv[1], "r")))
	{
		printf("can not open file: \'%s\'\n", argv[2]);
		exit(1);
	}
	/*if (!(flpe = fopen(argv[3], "r")))
	{
		printf("can not open file: \'%s\'\n", argv[3]);
		exit(1);
	}
	if (!(fin = fopen(argv[4], "r"))) {
		printf("can not open file: \'%s\'\n", argv[4]);
		exit(1);
	}
	if (!(fout = fopen(argv[5], "w"))) {
		printf("can not open file: \'%s\'\n", argv[5]);
		exit(1);
	}*/

	start_time = clock(); /* mircosecond */
	run(frul, /*flpe,*/ fin, fout, fnswm);
	end_time = clock(); /* mircosecond */
	total_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;

	fclose(frul);
	//fclose(flpe);
	if (fnswm != NULL)
	{
		fprintf(fnswm, "Time : %f sec \n", total_time);
		fclose(fnswm);
	}

	return 0;
}
void run(FILE *frul, /* FILE *flpe,*/ FILE *fin, FILE *fout, FILE *fnswm)
{
	FST fst;
	TEXT text_in, text_tmp, text_out;
	RULES rul;
	FLAGS flags;
	int i, j, k;

	srand(time(NULL));

	set_fst(&fst);
	// return;
	/*for (int i = 0, len = fst.num_state; i < len; i++){
		  for (int j = 0; j < fst.num_possible_forward[i]; j++){
				  printf("%s %s %s %s %s\n",
				  fst.arc[fst.state_idx[i] + j].istate,
				  fst.arc[fst.state_idx[i] + j].ostate,
				   fst.arc[fst.state_idx[i] + j].itemp,
				   fst.arc[fst.state_idx[i] + j].otemp,
				   fst.arc[fst.state_idx[i] + j].wtemp);
		  }
		  for (int j = 0; j < fst.num_end; j++){
				if (i == fst.end_state[j])
				{
					printf("%d\n", fst.end_state[j]);
				}
		  }
	}*/
	load_rules(frul, &rul);
	load_text(fin, &text_in);
	//load_flags(fflag, &flags);
	/*for (int i = 0; i < text_in.num_of_sentence; i++){
		  printf("%s\n", text_in.sentence[i]);
	}*/

	convservation(&fst, &text_in, &text_tmp, &flags, &(rul.tra), fnswm);
	//return;
	substitute(&text_tmp, &text_out, &(rul.sub));

	for (i = 0; i < text_out.num_of_sentence; i++)
	{
		fprintf(fout, "%s\n", text_out.sentence[i]);
	}

	destroy_text(&text_in);
	destroy_text(&text_tmp);
	destroy_text(&text_out);
	destroy_fst(&fst);
	destroy_rules(&rul);
}
void convservation(FST *fst, TEXT *text_in, TEXT *text_out, FLAGS *flags, TRANSFORMATION *tra, FILE *fnswm)
{
	int i;
	NSW_TOKEN nsw;
	VITERBIINFO vinfo;

	text_out->num_of_sentence = text_in->num_of_sentence;
	text_out->sentence = (char **)malloc(text_out->num_of_sentence * sizeof(char *));

	ini_nsw(&nsw);
	initial_viterbi_info(fst, &vinfo);
	for (i = 0; i < text_in->num_of_sentence; i++)
	{
		//printf("%d %s\n", i + 1, text_in->sentence[i]);
		paser_a_sentence(fst, &vinfo, text_in->sentence[i], &nsw);
		fill_text_out(text_in->sentence[i], &(text_out->sentence[i]), i, &nsw, flags, tra, fnswm);
	}
	destroy_viterbi_info(&vinfo);
	destroy_nsw(&nsw);
}
void fill_text_out(char *sentence_in, char **sentence_out, int raw, NSW_TOKEN *nsw, FLAGS *flags, TRANSFORMATION *tra, FILE *fnswm)
{
	int i, j, rel_idx, in_idx, out_len, ret, rel_ret, temp_idx;
	char *tok = (char *)malloc(sizeof(char));
	char word[7];

	out_len = strlen(sentence_in);
	*sentence_out = (char *)malloc((strlen(sentence_in) + 1) * sizeof(char));
	(*sentence_out)[0] = '\0';

	//printf("%s\n", sentence_in);
	for (i = in_idx = 0; i < nsw->size; i++)
	{
		//printf("%s %s\n", nsw->token[i], nsw->token[19]);
		ret = bin_transform_rule_search(nsw->rule[i], tra);
		//printf("%s %d %s %d s=%d e=%d\n", nsw->token[i], (int)strlen(nsw->token[i]), nsw->rule[i], ret, nsw->start_idx[i], nsw->end_idx[i]);
		
		if (ret == -1 || tra->rul[ret].status == 0)
		{
			nsw->SFW[i] = (char *)realloc(nsw->SFW[i], (strlen(nsw->token[i]) + 1) * sizeof(char));
			strcpy(nsw->SFW[i], nsw->token[i]);
		}
		else if (tra->rul[ret].status == 1)
		{
			tok = (char *)realloc(tok, (strlen(nsw->token[i]) + 1) * sizeof(char));
			strcpy(tok, nsw->token[i]);
			if (tra->rul[ret].rp_size > 0)
			{
				for (rel_idx = 0;;)
				{
					if ((rel_ret = bin_replace_word_search(&tok[rel_idx], &(tra->rul[ret]))) >= 0)
					{
						replacement(&tok, &rel_idx, tra->rul[ret].rp[rel_ret].raw, tra->rul[ret].rp[rel_ret].rel);
						//printf("%s %s %d\n", tok, tra->rul[ret].rp[rel_ret].raw, rel_idx);
					}
					else if (read_a_utf8_word(tok, word, &rel_idx) == 1)
					{
						break;
					}
				}
			}

			nsw->SFW[i] = (char *)realloc(nsw->SFW[i], (strlen(nsw->token[i]) * tra->rul[ret].scale_size + tra->rul[ret].extra_size) * sizeof(char));
			nsw->SFW[i][0] = '\0';
			//printf("\n%d %s\n", nsw->language[i], tra->rul[ret].prefix[nsw->language[i] - 1]);
			strcpy(nsw->SFW[i], tra->rul[ret].prefix[nsw->language[i] - 1]);
			//printf("%s %s\t", tra->rul[ret].prefix, nsw->SFW[i]);
			
			tra->rul[ret].transfer_fn(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			/*if (strcmp(tra->rul[ret].template, "NTISFW") == 0)
			{
				NTISFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DPTSFW") == 0)
			{
				DPTSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MMTDSF") == 0)
			{
				MMTDSF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NWMSFW") == 0)
			{
				NWMSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DMYTSF") == 0)
			{
				DMYTSF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DTDYMD") == 0)
			{
				DTDYMD(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "FRACSFW") == 0)
			{
				FRACSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "PTSFW") == 0)
			{
				PTSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "N2SSTF") == 0)
			{
				N2SSTF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "N2SWND") == 0)
			{
				N2SWND(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "N2IWND") == 0)
			{
				N2IWND(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "TADSRB") == 0)
			{
				TADSRB(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "URLNOR") == 0)
			{
				URLNOR(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "EMAILN") == 0)
			{
				EMAILN(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NESWND") == 0)
			{
				NESWND(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MDTOMD") == 0)
			{
				MDTOMD(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DMTODM") == 0)
			{
				DMTODM(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MDWNDI") == 0)
			{
				MDWNDI(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "HMTOHM") == 0)
			{
				HMTOHM(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "HMTSFW") == 0)
			{
				HMTSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "COMPRO") == 0)
			{
				COMPRO(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NTONPG") == 0)
			{
				NTONPG(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "SFWFSC") == 0)
			{
				SFWFSC(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "RSFWTF") == 0)
			{
				RSFWTF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "FSFWTF") == 0)
			{
				FSFWTF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "HICTU8") == 0)
			{
				HICTU8(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "TTFHSF") == 0)
			{
				TTFHSF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "YMTYMT") == 0)
			{
				YMTYMT(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CH_N2SWND") == 0)
			{
				CH_N2SWND(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MS2SFW") == 0)
			{
				MS2SFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DCSOIN") == 0)
			{
				DCSOIN(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CONAFF") == 0)
			{
				CONAFF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NSFWSP") == 0)
			{
				NSFWSP(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "PRNTPG") == 0)
			{
				PRNTPG(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "RACTEA") == 0)
			{
				RACTEA(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DSPFWW") == 0)
			{
				DSPFWW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CMNTSW") == 0)
			{
				CMNTSW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CMFSFW") == 0)
			{
				CMFSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CASSWA") == 0)
			{
				CASSWA(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "ECCWPS") == 0)
			{
				ECCWPS(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "ABOYTY") == 0)
			{
				ABOYTY(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "GFGCAS") == 0)
			{
				GFGCAS(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "RUOEAO") == 0)
			{
				RUOEAO(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "TPEFRU") == 0)
			{
				TPEFRU(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "RUTMSF") == 0)
			{
				RUTMSF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "N2SWND_FT") == 0)
			{
				N2SWND_FT(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "TN77SE") == 0)
			{
				TN77SE(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "FFDFCD") == 0)
			{
				FFDFCD(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "N2SSTF_LD") == 0)
			{
				N2SSTF_LD(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "EDNMNT") == 0)
			{
				EDNMNT(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NINB4I") == 0)
			{
				NINB4I(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "YMTSFW") == 0)
			{
				YMTSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MSTSFW") == 0)
			{
				MSTSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "UAPPUN") == 0)
			{
				UAPPUN(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NNLIRW") == 0)
			{
				NNLIRW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NILNRW") == 0)
			{
				NILNRW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "PN2SFW") == 0)
			{
				PN2SFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MSDWDW") == 0)
			{
				MSDWDW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MDD2YM") == 0)
			{
				MDD2YM(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NEIWND") == 0)
			{
				NEIWND(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "EANAPN") == 0)
			{
				EANAPN(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "VMPNDN") == 0)
			{
				VMPNDN(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "THCMCS") == 0)
			{
				THCMCS(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "UAPPMU") == 0)
			{
				UAPPMU(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "RSFSTF") == 0)
			{
				RSFSTF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "SEMINS") == 0)
			{
				SEMINS(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MYSHUT") == 0)
			{
				MYSHUT(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DPWAID") == 0)
			{
				DPWAID(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "YMOMDT") == 0)
			{
				YMOMDT(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "N2SCAC") == 0)
			{
				N2SCAC(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MASAFW") == 0)
			{
				MASAFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "EAWWON") == 0)
			{
				EAWWON(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CFTSFW") == 0)
			{
				CFTSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "RWAPAS") == 0)
			{
				RWAPAS(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "RWPOST") == 0)
			{
				RWPOST(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CRTSFW") == 0)
			{
				CRTSFW(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "LATEXT") == 0)
			{
				LATEXT(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "HSAESF") == 0)
			{
				HSAESF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "DAFROL") == 0)
			{
				DAFROL(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "MDHMTO") == 0)
			{
				MDHMTO(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NFNLT4") == 0)
			{
				NFNLT4(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "THMSSF") == 0)
			{
				THMSSF(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NFSNFS") == 0)
			{
				NFSNFS(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NFNLT3") == 0)
			{
				NFNLT3(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "NUDLOP") == 0)
			{
				NUDLOP(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else if (strcmp(tra->rul[ret].template, "CNWAAN") == 0)
			{
				CNWAAN(tok, &(nsw->SFW[i][strlen(nsw->SFW[i])]), nsw->language[i]);
			}
			else
			{
				strcpy(&(nsw->SFW[i][strlen(nsw->SFW[i])]), tok);
			}*/

			strcat(nsw->SFW[i], tra->rul[ret].suffix[nsw->language[i] - 1]);
			//printf("%s\n", nsw->SFW[i]);
		}
		concatenation(sentence_out, &out_len, nsw->SFW[i], sentence_in, &in_idx, nsw->start_idx[i], nsw->end_idx[i]);
		//printf("%s\n", *sentence_out);
		//fflush(stdout);
	}
	if (fnswm != NULL)
	{
		output_non_standard_word_marks(fnswm, sentence_in, nsw);
	}
	//printf("%s\n", *sentence_out);
	strncat(*sentence_out, &(sentence_in[in_idx]), strlen(sentence_in) - in_idx);
	// printf("%s\n\n", *sentence_out);

	free(tok);
}
void concatenation(char **sentence_out, int *out_len, char *SFW, char *sentence_in, int *in_idx, int start_idx, int end_idx)
{
	*out_len += strlen(SFW);
	*sentence_out = (char *)realloc(*sentence_out, (*out_len) * sizeof(char));

	strncat(*sentence_out, &(sentence_in[*in_idx]), start_idx - *in_idx);
	strcat(*sentence_out, SFW);
	*in_idx = end_idx;
}
void output_non_standard_word_marks(FILE *fnswm, char *line, NSW_TOKEN *nsw)
{
	int i, start_idx_utf8_form, end_idx_utf8_form;
	char word[7];
	int idx;

	fprintf(fnswm, "%s\t%d\n", line, nsw->size);
	for (i = 0; i < nsw->size; i++)
	{
		for (start_idx_utf8_form = end_idx_utf8_form = idx = 0; read_a_utf8_word(line, word, &idx) == 0;)
		{
			if (idx <= nsw->start_idx[i])
			{
				start_idx_utf8_form++;
			}
			if (idx <= nsw->end_idx[i])
			{
				end_idx_utf8_form++;
			}
			else
			{
				break;
			}
		}
		fprintf(fnswm, "\t%d∥\t%d∥\t%d∥\t%s∥\t%s∥\t%d∥\t%s\n", i + 1, start_idx_utf8_form, end_idx_utf8_form, nsw->token[i], nsw->rule[i], nsw->language[i], nsw->SFW[i]);
	}
}
void pypiloadrules(char *rules_config_path){
	FILE *frul;

	if (!(frul = fopen(rules_config_path, "r")))
	{
		printf("can not open rules_config\n");
		exit(1);
	}
	
	set_fst(&pypifst);
	load_rules(frul, &pypirul);
}
void pypiconversion(char **intext, char *output){
	TEXT text_in, text_tmp, text_out;
	int i, num_line = 0;
	
	for(i=0; intext[i][0]!='\0'; i++)
	{
		//printf("%s\n",intext[i]);
		num_line++;
	}
	text_in.num_of_sentence = num_line;
	text_in.sentence = (char **)malloc(text_in.num_of_sentence * sizeof(char *));

	for(i=0; intext[i][0]!='\0'; i++)
	{
		text_in.sentence[i] = (char *)malloc((strlen(intext[i]) + 1) * sizeof(char));
		strcpy(text_in.sentence[i], intext[i]);
	}

	convservation(&pypifst, &text_in, &text_tmp, &pypiflags, &(pypirul.tra), NULL);
	//return;
	substitute(&text_tmp, &text_out, &(pypirul.sub));

	//for (i = 0; i < text_out.num_of_sentence; i++)
	//{
	//	fprintf(stdout, "%s\n", text_out.sentence[i]);
	//}

	output[0] = '\0';
    for(i = 0; i < text_out.num_of_sentence; i++)
    {
        strcat(output, text_out.sentence[i]);
        //strcat(output, "\n");
    }


	destroy_text(&text_in);
	destroy_text(&text_tmp);
	destroy_text(&text_out);
}
