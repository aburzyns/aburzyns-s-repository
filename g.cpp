
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>


using namespace std;

void gland(int tab[50][50])
{
    srand(time(NULL));

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            tab[i][j] = 0;
        }
    }

    for(int o = 0; o < 10; o++)
    {
        int v1, v2;
        v1 = rand() % 50;
        v2 = rand() % 50;

        for(int m = -2; m < 3; m++)
        {
            for(int n = -2; n < 3; n++)
            {
                tab[v1 + m][v2 + n] = 1;
            }
        }

        for(int m = -3; m < 4; m++)
        {
            for(int n = -3; n < 4; n++)
            {
                if(tab[v1 + m][v2 + n] == 0)
                {
                    int random = rand() % 10;
                    if(random == 0)
                    {
                        tab[v1 + m][v2 + n] = 0;   
                    }
                    else
                    {
                        tab[v1 + m][v2 + n] = 1;
                    }
                }
                else
                {
                    tab[v1 + m][v2 + n] = 1;
                }
            }
        }

        for(int m = -4; m < 5; m++)
        {
            for(int n = -4; n < 5; n++)
            {
                if(tab[v1 + m][v2 + n] == 0)
                {
                    int random = rand() % 10;
                    if(random == 0 || random == 1 || random == 2 || random == 3)
                    {
                        tab[v1 + m][v2 + n] = 0;   
                    }
                    else
                    {
                        tab[v1 + m][v2 + n] = 1;
                    }
                }
                else
                {
                    tab[v1 + m][v2 + n] = 1;
                }
            }
        }

        for(int m = -5; m < 6; m++)
        {
            for(int n = -5; n < 6; n++)
            {
                if(tab[v1 + m][v2 + n] == 0)
                {
                    int random = rand() % 10;
                    if(random == 0 || random == 1 || random == 2 || random == 3 || random == 4 || random == 5 || random == 6)
                    {
                        tab[v1 + m][v2 + n] = 0;   
                    }
                    else
                    {
                        tab[v1 + m][v2 + n] = 1;
                    }
                }
                else
                {
                    tab[v1 + m][v2 + n] = 1;
                }
            }
        }

        for(int m = -5; m < 6; m++)
        {
            for(int n = -5; n < 6; n++)
            {
                if(tab[v1 + m][v2 + n] == 0)
                {
                    int random = rand() % 10;
                    if(random == 0 || random == 1 || random == 2 || random == 3 || random == 4 || random == 5 || random == 6 || random == 7 || random == 8)
                    {
                        tab[v1 + m][v2 + n] = 0;   
                    }
                    else
                    {
                        tab[v1 + m][v2 + n] = 1;
                    }
                }
                else
                {
                    tab[v1 + m][v2 + n] = 1;
                }
            }
        }

        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                if(tab[i][j] == 0)
                {
                    if(tab[i+1][j] == 1 || tab[i][j + 1] == 1 || tab[i - 1][j] == 1 || tab[i][j - 1] == 1)
                    {
                        tab[i][j] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                if(tab[i][j] == 0)
                {
                    if(tab[i+1][j] == 2 || tab[i][j + 1] == 2 || tab[i - 1][j] == 2 || tab[i][j - 1] == 2)
                    {
                        tab[i][j] = 3;
                    }
                }
            }
        }
    }
}

void color(int tab[50][50])
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            switch(tab[i][j])
            {
                case 0:
                    SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
                    cout << "   ";
                    break;
                case 1:
                    SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                    cout << "   ";
                    break;
                case 2:
                    SetConsoleTextAttribute(hOut,  BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    cout << "   ";
                    break;
                case 3:
                    SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                    cout << "   ";
                    break;
                default:
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED);
                    cout << "E  ";
                    break;
            }
        }
        SetConsoleTextAttribute(hOut, 7);
        cout << "\n";
    }
}

int main()
{
    int world[50][50];

    gland(world);
    color(world);

    system("pause");
    return 0;
}
