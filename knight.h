#include "chessBoard.h"
   
class knight :virtual public ChessBoard{
public:
    void knightmove(){
        // 7'o clock location from knight

        if(current_row==move_row-2 && current_col==move_col+1)
        {
            moves();
        }
        // 8'o clock location from knight
        else if(current_row==move_row-1 && current_col==move_col+2)
        {
            moves();
        }
        // 10'o clock location from knight
        else if(current_row==move_row+1 && current_col==move_col+2)
        {
            moves();
        }
        // 11'o clock location from knight
        else if(current_row==move_row+2 && current_col==move_col+1)
        {
            moves();
        }
        // 1'o clock location from knight
        else if(current_row==move_row+2 && current_col==move_col-1)
        {
            cout<<"Inside where you want"<<endl;
            moves();
        }
        // 2'o clock location from knight
        else if(current_row==move_row+1 && current_col==move_col-2)
        {
            moves();
        }
        //4'o clock location from knight
        else if(current_row==move_row-1 && current_col==move_col-2)
        {
            moves();
        }
        //5'o clock locatoin from knight
        else if(current_row==move_row-2 && current_col==move_col-1)
        {
            moves();
        }
        else
        {
            notvalid_display();
        }
    }
};