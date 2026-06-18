#ifndef _TNlib_
#define _TNlib_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DOUBLE_MIN -1.79769e+308
#define NUM_EXTERN 30
#define _NAN_ "<NAN>"
#define _NAE_ "<NAE>"
#define _NAM_ "<NAM>"
#define _IAN_ "<IAN>"
#define _IAE_ "<IAE>"
#define _IAM_ "<IAM>"

#define PAUSE_AND_EXIT                  \
	printf("Press Enter key to exit."); \
	fgetc(stdin);                       \
	exit(1);
#define PAUSE_AND_CONTINUE                  \
	printf("Press Enter key to continue."); \
	fgetc(stdin);

extern char Tmp_symC[1][4];
extern char Tmp_symF[1][4];
extern char Percentage[3][4];
extern char Comma[3][4];
extern char Slash[4][4];
extern char Dot[3][4];
extern char Number[20][4];
extern char Non_zero_number[18][4];
extern char English[104][4];
extern char Colon[4][4];
extern char Plus[3][4];
extern char Dash[6][4];
extern char divide_sign[3];
extern char multiple_sign[7][4];
extern char Tilde[2][4];
extern char UNIT[15][4];
extern char CH_number[10][4];
extern char two_for_measure_word[4];
extern char CH_point[4];
extern char ch_percent[10];
extern char ch_per_mill[10];
extern char spaces[3][4];
extern char crtl_char[6][6];
extern char Mandarin_year[4];
extern char fraction[7];
extern char proportion[4];
extern char one_yiao[4];
extern char Mandarin_time[4];
extern char Mandarin_month[4];
extern char Mandarin_day[4];
extern char Mandarin_number[4];
extern char Mandarin_grade[7];
extern char Mandarin_decimal_point[4];
extern char Mandarin_discount[4];
extern char Dose[4];
extern char item[4];
extern char ml[7];
extern char Tmp_sym_chin_F[7];
extern char Tmp_sym_chin_C[7];
extern char Tmp_DO[4];
extern char ch_dao[4];
extern char ch_zh4[4];
extern char ch_paa[4];
extern char ch_question[7];
extern char ch_Equal_Sign[7];
extern char ch_Under_Line[7];
extern char ch_Colon[7];
extern char ch_feng[4];
extern char ch_plus[4];
extern char ch_minus[4];
extern char ch_divide_by[7];
extern char ch_multiply_by[7];
extern char ch_euqal[7];
extern char ch_ratio[4];
extern char ch_hour[7];
extern char ch_negative[4];
extern char ch_floor[4];
extern char Ampersand[3][4];
extern char Question[3][4];
extern char Equal_Sign[3][4];
extern char Under_Line[3][4];
extern char Commercial_At[3][4];
extern char English_number[10][6];
extern char English_teens[10][10];
extern char English_tys[8][9];
extern char English_hundred[8];
extern char English_unit[10][12];
extern char L_Brackets[10][4];
extern char R_Brackets[10][4];
extern char splited_mark[8][7];
extern char Roman_numerals[32][2][5];
extern char currency_symbols[22][7];
extern char country_abbr[8][2][16];
extern char currsym2spokenform[18][3][16];
extern char number_sign[3][4];
extern char week_worship[2][7];
extern char mathematical_symbols[6][3][32];
extern char mathematical_symbols_english_only[2][2][32];
extern char mandarin_money[4];
extern char unit_table[1][2][32];

