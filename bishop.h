#include "chessBoard.h"

class bishop:virtual public ChessBoard{
    public:
    void bishopmove()
    {
         int p=current_row, q=current_col;
         bool bishopflag=false, obstacleflag=false;

         //left top move condition for bishop
         if(current_row>move_row && current_col>move_col)
         {
             //traverse to left top from the current bishop location
             for(p=p-1,q=q-1;p>=0 && q>=0 && !bishopflag &&!obstacleflag;p--,q--)
             {
                 //while traversing, if the location to be moved is found, then
                 //set bishopflag to true
                 if(p==move_row && q==move_col)
                 {
                     bishopflag=true;
                 }

                 //while traversing, if there are any obstacles(pieces) found,
                 //then set obstacleflag to true
                 else if(BW[p][q]==1 || BW[p][q]==2)
                 {
                     obstacleflag=true;
                 }
             }
             //if location is found AND there are no obstacles,
             //then move the bishop
             if(bishopflag && !obstacleflag)
             {
                 moves();
             }
             else
             {
                 notvalid_display();
             }
         }
          //right top move condition for bishop
         if(current_row>move_row && current_col<move_col)
         {
             //traverse to right top from the current bishop location
             for(p=p-1,q=q+1;p>=0 && q<=7 && !bishopflag &&!obstacleflag;p--,q++)
             {
                 if(p==move_row && q==move_col)
                 {
                     bishopflag=true;
                 }
                 else if(BW[p][q]==1 || BW[p][q]==2)
                 {
                     obstacleflag=true;
                 }
             }
             if(bishopflag && !obstacleflag)
             {
                 moves();
             }
             else
             {
                 notvalid_display();
             }
         }

         //right bottom move condition for bishop
         if(current_row<move_row && current_col<move_col)
         {
             //traverse to right bottom from the current bishop location
             for(p=p+1,q=q+1;p<=7 && q<=7 && !bishopflag &&!obstacleflag;p++,q++)
             {
                 if(p==move_row && q==move_col)
                 {
                     bishopflag=true;
                 }
                 else if(BW[p][q]==1 || BW[p][q]==2)
                 {
                     obstacleflag=true;
                 }
             }
             if(bishopflag && !obstacleflag)
             {
                 moves();
             }
             else
             {
                 notvalid_display();
             }
         }

         //left bottom move condition for bishop
         if(current_row<move_row && current_col>move_col)
         {
             //traverse to left bottom from the current bishop location
             for(p=p+1,q=q-1;p<=7 && q>=0 && !bishopflag &&!obstacleflag;p++,q--)
             {
                 if(p==move_row && q==move_col)
                 {
                     bishopflag=true;
                 }
                 else if(BW[p][q]==1 || BW[p][q]==2)
                 {
                     obstacleflag=true;
                 }
             }
             if(bishopflag && !obstacleflag)
             {
                 moves();
             }
             else
             {
                 notvalid_display();
             }
         }

    }

};

