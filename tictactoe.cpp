#include <iostream> 
#include <stdio.h>
#include "tictactoe.h"
#include <stack>
using namespace std;

TicTacToe::TicTacToe()
{
    this->board = new char*[3];
    this->moves = new int[9];
    for(auto i=0;i<3;i++){
        board[i] = new char[3];
    }
    this->player_one = 'X';
    this->player_two = 'O';
    this->countnum = 0;
    int x = 0;
    for(auto i=0;i<3;i++){
        for(auto j=0;j<3;j++){
            this->board[i][j] = this->square[x];
            x++;
        }
   
}
}
TicTacToe::~TicTacToe()
{
    for(auto i = 2 ; i >= 0; i--)  
        delete[] board[i]; 
 
    delete[] board; 
    
}
char TicTacToe::getPlayerone()
{
    return this->player_one;

}
char TicTacToe::getPlayertwo()
{
    return this->player_two;

}
char** TicTacToe::getBoard()
{
    return this->board;

}
void TicTacToe::setboard(int i,int j,char p){
    this->board[i][j] = p;
    
}
char TicTacToe::checkWin(char pt)
{
    stack<char> vertstack;
    stack<char> horzstack;
    stack<char> diag1stack;
    stack<char> diag2stack;
    
    for(auto i=0;i<3;i++){
        /* diagonal durum*/
        diag1stack.push(board[i][i]);
        diag2stack.push(board[2-i][i]);
        for(auto j=0;j<3;j++){
            /* vertical durum*/
            vertstack.push(board[j][i]);
            /* horizontal durum*/
            horzstack.push(board[i][j]);
       }
    }
    if(checkStack(vertstack,pt) == 1 || checkStack(horzstack,pt) == 1 ||
      checkStack(diag1stack,pt) == 1 || checkStack(diag2stack,pt) == 1 ){
        return pt;
      }
    else return '\0';
}
char TicTacToe::checkTie()
{
    if (this->checkWin(this->getPlayerone()) == this->getPlayerone()){
        return this->getPlayerone();
    }
    else if (this->checkWin(this->getPlayertwo()) == this->getPlayertwo()){
        return this->getPlayertwo();
    }
    else
        return 'T';
}
int TicTacToe::checkStack(stack <char> &stack,char pt){
    int counter;
    int gameWinner = 0;
    while(!stack.empty()){
        counter = 0;
        for(auto i=0;i<3;i++){
            if(stack.top() == pt){
                counter++;
            }
            stack.pop();
        }
        if(counter == 3){
            gameWinner++;
            break;
        }
        
    }
    if(gameWinner == 0)
        return 0;
    else
        return 1;

}
void TicTacToe::printBoard(){
    system("clear");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << this->board[0][0] << "  |  " << this->board[0][1] << "  |  " << this->board[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << this->board[1][0] << "  |  " << this->board[1][1] << "  |  " << this->board[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << this->board[2][0] << "  |  " << this->board[2][1] << "  |  " << this->board[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}


int TicTacToe::startGame(){
    system("clear");
    this->printBoard();
    if((this->countnum % 2) ==  0){
        this->playerTurn(this->getPlayerone());
    }
    else{
        this->playerTurn(this->getPlayertwo());
        }
    if(this->countnum>3){
        if(checkWin(this->getPlayerone()) == this->getPlayerone()){
            system("clear");
            this->printBoard();
            cout<<"Congratulations!Player with 'X' has won the game";
                return 1;
            }
        else if(checkWin(this->getPlayertwo()) == this->getPlayertwo()){
            system("clear");
            this->printBoard();
            cout<<"Congratulations!Player with 'O' has won the game";
                return 1;
            }
        if(this->countnum == 8){
            if(this->checkTie() == 'T'){
            system("clear");
            this->printBoard();
            cout<<"GAME DRAW!!!";
            for(auto i=0;i<9;i++){
                cout<<this->moves[i] <<" - ";

            }
            return 1;
            } 
        }
    }
    
    this->countnum++;
    this->startGame();
    }

void TicTacToe::playerTurn(char player){
    int choice;
    if(player == 'X'){
        cout<<"ntPlayer - 1 [X] turn : ";
    }
    else if(player == 'O'){
        cout<<"ntPlayer - 2 [O] turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start
    cin>> choice;
    this->moves[this->countnum] = choice;
    switch(choice){
        case 1: this->setboard(0,0,player); break;
        case 2: this->setboard(0,1,player); break;
        case 3: this->setboard(0,2,player); break;
        case 4: this->setboard(1,0,player); break;
        case 5: this->setboard(1,1,player); break;
        case 6: this->setboard(1,2,player); break;
        case 7: this->setboard(2,0,player); break;
        case 8: this->setboard(2,1,player); break;
        case 9: this->setboard(2,2,player); break;
        default:
            cout<<"Invalid Move";
    }
}
