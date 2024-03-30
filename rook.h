#include "chessBoard.h"

class rook : virtual public ChessBoard{
    public:
    void rookmove() //function to move a rook
    {
        int k;
        bool rookflag=true; //to indicate if rook can move or not
        if(current_row == move_row)
        {
            if(current_col<move_col)
            {
                //traversing to check if there are any obstacles
                //(white or black pieces) in moving path
                for(k=current_col+1;k<move_col && rookflag;k++)
                {
                    //if there are pieces, then set rookflag to false
                    if(BW[current_row][k]==2 || BW[current_row][k]==1)
                    {
                        rookflag=false;
                    }
                }
                //else, move the rook
                if(rookflag)
                {
                    moves();
                }
            }
            else //current column is greater than move column
            {
                rookflag=true;
                for(k=current_col-1;k>move_col && rookflag;k--)
                {
                    if(BW[current_row][k]==2 || BW[current_row][k]==1)
                    {
                        rookflag=false;
                    }
                }
                if(rookflag)
                {
                    moves();
                }
            }
        }
        else if(current_col == move_col)
        {
            if(current_row<move_row)
            {
                for(k=current_row+1;k<move_row && rookflag;k++)
                {
                    if(BW[k][current_col]==2 || BW[k][current_col]==1)
                    {
                        rookflag=false;
                    }
                }
                if(rookflag)
                {
                    moves();
                }
            }
            else //current row is greater than move row
            {
                rookflag=true;
                for(k=current_row-1;k>move_row && rookflag;k--)
                {
                    if(BW[k][current_col]==2 || BW[k][current_col]==1)
                    {
                        rookflag=false;
                    }
                }
                if(rookflag)
                {
                    moves();
                }
            }
        }
        if(!rookflag)
        {
            notvalid_display();
        }
    }
};