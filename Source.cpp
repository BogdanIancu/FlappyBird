#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

int main()
{
    system("Color 5E");

    cout << "           _____ _                 _____ _       _ " << endl;
    cout << "          |   __| |___ ___ ___ _ _| __  |_|___ _| |" << endl;
    cout << "          |   __| | .'| . | . | | | __ -| |  _| . |" << endl;
    cout << "          |__|  |_|__,|  _|  _|_  |_____|_|_| |___|" << endl;
    cout << "                      |_| |_| |___|                " << endl;

    cout << endl << endl << endl;
    cout << "            Original version by Code Blocks Coding"<<endl;
    cout << "               Current version by Facem Soft";
    cout << endl << endl << endl;

    cout << "                   Press any key to start";

    getch();
    system("cls");

    srand(time(0));//to make the program randomize
    char mv;
    char repeat = 'y';
    int highscore = 0;
    while (repeat == 'y') {
        int score = 0;
        bool wasit = true;
        long startTime = time(0);
        int x = 9;
        int rintangan[3]; // the y-asis of obstacle
        int rintang[3]; // the x-asis of obstacle
        rintang[0] = 10;
        rintang[1] = 18;
        rintang[2] = 27; // the starting x-asis of obstacle
        for (int i = 0; i < 3; i++)
        {
            rintangan[i] = (rand() - 1) % 12 + 2;
        }
        string map[20][30];
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (i == 0 || i == 19 || j == 29 || j == 0)
                    map[i][j] = "* ";
                else
                    map[i][j] = "  ";
            }
        }
        while (wasit == true)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 1; j < 19; j++)
                {
                    map[j][rintang[i]] = "  ";
                }
            }
            for (int i = 0; i < 3; i++) //make the obstacle move from right to left
            {
                rintang[i]--;
            }
            for (int i = 0; i < 3; i++) //make the obstacle back to right side if it touched left side
            {
                for (int j = 1; j < 19; j++)
                {
                    map[j][rintang[i]] = "| ";
                }
            }
            for (int i = 0; i < 3; i++) //to make a hole at the obstacle
            {
                map[rintangan[i]][rintang[i]] = "  ";
                map[rintangan[i] + 1][rintang[i]] = "  ";
                map[rintangan[i] + 2][rintang[i]] = "  ";
                map[rintangan[i] + 3][rintang[i]] = "  ";
                map[rintangan[i] + 4][rintang[i]] = "  ";
            }
            for (int i = 0; i < 3; i++)
            {
                if (rintang[i] == 1)
                {
                    rintang[i] = 28;
                    rintangan[i] = (rand() - 1) % 12 + 2;
                }
            }
            map[x][3] = "  ";
            if (kbhit())
            {
                mv = getch();
                x = x - 3;
            }
            x++;
            if (x < 1)
                x = 1;
            for (int i = 0; i < 3; i++)
            {
                if (rintang[i] == 3)
                    if (map[x][3] == "  ")
                        score = score + 1;
                if (map[x][3] == "| ")
                    wasit = false;
            }
            map[x][3] = "o ";
            for (int i = 1; i < 19; i++)
            {
                map[i][1] = "  ";
            }
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    cout << map[i][j];
                }
                cout << endl;
            }
            cout << endl << endl;
            cout << "                          SCORE " << score;
            long currentTime = time(0);
            long seconds = currentTime - startTime;
            long interval = seconds / 20;
            Sleep(interval < 100 ? 100 - interval : 0);
            system("cls");
        }
        cout << "Score = " << score << endl;
        if (highscore < score)
            highscore = score;
        cout << "Highscore = " << highscore << endl;
        cout << "Retry? (y/n) = "; cin >> repeat;
    }
    return 0;
}