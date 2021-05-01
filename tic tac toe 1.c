#include<bits/stdc++.h>

using namespace std;
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>

int board[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,comp;
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
FILE *fp;

void menu();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch,int pos);

int checkwin();
void playr();
void bord();
COORD coord= {0,0}; // this is global variable
//center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void main()
{
    int choice,x=9,y=2;
    fp = fopen("text.txt","w");
    fprintf(fp,"The result of the game Tic Tac Toe\n");
    printf("\t\t   *************************");
    printf("\n\t\t   ****** Tic Tac Toe ******\t\t\n");
    printf("\t\t   *************************");
    printf("\n   Starting the Game....\n");
    printf("\n\t1 : Play with Player");
    printf("\n\t2 : Play with Computer");
    printf("\n\t3 : Exit");
    printf("\n\tEnter your choice:> ");
    while(1)
    {


        scanf("%d",&choice);
        if(choice == 3)
        {
            break;
        }
        switch(choice)
        {
        case 1:
            gotoxy(x,y);
            printf("\n       --------About--------");
            printf("\n\n\tPlayer 1(x) means X for player 1   ");
            printf("\n\t\t\t\t\t\t\t\t");
            printf("\n\tPlayer 2(o) means O for player 2   ");
            printf("\n\t\t\t\t\t\t\t\t");
            playr();
            break;
        case 2:
            gotoxy(x,y);
            menu();
            break;
        case 3:
        {
            gotoxy(22,y);
            for(int l=0; l<13; l++)
            {
                for(int j=0; j<=6; j++)
                {
                    printf("\t");
                }
                printf("\n");
                gotoxy(22,y++);
            }
            exit(0);
        }
        }
        getch();
    }

}

void menu()
{
    int choice;
    printf("\n       --------MENU--------");
    printf("\n\n\tI : Play with X       ");
    printf("\n\tII : Play with O      ");
    printf("\n\tIII : Exit");
    printf("\n\tEnter your choice:> ");
    scanf("%d",&choice);
    turn = 1;
    switch (choice)
    {
    case 1:
    {
        player = 1;
        comp = 0;
        player_first();
        break;
    }
    case 2:
    {
        player = 0;
        comp = 1;
        start_game();
        break;
    }
    case 3:
        exit(1);

    }
}

int make2()
{
    if(board[5] == 2)
        return 5;
    if(board[2] == 2)
        return 2;
    if(board[4] == 2)
        return 4;
    if(board[6] == 2)
        return 6;
    if(board[8] == 2)
        return 8;
    return 0;
}

int make4()
{
    if(board[1] == 2)
        return 1;
    if(board[3] == 2)
        return 3;
    if(board[7] == 2)
        return 7;
    if(board[9] == 2)
        return 9;
    return 0;
}

int posswin(int p)
{
// p==1 then X   p==0  then  O
    int i;
    int check_val,pos;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)//row check
    {

        if(board[i] * board[i+1] * board[i+2] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+1] == 2)
                return i+1;
            if(board[i+2] == 2)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(board[i] * board[i+3] * board[i+6] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+3] == 2)
                return i+3;
            if(board[i+6] == 2)
                return i+6;
        }
        i++;
    }

    if(board[1] * board[5] * board[9] == check_val)
    {
        if(board[1] == 2)
            return 1;
        if(board[5] == 2)
            return 5;
        if(board[9] == 2)
            return 9;
    }

    if(board[3] * board[5] * board[7] == check_val)
    {
        if(board[3] == 2)
            return 3;
        if(board[5] == 2)
            return 5;
        if(board[7] == 2)
            return 7;
    }
    return 0;
}

void go(int n)
{
    if(turn % 2)
        board[n] = 3;
    else
        board[n] = 5;
    turn++;
}

void player_first()
{
    int pos,i,j,y=9;

    gotoxy(22,9);
    for(int l=0; l<18; l++)
    {
        for(int j=0; j<=8; j++)
        {
            printf("\t");
        }
        printf("\n");
    }

    check_draw();
    draw_board();
    gotoxy(30,18);
    printf("Your Turn :> ");
    scanf("%d",&pos);

    if(board[pos] != 2)
        player_first();

    if(pos == posswin(player))
    {
        go(pos);
        draw_board();
        gotoxy(30,22);
        printf("****** Player Wins ******\n");
        fp = fopen("text.txt","a");
        fprintf(fp,"Player Wins\n");
        gotoxy(9,2);
        printf("\n       --------MENU--------");
        printf("\n\n\t1 : Play with Player\t\t");
        printf("\n\t2 : Play with Computer\t\t");
        printf("\n\t3 : Exit\t\t\t\t\t");
        printf("\n\tEnter your choice:> ");


        gotoxy(22,y);
        for(int l=0; l<13; l++)
        {
            for(int j=0; j<=6; j++)
            {
                printf("\t");
            }
            printf("\n");
            gotoxy(22,y++);
        }
        gotoxy(28,8);
        getch();
        //exit(0);
    }

    go(pos);
    draw_board();
    start_game();
}