typedef struct _ARC_
{
	char  *itemp, *otemp;
	int istate, ostate;
} ARC;
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
	int num_state;
	ALL_ISYM_ISTATE_TABLE aiit;
	ARC *arc;
} FST;
typedef struct _TEXT_
{
	int num_of_sentence;
	char **sentence;
} TEXT;
typedef struct _NSW_TOKEN_
{
	int size;
	int capacity;
	int *language; //1 for mandarin, 2 for English
	int *start_idx;
	int *end_idx;
	char **token;
	char **SFW;
	char **rule;
} NSW_TOKEN;
typedef struct _OSYM_
{
	struct _OSYM_ *from;
	int state;
	int depth;
	int num_forward;
	char *output;
	char *input;
	int forward_step;
	int is_eps_input;
} OSYM;
typedef struct _TEMPLATE_
{
	char *str;
	int replace_idx;
} TEMPLATE;
typedef struct _SUBSTITUTION_WORDS_LIST_
{
	char **word;
	int *statr_idx;
	int size;
	int capacity;
} SUBSTITUTION_WORDS_LIST;
typedef struct _SUBSTITUTION_WORDS_
{
	char *raw_word;
	char *sub_word;
	int capacity_templates;
	int num_templates;
	TEMPLATE *templates;
} SUBSTITUTION_WORDS;
typedef struct _SUBSTITUTION_
{
	int capacity;
	int size;
	SUBSTITUTION_WORDS *words;
	SUBSTITUTION_WORDS_LIST list;
} SUBSTITUTION;
typedef struct _REPLACE_PAIR_{
	char *raw, *rel;
} REPLACE_PAIR;
typedef struct _TRANSFORMATION_RULES_
{
	char *name;
	int status;//1=on,0=off
	char *template;
	char **prefix; //0 for mandarin, 1 for English
	char **suffix; //0 for mandarin, 1 for English
	int rp_capacicty;
	int rp_size;
	int scale_size, extra_size;
	REPLACE_PAIR *rp;
	void (*transfer_fn)(char*, char*, int);
} TRANSFORMATION_RULES;
typedef struct _TRANSFORMATION_
{
	int capacity;
	int size;
	int scale_size, extra_size;
	TRANSFORMATION_RULES *rul;
} TRANSFORMATION;
typedef struct _RULES_
{
	SUBSTITUTION sub;
	TRANSFORMATION tra;
} RULES;
typedef struct _FLAG_TOKEN_
{
	int on;
	char *rules;
} FLAG_TOKEN;
typedef struct _FLAGS_
{
	FLAG_TOKEN *token;
	int size;
} FLAGS;
typedef struct _VITERBIINFO_
{
	OSYM **cur_state, **pre_state;
	int len, num_sur_pre_state, num_sur_cur_state;
	int *sur_pre_state, *sur_cur_state, *is_head;
} VITERBIINFO;
typedef struct _FN_MAP_{
    const char *name;
    void (*fn)(char *, char *, int);
} FN_MAP;

int isTmp_symC(char *word);
int isTmp_symF(char *word);
int isPercentage(char *word);
int isComma(char *word);
int isSlash(char *word);
int isDot(char *word);
int isNumber(char *word);
int isNumber_sign(char *word);
int isNon_zero_number(char *word);
int isEnglish(char *word);
int isColon(char *word);
int isPlus(char *word);
int isDash(char *word);
int isTilde(char *word);
int isspaces(char *word);
int isctrl_char(char *str);
int isapostrophe(char *word);
int isheximalC(char *word);
int isampersand(char *word);
int isquestion(char *word);
int isequal_sign(char *word);
int isunder_line(char *word);
int isCommercial_At(char *word);
int isL_Brackets(char *word);
int isR_Brackets(char *word);
int issplited_mark(char *word);
int iscurrency_symbol(char *word);
int ismultiple_sign(char *word);
int is_CH_number(char *word);

