#include "chessBoard.h"

class check : virtual public ChessBoard{
    public:
    bool whitecheck()
    {
        int row, col,check_flag=1;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(BW[i][j]==2)
                {
                //check if there are possibilities for check to black king by white pawn
                    if(board[i][j]=="pawn")
                    {
                        if(j==7 && i!=0)
                        {
                            if(board[i-1][j-1]=="king" && BW[i-1][j-1]==1)
                               return true;
                        }
                        else if(j==0 && i!=0)
                        {
                            if(board[i-1][j+1]=="king" && BW[i-1][j+1]==1)
                               return true;
                        }
                        else if((board[i-1][j-1]=="king" && BW[i-1][j-1]==1)||
                       (board[i-1][j+1]=="king" && BW[i-1][j+1]==1))
                        {
                            return true;
                        }
                    }
                //check if there are possibilities for check to black king by white rook
                    else if(board[i][j]=="rook")
                    {
                        if(check_rookmove(i, j,check_flag))
                            return true;
                    }
                //check if there are possibilities for check to black king by white bishop
                    else if(board[i][j]=="bishop")
                    {
                        if(check_bishopmove(i, j,check_flag))
                            return true;
                    }
                //check if there are possibilities for check to black king by white knight
                    else if(board[i][j]=="knight")
                    {
                        if(check_knightmove(i, j, check_flag))
                            return true;
                    }
                //check if there are possibilities for check to black king by white queen
                    else if(board[i][j]=="queen")
                    {
                        if(check_rookmove(i, j,check_flag) ||
                           check_bishopmove(i, j,check_flag))
                            return true;
                    }
                    else if(board[i][j]=="king")
                    {
                        if(check_kingmove(i,j, check_flag))
                            return true;
                    }
                }
            }
        }
        return false;
    }

    bool blackcheck()
    {
        int row, col,check_flag=2;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(BW[i][j]==1)
                {
                //check if there are possibilities for CHECK to white king by black pawn
                    if(board[i][j]=="pawn")
                    {
                        if(j==7 && i!=7)
                        {
                            if(board[i+1][j-1]=="king" && BW[i+1][j-1]==2)
                               return true;
                        }
                        else if(j==0 && i!=7)
                        {
                            if(board[i+1][j+1]=="king" && BW[i+1][j+1]==2)
                               return true;
                        }
                        else if((board[i+1][j-1]=="king" && BW[i+1][j-1]==2)||
                                (board[i+1][j+1]=="king" && BW[i+1][j+1]==2))
                        {
                            return true;
                        }
                    }
                //check if there are possibilities for check to black king by white rook
                    else if(board[i][j]=="rook")
                    {
                        if(check_rookmove(i, j, check_flag))
                            return true;
                    }
                //check if there are possibilities for check to black king by white bishop
                    else if(board[i][j]=="bishop")
                    {
                        if(check_bishopmove(i, j, check_flag))
                            return true;
                    }
                //check if there are possibilities for check to black king by white knight
                    else if(board[i][j]=="knight")
                    {
                        if(check_knightmove(i, j, check_flag))
                            return true;
                    }
                //check if there are possibilities for check to black king by white queen
                    else if(board[i][j]=="queen")
                    {
                        if(check_rookmove(i, j,check_flag) ||
                           check_bishopmove(i, j,check_flag))
                            return true;
                    }
                    else if(board[i][j]=="king")
                    {
                        if(check_kingmove(i,j, check_flag))
                            return true;
                    }
                }
            }
        }
        return false;
    }

    bool check_rookmove(int i, int j,int flag)
    {
        int row,col;

        //traversing up and checking
        if(i !=0)
        {
            for(row=i-1,col=j;row>=0;row--)
            {
                if(board[row][col]=="king" && BW[row][col]==flag)
                {
                    return true;
                }
                else if(BW[row][col]==1 || BW[row][col]==2)
                {
                    break;
                }
            }
        }

        //traversing down and checking
        if(i !=7)
        {
            for(row=i+1,col=j;row<=7;row++)
            {
                if(board[row][col]=="king" && BW[row][col]==flag)
                {
                    return true;
                }
                else if(BW[row][col]==1 || BW[row][col]==2)
                {
                    break;
                }
            }
        }

        //traversing right and checking
        if(j!=7)
        {
            for(row=i,col=j+1;col<=7;col++)
            {
                if(board[row][col]=="king" && BW[row][col]==flag)
                {
                    return true;
                }
                else if(BW[row][col]==1 || BW[row][col]==2)
                {
                    break;
                }
            }
        }

        //traversing left and checking
        if(j !=0)
        {
            for(row=i,col=j-1;col>=0;col--)
            {
                if(board[row][col]=="king" && BW[row][col]==flag)
                {
                    return true;
                }
                else if(BW[row][col]==1 || BW[row][col]==2)
                {
                    return false;
                    break;
                }
            }
        }
        return false;
    }

    bool check_bishopmove(int i, int j,int flag)
    {
        int row, col;
        //traverse to left top from the current bishop location
        if(i !=0 && j !=0)
        {
             for(row=i-1,col=j-1;row>=0 && col>=0;row--,col--)
             {
                 //while traversing, if black king is found, then return true
                 if(board[row][col]=="king"&&BW[row][col]==flag)
                 {
                     return true;
                 }
                 //while traversing, if there are any obstacles(pieces) found,
                 //then break the loop
                 else if(BW[row][col]==1 || BW[row][col]==2)
                 {
                     break;
                 }
             }
        }

         //traverse to right top from the current bishop location
         if(i!=0 && j!=7)
         {
             for(row=i-1,col=j+1;row>=0 && col<=7 ;row--,col++)
             {
                 if(board[row][col]=="king"&&BW[row][col]==flag)
                 {
                     return true;
                 }
                 else if(BW[row][col]==1 || BW[row][col]==2)
                 {
                     break;
                 }
             }
         }

         //traverse to right bottom from the current bishop location
         if(i!=7 && j!= 7)
         {
             for(row=i+1,col=j+1;row<=7 && col<=7;row++,col++)
             {
                 if(board[row][col]=="king"&&BW[row][col]==flag)
                 {
                     return true;
                 }
                 else if(BW[row][col]==1 || BW[row][col]==2)
                 {
                     break;
                 }
             }
         }

         //traverse to left bottom from the current bishop location
         if(i!=7 && j!=0)
         {
             for(row=i+1,col=j-1;row<=7 && col>=0;row++,col--)
             {
                 if(board[row][col]=="king"&&BW[row][col]==flag)
                 {
                     return true;
                 }
                 else if(BW[row][col]==1 || BW[row][col]==2)
                 {
                     break;
                 }
             }
         }

         return false;
    }

    bool check_knightmove(int i, int j,int flag)
    {
        int row=i,col=j;
        //10'o clock condition
        if(row>=1 && col >=2)
        {
            if(board[row-1][col-2]=="king"&& BW[row-1][col-2]==flag)
            {
               return true;
            }
        }

        //11'o clock condition
        if(row >=2 && col >=1)
        {
            if(board[row-2][col-1]=="king"&& BW[row-2][col-1]==flag)
            {
               return true;
            }
        }

        //1'o clock condition
        if(row >=2 && col <=6)
        {
            if(board[row-2][col+1]=="king"&& BW[row-2][col+1]==flag)
            {
               return true;
            }
        }

        //2'o clock condition
        if(row>=1 && col <=5)
        {
            if(board[row-1][col+2]=="king"&& BW[row-1][col+2]==flag)
            {
               return true;
            }
        }

        //4'o clock condition
        if(row<=6 && col <=5)
        {
            if(board[row+1][col+2]=="king"&& BW[row+1][col+2]==flag)
            {
               return true;
            }
        }

        //5'o clock condition
        if(row<=5 && col<=6)
        {
            if(board[row+2][col+1]=="king"&& BW[row+2][col+1]==flag)
            {
               return true;
            }
        }

        //7'o clock condition
        if(row<=5 && col>=1)
        {
            if(board[row+2][col-1]=="king"&& BW[row+2][col-1]==flag)
            {
               return true;
            }
        }

        //8'o clock condition
        if(row<=6 && col >=2)
        {
            if(board[row+1][col-2]=="king"&& BW[row+1][col-2]==flag)
            {
               return true;
            }
        }
    }

    bool check_kingmove(int i, int j, int flag)
    {
        int row=i, col=j;
        //top left move condition
        if(row!=0 && col!=0)
        {
            if(board[row-1][col-1]=="king"&&BW[row-1][col-1]==flag)
                return true;
        }
        //top move condition
        if(row!=0)
        {
            if(board[row-1][col]=="king"&&BW[row-1][col]==flag)
                return true;
        }
        //top right move condition
        if(row!=0 && j!=7)
        {
            if(board[row-1][col+1]=="king"&&BW[row-1][col+1]==flag)
                return true;
        }
        //right move condition
        if(col!=7)
        {
            if(board[row][col+1]=="king"&& BW[row][col+1]==flag)
                return true;
        }
        //bottom right move condition
        if(row!=7 && col!=7)
        {
            if(board[row+1][col+1]=="king" && BW[row+1][col+1]==flag)
                return true;
        }
        //bottom move condition
        if(row!=7)
        {
            if(board[row+1][col]=="king" && BW[row+1][col]==flag)
                return true;
        }
        //bottom left move condition
        if(row!=7 && col!=0)
        {
            if(board[row+1][col-1]=="king"&&BW[row+1][col-1]==flag)
                return true;
        }
        //left move condition
        if(col!=0)
        {
            if(board[row][col-1]=="king" && BW[row][col-1]==flag)
                return true;
        }
        return false;
    }

};

