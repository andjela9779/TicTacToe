#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char square [10] = {'o','1','2','3','4','5','6','7','8','9'};
int choice,player;

int checkForWin();
void displayBoard();
void markBoard(char mark);


int main ()
{
    int gameStatus;
    char mark;
    player = 1;



    do
    {
        displayBoard();

        // calculate the player
        player = (player%2) ? 1 : 2;

        // getting input from the user

        printf("Player %d , enter a number : ",player);
        scanf("%d",&choice);

        // determine what is the mark based on the player

        mark = (player==1) ? 'X' : 'O';

        markBoard(mark);

        gameStatus = checkForWin();

        player++;


    }
    while (gameStatus==-1);  // if game status is -1 , we jump out of the loop

    if(gameStatus==1)
        printf("==>\aPlayer %d is the winner!Congrats!",--player);
    else
        printf("==>\aGame draw!");

    return 0;


}
/*****************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH A RESULT
-1 FOR GAME IS IN PROGRESS
0 FOR GAME IS OVER AND NO RESULT OR DRAW
*****************************************/

int checkForWin()
{
    int returnValue = 0;

    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;
    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;
    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;
    else if (square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}
/*******************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYER MARK
*******************************************************/
void displayBoard()
{
    system("cls"); // clears the screen

    printf("\n\nTic Tac Toe Game\n\n");
    printf("Player 1(X)    Player 2(O)\n\n");

    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n",square[1],square[2],square[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n",square[4],square[5],square[6]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n",square[7],square[8],square[9]);
    printf("    |    |    \n");
}

void markBoard(char mark)
{
    if ( choice==1 && square[1]=='1')
        square[1] = mark;
    else if ( choice==2 && square[2]=='2')
        square[2] = mark;
    else if ( choice==3 && square[3]=='3')
        square[3] = mark;
    else if ( choice==4 && square[4]=='4')
        square[4] = mark;
    else if ( choice==5 && square[5]=='5')
        square[5] = mark;
    else if ( choice==6 && square[6]=='6')
        square[6] = mark;
    else if ( choice==7 && square[7]=='7')
        square[7] = mark;
    else if ( choice==8 && square[8]=='8')
        square[8] = mark;
    else if ( choice==9 && square[9]=='9')
        square[9] = mark;
    else
        {printf("Invalid move");

        player--;
        getch();

}

}