int parser_line(char *line, char *istate, char *ostate, char *itemp, char *otemp, char *wtemp);
void load_text(FILE *fin, TEXT *text_in);
void load_rules(FILE *frul, RULES *rul);
void load_flags(FILE *fflags, FLAGS *flags);
void load_substitution(FILE *frul, SUBSTITUTION *sub);
void load_transformation(FILE *frul, TRANSFORMATION *tra);
void forward_until_not_space_and_tab(char *line, int *idx);
int read_a_utf8_word(char *line, char *word, int *index);
int utf8_word_length(char *word);
void forward_all_table_binsearch(FST *fst, VITERBIINFO *vinfo, char *sentence, int *idx, char *word, NSW_TOKEN *nsw);
int isCJK_words(char *word);
unsigned long long int utf8word2decimal(char *word);
int isAscii(char *sentance);
void normalize_number(char *num_in, char *num_out);
void normalize_number_float(char *num_in, char *num_out);
void NTNSFW(char *num_in, char *NSPW, int decide_spoken_type);					// numerals_to_Numerical_spoken_form_word
void NTISFW(char *num_in, char *ISPW, int language_code);						// numerals_to_individually_spoken_form_word
void DPTSFW(char *num_in, char *DPSPW, int language_code);						// decimal_point_to_spoken_form_word
void DPWAID(char *num_in, char *DPSPW, int language_code);						// decimal_point_to_spoken_form_word which allow input include ~,-(means 到)
void NWMSFW(char *num_in, char *DPSPW, int language_code);						// numerals_with_measure_word_to_spoken_form_word
void N2SSTF(char *num_in, char *DPSPW, int language_code);						// Non-standard words to spoken-form words(short type first) with not digital input
void N2SSTF_LD(char *num_in, char *DPSPW, int language_code);					// Non-standard words to spoken-form words(short type first) with not digital input language dependence
void N2SWND(char *num_in, char *DPSPW, int language_code);						// Non-standard words to spoken-form words(Numerical) with not digital input
void N2IWND(char *num_in, char *DPSPW, int language_code);						// Non-standard words to spoken-form words(individual) with not digital input
void TADSRB(char *num_in, char *DPSPW, int language_code);						// Tilde and dash symbols replaced by 到
void URLNOR(char *URL, char *nor_url, int language_code);						// normalize URL
void BYTRAN(char *raw, char *modify);											// Byte transform
void EMAILN(char *raw, char *modify, int language_code);						// E-mail
void NENSFW(char *raw, char *modify);											// numerals_to_English_Numerical_spoken_form_word
void NEISFW(char *raw, char *modify);											// numerals_to_English_individually_spoken_form_word
void DPESFW(char *num_in, char *DPSPW);											// decimal_point_to_English_spoken_form_word
void NESWND(char *num_in, char *DPSPW, int language_code);						// Non-standard words to English spoken-form words(Numerical) with not digital input
void NEIWND(char *num_in, char *DPSPW, int language_code);						// Non-standard words to English spoken-form words(individual) with not digital input
void MDTOMD(char *num_in, char *MDS, int language_code);						// month/day to month/day
void DMTODM(char *num_in, char *DMS, int language_code);						// day/month to day/month
void MDTSFW(char *num_in, char *MDS);											// month/day to Spoken form word
void DMTSFW(char *num_in, char *DMS);											// day/month to Spoken form word
void MDWNDI(char *num_in, char *MDS, int language_code);						// month/day to Spoken form word with not digital input
void HMTOHM(char *num_in, char *MDS, int language_code);						// hour:minute to hour:minute
void HMTSFW(char *num_in, char *MDS, int language_code);						// hour:minute to Spoken form word
void COMPRO(char *num_in, char *PRO, int language_code);						// communication protocol e.g.802.11ac
void NTONPG(char *num_in, char *PER, int language_code);						// number to number % e.g.10-20%
void STFNVI(char *num_in, char *RES);											// short type first, Numerical vs individually
void SFWFSC(char *num_in, char *RES, int language_code);						// Spoken form word for stock code
void RSFWTF(char *num_in, char *RAT, int language_code);						// ratio spoken-form words with not digital input
void FSFWTF(char *num_in, char *FRA, int language_code);						// fraction spoken-form words with not digital input
void HICTU8(char *num_in, char *UTF, int language_code);						// html (ISO-10646;UNicode) to utf-8
void TTFHSF(char *num_in, char *TTF, int language_code);						// 24h to 二十四小時
void DTDYMD(char *num_in, char *DTD, int language_code);						// date to date (YYYY/MM/DD~YYYY/MM/DD)
void DSPFWW(char *num_in, char *DSF, int language_code);						// date spkoen-form word with others character
void DMYTSF(char *num_in, char *DMY, int language_code);						// date month year transformation
void MMTDSF(char *num_in, char *MMT, int language_code);						// money mark ($100) to decimal spoken form
void CSTSFW(char *num_in, char *CST, int language_code);						// currency symbol to spoken form words
void YMTYMT(char *num_in, char *YMT, int language_code);						// year/month to year/month transformation
void YMTSFW(char *num_in, char *YMT, int language_code);						// year/month to Spoken form word
void CH_N2SWND(char *num_in, char *DPSPW, int language_code);					// Non-standard words to spoken-form words(Numerical) with not digital input
void MS2SFW(char *num_in, char *DPSPW, int language_code);						// mathical signs 2 spoken-form words(transfer signs only)
void DCSOIN(char *num_in, char *DPSPW, int language_code);						// dot concatenate a series of integer number
void CONAFF(char *num_in, char *ordinal, int language_code);					// convert ordinal numbers abbreviation to full format
void NSFWSP(char *num_in, char *pair, int language_code);						// numerals_spoken_form_word special pair
void PRNTPG(char *raw, char *modify, int language_code);						// person + roman unmber to person + generation
void RACTEA(char *roman_alphabet, char *english_alphabet, int language_code);	// roman_alphabet_convert_to_english_alphabet
void CMNTSW(char *raw, char *modify, int language_code);						// convert mandarin numerals to spoken form word
void CMFSFW(char *raw, char *modify, int language_code);						// convert mathematical formula to spoken form word
void CASSWA(char *raw, char *modify, int language_code);						// convert Ampersand sign to spoken form word "and"
void ECCWPS(char *raw, char *modify, int language_code);						// English character concatenated with plus sign
void ABOYTY(char *raw, char *modify, int language_code);						// abbreviation of year to year, i.e. 2018-19
void GFGCAS(char *raw, char *modify, int language_code);						// gaming formula gust convert arithmetic symbols
void RUOEAO(char *raw, char *modify, int language_code);						// ridiculous usage of english alphabet i.e. 二O二O年
void TPEFRU(char *raw, char *modify, int language_code);						// template pair exchanged for ridiculous usage i.e. ?te
void RUTMSF(char *raw, char *modify, int language_code);						// roman unmber to mandarin spoken-form, i.e.Ⅰ期->一期
void N2SWND_FT(char *num_in, char *DPSPW, int language_code);					// Non-standard words to spoken-form words(Numerical) with not digital input for 2 -> 兩, i.e. 1、2次->一、兩次
void TN77SE(char *raw, char *modify, int language_code);						// text noraml for 7-11 or 711 to seven eleven
void FFDFCD(char *raw, char *modify, int language_code);						// fraction fit date format can't disambiguate
void EDNMNT(char *num_in, char *DPSPW, int language_code);						// English+("."+number)*N,N>=1, i.e. M.2、B.1.621
void NINB4I(char *num_in, char *DPSPW, int language_code);						// Numerical if numerals > 4 or individual with not digital input
void MSTSFW(char *ms, char *sfw, int language_code);							// mathematical symbols to spoken-form words
void UAPPUN(char *upu, char *modify, int language_code);						// union all possible precentage usage
void NNLIRW(char *num_in, char *NLNRI, int language_code);						// numerals_split_by_dash_to_Numerical(left)_and_individual(right)_spoken_form_word
void NILNRW(char *num_in, char *NLIRN, int language_code);						// numerals_split_by_dash_to_individual(left)_and_Numerical(right)_spoken_form_word
void PN2SFW(char *num_in, char *PNABR, int language_code);						// page_numerals_to_Numerical_spoken_form_word
void TODSFW(char *num_in, char *TODCN, int language_code);						// Tilde_or_dash_to_Numerical_spoken_form_word
void MSDWDW(char *num_in, char *MDS, int language_code);						// month/day(dayofweek) to month/day(dayofweek)
void MDD2YM(char *num_in, char *MDS, int language_code);						// month/day(dayofweek) to year/month
void EANAPN(char *num_in, char *MDS, int language_code);						// Engchar + Number + Plus Normalize
void VMPNDN(char *num_in, char *VMP, int language_code);						// version method prefix+[Number+dot]+Number ex:20.04、16.0.3
void BNIFRS(char *num_in, char *NIC, int language_code);						// begining Numerical, individually for rest string
void THCMCS(char *num_in, char *HMS, int language_code);						// Time : Hour : Minute : Second
void UAPPMU(char *upm, char *modify, int language_code);						// union all possible per mill usage
void RSFSTF(char *num_in, char *RAT, int language_code);						// ratio spoken-form words with not digital input(short type first)
void SEMINS(char *num_in, char *SEMI, int language_code);						// numerals with semi-Numerical suffix
void MYSHUT(char *num_in, char *MSU, int language_code);						// money slash unit i.e. 8萬/坪、$12/m2
void YMOMDT(char *num_in, char *modify, int language_code);						// Numeral+year+Numeral+to+month or Numeral+month+Numeral+to+day i.e 2015年4到9月
void YMOMDT(char *num_in, char *modify, int language_code);						// Numeral+year+Numeral+to+month or Numeral+month+Numeral+to+day i.e 2015年4到9月
void N2SCAC(char *num_in, char *modify, int language_code);						// colon as chapter i.e 約翰一書2:2；哥林多後書5:21；羅馬書3:23-26
void MASAFW(char *num_in, char *modify, int language_code);						// Minute and second of arc i.e 60°26′10″N 134°15′02″W
void EAWWON(char *num_in, char *modify, int language_code);						// English abbreviation with/wuthout numerals i.e. No.1
void CFTSFW(char *cf, char *modify, int language_code);							// chemical formula to spoken form word i.e. 2H+ + O2−
void RWAPAS(char *rw, char *modify, int language_code);							// range without any prefix and suffix i.e. 小行星列表/10001-11000,  2009-2010
void RWPOST(char *rw, char *modify, int language_code);							// range with prefix or suffix i.e. Ep56－68  pp. 319–349
void CRTSFW(char *cr, char *modify, int language_code);							// Competition results to spoken form word i.e. 2:13.51 +7.28
void LATEXT(char *latex, char *modify, int language_code);						// Latex to spoken form word i.e. 10^{-24}
void HSAESF(char *hsae, char *modify, int language_code);						// hat symbol as exponentiation i.e. 3^2=9 10^2 -5^2 10^0.5 1.5^8 2^2.71828
void DAFROL(char *num_in, char *modify, int language_code);						// Dash as "之" for regulations of law
void MDHMTO(char *num_in, char *modify, int language_code);						// mounth day hour minute - mounth day hour minute
void NFNLT4(char *num_in, char *modify, int language_code);						// numerical for Numerals less than 4 times ; shortest first for others
void THMSSF(char *num_in, char *HMS, int language_code);						// Time : : Minute : Second
void NFSNFS(char *num_in, char *modify, int language_code);						// Numerical_format_sequence dash Numerical_format_sequence
void NFNLT3(char *num_in, char *modify, int language_code);						// numerical for Numerals less than 3 times ; shortest first for others
void NUDLOP(char *num_in, char *modify, int language_code);						// Numerical_format_sequence/continuous_number unit dash loop i.e. 2,000萬元-1,200萬元-6萬元-2.85萬元
void CNWAAN(char *num_in, char *modify, int language_code);						// Chinese Numerals written as Arabic numerals

