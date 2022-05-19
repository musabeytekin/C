
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char ch;
    FILE *fp;
    char file[1000];
    char data[1000];
    int i = 0, size = 0;
    int ram[256];
    int AX = 0, BX = 0, CX = 0, DX = 0;

    int a, c, mod, j;

    int dAX[8] = {1, 0, 1, 0, 1, 0, 1, 0};
    int dBX[8] = {0, 1, 0, 1, 0, 1, 0, 1};
    int dCX[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    int dDX[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int dEX[8];

    // gramer tespiti icin gerekli degiskenler
    int command = 0;
    int parameters = 0;
                

    // Dosya okuma

    printf("Enter the path of file:  ");
    scanf("%s", file);

    if ((fp = fopen(file, "r")) == NULL)
    {

        printf("File could not be opened...\n");
        return 0; // program durdurulur
    }

    printf("**************************************************************** \n");
    printf("File's source code: \n\n");
    printf("");
    while (ch != EOF)
    {

        ch = fgetc(fp);
        data[i] = ch;
        printf("%c", data[i]);
        i++;
    }
    int hata = 0;
    i = 0;

    while (data[i] != NULL)
    {
        i++;
    }
    size = i;
    data[size] = '\0';

    printf("\n\n****** Results ******\n\n");

    for (i = 0; data[i] != '\0'; i++)
    {
        
        /*if (hata == 1)
        {
            printf("\nDosya Gramere uygun degildir..... \n");
            return 0; // program durdurulur...
        }*/

        if (data[i] == 'H' && data[i + 1] == 'R' && data[i + 2] == 'K')
        {
            //

            if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                AX = BX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                AX = CX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                AX = DX;
                c = AX;

            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                AX = a;
                c = AX;

            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                BX = AX;
                c = BX;

            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                BX = a;
                c = BX;

            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                BX = CX;
                c = BX;

            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                BX = DX;
                c = BX;

            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                CX = AX;
                c = CX;

            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                CX = BX;
                c = CX;

            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                CX = a;
                c = CX;

            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                CX = DX;
                c = CX;

            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                DX = AX;
                c = DX;

            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                DX = BX;
                c = DX;

            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                DX = CX;
                c = DX;

            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                DX = a;
                c = DX;

            }
            else
            {
                parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
            if (data[i + 3] == ' ')
            {
                command = 1;
            }
            else
            {
                command = 0;
                printf("file gramere uygun degildir...");
                return 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
        }
        else if (data[i] == 'T' && data[i + 1] == 'O' && data[i + 2] == 'P')
        {
            if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                AX = AX + BX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                AX = AX + CX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                AX = AX + DX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                AX = AX + AX;
                c = AX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                BX = BX + AX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                BX = BX + BX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                BX = BX + CX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                BX = BX + DX;
                c = BX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                CX = CX + AX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                CX = CX + BX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                CX = CX + CX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                CX = CX + DX;
                c = CX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                DX = DX + AX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                DX = DX + BX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                DX = DX + CX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                DX = DX + DX;
                c = DX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 5] != 'X')
            {
                a = data[i + 7] - '0';
                AX = AX + a;
                c = AX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                BX = BX + a;
                c = BX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                CX = CX + a;
                c = CX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                DX = DX + a;
                c = DX;
            }
            else
            {
                parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
            if (data[i + 3] == ' ')
            {
                command = 1;
            }
            else
            {
                command = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
        }

        else if (data[i] == 'C' && data[i + 1] == 'R' && data[i + 2] == 'P')
        {

            if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                AX = AX * BX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                AX = AX * CX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                AX = AX * DX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                AX = AX * AX;
                c = AX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                BX = BX * AX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                BX = BX * BX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                BX = BX * CX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                BX = BX * DX;
                c = BX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                CX = CX * AX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                CX = CX * BX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                CX = CX * CX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                CX = CX * DX;
                c = CX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                DX = DX * AX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                DX = DX * BX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                DX = DX * CX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                DX = DX * DX;
                c = DX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                AX = AX * a;
                c = AX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                BX = BX * a;
                c = BX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                CX = CX * a;
                c = CX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                DX = DX * a;
                c = DX;
            }
            else
            {
                parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
            

            if (data[i + 3] == ' ')
            {
                command = 1;
            }
            else
            {
                command = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
        }

        else if (data[i] == 'C' && data[i + 1] == 'I' && data[i + 2] == 'K')
        {

            if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                AX = AX - BX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                AX = AX - CX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                AX = AX - DX;
                c = AX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                AX = AX - AX;
                c = AX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                BX = BX - AX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                BX = BX - BX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                BX = BX - CX;
                c = BX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                BX = BX - DX;
                c = BX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                CX = CX - AX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                CX = CX - BX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                CX = CX - CX;
                c = CX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                CX = CX - DX;
                c = CX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                DX = DX - AX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                DX = DX - BX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                DX = DX - CX;
                c = DX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                DX = DX - DX;
                c = DX;
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                AX = AX - a;
                c = AX;
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                BX = BX - a;
                c = BX;
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                CX = CX - a;
                c = CX;
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                DX = DX - a;
                c = DX;
            }
            else
            {
                parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
            

            if (data[i + 3] == ' ')
            {
                command = 1;
            }
            else
            {
                command = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
        }

        else if (data[i] == 'B' && data[i + 1] == 'O' && data[i + 2] == 'L')
        {
            if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                AX = AX / BX;
                mod = AX % BX;
                c = AX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                AX = AX / CX;
                mod = AX % CX;
                c = AX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                AX = AX / DX;
                mod = AX % DX;
                c = AX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                AX = AX / AX;
                mod = AX % AX;
                c = AX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                BX = BX / AX;
                mod = BX % AX;
                c = BX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                BX = BX / BX;
                mod = BX % BX;
                c = BX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                BX = BX / CX;
                mod = BX % CX;
                c = BX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                BX = BX / DX;
                mod = BX % DX;
                c = BX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                CX = CX / AX;
                mod = CX % AX;
                c = CX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                CX = CX / BX;
                mod = CX % BX;
                c = CX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                CX = CX / CX;
                mod = CX % CX;
                c = CX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'D' && data[i + 8] == 'X')
            {
                CX = CX / DX;
                mod = CX % DX;
                c = CX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'A' && data[i + 8] == 'X')
            {
                DX = DX / AX;
                mod = DX % AX;
                c = DX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'B' && data[i + 8] == 'X')
            {
                DX = DX / BX;
                mod = DX % BX;
                c = DX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] == 'C' && data[i + 8] == 'X')
            {
                DX = DX / CX;
                mod = DX % CX;
                c = DX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                DX = DX / DX;
                mod = DX % DX;
                c = DX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'A' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'A' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                AX = AX / a;
                mod = AX % a;
                c = AX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'B' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                BX = BX / a;
                mod = BX % a;
                c = BX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'C' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                CX = CX / a;
                mod = CX % a;
                c = CX;
                printf("leftover from mod= %d", mod);
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X' && data[i + 6] == ',' && data[i + 7] != 'D' && data[i + 8] != 'X')
            {
                a = data[i + 7] - '0';
                DX = DX / a;
                mod = DX % a;
                c = DX;
                printf("leftover from mod= %d", mod);
            }
            else
            {
                parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
            
            if (data[i + 3] == ' ')
            {
                command = 1;
            }
            else
            {
                command = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
        }

        else if (data[i] == 'V' && data[i + 1] == 'E')
        {
            if (data[i + 2] == 'Y' && data[i + 3] == 'A')
            {
                if (data[i + 4] == ' ')
                {
                    command = 1;
                }
                else
                {
                    command = 0;
                printf("file gramere uygun degildir...");
                return 0;
                }
                if (data[i + 5] == 'A' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'B' && data[i + 9] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] + dBX[j];
                        if (dAX[j] > 1)
                        {
                            dAX[j] = 1;
                        }
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 5] == 'A' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'C' && data[i + 9] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] + dCX[j];
                        if (dAX[j] > 1)
                        {
                            dAX[j] = 1;
                        }
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 5] == 'A' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'D' && data[i + 9] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] + dDX[j];
                        if (dAX[j] > 1)
                        {
                            dAX[j] = 1;
                        }
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 5] == 'A' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'A' && data[i + 9] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] + dAX[j];
                        if (dAX[j] > 1)
                        {
                            dAX[j] = 1;
                        }
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 5] == 'B' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'A' && data[i + 9] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dBX[j] + dAX[j];
                        if (dBX[j] > 1)
                        {
                            dBX[j] = 1;
                        }
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 5] == 'B' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'B' && data[i + 9] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] + dBX[j];
                        if (dBX[j] > 1)
                        {
                            dBX[j] = 1;
                        }
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 5] == 'B' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'C' && data[i + 9] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] + dCX[j];
                        if (dBX[j] > 1)
                        {
                            dBX[j] = 1;
                        }
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 5] == 'B' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'D' && data[i + 9] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] + dDX[j];
                        if (dBX[j] > 1)
                        {
                            dBX[j] = 1;
                        }
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 5] == 'C' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'A' && data[i + 9] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] + dAX[j];
                        if (dCX[j] > 1)
                        {
                            dCX[j] = 1;
                        }
                         
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 5] == 'C' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'B' && data[i + 9] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] + dBX[j];
                        if (dCX[j] > 1)
                        {
                            dCX[j] = 1;
                        }
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 5] == 'C' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'C' && data[i + 9] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] + dCX[j];
                        if (dCX[j] > 1)
                        {
                            dCX[j] = 1;
                        }
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 5] == 'C' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'D' && data[i + 9] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] + dDX[j];
                        if (dCX[j] > 1)
                        {
                            dCX[j] = 1;
                        }
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 5] == 'D' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'A' && data[i + 9] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] + dAX[j];
                        if (dDX[j] > 1)
                        {
                            dDX[j] = 1;
                        }
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 5] == 'D' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'B' && data[i + 9] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] + dBX[j];
                        if (dDX[j] > 1)
                        {
                            dDX[j] = 1;
                        }
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 5] == 'D' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'C' && data[i + 9] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] + dCX[j];
                        if (dDX[j] > 1)
                        {
                            dDX[j] = 1;
                        }
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 5] == 'D' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] == 'D' && data[i + 9] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] + dDX[j];
                        if (dDX[j] > 1)
                        {
                            dDX[j] = 1;
                        }
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 5] == 'A' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] != 'A' && data[i + 9] != 'X')
                {
                    a = data[i + 8] - '0';
                    printf("\n\nAX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] + dEX[j];
                        if (dAX[j] > 1)
                        {
                            dAX[j] = 1;
                        }
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 5] == 'B' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] != 'B' && data[i + 9] != 'X')
                {
                    a = data[i + 8] - '0';
                    printf("\n\nBX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] + dEX[j];
                        if (dBX[j] > 1)
                        {
                            dBX[j] = 1;
                        }
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 5] == 'C' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] != 'C' && data[i + 9] != 'X')
                {
                    a = data[i + 8] - '0';
                    printf("\n\nCX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] + dCX[j];
                        if (dCX[j] > 1)
                        {
                            dCX[j] = 1;
                        }
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 5] == 'D' && data[i + 6] == 'X' && data[i + 7] == ',' && data[i + 8] != 'D' && data[i + 9] != 'X')
                {
                    a = data[i + 8] - '0';
                    printf("\n\nDX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] + dEX[j];
                        if (dDX[j] > 1)
                        {
                            dDX[j] = 1;
                        }
                        printf("%d,", dDX[j]);
                    }
                }
                else
                {
                    parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
                }
            
            }
            else
            {
                if (data[i + 3] == 'A' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'B' && data[i + 7] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] * dBX[j];
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 3] == 'A' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'C' && data[i + 7] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] * dCX[j];
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 3] == 'A' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'D' && data[i + 7] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] * dDX[j];
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 3] == 'A' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'A' && data[i + 7] == 'X')
                {
                    printf("\n\nAX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] * dAX[j];
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 3] == 'B' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'A' && data[i + 7] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dBX[j] * dAX[j];
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 3] == 'B' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'B' && data[i + 7] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] * dBX[j];
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 3] == 'B' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'C' && data[i + 7] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] * dCX[j];
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 3] == 'B' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'D' && data[i + 7] == 'X')
                {
                    printf("\n\nBX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] * dDX[j];
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 3] == 'C' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'A' && data[i + 7] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] * dAX[j];
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 3] == 'C' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'B' && data[i + 7] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] * dBX[j];
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 3] == 'C' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'C' && data[i + 7] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] * dCX[j];
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 3] == 'C' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'D' && data[i + 7] == 'X')
                {
                    printf("\n\nCX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] * dDX[j];
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 3] == 'D' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'A' && data[i + 7] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] * dAX[j];
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 3] == 'D' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'B' && data[i + 7] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] * dBX[j];
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 3] == 'D' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'C' && data[i + 7] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] * dCX[j];
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 3] == 'D' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] == 'D' && data[i + 7] == 'X')
                {
                    printf("\n\nDX - Binary Code = ");
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] * dDX[j];
                        printf("%d,", dDX[j]);
                    }
                }
                else if (data[i + 3] == 'A' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] != 'A' && data[i + 7] == 'X')
                {
                    a = data[i + 6] - '0';
                    printf("\n\nAX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dAX[j] = dAX[j] * dEX[j];
                        printf("%d,", dAX[j]);
                    }
                }
                else if (data[i + 3] == 'B' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] != 'B' && data[i + 7] != 'X')
                {
                    a = data[i + 6] - '0';
                    printf("\n\nBX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dBX[j] = dBX[j] * dEX[j];
                        printf("%d,", dBX[j]);
                    }
                }
                else if (data[i + 3] == 'C' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] != 'C' && data[i + 7] != 'X')
                {
                    a = data[i + 6] - '0';
                    printf("\n\nCX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dCX[j] = dCX[j] * dEX[j];
                        printf("%d,", dCX[j]);
                    }
                }
                else if (data[i + 3] == 'D' && data[i + 4] == 'X' && data[i + 5] == ',' && data[i + 6] != 'D' && data[i + 7] != 'X')
                {
                    a = data[i + 6] - '0';
                    printf("\n\nDX - Binary Code = ");
                    for (j = 8; a > 0; j--)
                    {
                        dEX[j] = a % 2;
                        a = a / 2;
                    }
                    for (j = 0; j < 8; j++)
                    {
                        dDX[j] = dDX[j] * dEX[j];
                        printf("%d,", dDX[j]);
                    }
                }
                else
                {
                    parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
                }
            
            }
        }

        else if (data[i] == 'D' && data[i + 1] == 'E' && data[i + 2] == 'G')
        {
            if (data[i + 4] == 'A' && data[i + 5] == 'X')
            {
                printf("\n\nAX - Binary Code = ");
                for (j = 0; j < 8; j++)
                {
                    if (dAX[j] == 1)
                    {
                        dAX[j] = 0;
                    }
                    else
                    {
                        dAX[j] = 1;
                    }
                    printf("%d,", dAX[j]);
                }
            }
            else if (data[i + 4] == 'B' && data[i + 5] == 'X')
            {
                printf("\n\nBX - Binary Code = ");
                for (j = 0; j < 8; j++)
                {
                    if (dBX[j] == 1)
                    {
                        dBX[j] = 0;
                    }
                    else
                    {
                        dBX[j] = 1;
                    }
                    printf("%d,", dBX[j]);
                }
            }
            else if (data[i + 4] == 'C' && data[i + 5] == 'X')
            {
                printf("\n\nCX - Binary Code = ");
                for (j = 0; j < 8; j++)
                {
                    if (dCX[j] == 1)
                    {
                        dCX[j] = 0;
                    }
                    else
                    {
                        dCX[j] = 1;
                    }
                    printf("%d,", dCX[j]);
                }
            }
            else if (data[i + 4] == 'D' && data[i + 5] == 'X')
            {
                printf("\n\nDX - Binary Code = ");
                for (j = 0; j < 8; j++)
                {
                    if (dDX[j] == 1)
                    {
                        dDX[j] = 0;
                    }
                    else
                    {
                        dDX[j] = 1;
                    }
                    printf("%d,", dDX[j]);
                }
            }
            else
            {
                parameters = 0;
                printf("file gramere uygun degildir...");
                return 0;
            }
            
        }
    }

    /*for(i = 0; i < size; i++){
        printf("\n");
        printf("%c", data[i]);
    }*/

    printf("\n");

    printf("\nAX= %d\nBX= %d\nCX= %d\nDX= %d", AX, BX, CX, DX);

    return 0;
}