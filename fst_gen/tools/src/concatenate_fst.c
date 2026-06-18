#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser_line(char *line, char *istate, char *ostate, char *itemp, char *otemp, char *wtemp);
int read_a_line(char **line, int *capacity_of_line, FILE *fin);
int get_maximum_state_idx(FILE *ffst);
void concatenation(FILE *fin1, FILE *fin2, FILE *fout, int start_idx);
void run(FILE *fin1, FILE *fin2, FILE *fout);
int main(int argc, char *argv[])
{
    FILE *fin1, *fin2, *fout;

    if (argc != 4)
    {
        printf("Usage: execution input_fst_1 input_fst_2 output_fst\n");
        exit(1);
    }
    if (!(fin1 = fopen(argv[1], "r")))
    {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }
    if (!(fin2 = fopen(argv[2], "r")))
    {
        printf("Can't open %s\n", argv[2]);
        exit(1);
    }
    if (!(fout = fopen(argv[3], "w")))
    {
        printf("Can't open %s\n", argv[3]);
        exit(1);
    }

    run(fin1, fin2, fout);

    fclose(fin1);
    fclose(fin2);
    fclose(fout);

    return 0;
}
void run(FILE *fin1, FILE *fin2, FILE *fout)
{
    int start_idx;

    start_idx = get_maximum_state_idx(fin1);
    //printf("%d\n", start_idx);
    concatenation(fin1, fin2, fout, start_idx);
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