/*add from shoawei's RBTN version 1090429*/
void NWDSFW(char *num_in, char *DPSPW);											// numerals_with_date_word_to_spoken_form_word
void FRACSFW(char *num_in, char *DPSPW, int language_code);						//fraction_to_spoken_form_word
void PTSFW(char *num_in, char *DPSPW, int language_code);						//proportion_to_spoken_form_word
void SDPTSFW(char *num_in, char *DPSPW);										// simple_decimal_point_to_spoken_form_word
//void TempDPTSFW(char *num_in, char *DPSPW);									// decimal_point_to_spoken_form_word
/*add from shoawei's RBTN version 1090429*/

void set_fst(FST *fst);
void destroy_rules(RULES *rul);
void destroy_flags(FLAGS *flags);
void destroy_transformation(TRANSFORMATION *tra);
void destroy_substitution(SUBSTITUTION *sub);
int read_a_line(char **line, int *capacity_of_line, FILE *fin);
void destroy_fst(FST *fst);
void destroy_text(TEXT *text);
void ini_nsw(NSW_TOKEN *nsw);
void destroy_nsw(NSW_TOKEN *nsw);
void paser_a_sentence(FST *fst, VITERBIINFO *vinfo, char *line, NSW_TOKEN *nsw);
int Retreat_a_utf8_word(char *line, int *index);
int fill_osym(OSYM **pre, OSYM **next, int depth, int state, char *input, char *output, int step);
void destroy_osym(OSYM *head);
int fill_nsw(NSW_TOKEN *nsw, FST *fst, OSYM **head, int num_sur_state, int *sur_state, char *sentence, char *word, int *read_idx, int statr_idx, int *replace_flag);
void fill_text_out(char *sentence_in, char **sentence_out, int raw, NSW_TOKEN *nsw, FLAGS *flags, TRANSFORMATION *tra, FILE *fnswm);
void substitute(TEXT *text_in, TEXT *text_tmp, SUBSTITUTION *sub);
int compare_template(TEMPLATE *template, char *sentence, int idx);
void substituting(SUBSTITUTION_WORDS *sub_word, char **sentence, int idx);
void concatenation(char **sentence_out, int *out_len, char *SFW, char *sentence_in, int *in_idx, int start_idx, int end_idx);
int replacecomparefun(const void *a, const void *b);
int subcomparefun(const void *a, const void *b);
int bin_substitution_search(char *sentence, SUBSTITUTION_WORDS_LIST *list);
int bin_transform_rule_search(char *rul_name, TRANSFORMATION *tra);
int bin_replace_word_search(char *rel_word, TRANSFORMATION_RULES *trel);
int bin_string_search_len_match(char *sentence, char **set, int set_size);
int check_flags(char *rule, FLAGS *flags);
int flagscomparefun(const void *a, const void *b);
void replacement(char **line, int *start_idx, char *rel_raw, char *rel_des);
int has_number(char *line);
int has_slash(char *line);
int has_colon(char *line);
int has_mandarin(char *line);
int has_dot(char *line);
int has_dot_numerals(char *line);
int has_comma(char *line);
int has_dash(char *line);
void normalize_date(char *num_in, char *nor_num_in);
//void normalize_raw_text(TEXT *raw, TEXT *modify);
int stringcomparefun(const void *a, const void *b);
int stringlengthcomparefun(const void *a, const void *b);
int get_heximal_val(char *word);
char *get_ch_Number(char *word);
char *get_eng_Number(char *word);
char *html2utf8(char *hcode);
char *retdaynum();
int decide_language(char *line, NSW_TOKEN *nsw);
int decide_language_by_sentence(char *line, NSW_TOKEN *nsw);
void insert_string(char *line, char *prev, char *next, char *insert_s);
void numerical_to_ordinal(char *in, char *out);
void roman_num2arabic_num(char *in, char *out);
void pluralize(char *in, char *out);
void normalize_english_uppercase(char *eng_in, char *eng_out);
int roman_num_converter(char *roman_num);
int strfinncmp(char *line1, char *line2, int count);
void initial_viterbi_info(FST *fst, VITERBIINFO *vinfo);
void destroy_viterbi_info(VITERBIINFO *vinfo);
int myatoi(char *sa);
float myatof(char *sa);
void add_day_suffix(char *in, char *out);
int country_name_idx(char *name);
void normalize_alphabet_to_ascii(char *raw, char *modify, int capital_flag);
int AllisNumber(char *line);
void remove_space(char *line);
int is_utf8_string(char *line);
int ch_numerals_to_ar_numerals(char *in, char *out);
void wrap_strcpy(char *t, char *s, int dummy);
#endif
