
// 02190201003-MUSA BEYTEKİN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doldur(int satirBoyut, char matris[satirBoyut][100], int satir, char kelime[])
{
    int i;
    for (i = 0; kelime[i] != '\0'; i++)
    {
        matris[satir][i] = kelime[i];
    }
    matris[satir][i] = '\0';
}


int main()
{

    FILE *file;
    char ch;
    char kelime[100];
    int i, j, m, t, f, counter = 0;
    char dosya[1000];

    printf("dosyanin yolunu giriniz: ");
    scanf("%s", dosya);

    printf("**************************************************************** \n");
    printf("Dosya kaynak kodu: \n");
    printf("");

    if ((file = fopen(dosya, "r")) == NULL)
    {

        printf("Dosya acilamadi...\n");
    }
    else
    {

        while (ch != EOF)
        {

            ch = fgetc(file);
            printf("%c", ch);
            if (ch == ' ' || ch == '\n' || ch == '\t')
            {
                continue;
            }
            j++;
        }
    }

    char operatorler[] = {';', ':', ',', '!', '<', '>', '=', '(', ')', '{', '}', '[', ']', '+', '-', '*', '/', '\'', '\"', '\\', '%', '&', '|', '#'};
    char degerler[][100] = {"int", "char", "float", "double", "long", "short", "case", "return", "else", "void"};

    int boyut = j;

    j = 0;

    int degerlerBoyut = sizeof(degerler) / sizeof(degerler[0]);
    char karakterler[boyut];
    char sonVeri[boyut][100];

    file = fopen(dosya, "r");

    fseek(file, 0, SEEK_SET);

    j = 0;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            continue;
        }

        karakterler[j] = ch;
        j++;
    }

    karakterler[boyut] = '\0';

    fclose(file);

    int operator= 0;
    int cift = 0;

    memset(kelime, 0, sizeof(kelime));

    for (i = 0; i < boyut; i++)
    {
        for (j = 0; j < sizeof(operatorler); j++)
        {
            if (karakterler[i] == operatorler[j])
            {
                operator= 1;

                if (karakterler[i] == '+' && karakterler[i] == karakterler[i + 1])
                {
                    cift = 1;
                    break;
                }

                if (karakterler[i] == '-' && karakterler[i] == karakterler[i + 1])
                {
                    cift = 1;
                    break;
                }

                if (karakterler[i] == '&' && karakterler[i] == karakterler[i + 1])
                {
                    cift = 1;
                    break;
                }

                if (karakterler[i] == '|' && karakterler[i] == karakterler[i + 1])
                {
                    cift = 1;
                    break;
                }

                if (karakterler[i] == '/' && karakterler[i] == karakterler[i + 1])
                {
                    cift = 1;
                    break;
                }

                if (karakterler[i] == '/' && karakterler[i + 1] == '*')
                {
                    cift = 1;
                    break;
                }

                if (karakterler[i] == '\\' && karakterler[i + 1] == 'n')
                {
                    cift = 1;
                    break;
                }

                if (karakterler[i] == '*' && karakterler[i + 1] == '/')
                {
                    cift = 1;
                    break;
                }

                if ((karakterler[i] == '>' || karakterler[i] == '<' || karakterler[i] == '+' || karakterler[i] == '-' || karakterler[i] == '*' || karakterler[i] == '/' || karakterler[i] == '%' || karakterler[i] == '!' || karakterler[i] == '=') && karakterler[i + 1] == '=')
                {
                    cift = 1;
                    break;
                }
            }
        }

        if (operator== 0)
        {
            kelime[m] = karakterler[i];
            int dogruMu;

            for (j = 0; j < degerlerBoyut; j++)
            {
                dogruMu = 1;
                for (t = 0; degerler[j][t] != '\0'; t++)
                {
                    if (kelime[t] != degerler[j][t])
                    {
                        dogruMu = 0;
                        break;
                    }
                }

                if (dogruMu == 1)
                {
                    doldur(boyut, sonVeri, counter++, degerler[j]);

                    m = -1;
                    memset(kelime, 0, sizeof(kelime));
                    break;
                }
            }
            m++;
        }
        else
        {
            if (kelime[0] != '\0')
            {
                kelime[m] = '\0';
                doldur(boyut, sonVeri, counter++, kelime);
            }

            if (cift == 1)
            {
                char temp1[3] = {karakterler[i], karakterler[i + 1], '\0'};
                doldur(boyut, sonVeri, counter++, temp1);
                i++;
            }
            else
            {
                char temp2[2] = {karakterler[i], '\0'};
                doldur(boyut, sonVeri, counter++, temp2);
            }

            m = 0;
            operator= 0;
            cift = 0;
            memset(kelime, 0, sizeof(kelime));
        }
    }

    printf("\nKelimelestirilmis hali : \n");
    for (i = 0; i < counter; i++)
    {
        for (j = 0; sonVeri[i][j] != '\0'; j++)
        {
            printf("%c", sonVeri[i][j]);
        }
        printf(", ");
    }

    return 0;
}