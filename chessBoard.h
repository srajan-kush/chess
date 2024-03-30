#include<cstring> //header to use memset function
#include<iomanip>
#include<string>
#include<windows.h> //header to change text color of the OP text
#include<limits> 
#include<random>
#include<iostream>
using namespace std;
#define N 8

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard{
    protected:
    int i, j,k,movecount=1, prev_white_col,prev_black_col;
    int prev_curr_row, prev_curr_col,curr_piece_value,  move_piece_value;

    std::string curr_piece, move_piece;
    std::string board[N][N];

    int BW[N][N] , whitepawn_moves[N],blackpawn_moves[N] ;
    int whiterook[N], blackrook[N];
    int current_row, current_col,move_row,move_col, promote_choice;
    bool blackenpassant[N], whiteenpassant[N];

    public:
    bool flag=true;
    int move_flag, whiteking=0, blackking=0;

    void changeColor(int desiredColor)
    {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
    }

    void moves(){
    //if a piece captures other piece
      if(BW[current_row][current_col] + BW[move_row][move_col] == 3){
          //if black captures white
          if(BW[current_row][current_col]==1)
          {
              changeColor(12);
              cout<<"\n\t\t\t Black "<<board[current_row][current_col];changeColor(7);
              cout<<" captured ";changeColor(14);
              cout<<"White "<<board[move_row][move_col];
              changeColor(7);
          }
          else //if white captures black
          {
              changeColor(14);
              cout<<"\n\t\t\t White "<<board[current_row][current_col];changeColor(7);
              cout<<" captured ";changeColor(12);
              cout<<"Black "<<board[move_row][move_col];
              changeColor(7);
          }
          cout<<endl;
      }
      cout<<"\n ";
      board[move_row][move_col] = board[current_row][current_col];

      if(BW[current_row][current_col] == 2) //if current piece is white
          BW[move_row][move_col] = 2;
      else                                  //if current piece is black
          BW[move_row][move_col] = 1;

      board[current_row][current_col] = '\0';
      BW[current_row][current_col] = 0;   //setting the current location to zero
      movecount++;       //increment the total number of moves
      flag=true;         //a move has happened successfully
    }

    void declare()
    {
        flag=true;
        move_flag, whiteking=0, blackking=0,movecount=1;
    
        memset(whitepawn_moves,0,sizeof(whitepawn_moves));
        memset(blackpawn_moves,0,sizeof(blackpawn_moves));
        memset(whiterook,0,sizeof(whiterook));
        memset(blackrook,0,sizeof(blackrook));
    
        memset(BW,0,sizeof(BW));
        memset(board,'\0',64);
    
        memset(blackenpassant,false,sizeof(blackrook));
        memset(whiteenpassant,false,sizeof(blackrook));
    
        //declaring black pawn
        for(i=1,j=0;j<8;j++)
        {
            board[i][j] = "pawn";
            BW[i][j] = 1;     //1 for black
        }
    
        //declaring white pawn
        for(i=6,j=0;j<8;j++)
        {
            board[i][j] = "pawn";
            BW[i][j] = 2;     //2 for white
        }
    
        //DECLARING BLACK COINS
    
        //black rooks
        board[0][0] = "rook";
        BW[0][0] = 1;
        board[0][7] = "rook";
        BW[0][7] = 1;
    
        //black horses
        board[0][1] = "knight";
        BW[0][1] = 1;
        board[0][6] = "knight";
        BW[0][6] = 1;
    
        //black bishops
        board[0][2] = "bishop";
        BW[0][2] = 1;
        board[0][5] = "bishop";
        BW[0][5] = 1;
    
        //black king and queen
        board[0][3] = "queen";
        BW[0][3] = 1;
        board[0][4] = "king";
        BW[0][4] = 1;
    
    
        //DECLARING WHITE COINS
    
        //white rooks
        board[7][0] = "rook";
        BW[7][0] = 2;
        board[7][7] = "rook";
        BW[7][7] = 2;
    
        //white horses
        board[7][1] = "knight";
        BW[7][1] = 2;
        board[7][6] = "knight";
        BW[7][6] = 2;
    
        //white bishops
        board[7][2] = "bishop";
        BW[7][2] = 2;
        board[7][5] = "bishop";
        BW[7][5] = 2;
    
        //white king and queen
        board[7][3] = "queen";
        BW[7][3] = 2;
        board[7][4] = "king";
        BW[7][4] = 2;
    
    }
    void notvalid_display(){
        changeColor(11);
        cout<<"\n\t\t PLEASE ENTER A VALID MOVE !! \n\n";
        changeColor(7);
        flag=false;
    }
};

#endif