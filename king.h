#include "chessBoard.h"

class king :virtual public ChessBoard{
public:
    void kingmove(){
        bool moved=true; //to indicate if king has moved or not
        //moving left or right one step
        if(current_row==move_row &&
           (current_col==move_col+1 || current_col==move_col-1))
        {
            moves();
        }
        //moving up or down one step
        else if(current_col==move_col &&
                (current_row==move_row+1 || current_row==move_row-1))
        {
            moves();
        }
        //moving left top one step
        else if(current_row==move_row+1 && current_col==move_col+1)
        {
            moves();
        }
        //moving right top one step
        else if(current_row==move_row+1 && current_col==move_col-1)
        {
            moves();
        }
        //moving right bottom one step
        else if(current_row==move_row-1 && current_col==move_col-1)
        {
            moves();
        }
        //moving left bottom one step
        else if(current_row==move_row-1 && current_col==move_col+1)
        {
            moves();
        }
        else
        {
            moved=false; //if king has not moved
            notvalid_display();
        }
        if(moved)
        {
        //Increment the value for the moved king. Since by calling
        //moves() function above,the movecount value increases
        //by 1,hence change the below if condition
            if(move_flag==1)
                whiteking++;
            else
                blackking++;
        }
    }
};

