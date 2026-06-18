#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ARC_
{
	char *istate, *ostate, *itemp, *otemp, *wtemp;
} ARC;
typedef struct _ISYM2ISTATE_
{
	char *input;
	int number_of_forward_arcs;
	int *arcs;
} ISYM2ISTATE;
typedef struct _STATE_ZERO_TRANSITIONS_
{
	int size;
	int length;
	ISYM2ISTATE *IS2S;
} STATE_ZERO_TRANSITIONS;
typedef struct _STATE_ZERO_INFO_
{
	int HMKOIL; // how many kind of input lenght
	STATE_ZERO_TRANSITIONS *regular_input;
	STATE_ZERO_TRANSITIONS non_regular_input;
} STATE_ZERO_INFO;
typedef struct _ALL_ISYM_ISTATE_TABLE_
{
	int regular_input_size, max_input_length_size, *each_regular_input_length_word_number, *each_regular_input_length_start_idx;
	char **regular_inputs;
	unsigned short **possible_forward;
	int ***forward_arcs;
	int *non_regular_input_arc_num, **non_regular_input_arcs;
	int *eps_input_num, **eps_input_arcs;
	int *kind_of_regular_input_length, **state_regular_input_length;

} ALL_ISYM_ISTATE_TABLE;
typedef struct _FST_
{
	int capacity, size, num_end;
	int *end_state;
	char **end_state_weight;
	int *state_idx;
	int **possible_forward, *num_possible_forward;
	int num_state;
	int state_zero_possible_forward;
	int FC_state_zero_possible_forward;
	int *FC_state_zero_itemp_strat_idx;
	char **state_zero_itemp;
	char **FC_state_zero_itemp;
	STATE_ZERO_INFO state_zero_info;
	ALL_ISYM_ISTATE_TABLE aiit;
	ARC *arc;
} FST;

