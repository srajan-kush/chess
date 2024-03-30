#include "chessBoard.h"

class pown:virtual public ChessBoard{
    public:
    void pawn_promotion_choice(){
        cout<<"\n Pawn ";changeColor(7);
        cout<<"promotion\n\n Promote pawn to ?\n 1-> Queen\n 2-> Rook";
        cout<<"\n 3-> Bishop\n 4-> Knight";
        cout<<"\n Enter your choice : ";

        //to get integer input for the promotion choice
        while(!(cin>>promote_choice) || (promote_choice!=1 &&
            promote_choice!=2 && promote_choice!=3 && promote_choice!=4)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\n\t\t\t  Please enter a ";changeColor(11);
            cout<<"valid ";changeColor(7);cout<<"choice !!";
            cout<<"\n\n Enter your choice correctly : ";
        }
    }

    void pawnpromotion(){
        switch(promote_choice)
        {
            //pawn to queen
            case 1:
                board[move_row][move_col] = "queen";
                cout<<"queen\n";
                break;
            //pawn to rook
            case 2:
                board[move_row][move_col] = "rook";
                cout<<"rook\n";
                break;
            //pawn to bishop
            case 3:
                board[move_row][move_col] = "bishop";
                cout<<"bishop\n";
                break;
            //pawn to knight
            case 4:
                board[move_row][move_col] = "knight";
                cout<<"knight\n";
                break;
        }
        changeColor(7);
    }   

};