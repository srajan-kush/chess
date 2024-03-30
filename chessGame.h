#include <random>
#include <ctime>
#include "pieceSelection.h"
#include "check.h"

class chessGame :virtual public pieceSelection, virtual public check{
    public:
    chessGame() //constructor to initialize the board
    {   
        changeColor(7);
        cout<<"\n\t\t\t TWO PLAYER CHESS GAME \n";
        changeColor(12);
        cout<<"\n   red -> ";changeColor(7);cout<<" BLACK COINS";
        changeColor(14);
        cout<<"\n   yellow -> ";changeColor(7);cout<<" WHITE COINS";
        changeColor(7);
        cout<<"\n\n   ";
    }
    void display()
    {
        cout<<"\t";
        //to display column numbers above the board
        for(i=0;i<N;i++)
            cout<<i<<"        ";
        cout<<"\n   ";
        for(i=0;i<8;i++)
            cout<<"---------";
        cout<<"-"<<endl;
        for(i=0;i<N;i++)
        {
            cout<<" "<<i; //to display row numbers
            for(j=0;j<N;j++)
            {
                if(BW[i][j]==1)
                {
                    changeColor(7); //changes text color to white
                    cout<<" |";
                    changeColor(12);//changes text color to red
                    cout<<setw(7)<<board[i][j];
                }
                else{
                    changeColor(7);
                    cout<<" |";
                    changeColor(14); //changes text color to yellow
                    cout<<setw(7)<<board[i][j];
                }
            }
            changeColor(7);
            //to display row numbers on right side of the board
            cout<<" | "<<i<<"\n   ";
            for(k=0;k<8;k++)
                cout<<"---------";
            cout<<"-\n";
        }
        cout<<"\t";
        //to display column numbers below the board
        for(i=0;i<N;i++)
            cout<<i<<"        ";
        cout<<"\n";
    }

    void getmoves()
    {   
        if(movecount%2 != 0)
        {
            changeColor(14);
            cout<<"\n WHITE'S MOVE \n";
            move_flag=1; //a flag to indicate that this is white's move
            changeColor(7);
        }
        else
        {
            changeColor(12);
            cout<<"\n BLACK'S MOVE \n ";
            move_flag=0; //a flag to indicate that this is black's move
            changeColor(7);
        }

        cout<<"\n Enter the current ROW of the piece which you want to move : ";

        /* getting input through 'cin', and checking if it is not an integer */

        while(!(cin >> current_row) || (current_row > 7) || (current_row < 0))
        {
            /* if the entered value is not an integer,
            then while loop gets executed */

            cin.clear();
            /* cin.clear() clears the error flag on cin,
               so that future I/O operations will work correctly. */

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            /* cin.ignore(numeric_limits<streamsize>::max(), '\n')
               skips to the next newline (to ignore anything else on the same line
               as the non-number so that it does not cause another parse failure) */

            /* streamsize is signed integral which gives the number of i/o character
            transferred (or) size of I/O buffer.

            Here, by using "numeric_limits" template class we wanted to know max limit
            of I/O buffer or character transferred. */

            notvalid_display();
            cout<<"\n Enter the current ROW of the piece which you want to move : ";
        }

        cout<<" Enter the current COL of the piece which you want to move : ";
        while(!(cin >> current_col) || (current_col > 7) || (current_col < 0))  //to get only integer values as input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            notvalid_display();
            cout<<"\n Enter the current COL of the piece which you want to move : ";
        }

        // checking cnditions for selecting correct piece
        // at position of current_row and current_col must be not null
        if(BW[current_row][current_col] == 0){
            notvalid_display();
            getmoves();
        }