void start_game()
{
// p==1 then X   p==0  then  O
    int y=9;
    if(posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if(posswin(player))
        go(posswin(player));
    else if(make2())
        go(make2());
    else
        go(make4());
    draw_board();

    if(flag)
    {
        gotoxy(30,22);
        printf("****** Computer wins ******\n");
        fp = fopen("text.txt","a");
        fprintf(fp,"Computer wins\n");
        gotoxy(9,2);
        printf("\n       --------MENU--------");
        printf("\n\n\t1 : Play with Player\t\t");
        printf("\n\t2 : Play with Computer\t\t");
        printf("\n\t3 : Exit\t\t\t\t\t");
        printf("\n\tEnter your choice:> ");

        gotoxy(22,y);
        for(int l=0; l<13; l++)
        {
            for(int j=0; j<=6; j++)
            {
                printf("\t");
            }
            printf("\n");
            gotoxy(22,y++);
        }
        gotoxy(28,8);
        getch();

        // exit(0);
    }
    else
        player_first();
}

void check_draw()
{
    if(turn > 9)
    {
        gotoxy(30,22);
        printf("~~~ Game Draw ~~~\n");
        fp = fopen("text.txt","a");
        fprintf(fp,"Game Draw\n");
        gotoxy(9,2);
        printf("\n       --------MENU--------");
        printf("\n\n\t1 : Play with Player\t\t");
        printf("\n\t2 : Play with Computer\t\t");
        printf("\n\t3 : Exit\t\t\t\t\t");
        printf("\n\tEnter your choice:> ");

        int y=9;
        gotoxy(22,y);
        for(int l=0; l<13; l++)
        {
            for(int j=0; j<=6; j++)
            {
                printf("\t");
            }
            printf("\n");
            gotoxy(22,y++);
        }
        gotoxy(28,8);
        getch();
    }
}

void draw_board()
{
    int j;

    for(j=9; j<17; j++)
    {
        gotoxy(35,j);
        printf("|       |");
    }
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1; j<10; j++)
    {
        if(board[j] == 3)
            put_X_O('X',j);
        else if(board[j] == 5)
            put_X_O('O',j);
    }
}

void put_X_O(char ch,int pos)
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }
    gotoxy(x,y);
    printf("%c",ch);
}


void playr()
{
    int player = 1, i, choice;
    char mark;
    do
    {

        bord();
        player = (player % 2) ? 1 : 2;
        gotoxy(18,22);
        printf("Player %d, enter a number:  \t", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }
    while (i ==  - 1);

    bord();

    if (i == 1)
    {
        gotoxy(18,22);
        printf("\t\t****** \aPlayer %d win ******   ", --player);
        fp = fopen("text.txt","a");
        fprintf(fp,"Player %d win", --player);
        gotoxy(22,9);
        for(int l=0; l<13; l++)
        {
            for(int j=0; j<=6; j++)
            {
                printf("\t");
            }
            printf("\n");
        }
        gotoxy(9,2);
        printf("\n       --------MENU--------");
        printf("\n\n\t1 : Play with Player\t\t");
        printf("\n\t2 : Play with Computer\t\t");
        printf("\n\t3 : Exit\t\t\t\t\t");
        printf("\n\tEnter your choice:> ");


    }
    else
    {
        gotoxy(18,22);
        printf("****** \aGame draw ******   ");
        fp = fopen("text.txt","a");
        fprintf(fp,"Game draw");
        gotoxy(22,9);
        for(int l=0; l<13; l++)
        {
            for(int j=0; j<=6; j++)
            {
                printf("\t");
            }
            printf("\n");
        }
        gotoxy(9,2);
        printf("\n       --------MENU--------");
        printf("\n\t1 : Play with Player\t\t");
        printf("\n\t2 : Play with Computer\t\t");
        printf("\n\t3 : Exit\t");
        printf("\n\tEnter your choice:> ");

    }
    getch();

}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
             != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}

void bord()
{
    //system("cls");
    gotoxy(18,10);
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    gotoxy(22,12);
    printf("     |     |     \n");
    gotoxy(22,13);
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    gotoxy(22,14);
    printf("_____|_____|_____\n");
    gotoxy(22,15);
    printf("     |     |     \n");
    gotoxy(22,16);
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    gotoxy(22,17);
    printf("_____|_____|_____\n");
    gotoxy(22,18);
    printf("     |     |     \n");
    gotoxy(22,19);
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    gotoxy(22,20);
    printf("     |     |     \n\n");
}
