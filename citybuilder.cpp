#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>


using namespace std;

void gland(int tab[20][20])
{
    srand(time(NULL));

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            tab[i][j] = 0;
        }
    }

    for(int o = 0; o < 3; o++)
    {
        int v1, v2;
        v1 = rand() % 20;
        v2 = rand() % 20;

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
                    if(random == 0 || random == 1 || random == 2 || random == 3 || random == 4 || random == 5 || random == 6 || random == 7)
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
    }
}

void color(int tab[20][20])
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            switch(tab[i][j])
            {
                case 0:
                    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
                    cout << "0  ";
                    break;
                case 1:
                    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
                    cout << "1  ";
                    break;
                default:
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED);
                    cout << "E  ";
                    break;
            }
        }
        cout << endl;
    }
}

int main()
{
    int world[20][20];

    gland(world);
    color(world);

    return 0;
}