        cout<<" Enter the ROW where you want to move : ";
        while(!(cin >> move_row) || (move_row > 7) || (move_row < 0))  //to get only integer values as input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            notvalid_display();
            cout<<"\n Enter the ROW where you want to move : ";
        }

        cout<<" Enter the COL where you want to move : ";
        while(!(cin >> move_col) || (move_col > 7) || (move_col < 0))  //to get only integer values as input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            notvalid_display();
            cout<<"\n Enter the COL where you want to move : ";
        }

        if(current_row<0 || current_row>7 ||current_col<0 ||current_col>7 ||
           move_row<0 ||move_row>7 ||move_col<0||move_col>7)   //Invalid input
        {
            notvalid_display();
        }

        else if(board[current_row][current_col] == "\0") //if choosing a empty location
        {
            notvalid_display();
        }
        else if(current_row == move_row && current_col == move_col) //moving to same location
        {
            notvalid_display();
        }

        else if(move_flag && BW[current_row][current_col]==2)
        {
            int ch;
            //copy the current location's piece name and value
            curr_piece = board[current_row][current_col];
            curr_piece_value = BW[current_row][current_col];

            //copy the current location's piece name and value
            move_piece = board[move_row][move_col];
            move_piece_value = BW[move_row][move_col];

            white_move(); /* WHITE MOVE FUNCTION CALL */


        //if the current white move leads to CHECK for white king, then stop the move
            if(blackcheck() && flag)
            {
                cout<<"\n\t\t  This move will bring your ";changeColor(14);
                cout<<"King ";changeColor(7);
                cout<<"under ";changeColor(11);
                cout<<"CHECKMATE\n";changeColor(7);

                cout<<"\n Do you want to continue?\n 1 -> Yes\n 2 -> No";
                cout<<"\n Enter your choice : ";
                while(!(cin>>ch) || (ch!=1 && ch!=2))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"\n\t\t\t  Please enter a ";changeColor(11);
                    cout<<"valid ";changeColor(7);cout<<"choice !!";
                    cout<<"\n\n Enter your choice correctly : ";
                }
                if(ch==1)
                {
                    /* In main function the checkmate is displayed,
                       and the game ends */
                }
                else if(ch==2)
                {
                    copy_contents_back();
                }
                else
                {
                    notvalid_display();
                }
            }
        }

        else if(!move_flag && BW[current_row][current_col]==1)
        {
            int ch;
            //copy the current location's piece name and value
            curr_piece = board[current_row][current_col];
            curr_piece_value = BW[current_row][current_col];

            //copy the current location's piece name and value
            move_piece = board[move_row][move_col];
            move_piece_value = BW[move_row][move_col];

            black_move();  /* BLACK MOVE FUNCTION CALL */

        //if the current black move leads to CHECK for black king, then stop the move
            if(whitecheck() && flag)
            {
                cout<<"\n\t\t  This move will bring your ";changeColor(12);
                cout<<"King ";changeColor(7);
                cout<<"under ";changeColor(11);
                cout<<"CHECKMATE\n";changeColor(7);
                cout<<"\n Do you want to continue?\n 1 -> Yes\n 2 -> No";
                cout<<"\n Enter your choice : ";
                while(!(cin>>ch) || (ch!=1 && ch!=2))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"\n\t\t\t  Please enter a ";changeColor(11);
                    cout<<"valid ";changeColor(7);cout<<"choice !!";
                    cout<<"\n\n Enter your choice correctly : ";
                }
                if(ch==1)
                {
                    /* In main function the checkmate is displayed,
                       and the game ends */
                }
                else if(ch ==2)
                {
                    copy_contents_back();
                }
                else
                {
                    notvalid_display();
                }
            }
        }
        else
            notvalid_display();
    }
    void copy_contents_back(){
        changeColor(11);
        cout<<"\n\t\t   Move cancelled successfully !!\n";
        changeColor(7);

        flag=false; //set flag as false
        movecount--;

        //copying back the moving location's piece contents
        board[move_row][move_col]=move_piece;
        BW[move_row][move_col]=move_piece_value;

        //copying back the current location's piece contents
        board[current_row][current_col]=curr_piece;
        BW[current_row][current_col]=curr_piece_value;
    }


    void play_again()
    {
        int play_choice;
        cout<<"\n Do you want to play another game?";
        cout<<"\n 1 -> Yes\n 2 -> No";
        cout<<"\n Enter your choice : ";
        while(!(cin>>play_choice) || (play_choice!=1 && play_choice!=2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\n\t\t\t  Please enter a ";changeColor(11);
            cout<<"valid ";changeColor(7);cout<<"choice !!";
            cout<<"\n\n Enter your choice correctly : ";
        }
        if(play_choice==1)
        {
            //separator line
            cout<<endl;
            for(int i=0;i<14;i++)
                cout<<"--------";
            cout<<endl;
    
            changeColor(11);
            cout<<"\n\n\t\t\t\t NEW GAME \n\n";
            changeColor(7);
    
            //call the declare function to newly declare the board
            declare();
            for(i=2;i<6;i++)
            {
                for(j=0;j<N;j++)
                {
                    board[i][j]="\0";
                    BW[i][j]=0;
                }
            }
            display(); //display the newly declared board
        }
        else
        {
            cout<<"\n\n\t\t\t   THANKS FOR ";changeColor(10);
            cout<<"PLAYING CHESS !!\n\n";changeColor(7);
            //separator line
            cout<<endl;
            for(int i=0;i<14;i++)
                cout<<"--------";
            cout<<endl;
            exit(0); //exits the program
        }
    }

    void check_draw(){ // draw of game using fifty rule
        if(movecount == 50){
            changeColor(11);
            cout<<"\n\n\t\t\t Draw under the fifty rule";
            changeColor(7);cout<<" !!\n\n";
            play_again();
        }else{
            return;
        }
        return;
    }
};