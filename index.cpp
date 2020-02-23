#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;


/******************GLOBAL VARIABLES*********************/

    char positions[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int column,row;
    int choice;
    bool draw = false;
    char turn='X';

/***********************************************************/



/********************BOARD DESIGN************************/

    void Display()
    {
        //TO CLEAR THE SCREEN AND NOT REPEATING THE SET UP AGAIN AND AGAIN
        system("cls");
        //BOARD DESIGN
        cout<<"\t\t\t\tTIC TAC TOE "<<endl<<endl;

        cout<<"  Player 1 : [X]"<<endl;
        cout<<"  Player 2 : [0]"<<endl<<endl<<endl;

    cout<<"\t\t       |       |       "<<endl;
    cout<<"\t\t   "<<positions[0][0]<<"   |   "<<positions[0][1]<<"   |   "<<positions[0][2]<<"   "<<endl;
    cout<<"\t\t_______|_______|_______"<<endl;
    cout<<"\t\t       |       |       "<<endl;
    cout<<"\t\t   "<<positions[1][0]<<"   |   "<<positions[1][1]<<"   |   "<<positions[1][2]<<"   "<<endl;
    cout<<"\t\t_______|_______|_______"<<endl;
    cout<<"\t\t       |       |       "<<endl;
    cout<<"\t\t   "<<positions[2][0]<<"   |   "<<positions[2][1]<<"   |   "<<positions[2][2]<<"   "<<endl;
    cout<<"\t\t       |       |       "<<endl<<endl<<endl;

    }
/***************************************************/


/******************EVERY TIME PLAYER ENTER A NUMBER, WE HAVE TO REPLACE IT WITH X OR 0*************/

    turnp()
    {
        if(turn=='X')
        {
        cout<<"Enter the number player 1[X] : ";
        cin>>choice;
        }
        else if(turn=='0')
        {
        cout<<"Enter the number player 2[0] : ";
        cin>>choice;
        }
        //REPLACING
        switch(choice)
    {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Wrong choice";
            break;
    }

    if(turn=='X' && positions[row][column]!='X' && positions[row][column]!='0')
    {
        positions[row][column]='X';
        //TO SWITCH THE TURN
        turn='0';
    }
    else if(turn=='0'&& positions[row][column]!='X' && positions[row][column]!='0')
    {
        positions[row][column]='0';
        //TO SWITCH THE TURN
        turn='X';
    }
    else
    {
        //WHEN PLAYER 1 AND PLAYER 2 ENTER THE SAME NUMBER
        cout<<"Wrong choice. Enter another number you copy cat!..."<<endl<<endl<<endl;
        turnp();
    }
    }

/*************************************************************/


/*******************LOGIC FOR WINING******************/

    bool calc()
    {
        for(int i=0;i<3;i++)
        {
        //FOR SAME ROWS AND COLUMNS
        if(positions[i][0]==positions[i][1]&&positions[i][0]==positions[i][2]||positions[0][i]==positions[1][i]&&positions[0][i]==positions[2][i])
        {
           return false;
        }
        //FOR DIAGNALS
        if(positions[0][0]==positions[1][1]&&positions[0][0]==positions[2][2] || positions[0][2]==positions[1][1]&&positions[0][2]== positions[2][0])
        {
            return false;
        }
        }

        //IN CASE GAME DRAWS BETWEEN BOTH THE PLAYERS
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(positions[i][j]!='X'&&positions[i][j]!='0')
                    return true;
            }
        }

       draw = true;
        return false;
    }

/*********************************************************/



/*********************MAIN FUNCTION************/

main()
{
    while(calc())
    {
    Display();
    turnp();
    calc();
    }

    if(turn=='X'&&draw == false)
    {
        cout<<"\n\nPlayer 2 wins!!! Congrats Player 2 :)\n \n";
    }
    else if(turn=='0'&&draw == false)
    {
        cout<<"\n\nPlayer 1 wins!!! Congrats Player 1 :)\n \n";
    }
    else
    {
        cout<<"\n\nGAME DRAW!";
    }
}
/******************************************************/
