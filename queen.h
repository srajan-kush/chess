#include "rook.h"
#include "bishop.h"

class queen :virtual public bishop,virtual public rook{
public:
    void queen_move(){
        //if (current row and move row) or (current col and move col) are same, then
            if((current_row == move_row || current_col == move_col)&&
               BW[move_row][move_col]!=2) //moving location must not have a white piece
            {
                blackenpassant[prev_black_col]=false;
                //if queen's move location is similar to rook's move,then
                //do rook move for queen
                rookmove();
            }
            else if(current_row!= move_row && current_col!=move_col &&
                BW[move_row][move_col]!=2)
            {
                blackenpassant[prev_black_col]=false;
                //if queen's move location is similar to bishop's move,then
                //do bishop move for queen
                bishopmove();
            }
            else
            {
                notvalid_display();
            }
    }
};

