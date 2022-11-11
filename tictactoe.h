#include <iostream>
#include <stdio.h>
#include <stack>


class TicTacToe 
{
    /*
        The class construct a FIFO queue.
    */

private:
    char **board;
    char player_one;
    char player_two; 
    int countnum;   
    int *moves;
    char square[9] = {'1','2','3','4','5','6','7','8','9'};
public:
    TicTacToe();
    ~TicTacToe();
    char getPlayerone();
    char getPlayertwo();
    char** getBoard();
    void setboard(int,int,char);
    char checkTie();
    char checkWin(char);
    int checkStack(std::stack<char>&,char);
    int startGame();
    void printBoard();
    void playerTurn(char);

};