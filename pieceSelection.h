#include "queen.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"

using namespace std;

class pieceSelection : virtual public king ,virtual public knight , 
virtual public pown ,virtual public queen {
    public:
    void white_move()
    {
        //WHITE PAWN

        if(board[current_row][current_col] == "pawn" &&
            BW[current_row][current_col] == 2)
        {
            if(move_row >= current_row)
            {
                notvalid_display();
            }
            //checking if the moving location is not having a white piece
            else if(BW[move_row][move_col] !=2)
            {
                if(current_row == 6)
                {
                    blackenpassant[prev_black_col]=false;
                    if(whitepawn_moves[current_col]==0) //if first move of a pawn
                    {
                        //a pawn can move 1 or 2 steps forward in first move
                        if((current_row - move_row ==1 || current_row - move_row==2)&&
                           current_col == move_col && BW[move_row][move_col]!=1 &&
                            BW[current_row-1][current_col]==0)
                        {
                            if(current_row-move_row==2) //to make whiteenpasant true
                            {
                                prev_white_col=current_col;
                                whiteenpassant[current_col]=true;
                            }
                            whitepawn_moves[current_col]++;
                            moves();
                        }
                        else if((current_row == move_row+1)&& current_col != move_col &&
                            (abs(move_col - current_col)<2) && BW[move_row][move_col]==1)
                                    //if a pawn can capture a piece at first move
                        {
                            whitepawn_moves[current_col]++;
                            moves();
                        }
                        else
                        {
                            notvalid_display();
                        }

                    }
                    //moves forward one step after its first step
                    else if(current_row - move_row == 1 && current_col == move_col &&
                             BW[move_row][move_col]!=1)
                    {
                        moves();
                    }
                    //pawn capturing a piece after its first step
                    else if(current_row - move_row == 1 && current_col!=move_col &&
                        ((abs(move_col - current_col)<2) && BW[move_row][move_col]==1))
                    {
                        moves();
                    }
                }
                //Pawn promotion condition for white pawn
                else if(current_row==1 && current_row - move_row == 1 &&
                        current_col == move_col && BW[move_row][move_col]!=1)
                {
                    blackenpassant[prev_black_col]=false;
                    changeColor(14);

                    pawn_promotion_choice();  //getting input for promotion choice

                    moves();        //do the move first

                    changeColor(14);
                    cout<<"\n\t\t White player ";changeColor(7);
                    cout<<"has promoted ";changeColor(14);
                    cout<<"Pawn ";changeColor(7);cout<<"to ";
                    changeColor(14);

                    pawnpromotion(); //do pawn promotion
                }
                else
                {

                    //moves forward one step after its first step
                    if(current_row - move_row == 1 && current_col == move_col
                       && BW[move_row][move_col]!=1)
                    {
                        blackenpassant[prev_black_col]=false;
                        moves();
                    }

                    //En passant condition
                    else if(current_row - move_row == 1 && current_col!=move_col &&
                         (abs(move_col - current_col)<2) &&
                        ((board[current_row][current_col+1]=="pawn" && BW[current_row][current_col+1]==1)||
                         (board[current_row][current_col-1]=="pawn"&& BW[current_row][current_col-1]==1))&&
                            blackpawn_moves[move_col]==1 &&blackenpassant[prev_black_col])
                    {
                        bool enpassant_move=true;//to indicate if enpasant has happened or not

                        //right side black pawn condtion
                        if(board[current_row][current_col+1]=="pawn" && BW[current_row][current_col+1]==1 &&
                           current_row==move_row+1 && current_col==move_col-1)
                        {
                            board[current_row][current_col+1]="\0";
                            BW[current_row][current_col+1]=0;
                            moves();
                        }

                        //left side black pawn condition
                        else if(board[current_row][current_col-1]=="pawn"&& BW[current_row][current_col-1]==1 &&
                           current_row==move_row+1 && current_col==move_col+1)
                        {
                            board[current_row][current_col-1]="\0";
                            BW[current_row][current_col-1]=0;
                            moves();
                        }
                        else
                        {
                            enpassant_move=false;
                            notvalid_display();
                        }
                        if(enpassant_move) //if en passant has happened
                        {
                            changeColor(14);
                            cout<<"\t\t White pawn ";changeColor(7);
                            cout<<"has captured ";changeColor(12);
                            cout<<"Black pawn";changeColor(7);
                            cout<<" by ";changeColor(11);cout<<"En Passant\n\n";
                            changeColor(7);
                        }
                    }

                    //pawn capturing a piece after its first step
                    else if(current_row - move_row == 1 && current_col!=move_col &&
                            ((abs(move_col - current_col)<2) && BW[move_row][move_col]==1))
                    {
                        blackenpassant[prev_black_col]=false;
                        moves();

                        //if moving to last row, then pawn promotion is possible
                        if(current_row==1)
                        {

                            changeColor(14);

                            pawn_promotion_choice();

                            changeColor(14);
                            cout<<"\n\t\t White player ";changeColor(7);
                            cout<<"has promoted ";changeColor(14);
                            cout<<"Pawn ";changeColor(7);cout<<"to ";
                            changeColor(14);
                            pawnpromotion();
                            cout<<"\n";
                        }
                    }
                    else
                    {
                        notvalid_display();
                    }
                }
            }
            else
            {
                notvalid_display();
            }
        }
    // 
        //WHITE ROOK

        else if(board[current_row][current_col]=="rook" && BW[current_row][current_col]==2)
        {
            //if (current row and move row) or (current col and move col) are same, then
            if((current_row == move_row || current_col == move_col)&&
               BW[move_row][move_col]!=2) //moving location must not have a white piece
            {
                blackenpassant[prev_black_col]=false;
                whiterook[current_col]++;
                rookmove();
            }
            else
            {
                notvalid_display();
            }
        }

        //WHITE KNIGHT

        else if(board[current_row][current_col]=="knight" && BW[current_row][current_col]==2)
        {
             if(current_row!= move_row && current_col!=move_col &&
                BW[move_row][move_col]!=2)
             {
                blackenpassant[prev_black_col]=false;

                // 
                // knightmove();

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
            else
            {
                notvalid_display();
            }
        }

        //WHITE BISHOP

        else if(board[current_row][current_col]=="bishop" && BW[current_row][current_col]==2)
        {
            if(current_row!= move_row && current_col!=move_col &&
                BW[move_row][move_col]!=2)
             {
                 blackenpassant[prev_black_col]=false;
                 bishopmove();
             }
             else
             {
                 notvalid_display();
             }
        }

        //WHITE KING

        else if(board[current_row][current_col]=="king" && BW[current_row][current_col]==2)
        {
            //kingside castling
            if(BW[7][5]==0 && BW[7][6]==0 &&current_row==7 &&current_col==4 &&
               move_row==7 && move_col==6 && whiteking==0 &&
                whiterook[7]==0 &&board[7][7]=="rook")
            {
                blackenpassant[prev_black_col]=false;

                whiteking++;
                whiterook[7]++;

                board[7][6]="king";
                BW[7][6]=2;
                board[7][4]="\0";
                BW[7][4]=0;

                board[7][5]="rook";
                BW[7][5]=2;
                board[7][7]="\0";
                BW[7][7]=0;

                changeColor(14);
                cout<<"\n\t\t  White player ";changeColor(7);
                cout<<"has performed ";changeColor(14);
                cout<<"Kingside castling\n\n";
                changeColor(7);

                movecount++;       //increment the total number of moves
                flag=true;         //a move has happened successfully
            }
            //Queen side castling
            else if(BW[7][3]==0 && BW[7][2]==0 &&BW[7][1]==0 &&current_row==7 &&
               current_col==4 && move_row==7 && move_col==2 && whiteking==0 &&
                whiterook[0]==0 &&board[7][0]=="rook")
            {
                blackenpassant[prev_black_col]=false;

                whiteking++;
                whiterook[0]++;

                board[7][2]="king";
                BW[7][2]=2;
                board[7][4]="\0";
                BW[7][4]=0;

                board[7][3]="rook";
                BW[7][3]=2;
                board[7][0]="\0";
                BW[7][0]=0;

                changeColor(14);
                cout<<"\n\t\t  White player ";changeColor(7);
                cout<<"has performed ";changeColor(14);
                cout<<"Queenside castling\n\n";
                changeColor(7);

                movecount++;       //increment the total number of moves
                flag=true;         //a move has happened successfully
            }
            else if(BW[move_row][move_col]!=2)
            {
                blackenpassant[prev_black_col]=false;
                kingmove();
            }
            else
            {
                notvalid_display();
            }
        }

        //WHITE QUEEN

        else if(board[current_row][current_col]=="queen" && BW[current_row][current_col]==2)
        {

            queen_move();
            // //if (current row and move row) or (current col and move col) are same, then
            // if((current_row == move_row || current_col == move_col)&&
            //    BW[move_row][move_col]!=2) //moving location must not have a white piece
            // {
            //     blackenpassant[prev_black_col]=false;
            //     //if queen's move location is similar to rook's move,then
            //     //do rook move for queen
            //     rookmove();
            // }
            // else if(current_row!= move_row && current_col!=move_col &&
            //     BW[move_row][move_col]!=2)
            // {
            //     blackenpassant[prev_black_col]=false;
            //     //if queen's move location is similar to bishop's move,then
            //     //do bishop move for queen
            //     bishopmove();
            // }
            // else
            // {
            //     notvalid_display();
            // }
        }
    }

    void black_move()
{
    //BLACK PAWN
    if(board[current_row][current_col] == "pawn" && BW[current_row][current_col]==1)
    {
        if(move_row <= current_row)
        {
            notvalid_display();
        }
        //checking if the moving location is not having a black piece
        else if(BW[move_row][move_col] !=1)
        {
            if(current_row==1)
            {
                whiteenpassant[prev_white_col]=false;
                if(blackpawn_moves[current_col]==0)
                {
                    //a pawn can move 1 or 2 steps forward in first move
                     if((move_row - current_row ==1 || move_row - current_row==2 )&&
                           current_col == move_col && BW[move_row][move_col]!=2 &&
                           BW[current_row+1][current_col]==0)
                        {
                            if(move_row-current_row==2)
                            {
                                prev_black_col=current_col;
                                blackenpassant[current_col]=true;
                            }
                            blackpawn_moves[current_col]++;
                            moves();
                        }
                        else if((move_row == current_row+1) && current_col != move_col &&
                                (abs(move_col - current_col)<2) && BW[move_row][move_col] == 2)
                                    //if a pawn can capture a piece at first move
                        {
                            blackpawn_moves[current_col]++;
                            moves();
                        }
                        else
                        {
                            notvalid_display();
                        }
                }
            }
            //Pawn promotion condition for black pawn
            else if(current_row==6 && move_row - current_row == 1 &&
                    current_col == move_col && BW[move_row][move_col]!=2)
            {
                whiteenpassant[prev_white_col]=false;
                changeColor(12);

                pawn_promotion_choice(); //get input for promotion choice

                moves();        //do the move first

                changeColor(12);
                cout<<"\n\t\t Black player ";changeColor(7);
                cout<<"has promoted ";changeColor(12);
                cout<<"Pawn ";changeColor(7);cout<<"to ";
                changeColor(12);

                pawnpromotion(); //do pawn promotion
            }
            else
            {
                //moves forward one step after its first step
                if(move_row - current_row == 1 && current_col == move_col && BW[move_row][move_col]!=2)
                {
                    whiteenpassant[prev_white_col]=false;
                    moves();
                }

                //En passant condition
                else if(move_row - current_row == 1 && current_col!=move_col &&
                     (abs(move_col - current_col)<2) &&
                    ((board[current_row][current_col+1]=="pawn" && BW[current_row][current_col+1]==2)||
                     (board[current_row][current_col-1]=="pawn"&& BW[current_row][current_col-1]==2))&&
                        whitepawn_moves[move_col]==1 &&whiteenpassant[prev_white_col])
                {
                    bool enpassant_move=true; //to indicate if en passant has happened or not

                    //right side white pawn condition
                    if(board[current_row][current_col+1]=="pawn" && BW[current_row][current_col+1]==2 &&
                           current_row==move_row-1 && current_col==move_col-1)
                    {
                        board[current_row][current_col+1]="\0";
                        BW[current_row][current_col+1]=0;
                        moves();
                    }

                    //left side white pawn condition
                    else if(board[current_row][current_col-1]=="pawn"&& BW[current_row][current_col-1]==2 &&
                           current_row==move_row-1 && current_col==move_col+1)
                    {
                        board[current_row][current_col-1]="\0";
                        BW[current_row][current_col-1]=0;
                        moves();
                    }
                    else
                    {
                        enpassant_move=false;
                        notvalid_display();
                    }
                    if(enpassant_move)
                    {
                        changeColor(12);
                        cout<<"\t\t Black pawn ";changeColor(7);
                        cout<<"has captured ";changeColor(14);
                        cout<<"White pawn";changeColor(7);
                        cout<<" by ";changeColor(11);cout<<"En Passant\n\n";
                        changeColor(7);
                    }
                }

                //pawn capturing a piece after its first step
                else if(move_row - current_row == 1 && current_col!=move_col &&
                        ((abs(move_col - current_col)<2) && BW[move_row][move_col]==2))
                {
                    whiteenpassant[prev_white_col]=0;
                    moves();

                    //if moving to last row, then pawn promotion is possible
                    if(current_row==6)
                    {

                        changeColor(12);

                        pawn_promotion_choice();

                        changeColor(12);
                        cout<<"\n\t\t Black player ";changeColor(7);
                        cout<<"has promoted ";changeColor(12);
                        cout<<"Pawn ";changeColor(7);cout<<"to ";
                        changeColor(12);

                        pawnpromotion();
                        cout<<"\n";
                    }
                }
                else
                {
                    notvalid_display();
                }
            }
        }
        else
        {
            notvalid_display();
        }
    }

    //BLACK ROOK

        else if(board[current_row][current_col]=="rook" && BW[current_row][current_col]==1)
        {
            //if (current row and move row) or (current col and move col) are same, then
            if((current_row == move_row || current_col == move_col)&&
               BW[move_row][move_col]!=1) //moving location must not have a black piece
            {
                whiteenpassant[prev_white_col]=false;
                blackrook[current_col]++;
                rookmove();
            }
            else
            {
                notvalid_display();
            }
        }
    
        //BLACK KNIGHT
    
        else if(board[current_row][current_col]=="knight" && BW[current_row][current_col]==1)
        {
             if(current_row!= move_row && current_col!=move_col &&
                BW[move_row][move_col]!=1)
             {
                 whiteenpassant[prev_white_col]=false;
                 
                 // knightmove();

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
             else
             {
                 notvalid_display();
             }
        }
    
        //BLACK BISHOP
    
        else if(board[current_row][current_col]=="bishop" && BW[current_row][current_col]==1)
        {
            if(current_row!= move_row && current_col!=move_col &&
                BW[move_row][move_col]!=1)
             {
                 whiteenpassant[prev_white_col]=false;
                 bishopmove();
             }
             else
             {
                 notvalid_display();
             }
        }
    
        //BLACK KING
    
        else if(board[current_row][current_col]=="king" && BW[current_row][current_col]==1)
        {
            //kingside castling
            if(BW[0][5]==0 && BW[0][6]==0 &&current_row==0 &&current_col==4 &&
               move_row==0 && move_col==6 && blackking==0 &&
                blackrook[7]==0 &&board[0][7]=="rook")
            {
                whiteenpassant[prev_white_col]=false;
    
                blackking++;
                blackrook[7]++;
    
                board[0][6]="king";
                BW[0][6]=1;
                board[0][4]="\0";
                BW[0][4]=0;
    
                board[0][5]="rook";
                BW[0][5]=1;
                board[0][7]="\0";
                BW[0][7]=0;
    
                changeColor(12);
                cout<<"\n\t\t  Black player ";changeColor(7);
                cout<<"has performed ";changeColor(12);
                cout<<"Kingside castling\n\n";
                changeColor(7);
    
                movecount++; //increment the total number of moves
                flag=true;   //a move has happened successfully
            }
            //Queen side castling
            else if(BW[0][3]==0 && BW[0][2]==0 &&BW[0][1]==0 &&current_row==0 &&
               current_col==4 && move_row==0 && move_col==2 && blackking==0 &&
                blackrook[0]==0 &&board[0][0]=="rook")
            {
                whiteenpassant[prev_white_col]=false;
    
                blackking++;
                blackrook[0]++;
    
                board[0][2]="king";
                BW[0][2]=1;
                board[0][4]="\0";
                BW[0][4]=0;
    
                board[0][3]="rook";
                BW[0][3]=1;
                board[0][0]="\0";
                BW[0][0]=0;
    
                changeColor(12);
                cout<<"\n\t\t  Black player ";changeColor(7);
                cout<<"has performed ";changeColor(12);
                cout<<"Queenside castling\n\n";
                changeColor(7);
    
                movecount++;       //increment the total number of moves
                flag=true;         //a move has happened successfully
            }
    
            else if(BW[move_row][move_col]!=1)
            {
                whiteenpassant[prev_white_col]=false;
    
                kingmove();
            }
            else
            {
                notvalid_display();
            }
        }
    
        //BLACK QUEEN
        else if(board[current_row][current_col]=="queen" && BW[current_row][current_col]==1)
        {
            //if (current row and move row) or (current col and move col) are same, then
            //queen is going to have same move as rook, then call rookmove function
            if((current_row == move_row || current_col == move_col)&&
               BW[move_row][move_col]!=1)
            {
                whiteenpassant[prev_white_col]=false;
                rookmove();
            }
            //if (current row and move row) or (current col and move col) are not same,then
            //queen is going to have same move as bishop, then call bishopmove function
            else if(current_row!= move_row && current_col!=move_col &&
                BW[move_row][move_col]!=1)
            {
                whiteenpassant[prev_white_col]=false;
                bishopmove();
            }
            else
            {
                notvalid_display();
            }
        }
}
};