int read_a_utf8_word(char *line, char *word, int *index);
int bin_string_search_len_match(char *sentence, char **set, int set_size);
int isym2istatecomparefun(const void *a, const void *b);
int stringlengthcomparefun(const void *a, const void *b);
int stringcomparefun(const void *a, const void *b);
void readfst(FST *fst, FILE *ffst);
int parser_line(char *line, char *istate, char *ostate, char *itemp, char *otemp, char *wtemp);
int read_a_line(char **line, int *capacity_of_line, FILE *fin);
int get_maximum_state_idx(FILE *ffst);
void concatenation(FILE *fin1, FILE *fin2, FILE *fout, int start_idx);
void run(FILE *fin, FILE *fout);
int main(int argc, char *argv[])
{
	FILE *fin, *fout;

	if (argc != 3)
	{
		printf("Usage: fstnetwork input_fst.txt output_network_h\n");
		exit(1);
	}
	if (!(fin = fopen(argv[1], "r")))
	{
		printf("Can't open %s\n", argv[1]);
		exit(1);
	}
	if (!(fout = fopen(argv[2], "w")))
	{
		printf("Can't open %s\n", argv[2]);
		exit(1);
	}

	run(fin, fout);

	fclose(fin);
	fclose(fout);

	return 0;
}
void run(FILE *fin, FILE *fout)
{
	int i, j, k, total_size;
	int maxlen, non_zero_num;
	FST fst;

	readfst(&fst, fin);

	fprintf(fout, "#ifndef _FST_NETWORK_H_\n");
	fprintf(fout, "#define _FST_NETWORK_H_\n");

	fprintf(fout, "int fst_network_capacity=%d;\n", fst.capacity);
	fprintf(fout, "int fst_network_size=%d;\n", fst.size);
	fprintf(fout, "int fst_network_num_end=%d;\n", fst.num_end);
	fprintf(fout, "int fst_network_num_state=%d;\n", fst.num_state);
	fprintf(fout, "int fst_network_aiit_regular_input_size=%d;\n", fst.aiit.regular_input_size);
	fprintf(fout, "int fst_network_aiit_max_input_length_size=%d;\n", fst.aiit.max_input_length_size);

	for (i = total_size = 0; i < fst.num_state; i++)
	{
		total_size += fst.aiit.kind_of_regular_input_length[i];
	}
	fprintf(fout, "int fst_network_aiit_state_regular_input_length[%d]={", total_size);
	for (i = 0; i < fst.num_state; i++)
	{
		for (j = 0; j < fst.aiit.kind_of_regular_input_length[i]; j++)
		{
			fprintf(fout, "%d", fst.aiit.state_regular_input_length[i][j]);
			if (i < fst.num_state - 1 || j < fst.aiit.kind_of_regular_input_length[i] - 1)
			{
				fprintf(fout, ",");
			}
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/
	fprintf(fout, "int fst_network_aiit_kind_of_regular_input_length[%d]={", fst.num_state);
	for (i = 0; i < fst.num_state; i++)
	{
		fprintf(fout, "%d", fst.aiit.kind_of_regular_input_length[i]);
		if (j < fst.num_state - 1)
		{
			fprintf(fout, ", ");
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/
	for (i = total_size = 0; i < fst.num_state; i++)
	{
		total_size += fst.aiit.eps_input_num[i];
	}
	fprintf(fout, "int fst_network_aiit_eps_input_arcs[%d]={", total_size);
	for (i = 0; i < fst.num_state; i++)
	{
		for (j = 0; j < fst.aiit.eps_input_num[i]; j++)
		{
			fprintf(fout, "%d", fst.aiit.eps_input_arcs[i][j]);
			if (i < fst.num_state - 1 || j < fst.aiit.eps_input_num[i] - 1)
			{
				fprintf(fout, ",");
			}
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/
	fprintf(fout, "int fst_network_aiit_eps_input_num[%d]={", fst.num_state);
	for (i = 0; i < fst.num_state; i++)
	{
		fprintf(fout, "%d", fst.aiit.eps_input_num[i]);
		if (j < fst.num_state - 1)
		{
			fprintf(fout, ", ");
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/
	for (i = total_size = 0; i < fst.num_state; i++)
	{
		total_size += fst.aiit.non_regular_input_arc_num[i];
	}
	fprintf(fout, "int fst_network_aiit_non_regular_input_arcs[%d]={", total_size);
	for (i = 0; i < fst.num_state; i++)
	{
		for (j = 0; j < fst.aiit.non_regular_input_arc_num[i]; j++)
		{
			fprintf(fout, "%d", fst.aiit.non_regular_input_arcs[i][j]);
			if (i < fst.num_state - 1 || j < fst.aiit.non_regular_input_arc_num[i] - 1)
			{
				fprintf(fout, ",");
			}
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/
	fprintf(fout, "int fst_network_aiit_non_regular_input_arc_num[%d]={", fst.num_state);
	for (i = 0; i < fst.num_state; i++)
	{
		fprintf(fout, "%d", fst.aiit.non_regular_input_arc_num[i]);
		if (j < fst.num_state - 1)
		{
			fprintf(fout, ", ");
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/
	for (maxlen = 1, i = 0, non_zero_num = 0, total_size = 0; i < fst.num_state; i++)
	{
		for (j = 0; j < fst.aiit.regular_input_size; j++)
		{
			total_size += fst.aiit.possible_forward[i][j];
			if (fst.aiit.possible_forward[i][j] > 0)
			{
				non_zero_num++;
				if (maxlen < fst.aiit.possible_forward[i][j])
				{
					maxlen = fst.aiit.possible_forward[i][j];
				}
			}

		}
	}
	//fprintf(fout, "int fst_network_aiit_forward_arcs[%d]={", total_size);
	//for (i = 0; i < fst.num_state; i++)
	//{
	//	for (j = 0; j < fst.aiit.regular_input_size; j++)
	//	{
	//		for (k = 0; k < fst.aiit.possible_forward[i][j]; k++)
	//		{
	//			fprintf(fout, "%d ", fst.aiit.forward_arcs[i][j][k]);
	//			if ((i < fst.num_state - 1 || j < fst.aiit.regular_input_size - 1) || k < fst.aiit.possible_forward[i][j] - 1)
	//			{
	//				fprintf(fout, ",");
	//			}
	//		}
	//	}
	//}
	fprintf(fout, "int fst_network_aiit_forward_arcs[%d][%d]={\n", non_zero_num, maxlen);
	for (i = 0; i < fst.num_state; i++)
	{
		for (j = 0; j < fst.aiit.regular_input_size; j++)
		{
			if (fst.aiit.possible_forward[i][j] > 0)
			{
				fprintf(fout, "{");
				for (k = 0; k < fst.aiit.possible_forward[i][j]; k++)
				{
					fprintf(fout, "%d ", fst.aiit.forward_arcs[i][j][k]);
					if ((i < fst.num_state - 1 || j < fst.aiit.regular_input_size - 1) || k < fst.aiit.possible_forward[i][j] - 1)
					{
						fprintf(fout, ",");
					}
				}
				fprintf(fout, "},");
			}
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/
	fprintf(fout, "unsigned short fst_network_aiit_possible_forward[%d][%d]={\n", fst.num_state, fst.aiit.regular_input_size);
	for (i = 0; i < fst.num_state; i++)
	{
		fprintf(fout, "{");
		for (j = 0; j < fst.aiit.regular_input_size; j++)
		{
			fprintf(fout, "%d ", fst.aiit.possible_forward[i][j]);
			if (j < fst.aiit.regular_input_size - 1)
			{
				fprintf(fout, ",");
			}
		}
		fprintf(fout, "},\n");
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/

	fprintf(fout, "int fst_network_aiit_each_regular_input_length_word_number[%d]={", fst.aiit.max_input_length_size);
	for (i = 0; i < fst.aiit.max_input_length_size; i++)
	{
		fprintf(fout, "%d", fst.aiit.each_regular_input_length_word_number[i]);
		if (i < fst.aiit.max_input_length_size - 1)
		{
			fprintf(fout, ", ");
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/

	fprintf(fout, "int fst_network_aiit_each_regular_input_length_start_idx[%d]={", fst.aiit.max_input_length_size);
	for (i = 0; i < fst.aiit.max_input_length_size; i++)
	{
		fprintf(fout, "%d", fst.aiit.each_regular_input_length_start_idx[i]);
		if (i < fst.aiit.max_input_length_size - 1)
		{
			fprintf(fout, ", ");
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/

	for (maxlen = 1, i = 0; i < fst.aiit.regular_input_size; i++)
	{
		if (maxlen < strlen(fst.aiit.regular_inputs[i]) + 1)
		{
			maxlen = strlen(fst.aiit.regular_inputs[i]) + 1;
		}
	}
	fprintf(fout, "char fst_network_aiit_regular_inputs[%d][%d]={", fst.aiit.regular_input_size, maxlen);
	for (i = 0; i < fst.aiit.regular_input_size; i++)
	{
		if (strcmp("\"", fst.aiit.regular_inputs[i]) == 0)
		{
			fprintf(fout, "\"\\\"\"");
		}
		else
		{
			fprintf(fout, "\"%s\"", fst.aiit.regular_inputs[i]);
		}
		if (i < fst.size - 1)
		{
			fprintf(fout, ",\n");
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/

	fprintf(fout, "int fst_network_end_state[%d]={", fst.num_end);
	for (i = 0; i < fst.num_end; i++)
	{
		fprintf(fout, "%d", fst.end_state[i]);
		if (i < fst.num_end - 1)
		{
			fprintf(fout, ", ");
		}
	}
	fprintf(fout, "};\n");
/*************************************************************************************************************************************/

	// for (maxlen = 1, i = 0; i < fst.num_end; i++)
	//{
	//	if (maxlen < strlen(fst.end_state_weight[i]) + 1)
	//	{
	//		maxlen = strlen(fst.end_state_weight[i]) + 1;
	//	}
	// }
	// fprintf(fout, "char fst_network_end_state_weight[%d][%d]={", fst.num_end, maxlen);
	// for (i = 0; i < fst.num_end; i++)
	//{
	//	fprintf(fout, "\"%s\"", fst.end_state_weight[i]);
	//	if (i < fst.num_end - 1)
	//	{
	//		fprintf(fout, ", ");
	//	}
	// }
	// fprintf(fout, "};\n");

	//fprintf(fout, "int fst_network_state_idx[%d]={", fst.num_state);
	//for (i = 0; i < fst.num_state; i++)
	//{
	//	fprintf(fout, "%d", fst.state_idx[i]);
	//	if (i < fst.num_state - 1)
	//	{
	//		fprintf(fout, ", ");
	//	}
	//}
	//fprintf(fout, "};\n");
/*************************************************************************************************************************************/

	for (maxlen = 1, i = 0; i < fst.size; i++)
	{
		if (maxlen < strlen(fst.arc[i].istate) + 1)
		{
			maxlen = strlen(fst.arc[i].istate) + 1;
		}
		else if (maxlen < strlen(fst.arc[i].ostate) + 1)
		{
			maxlen = strlen(fst.arc[i].ostate) + 1;
		}else if (maxlen < strlen(fst.arc[i].itemp) + 1)
		{
			maxlen = strlen(fst.arc[i].itemp) + 1;
		}
		else if (maxlen < strlen(fst.arc[i].otemp) + 1)
		{
			maxlen = strlen(fst.arc[i].otemp) + 1;
		}
	}
	fprintf(fout, "char fst_network_arcs_io[%d][2][%d]={", fst.size, maxlen);
	for (i = 0; i < fst.size; i++)
	{
		fst.arc[i].otemp[strlen(fst.arc[i].otemp) - 1] = '\0';
		if (strcmp(fst.arc[i].itemp,"\"") == 0)
		{
			fprintf(fout, "{\"\\\"\",\"%s\"}", fst.arc[i].otemp);
		}
		else
		{
			fprintf(fout, "{\"%s\",\"%s\"}", fst.arc[i].itemp, fst.arc[i].otemp);
		}
		if (i < fst.size - 1)
		{
			fprintf(fout, ",\n");
		}
	}
	fprintf(fout, "};\n");
	fprintf(fout, "int fst_network_arcs_state[%d][2]={", fst.size);
	for (i = 0; i < fst.size; i++)
	{
		fst.arc[i].otemp[strlen(fst.arc[i].otemp) - 1] = '\0';
		fprintf(fout, "{%d,%d}", atoi(fst.arc[i].istate), atoi(fst.arc[i].ostate));
		if (i < fst.size - 1)
		{
			fprintf(fout, ",\n");
		}
	}
	fprintf(fout, "};\n");
	/*************************************************************************************************************************************/

	fprintf(fout, "#endif\n");

	return;
}
void concatenation(FILE *fin1, FILE *fin2, FILE *fout, int start_idx)
{
	int FILEEND, capacity_of_line = 0;
	char *line = (char *)malloc(sizeof(char));
	char istate[1024], ostate[1024], itemp[1024], otemp[1024], wtemp[1024];
	int ret, sidx, oidx, eidx;

	for (FILEEND = 0; FILEEND == 0;)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, fin1);
		if (line[0] != '\0')
		{
			fprintf(fout, "%s\n", line);
		}
	}
	for (FILEEND = 0; FILEEND == 0;)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, fin2);
		if (line[0] != '\0')
		{
			ret = parser_line(line, istate, ostate, itemp, otemp, wtemp);
			if (ret == 1)
			{
				eidx = atoi(istate);
				if (eidx > 0)
				{
					eidx += start_idx;
				}
				fprintf(fout, "%d\n", eidx);
			}
			else
			{
				sidx = atoi(istate);
				if (sidx > 0)
				{
					sidx += start_idx;
				}
				oidx = atoi(ostate);
				if (oidx > 0)
				{
					oidx += start_idx;
				}
				fprintf(fout, "%d\t%d\t%s\t%s\n", sidx, oidx, itemp, otemp);
			}
		}
	}

	free(line);
}
int get_maximum_state_idx(FILE *ffst)
{
	int ret = 0;
	int FILEEND, capacity_of_line = 0;
	char *line = (char *)malloc(sizeof(char));
	char istate[1024], ostate[1024], itemp[1024], otemp[1024], wtemp[1024];

	for (FILEEND = 0; FILEEND == 0;)
	{
		FILEEND = read_a_line(&line, &capacity_of_line, ffst);
		if (line[0] != '\0')
		{
			parser_line(line, istate, ostate, itemp, otemp, wtemp);
			if (atoi(istate) > ret)
			{
				
				ret = atoi(istate);
			}
		}
	}
	fseek(ffst, 0, SEEK_SET);
	free(line);
	return ret;
}
int read_a_line(char **line, int *capacity_of_line, FILE *fin)
{
	char temp[1024];
	int cnt, times, ENDOFLINE = 0, FILEEND = 0;

	for (*line[0] = '\0', times = 1; ENDOFLINE == 0; times++)
	{
		for (cnt = 0; 1; cnt++)
		{
			temp[cnt] = fgetc(fin);
			if (temp[cnt] == '\n' || temp[cnt] == EOF || cnt == 1022)
			{
				if (temp[cnt] == '\n' || temp[cnt] == EOF)
				{
					ENDOFLINE = 1;
					if (temp[cnt] == EOF)
					{
						FILEEND = 1;
					}
					temp[cnt] = '\0';
				}
				break;
			}
		}
		if (*capacity_of_line < times * 1024)
		{
			*line = (char *)realloc(*line, times * 1024 * sizeof(char));
			*capacity_of_line = times * 1024;
			//printf("%d %d %d\n", times, (times - 1) * 1024 - times + 1, *capacity_of_line);
			(*line)[(times - 1) * 1024 - times + 1] = '\0';
		}
		if (cnt == 1022)
		{
			temp[cnt + 1] = '\0';
		}
		strcat(*line, temp);
	}
	//printf("%s\n", *line);

	return FILEEND;
}
int parser_line(char *line, char *istate, char *ostate, char *itemp, char *otemp, char *wtemp)
{
	int i, index;

	for (i = 0, index = 0;line[index] != '\t' && line[index] != ' ' && line[index] != '\0';i++, index++)
	{
		istate[i] = line[index];
	}
	istate[i] = '\0';
	if (line[index] == '\0')
	{
		strcpy(wtemp, "0.0");
		return 1;
	}
	for (i = 0, index++;line[index] != '\t' && line[index] != ' ' && line[index] != '\0';i++, index++)
	{
		ostate[i] = line[index];
	}
	ostate[i] = '\0';
	if (line[index] == '\0')
	{
		strcpy(wtemp, ostate);
		return 1;
	}
	for (i = 0, index++; line[index] != '\t' && line[index] != ' '; i++, index++)
	{
		itemp[i] = line[index];
	}
	itemp[i] = '\0';
	for (i = 0, index++; line[index] != '\0' && line[index] != '\t' && line[index] != ' '; i++, index++)
	{
		otemp[i] = line[index];
	}
	otemp[i] = '\0';
	if (line[index] == '\t' || line[index] == ' ')
	{
		for (i = 0, index++; line[index] != '\0'; i++, index++)
		{
			wtemp[i] = line[index];
		}
		// wtemp[0]='-';
		wtemp[i] = '\0';
	}
	else
	{
		strcpy(wtemp, "0.0");
	}
	return 0;
}
void readfst(FST *fst, FILE *ffst)
{
	int i, j, k, temp_size, ret, len;
	int idx;
	char word[7];
	char line[1024];
	char istate[1024], ostate[1024], itemp[1024], otemp[1024], wtemp[1024];
	int maximum_length_of_input = 0;
	int input_length_num[1024] = {0};
	char **temp_regular_input;
	int temp_regular_input_size, *temp_regular_input_num_split_by_len;
	int *exist_flag;

	for (fst->capacity = 0, fst->num_end = 0; fgets(line, 1023, ffst) != NULL;
		 fst->capacity++)
	{
		if (parser_line(line, istate, ostate, itemp, otemp, wtemp) == 1)
		{
			fst->num_end++;
		}
	}
	fst->num_state = atoi(istate) + 1;
	// printf("fst->num_state=%d\n", fst->num_state);
	fseek(ffst, 0, SEEK_SET);
	fst->arc = (ARC *)malloc(fst->capacity * sizeof(ARC));
	fst->end_state = (int *)malloc(fst->num_end * sizeof(int));
	fst->end_state_weight = (char **)malloc(fst->num_end * sizeof(char *));

	temp_regular_input = (char **)malloc(fst->capacity * sizeof(char *));

	for (temp_regular_input_size = fst->size = 0, i = 0; fgets(line, 1023, ffst) != NULL;)
	{
		ret = parser_line(line, istate, ostate, itemp, otemp, wtemp);
		if (ret == 1)
		{
			fst->end_state[i] = atoi(istate);
			// strcpy(fst->end_state[i], istate);
			fst->end_state_weight[i] =
				(char *)malloc((strlen(wtemp) + 1) * sizeof(char));
			strcpy(fst->end_state_weight[i++], wtemp);
			// printf("%d ", atoi(istate));
		}
		else
		{
			fst->arc[fst->size].istate = (char *)malloc((strlen(istate) + 1) * sizeof(char));
			strcpy(fst->arc[fst->size].istate, istate);
			fst->arc[fst->size].ostate = (char *)malloc((strlen(ostate) + 1) * sizeof(char));
			strcpy(fst->arc[fst->size].ostate, ostate);
			fst->arc[fst->size].itemp = (char *)malloc((strlen(itemp) + 1) * sizeof(char));
			if (strcmp(itemp, "<space>") == 0)
			{
				strcpy(itemp, " ");
			}
			else if (strcmp(itemp, "<tab>") == 0)
			{
				strcpy(itemp, "\t");
			}
			strcpy(fst->arc[fst->size].itemp, itemp);
			fst->arc[fst->size].otemp = (char *)malloc((strlen(otemp) + 1) * sizeof(char));
			strcpy(fst->arc[fst->size].otemp, otemp);
			fst->arc[fst->size].wtemp = (char *)malloc((strlen(wtemp) + 1) * sizeof(char));
			// printf("%d %s\n", fst->size, fst->arc[fst->size].itemp);
			strcpy(fst->arc[fst->size++].wtemp, wtemp);
			if (maximum_length_of_input < strlen(itemp) && (itemp[0] != '<' || itemp[strlen(itemp) - 1] != '>'))
			{
				maximum_length_of_input = strlen(itemp);
				// printf("%d %s\n", fst->size, fst->arc[fst->size-1].itemp);
			}
			if (itemp[0] != '<' || itemp[strlen(itemp) - 1] != '>')
			{
				temp_regular_input[temp_regular_input_size] = (char *)malloc((strlen(itemp) + 1) * sizeof(char));
				strcpy(temp_regular_input[temp_regular_input_size++], itemp);
			}
		}
	}
	/*******************************************************************************************************************************/
	qsort(temp_regular_input, temp_regular_input_size, sizeof(char *), stringlengthcomparefun);
	temp_regular_input_num_split_by_len = (int *)malloc(maximum_length_of_input * sizeof(int));
	fst->aiit.max_input_length_size = maximum_length_of_input;
	fst->aiit.each_regular_input_length_word_number = (int *)malloc(maximum_length_of_input * sizeof(int));
	fst->aiit.each_regular_input_length_start_idx = (int *)malloc(maximum_length_of_input * sizeof(int));
	exist_flag = (int *)malloc(maximum_length_of_input * sizeof(int));
	for (i = 0; i < maximum_length_of_input; i++)
	{
		temp_regular_input_num_split_by_len[i] = 0;
		fst->aiit.each_regular_input_length_word_number[i] = 0;
		exist_flag[i] = 0;
	}
	for (i = 0; i < temp_regular_input_size; i++)
	{
		temp_regular_input_num_split_by_len[strlen(temp_regular_input[i]) - 1]++;
	}
	for (i = 0, j = 0; i < maximum_length_of_input; i++)
	{
		// printf("%d %d\n", temp_regular_input_num_split_by_len[i], j);
		qsort(&temp_regular_input[j], temp_regular_input_num_split_by_len[i], sizeof(char *), stringcomparefun);
		j += temp_regular_input_num_split_by_len[i];
	}
	fst->aiit.each_regular_input_length_word_number[strlen(temp_regular_input[0]) - 1]++;
	for (i = 1; i < temp_regular_input_size; i++)
	{
		if (strcmp(temp_regular_input[i], temp_regular_input[i - 1]) != 0)
		{
			fst->aiit.each_regular_input_length_word_number[strlen(temp_regular_input[i]) - 1]++;
		}
	}
	fst->aiit.each_regular_input_length_start_idx[0] = 0;
	for (i = 0, fst->aiit.regular_input_size = 0; i < fst->aiit.max_input_length_size; i++)
	{
		fst->aiit.regular_input_size += fst->aiit.each_regular_input_length_word_number[i];
		if (i > 0)
		{
			fst->aiit.each_regular_input_length_start_idx[i] = fst->aiit.each_regular_input_length_start_idx[i - 1] + fst->aiit.each_regular_input_length_word_number[i - 1];
		}
		// printf("%d %d\n", fst->aiit.each_regular_input_length_word_number[i], fst->aiit.each_regular_input_length_start_idx[i]);
	}
	fst->aiit.regular_inputs = (char **)malloc(fst->aiit.regular_input_size * sizeof(char *));
	fst->aiit.regular_inputs[0] = (char *)malloc((strlen(temp_regular_input[0]) + 1) * sizeof(char));
	strcpy(fst->aiit.regular_inputs[0], temp_regular_input[0]);
	for (i = 1, j = 1; i < temp_regular_input_size; i++)
	{
		if (strcmp(temp_regular_input[i], temp_regular_input[i - 1]) != 0)
		{
			fst->aiit.regular_inputs[j] = (char *)malloc((strlen(temp_regular_input[i]) + 1) * sizeof(char));
			strcpy(fst->aiit.regular_inputs[j++], temp_regular_input[i]);
		}
	}
	// for (i = 0; i < fst->aiit.regular_input_size; i++)
	//{
	//	printf("%d %s\n", i + 1, fst->aiit.regular_inputs[i]);
	// }
	fst->aiit.possible_forward = (unsigned short **)malloc(fst->num_state * sizeof(int *));
	fst->aiit.forward_arcs = (int ***)malloc(fst->num_state * sizeof(int **));
	fst->aiit.non_regular_input_arc_num = (int *)malloc(fst->num_state * sizeof(int));
	fst->aiit.non_regular_input_arcs = (int **)malloc(fst->num_state * sizeof(int *));
	fst->aiit.eps_input_num = (int *)malloc(fst->num_state * sizeof(int));
	fst->aiit.eps_input_arcs = (int **)malloc(fst->num_state * sizeof(int *));
	fst->aiit.kind_of_regular_input_length = (int *)malloc(fst->num_state * sizeof(int));
	fst->aiit.state_regular_input_length = (int **)malloc(fst->num_state * sizeof(int *));
	for (i = 0; i < fst->num_state; i++)
	{
		fst->aiit.possible_forward[i] = (unsigned short *)malloc(fst->aiit.regular_input_size * sizeof(int));
		fst->aiit.forward_arcs[i] = (int **)malloc(fst->aiit.regular_input_size * sizeof(int *));
		fst->aiit.non_regular_input_arc_num[i] = 0;
		fst->aiit.eps_input_num[i] = 0;
		fst->aiit.kind_of_regular_input_length[i] = 0;
		for (j = 0; j < fst->aiit.regular_input_size; j++)
		{
			fst->aiit.possible_forward[i][j] = 0;
		}
	}
	// printf("fst->num_state=%d fst->aiit.regular_input_size=%d\n", fst->num_state, fst->aiit.regular_input_size);
	for (i = 0; i < fst->size; i++)
	{
		if (fst->arc[i].itemp[0] != '<' || fst->arc[i].itemp[strlen(fst->arc[i].itemp) - 1] != '>')
		{
			fst->aiit.possible_forward[atoi(fst->arc[i].istate)][fst->aiit.each_regular_input_length_start_idx[strlen(fst->arc[i].itemp) - 1] + bin_string_search_len_match(fst->arc[i].itemp, &fst->aiit.regular_inputs[fst->aiit.each_regular_input_length_start_idx[strlen(fst->arc[i].itemp) - 1]], fst->aiit.each_regular_input_length_word_number[strlen(fst->arc[i].itemp) - 1])]++;
			exist_flag[strlen(fst->arc[i].itemp) - 1] = 1;
		}
		else if (strcmp(fst->arc[i].itemp, "<eps>") == 0)
		{
			fst->aiit.eps_input_num[atoi(fst->arc[i].istate)]++;
		}
		else
		{
			fst->aiit.non_regular_input_arc_num[atoi(fst->arc[i].istate)]++;
		}
		if (i < fst->size - 1)
		{
			if (atoi(fst->arc[i].istate) != atoi(fst->arc[i + 1].istate))
			{
				for (j = 0; j < maximum_length_of_input; j++)
				{
					fst->aiit.kind_of_regular_input_length[atoi(fst->arc[i].istate)] += exist_flag[j];
					exist_flag[j] = 0;
				}
			}
		}
		else
		{
			for (j = 0; j < maximum_length_of_input; j++)
			{
				fst->aiit.kind_of_regular_input_length[atoi(fst->arc[i].istate)] += exist_flag[j];
				exist_flag[j] = 0;
			}
		}
	}
	for (i = 0; i < fst->num_state; i++)
	{
		fst->aiit.non_regular_input_arcs[i] = (int *)malloc((fst->aiit.non_regular_input_arc_num[i] + 1) * sizeof(int));
		fst->aiit.non_regular_input_arc_num[i] = 0;
		fst->aiit.eps_input_arcs[i] = (int *)malloc((fst->aiit.eps_input_num[i] + 1) * sizeof(int));
		fst->aiit.eps_input_num[i] = 0;
		fst->aiit.state_regular_input_length[i] = (int *)malloc((fst->aiit.kind_of_regular_input_length[i] + 1) * sizeof(int));
		fst->aiit.kind_of_regular_input_length[i] = 0;
		for (j = 0; j < fst->aiit.regular_input_size; j++)
		{
			fst->aiit.forward_arcs[i][j] = (int *)malloc((fst->aiit.possible_forward[i][j] + 1) * sizeof(int));
			fst->aiit.possible_forward[i][j] = 0;
		}
	}
	for (i = 0; i < fst->size; i++)
	{
		if (fst->arc[i].itemp[0] != '<' || fst->arc[i].itemp[strlen(fst->arc[i].itemp) - 1] != '>')
		{
			fst->aiit.forward_arcs[atoi(fst->arc[i].istate)][fst->aiit.each_regular_input_length_start_idx[strlen(fst->arc[i].itemp) - 1] + bin_string_search_len_match(fst->arc[i].itemp, &fst->aiit.regular_inputs[fst->aiit.each_regular_input_length_start_idx[strlen(fst->arc[i].itemp) - 1]], fst->aiit.each_regular_input_length_word_number[strlen(fst->arc[i].itemp) - 1])][fst->aiit.possible_forward[atoi(fst->arc[i].istate)][fst->aiit.each_regular_input_length_start_idx[strlen(fst->arc[i].itemp) - 1] + bin_string_search_len_match(fst->arc[i].itemp, &fst->aiit.regular_inputs[fst->aiit.each_regular_input_length_start_idx[strlen(fst->arc[i].itemp) - 1]], fst->aiit.each_regular_input_length_word_number[strlen(fst->arc[i].itemp) - 1])]++] = i;
			exist_flag[strlen(fst->arc[i].itemp) - 1] = 1;
		}
		else if (strcmp(fst->arc[i].itemp, "<eps>") == 0)
		{
			fst->aiit.eps_input_arcs[atoi(fst->arc[i].istate)][fst->aiit.eps_input_num[atoi(fst->arc[i].istate)]++] = i;
		}
		else
		{
			fst->aiit.non_regular_input_arcs[atoi(fst->arc[i].istate)][fst->aiit.non_regular_input_arc_num[atoi(fst->arc[i].istate)]++] = i;
		}
		if (i < fst->size - 1)
		{
			if (atoi(fst->arc[i].istate) != atoi(fst->arc[i + 1].istate))
			{
				for (j = 0; j < maximum_length_of_input; j++)
				{
					if (exist_flag[j] == 1)
					{
						fst->aiit.state_regular_input_length[atoi(fst->arc[i].istate)][fst->aiit.kind_of_regular_input_length[atoi(fst->arc[i].istate)]++] = j + 1;
					}
					exist_flag[j] = 0;
				}
			}
		}
		else
		{
			for (j = 0; j < maximum_length_of_input; j++)
			{
				if (exist_flag[j] == 1)
				{
					fst->aiit.state_regular_input_length[atoi(fst->arc[i].istate)][fst->aiit.kind_of_regular_input_length[atoi(fst->arc[i].istate)]++] = j + 1;
				}
				exist_flag[j] = 0;
			}
		}
	}
	/*printf("fst->aiit.possible_forward[0][743] = %d\n", fst->aiit.possible_forward[0][743]);
	for (i = 0; i < fst->aiit.possible_forward[0][743]; i++)
	{
		printf("%d\n", fst->aiit.forward_arcs[0][743][i]);
	}
	printf("fst->aiit.non_regular_input_arc_num[0]=%d\n", fst->aiit.non_regular_input_arc_num[0]);
	for (i = 0; i < fst->aiit.non_regular_input_arc_num[0]; i++)
	{
		printf("%d\n", fst->aiit.non_regular_input_arcs[0][i]);
	}
	printf("fst->aiit.non_regular_input_arc_num[24]=%d\n", fst->aiit.eps_input_num[24]);
	for (i = 0; i < fst->aiit.eps_input_num[24]; i++)
	{
		printf("%d\n", fst->aiit.eps_input_arcs[24][i]);
	}
	printf("fst->aiit.kind_of_regular_input_length[1638]=%d\n", fst->aiit.kind_of_regular_input_length[1638]);
	for (i = 0; i < fst->aiit.kind_of_regular_input_length[1638]; i++)
	{
		printf("%d\n", fst->aiit.state_regular_input_length[1638][i]);
	}*/

	for (i = 0; i < temp_regular_input_size; i++)
	{
		free(temp_regular_input[i]);
	}
	free(temp_regular_input);
	free(temp_regular_input_num_split_by_len);
	free(exist_flag);
	/*******************************************************************************************************************************/

	len = fst->num_state;
	fst->state_idx = (int *)malloc(len * sizeof(int));
	fst->num_possible_forward = (int *)malloc(len * sizeof(int));
	fst->possible_forward = (int **)malloc(len * sizeof(int *));
	for (i = 0; i < len; i++)
	{
		fst->num_possible_forward[i] = 0;
	}
	// printf("%d ",atoi(fst->arc[fst->size - 1].istate) + 1);
	for (j = 0; j < fst->num_end; j++)
	{
		fst->state_idx[(fst->end_state[j])] = 0;
		// printf("%d\n", fst->end_state[j]);
	}
	fst->state_idx[0] = 0;
	for (i = 0, j = atoi(fst->arc[i].istate); i < fst->size; i++)
	{
		// printf("%d %d\n", j, atoi(fst->arc[i].istate));
		if (j != atoi(fst->arc[i].istate))
		{
			fst->num_possible_forward[atoi(fst->arc[i].istate)]++;
			// printf("%d ", fst->num_possible_forward[j]);
			j = atoi(fst->arc[i].istate);
			fst->state_idx[j] = i;
		}
		else
		{
			fst->num_possible_forward[j]++;
		}
	}
	/*
	for (i = 0; i < atoi(fst->arc[fst->size - 1].istate); i++)
	{
		printf("%d %d \n",i, fst->state_idx[i]);
	}
	*/

	for (i = 0; i < len; i++)
	{
		fst->possible_forward[i] = (int *)malloc(sizeof(int) * fst->num_possible_forward[i]);
		// printf("%d\t", i);
		for (j = 0; j < fst->num_possible_forward[i]; j++)
		{
			fst->possible_forward[i][j] = atoi(fst->arc[fst->state_idx[i] + j].ostate);
			// printf("%d ", fst->possible_forward[i][j]);
		}
		// printf("\n");
	}

	fst->state_zero_itemp = (char **)malloc(fst->num_possible_forward[0] * sizeof(char *));
	fst->state_zero_info.non_regular_input.size = 0;
	for (i = 0, fst->state_zero_possible_forward = 0; i < fst->num_possible_forward[0]; i++)
	{
		for (j = 0; j < fst->state_zero_possible_forward; j++)
		{
			if (strcmp(fst->arc[i].itemp, fst->state_zero_itemp[j]) == 0)
			{
				break;
			}
		}
		if (j == fst->state_zero_possible_forward)
		{
			fst->state_zero_itemp[j] = (char *)malloc((strlen(fst->arc[i].itemp) + 1) * sizeof(char));
			strcpy(fst->state_zero_itemp[j], fst->arc[i].itemp);
			fst->state_zero_possible_forward++;
			if (fst->state_zero_itemp[j][0] != '<' || fst->state_zero_itemp[j][strlen(fst->state_zero_itemp[j]) - 1] != '>')
			{
				input_length_num[strlen(fst->state_zero_itemp[j]) - 1]++;
			}
			else
			{
				for (k = 0; k < fst->state_zero_info.non_regular_input.size; k++)
				{
					if (strcmp(fst->state_zero_info.non_regular_input.IS2S[k].input, fst->state_zero_itemp[j]) == 0)
					{
						break;
					}
				}
				if (k == fst->state_zero_info.non_regular_input.size)
				{
					if (fst->state_zero_info.non_regular_input.size == 0)
					{
						fst->state_zero_info.non_regular_input.IS2S = (ISYM2ISTATE *)malloc(sizeof(ISYM2ISTATE));
						fst->state_zero_info.non_regular_input.IS2S[0].input = (char *)malloc((strlen(fst->state_zero_itemp[j]) + 1) * sizeof(char));
						strcpy(fst->state_zero_info.non_regular_input.IS2S[0].input, fst->state_zero_itemp[j]);
						fst->state_zero_info.non_regular_input.size = 1;
					}
					else
					{
						fst->state_zero_info.non_regular_input.IS2S = (ISYM2ISTATE *)realloc(fst->state_zero_info.non_regular_input.IS2S, (fst->state_zero_info.non_regular_input.size + 1) * sizeof(ISYM2ISTATE));
						fst->state_zero_info.non_regular_input.IS2S[fst->state_zero_info.non_regular_input.size].input = (char *)malloc((strlen(fst->state_zero_itemp[j]) + 1) * sizeof(char));
						strcpy(fst->state_zero_info.non_regular_input.IS2S[fst->state_zero_info.non_regular_input.size].input, fst->state_zero_itemp[j]);
						fst->state_zero_info.non_regular_input.size++;
					}
				}
			}
		}
	}
	//	for (i = 0; i < fst->state_zero_info.non_regular_input.size; i++)
	//	{
	//		printf("%s\n", fst->state_zero_info.non_regular_input.IS2S[i].input);
	//	}
	for (i = 0, fst->state_zero_info.HMKOIL = 0; i < maximum_length_of_input; i++)
	{
		if (input_length_num[i] != 0)
		{
			fst->state_zero_info.HMKOIL++;
		}
	}
	fst->state_zero_info.regular_input = (STATE_ZERO_TRANSITIONS *)malloc(fst->state_zero_info.HMKOIL * sizeof(STATE_ZERO_TRANSITIONS));
	for (i = j = 0; i < maximum_length_of_input; i++)
	{
		if (input_length_num[i] != 0)
		{
			fst->state_zero_info.regular_input[j].length = i + 1;
			fst->state_zero_info.regular_input[j++].size = input_length_num[i];
		}
	}
	for (i = 0; i < fst->state_zero_info.HMKOIL; i++)
	{
		fst->state_zero_info.regular_input[i].IS2S = (ISYM2ISTATE *)malloc(fst->state_zero_info.regular_input[i].size * sizeof(ISYM2ISTATE));
		for (j = 0, temp_size = 0; j < fst->num_possible_forward[0]; j++)
		{
			if (fst->state_zero_info.regular_input[i].length == strlen(fst->arc[j].itemp) && (fst->arc[j].itemp[0] != '<' || fst->arc[j].itemp[strlen(fst->arc[j].itemp) - 1] != '>'))
			{
				for (k = 0; k < temp_size; k++)
				{
					if (strcmp(fst->state_zero_info.regular_input[i].IS2S[k].input, fst->arc[j].itemp) == 0)
					{
						break;
					}
				}
				if (k == temp_size)
				{
					fst->state_zero_info.regular_input[i].IS2S[temp_size].input = (char *)malloc((strlen(fst->arc[j].itemp) + 1) * sizeof(char));
					strcpy(fst->state_zero_info.regular_input[i].IS2S[temp_size].input, fst->arc[j].itemp);
					fst->state_zero_info.regular_input[i].IS2S[temp_size].number_of_forward_arcs = 1;
					temp_size++;
				}
				else
				{
					fst->state_zero_info.regular_input[i].IS2S[k].number_of_forward_arcs++;
				}
				// printf("%s ", fst->arc[j].itemp);
			}
		}
		// printf("%d %d %d\n", fst->state_zero_info.regular_input[i].length, temp_size, fst->state_zero_info.regular_input[i].size);
		// for (j = 0; j < fst->state_zero_info.regular_input[i].size; j++)
		//{
		//	printf("(%s %d) ", fst->state_zero_info.regular_input[i].IS2S[j].input, fst->state_zero_info.regular_input[i].IS2S[j].number_of_forward_arcs);
		// }
		// printf("\n\n");
	}
	for (i = 0; i < fst->state_zero_info.HMKOIL; i++)
	{
		for (j = 0; j < fst->state_zero_info.regular_input[i].size; j++)
		{
			fst->state_zero_info.regular_input[i].IS2S[j].arcs = (int *)malloc(fst->state_zero_info.regular_input[i].IS2S[j].number_of_forward_arcs * sizeof(int));
			fst->state_zero_info.regular_input[i].IS2S[j].number_of_forward_arcs = 0;
		}
		for (j = 0; j < fst->num_possible_forward[0]; j++)
		{
			if (fst->state_zero_info.regular_input[i].length == strlen(fst->arc[j].itemp) && (fst->arc[j].itemp[0] != '<' || fst->arc[j].itemp[strlen(fst->arc[j].itemp) - 1] != '>'))
			{
				for (k = 0; k < fst->state_zero_info.regular_input[i].size; k++)
				{
					if (strcmp(fst->state_zero_info.regular_input[i].IS2S[k].input, fst->arc[j].itemp) == 0)
					{
						break;
					}
				}
				if (k == fst->state_zero_info.regular_input[i].size)
				{
					printf("Error: FST-network reading fail.\n");
					exit(1);
				}
				else
				{
					fst->state_zero_info.regular_input[i].IS2S[k].arcs[fst->state_zero_info.regular_input[i].IS2S[k].number_of_forward_arcs++] = j;
				}
			}
		}
		qsort(fst->state_zero_info.regular_input[i].IS2S, fst->state_zero_info.regular_input[i].size, sizeof(ISYM2ISTATE), isym2istatecomparefun);
		//		printf("%d %d %d\n", fst->state_zero_info.regular_input[i].length, temp_size, fst->state_zero_info.regular_input[i].size);
		//		for (j = 0; j < fst->state_zero_info.regular_input[i].size; j++)
		//		{
		//			printf("(%s %d) ", fst->state_zero_info.regular_input[i].IS2S[j].input, fst->state_zero_info.regular_input[i].IS2S[j].number_of_forward_arcs);
		//			for (k = 0; k < fst->state_zero_info.regular_input[i].IS2S[j].number_of_forward_arcs; k++)
		//			{
		//				printf("%d ", fst->state_zero_info.regular_input[i].IS2S[j].arcs[k]);
		//			}
		//			printf("\n");
		//		}
		//		printf("\n");
	}
	for (i = 0; i < fst->state_zero_info.non_regular_input.size; i++)
	{
		fst->state_zero_info.non_regular_input.IS2S[i].number_of_forward_arcs = 0;
		for (j = 0; j < fst->num_possible_forward[0]; j++)
		{
			if (strcmp(fst->state_zero_info.non_regular_input.IS2S[i].input, fst->arc[j].itemp) == 0)
			{
				fst->state_zero_info.non_regular_input.IS2S[i].number_of_forward_arcs++;
			}
		}

		fst->state_zero_info.non_regular_input.IS2S[i].arcs = (int *)malloc(fst->state_zero_info.non_regular_input.IS2S[i].number_of_forward_arcs * sizeof(int));
		for (j = temp_size = 0; j < fst->num_possible_forward[0]; j++)
		{
			if (strcmp(fst->state_zero_info.non_regular_input.IS2S[i].input, fst->arc[j].itemp) == 0)
			{
				fst->state_zero_info.non_regular_input.IS2S[i].arcs[temp_size++] = j;
			}
		}
		// printf("%s %d\t", fst->state_zero_info.non_regular_input.IS2S[i].input, fst->state_zero_info.non_regular_input.IS2S[i].number_of_forward_arcs);
		// for (j = 0; j < fst->state_zero_info.non_regular_input.IS2S[i].number_of_forward_arcs; j++)
		//{
		//	printf("%d ", fst->state_zero_info.non_regular_input.IS2S[i].arcs[j]);
		// }
		// printf("\n");
	}
	//	printf("maximum_length_of_input=%d\n", maximum_length_of_input);
	//	for (i = 0; i < maximum_length_of_input;i++)
	//	{
	//		printf("%d\n", input_length_num[i]);
	//	}
	//	printf("HMKOIL = %d\n", fst->state_zero_info.HMKOIL);
	//	for (i = 0; i < fst->state_zero_info.HMKOIL; i++)
	//	{
	//		printf("%d %d\n", fst->state_zero_info.regular_input[i].length, fst->state_zero_info.regular_input[i].size);
	//	}
	qsort(fst->state_zero_itemp, fst->state_zero_possible_forward, sizeof(char *), stringcomparefun);
	/*printf("%d\n", fst->state_zero_possible_forward);
	for (j = 0; j < fst->state_zero_possible_forward; j++)
	{
		printf("%d word=%s len=%d\n", j + 1, fst->state_zero_itemp[j], strlen(fst->state_zero_itemp[j]));
	}*/
	fst->FC_state_zero_itemp = (char **)malloc(fst->state_zero_possible_forward * sizeof(char *));
	fst->FC_state_zero_itemp_strat_idx = (int *)malloc((fst->state_zero_possible_forward + 1) * sizeof(int));
	idx = 0;
	read_a_utf8_word(fst->state_zero_itemp[0], word, &idx);
	fst->FC_state_zero_itemp[0] = (char *)malloc((strlen(word) + 1) * sizeof(char));
	strcpy(fst->FC_state_zero_itemp[0], word);
	fst->FC_state_zero_itemp_strat_idx[0] = 0;
	for (i = 1, fst->FC_state_zero_possible_forward = 1, idx = 0; i < fst->state_zero_possible_forward; i++, idx = 0)
	{
		read_a_utf8_word(fst->state_zero_itemp[i], word, &idx);
		if (strcmp(fst->FC_state_zero_itemp[fst->FC_state_zero_possible_forward - 1], word) != 0)
		{
			fst->FC_state_zero_itemp[fst->FC_state_zero_possible_forward] = (char *)malloc((strlen(word) + 1) * sizeof(char));
			strcpy(fst->FC_state_zero_itemp[fst->FC_state_zero_possible_forward], word);
			fst->FC_state_zero_itemp_strat_idx[fst->FC_state_zero_possible_forward++] = i;
		}
	}
	fst->FC_state_zero_itemp_strat_idx[fst->FC_state_zero_possible_forward] = fst->state_zero_possible_forward;

	/*printf("%d\n",fst->FC_state_zero_possible_forward);
	for (i = 0; i < fst->FC_state_zero_possible_forward; i++)
	{
		printf("%d %s %d\n", i + 1, fst->FC_state_zero_itemp[i], fst->FC_state_zero_itemp_strat_idx[i]);
	}*/
}
int stringcomparefun(const void *a, const void *b)
{
	const char *pa = (*(char **)a);
	const char *pb = (*(char **)b);
	return strcmp(pa, pb);
}
int stringlengthcomparefun(const void *a, const void *b)
{
	int alen = strlen((*(char **)a));
	int blen = strlen((*(char **)b));
	if (alen > blen)
	{
		return 1;
	}
	else if (alen == blen)
	{
		return 0;
	}
	return -1;
}
int isym2istatecomparefun(const void *a, const void *b)
{
	const char *pa = ((ISYM2ISTATE *)a)->input;
	const char *pb = ((ISYM2ISTATE *)b)->input;
	return strcmp(pa, pb);
}
int bin_string_search_len_match(char *sentence, char **set, int set_size)
{
	int i, low = 0, up = set_size - 1, middle;

	while (1)
	{
		middle = (low + up) * 0.5;
		// printf("%s %d %d %d\n", set[middle], low, up, middle);
		if (strncmp(sentence, set[middle], strlen(set[middle])) > 0)
		{
			low = middle + 1;
		}
		else if (strncmp(sentence, set[middle], strlen(set[middle])) == 0)
		{
			return middle;
		}
		else if (strncmp(sentence, set[middle], strlen(set[middle])) < 0)
		{
			up = middle - 1;
		}
		if ((up == low && up == middle) || up < low)
		{
			return -1;
		}
	}
}
int read_a_utf8_word(char *line, char *word, int *index)
{
	unsigned char trick = 64;   // 0x01000000
	unsigned char trick1 = 128; // 0x10000000
	int i = 1;

	word[0] = line[(*index)++];
	if (word[0] == '\0')
	{
		word[i] = '\0';
		(*index)--;
		return 1;
	}
	while (word[0] & trick && word[0] & trick1)
	{
		word[i++] = line[(*index)++];
		trick = trick >> 1;
	}
	word[i] = '\0';

	return 0;
}