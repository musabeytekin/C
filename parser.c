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

int operatorControl(char c, int alfabeUzunlugu, char operatorler[alfabeUzunlugu])
{
    int i;
    for (i = 0; i < alfabeUzunlugu; i++)
    {
        if (c == operatorler[i])
        {
            return 1;
        }
    }

    return 0;
}
int sayiHarfControl(char c, int alfabeUzunlugu, char sayilarHarfler[alfabeUzunlugu])
{
    int i;
    for (i = 0; i < alfabeUzunlugu; i++)
    {
        if (c == sayilarHarfler[i])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{

    FILE *file;
    char operatorler[] = {';', ':', ',', '!', '<', '>', '=', '(', ')', '{', '}', '[', ']', '+', '-', '*', '/', '\'', '\"', '\\', '%', '&', '|', '#'};
    char degerler[][100] = {"int", "char", "float", "double", "long", "short", "case", "return", "else", "void"};
    char sayilarHarfler[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F'};
    int degerlerBoyut = sizeof(degerler) / sizeof(degerler[0]);
    int operatorlerBoyut = sizeof(operatorler) / sizeof(operatorler[0]);
    int sayilarHarflerBoyut = sizeof(operatorler) / sizeof(operatorler[0]);

    char ch;
    char kelime[100];
    int i, j = 0, m, t, f, counter = 0;
    char dosya[1000];

    printf("dosyanin yolunu giriniz: ");
    // scanf("%s", dosya);

    gets(dosya);

    printf("**************************************************************** \n");
    printf("Dosya kaynak kodu: \n");
    printf("");

    file = fopen(dosya, "r");

    if (file == NULL)
    {
        printf("Dosya acilamadi...\n");
        return 0; // program durudurulur.
    }

    j = 0;

    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            continue;
        }
        j++;
    }

    int boyut = j;

    char karakterler[boyut];
    char sonVeri[boyut][100];

    // file = fopen(dosya, "r");

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

    m = 0;
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

    int hata = 0;
    int kontrolIf = 0;
    int normalParantez = -1;
    int susluParantez = -1;
    int operatorVarMi = 0;
    int atamaDurum = 0;
    int innerCounter = 1;
    int icAtama = 0;
    int state;
    int ifIciHata = 0;
    // int kontrolElseIf = 0;
    // int kontrolElse = 0;
    for (i = 0; i < counter; i++)
    {
        for (j = 0; sonVeri[i][j] != '\0'; j++)
        {
            if (hata == 1)
            {
                i = counter;
                break;
            }

            else if (kontrolIf == 0)
            {

                if (sonVeri[i][j] == 'i' && sonVeri[i][j + 1] == 'f' && sonVeri[i][j + 2] == '\0')
                {
                    kontrolIf = 1;
                    break;
                }
            }

            else if (normalParantez == -1)
            {
                if (sonVeri[i][j] == '(')
                {
                    normalParantez++;
                    break;
                }
                else
                {
                    hata = 1;
                }
            }
            else if (normalParantez == 0)
            {
                if (innerCounter == 1 || innerCounter == 3)
                {
                    hata = operatorControl(sonVeri[i][j], operatorlerBoyut, operatorler);
                    innerCounter++;
                    break;
                }
                else if (innerCounter == 2)
                {
                    if (sonVeri[i][j] == '>' || sonVeri[i][j] == '<' || (sonVeri[i][j] == '<' && sonVeri[i][j + 1] == '=') ||
                        (sonVeri[i][j] == '>' && sonVeri[i][j + 1] == '=') || (sonVeri[i][j] == '=' && sonVeri[i][j + 1] == '=') ||
                        (sonVeri[i][j] == '!' && sonVeri[i][j + 1] == '='))
                    {
                        operatorVarMi = 1;
                        innerCounter++;
                        break;
                    }
                    else
                    {
                        hata = 1;
                    }
                }
                else if (innerCounter == 4)
                {
                    if (sonVeri[i][j] == ')')
                    {
                        normalParantez++;
                        innerCounter = 1;
                        break;
                    }
                    else
                    {
                        hata = 1;
                    }
                }
            }
            else if (susluParantez == -1)
            {
                if (sonVeri[i][j] == '{')
                {
                    susluParantez++;
                    break;
                }
                else
                {

                    hata = 1;
                }
            }

            else if (susluParantez == 0)
            {
                if (innerCounter == 1 || innerCounter == 3)
                {
                    hata = operatorControl(sonVeri[i][j], operatorlerBoyut, operatorler);
                    innerCounter++;
                    break;
                }
                else if (innerCounter == 2)
                {
                    if (sonVeri[i][j] == '=' && sonVeri[i][j + 1] == '\0')
                    {
                        atamaDurum = 1;
                        innerCounter++;
                    }
                    else
                    {
                        hata = 1;
                    }

                    break;
                }
                else if (innerCounter == 4)
                {
                    if (sonVeri[i][j] == '+' || sonVeri[i][j] == '-' || (sonVeri[i][j] == '/' && sonVeri[i][j] == '*'))
                    {

                        state = sayiHarfControl(sonVeri[i + 1][j], sayilarHarflerBoyut, sayilarHarfler);

                        if (state == 0)
                        {
                            ifIciHata = 1;
                        }
                    }
                    if (sonVeri[i][j] == '}')
                    {
                        susluParantez++;

                        innerCounter = 0;

                        break;
                    }
                }
            }

            else if (kontrolIf == 1 && normalParantez == 1 && susluParantez == 1 && atamaDurum == 1 && operatorVarMi == 1)
            {
                if (sonVeri[i][j] == 'e' && sonVeri[i][j + 1] == 'l' && sonVeri[i][j + 2] == 's' && sonVeri[i][j + 3] == 'e')
                {
                    if (sonVeri[i + 1][0] == '{')
                    {
                        susluParantez = -1;
                        atamaDurum = 0;
                        innerCounter = 1;
                        icAtama = 0;
                    }
                    else if (sonVeri[i + 1][0] == 'i')
                    {
                        kontrolIf = 0;
                        normalParantez = -1;
                        susluParantez = -1;
                        operatorVarMi = 0;
                        atamaDurum = 0;

                        innerCounter = 1;
                        icAtama = 0;
                    }
                    else
                    {
                        hata = 1;
                    }
                    break;
                }
                else
                {
                    hata = 1;
                }
            }
        }
    }

    printf("\n================================\n");
    if (kontrolIf == 1 && normalParantez == 1 && susluParantez == 1 && atamaDurum == 1 && operatorVarMi == 1 && hata == 0 && ifIciHata == 0)
    {
        printf("Program gramer'e uygun.");
    }
    else if (kontrolIf != 1)
    {
        printf("if sozcugunun kullaniminda hata var");
    }
    else if (ifIciHata == 1)
    {
        printf("if blogu icerisinde hata var ");
    }
    else if (normalParantez != 1)
    {
        printf("( ) ifadesinde hata var ");
    }
    else if (atamaDurum != 1)
    {
        printf(" atama blogunda hata var");
    }
    else if (susluParantez != 1)
    {
        printf("{ } ifadesinde hata var ");
    }

    else if (operatorVarMi != 1)
    {
        printf("operator kullaniminda hata var ");
    }

    else
    {
        printf(" Program gramer ' e uygun degil");
    }
}
