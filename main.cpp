#include<iostream>
#include "chessGame.h"

using namespace std;

int main()
{
    chessGame obj; //creating an object for the class ChessGame
    obj.declare();
    obj.display(); //display the initial board;

    while(true)
    {
        //displaying the separator(border) for differentiating each move
        std::cout<<endl;
        for(int i=0;i<14;i++)
            std::cout<<"--------";
        std::cout<<endl;

        obj.check_draw(); // draw if fifty moves completed

        obj.getmoves(); //getting input for the move and performing it

        //if a move has happened, then display the board
        if(obj.flag)
        {
            obj.display();
            if(obj.move_flag)
            {
                //checking CHECKMATE condition for white king
                if(obj.blackcheck())
                {
                    obj.changeColor(11);
                    cout<<"\n\n\t\t\t     CHECKMATE";obj.changeColor(7);
                    cout<<" for ";obj.changeColor(14);
                    cout<<"White King";
                    obj.changeColor(7);

                    obj.changeColor(12);
                    cout<<"\n\n\t\t\t Black player";obj.changeColor(7);
                    cout<<" has ";obj.changeColor(11);
                    cout<<"WON the game";
                    obj.changeColor(7);cout<<" !!\n\n";

                    //function to ask user if they want to play again
                    obj.play_again();

                }
                //'CHECK' condition for black king
                if(obj.whitecheck())
                {
                    obj.changeColor(11);
                    cout<<"\n\t\t\t    Check ";obj.changeColor(7);
                    cout<<"for ";obj.changeColor(12);
                    cout<<"Black King";
                    obj.changeColor(7);cout<<" !!\n";
                }
            }
            else
            {
                 //checking CHECKMATE condition for black king
                if(obj.whitecheck())
                {
                    obj.changeColor(11);
                    cout<<"\n\n\t\t\t     CHECKMATE";obj.changeColor(7);
                    cout<<" for ";obj.changeColor(12);
                    cout<<"Black King";
                    obj.changeColor(7);

                    obj.changeColor(14);
                    cout<<"\n\n\t\t\t White player";obj.changeColor(7);
                    cout<<" has ";obj.changeColor(11);
                    cout<<"WON the game";
                    obj.changeColor(7);cout<<" !!\n\n";

                    obj.play_again();
                }
                //'CHECK' condition for white king
                else if(obj.blackcheck())
                {
                    obj.changeColor(11);
                    cout<<"\n\t\t\t    Check ";obj.changeColor(7);
                    cout<<"for ";obj.changeColor(14);
                    cout<<"White King";
                    obj.changeColor(7);cout<<" !!\n";
                }
            }
        }
    }
    return 0;
}