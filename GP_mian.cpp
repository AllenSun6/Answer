#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define SPADE   "\xE2\x99\xA0"  // define four different suits
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"


void SendCard(int cards[], int cardsAI1[], int cardsAI2[], int cardsAI3[], int judge[], int order)
{   
    srand((unsigned)time(NULL));
    int x = rand()%100000;
    srand((unsigned)x);
    cards[order] =rand()%36;
    if (judge[1] == 1)
    {
        cardsAI1[order] =rand()%36;
    }
    if (judge[2] == 1)
    {
        cardsAI2[order] =rand()%36;
    }
    if (judge[3] == 1)
    {
        cardsAI3[order] =rand()%36;
    }
}

void PrintCard(int cards[], int order, string suits[])
{
    int index = 0;
    cout << "YOUR CARD: ";
    for (index = 0; index < order+1; index++)
    {
        cout << cards[index] % 9 + 1 << suits[cards[index] / 9] << " ";
    }
    cout << endl;
}

bool IfEnd__JudgeGame(int cards[], int cardsAI1[], int cardsAI2[], int cardsAI3[], int judge[], int order, bool ifend)
{
    int total1 = 0, total2 = 0, total3 = 0, total4 = 0;
    int elimination = 0;
    for (int p = 0; p <= order; p++)
    {
        total1 += cards[p] % 9 + 1;
        total2 += cardsAI1[p] % 9 + 1;
        total3 += cardsAI2[p] % 9 + 1;
        total4 += cardsAI3[p] % 9 + 1;
    }
    if (total1 > 21)
    {
        ifend = 0;
        return ifend;
    }
    for (int i = 1; i < 4; i++)
    {
        if (total2 > 21 || total3 > 21 || total4 > 21)
        {
            elimination += 1;
            if (total2 > 21)
            {
                judge[1] = 0;
            }
            if (total3 > 21)
            {
                judge[2] = 0;
            }
            if (total4 > 21)
            {
                judge[3] = 0;
            }
        }
    }
    if (elimination >= 3)
    {
        ifend = 0;
        return ifend;
    }
    else
    {
        ifend = 1;
        return ifend;
    }
    
}

void ShowEndCard(int cards[], int cardsAI1[], int cardsAI2[], int cardsAI3[], int order, string suits[], int rank[])
{
    int total1 = 0, total2 = 0, total3 = 0, total4 = 0;
    cout << "YOUR FINAL CARD: ";
    for (int index = 0; index < order; index++)
    {
        total1 += (cards[index] % 9) + 1;
        cout << cards[index] % 9 + 1 << suits[cards[index] / 9] << " ";
    }
    rank[0] = total1;
    cout << "    " << "TOTAL POINTS = " << total1 << endl;
    cout << "FINAL CARD OF PLAYER" << 2 << ": ";
    for (int index = 0; index < order; index++)
    {
        total2 += (cardsAI1[index] % 9) + 1;
        cout << cardsAI1[index] % 9 + 1 << suits[cardsAI1[index] / 9] << " ";
    }
    rank[1] = total2;
    cout << "    " << "TOTAL POINTS = " << total2 << endl;
    cout << "FINAL CARD OF PLAYER" << 3 << ": ";
    for (int index = 0; index < order; index++)
    {
        total3 += (cardsAI2[index] % 9) + 1;
        cout << cardsAI2[index] % 9 + 1 << suits[cardsAI2[index] / 9] << " ";
    }
    rank[2] = total3;
    cout << "    " << "TOTAL POINTS = " << total3 << endl;
    cout << "FINAL CARD OF PLAYER" << 4 << ": ";
    for (int index = 0; index < order; index++)
    {
        total4 += (cardsAI3[index] % 9) + 1;
        cout << cardsAI3[index] % 9 + 1 << suits[cardsAI3[index] / 9] << " ";
    }
    rank[3] = total4;
    cout << "    " << "TOTAL POINTS = " << total4 << endl;

    
}

void RankCard(int points[])
{
    int NO = 1;
    for (int k = 1; k < 4; k++)
    {
        if ((points[0] < points[k] && points[k] < 22) || (points[0] > points[k] && points[0] > 21))
        {
            NO += 1;
        }
    }
    cout << endl <<  "You ranked No." << NO << " !!!";
}

int Settingdifficulty(int n)
{
    if (n == 1)
    {
        cout << "The current difficulty is: SIMPLE" << endl;
    }
    if (n == 2)
    {
        cout << "The current difficulty is: NORMAL" << endl;
    }
    if (n == 3)
    {
        cout << "The currebt difficulty is: HARD" << endl;
    }
    char a;
    cout << "Please choose difficulty(S, N or H): ";
    cin >> a;
    while (a != 'S' && a != 'H' && a != 'N')
    {
        cout << "Invalid selection, please try again: ";
        cin >> a;
    }
    if (a == 'S')
    {
        return 1;
    }
    if (a == 'N')
    {
        return 2;
    }
    if (a == 'H')
    {
        return 3;
    }
}

void Operation1()
{
    
}

int main()
{
    cout << "Welcome to BlackJack2.0" << endl;
    cout << "----------CATALOGUE----------" << endl << "1:DIFFICULTY" << endl << "2:FILE READING" << endl << "3:STARTING NEW GAME" << endl;
    int cat, diff = 1;
    cout << "Your Choice: ";
    cin >> cat;
    while (cat != 3)
    {
        if (cat == 1)
        {
            diff = Settingdifficulty(diff);
        }
        cout << "----------CATALOGUE----------" << endl << "1:DIFFICULTY" << endl << "2:FILE READING" << endl << "3:STARTING NEW GAME" << endl;
        cout << "Your Choice: ";
        cin >> cat;
    }
    if (cat == 3)
    {
        cout << "Please select the maximum number of cards: ";
        int SIZE;
        cin >> SIZE;
        int *cards = new int[SIZE];
        int *cardsAI1 = new int[SIZE];
        int *cardsAI2 = new int[SIZE];
        int *cardsAI3 = new int[SIZE];
        string suits[4] = {SPADE, CLUB, HEART, DIAMOND};
        int round = 0, judge[4] = {1, 1, 1, 1}, number = 4, Y_N = 1, finalcount[4];
        char key;
        while (Y_N && round < SIZE)
        {
            cout << "ROUND " << round+1 << ":   " << "-------------------------------+----------------------------" << endl;
            SendCard(cards, cardsAI1, cardsAI2, cardsAI3, judge, round);
            PrintCard(cards, round, suits);
            Y_N = IfEnd__JudgeGame(cards, cardsAI1, cardsAI2, cardsAI3, judge, round, Y_N);
            round += 1;
            cout << "Continue Or Not (Y or N) : ";
            cin >> key;
            if (key == 'Y')
            {
                continue;
            }
            else
            {
                cout << "The Game Is Paused By Player...";
                break;
            }
        }
        cout << endl << "-------------------------+++++GAME OVER+++++---------------------------" << endl << endl;
        ShowEndCard(cards, cardsAI1, cardsAI2, cardsAI3, round, suits, finalcount);
        RankCard(finalcount);
        delete [] cards;
        delete [] cardsAI1;
        delete [] cardsAI2;
        delete [] cardsAI3;
        return 0;
    }
}
