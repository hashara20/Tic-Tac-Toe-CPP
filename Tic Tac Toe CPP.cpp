#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//1D array for slots of the game board
char board[9]={'1','2','3','4','5','6','7','8','9'};

//important variables to use
int slotNumber;
char marker1;
char marker2;
string playerOne;
string playerTwo;
int a;

//function to draw the game board's characters as a box
void draw(){
    cout<<"-------------------"<<endl;
    cout<<"|  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"  |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"|  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"  |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"|  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"  |"<<endl;
    cout<<"-------------------"<<endl;
}

//function to replace the characters in game board
int replaceMarker(int slot,int x){
    //for player one
    if(x==1)
    {
        board[slot-1]=marker1; //replace the particular character according to player 1s input
    }
    //for player two
    if(x==2)
    {
        board[slot-1]=marker2;//replace the particular character according to player 2s input
    }

}
//a function to check whether the player input number is already taken or not
void isSwap()
{
    if(board[slotNumber-1]=='X' || board[slotNumber-1]=='O')
    {
        a=1; // if user input number is already taken assign 1 to a
    }
    else
    {
        a=0; // if user input number is new one assign 0 to a
    }
}

// a function to check whether players win or not
void isWin() {
    // for player one

    //check the characters order is ok for winning
    if (board[0] == marker1 && board[1] == marker1 && board[2] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort(); // if the player wins stop the whole program
    }
    if (board[3] == marker1 && board[4] == marker1 && board[5] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort();
    }
    if (board[6] == marker1 && board[7] == marker1 && board[8] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort();
    }
    if (board[0] == marker1 && board[3] == marker1 && board[6] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort();
    }
    if (board[1] == marker1 && board[4] == marker1 && board[7] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort();
    }
    if (board[2] == marker1 && board[5] == marker1 && board[8] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort();
    }
    if (board[0] == marker1 && board[4] == marker1 && board[8] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort();
    }
    if (board[2] == marker1 && board[4] == marker1 && board[6] == marker1) {
        cout << ">>>>>>> " << playerOne << " IS WIN";
        abort();
    }

    //for player two
    if (board[0] == marker2 && board[1] == marker2 && board[2] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
    if (board[3] == marker2 && board[4] == marker2 && board[5] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
    if (board[6] == marker2 && board[7] == marker2 && board[8] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
    if (board[0] == marker2 && board[3] == marker2 && board[6] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
    if (board[1] == marker2 && board[4] == marker2 && board[7] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
    if (board[2] == marker2 && board[5] == marker2 && board[8] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
    if (board[0] == marker2 && board[4] == marker2 && board[8] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
    if (board[2] == marker2 && board[4] == marker2 && board[6] == marker2) {
        cout << ">>>>>>> " << playerTwo << " IS WIN";
        abort();
    }
}

// the function for play the tictactoe game palyer vs player
void playerVSplayer() {

    draw();
    cout<<"Enter the player 1's name:  "<<endl; //taking name as a input
    cin>>playerOne;                            // store the name in string
    cout<<"Enter the player 2's name:  "<<endl;
    cin>>playerTwo;

    cout<<"Enter the "<<playerOne<<"'s marker (X or O)"<<endl; //taking player1's marker
    cin>>marker1; //store the player 1's marker in character marker1


    //loop to play game
    for(int i=0;i<9;i++) {
        if (marker1 == 'X' || marker1 == 'x') {
            marker1 = 'X'; // if player1 enters simple x take it as a cpital letter X
            marker2 = 'O';//if player one like X assign O to player 2's marker
        }
        else if (marker1 == 'O' || marker1 == 'o') {
            marker1 = 'O';// if player1 enters simple o take it as a cpital letter O
            marker2 = 'X';//if player one like O assign X to player 2's marker
        }
        else if (marker1 != 'X' || marker1 != 'x' || marker1 != 'O' || marker1 != 'o') {
            // if the players enter a wrong character
            cout << "Invalid marker..... Enter the marker again(X or O)" << endl;
            i = i - 1;
            continue;
        }

        //player One
        //taking inputs from player 1
        cout << playerOne << "'s turn---" << endl;
        cout << "Enter the slot number(1 to 9) :  " << endl;
        cin >> slotNumber; // store the input in a integer
        isSwap(); // call to isSwap function to check whether input number is already taken or not

        //isSwap gives a=1 if the input is already taken
        if(a==1)
        {
            cout<<"This slot is already taken try an other slot"<<endl; //say to enter the slot number agaim
            i=i-1; //decrease the value of i because input is wrong one
            continue; // continue running programm again from for loop
        }

        if (slotNumber < 1 || slotNumber > 9) {
            //check whether the input slot number is between 1 and 9 or not
            cout << " Invalid slot number please enter again(1 to 9): " << endl; //if input number is wrong say to enter again
            i = i - 1;//decrease the value of i because input is wrong one
            continue;// continue running programm again from for loop

        }
        replaceMarker(slotNumber, 1);//call to replaceMarker function to replace the characters
        draw(); // call to draw function to draw the board
        isWin(); //call to isWin function check whether the player one is Win or not


        //player Two
        //Repeat the same things for the player two
        cout << playerTwo << "'s turn---" << endl;
        cout << "Enter the slot number(1 to 9) :  " << endl;
        cin >> slotNumber;
        isSwap();

        if(a==1)
        {
            cout<<"This slot is already taken try an other slot"<<endl;
            i=i-1;
            continue;
        }


        if (slotNumber < 1 || slotNumber > 9) {
            cout << " Invalid slot number please enter again(1 to 9): " << endl;
            i = i - 1;
            continue;
        }
        replaceMarker(slotNumber, 2);
        draw();
        isWin();

    }
}

//the function to play tictactoe game player vs computer

/*repeat the same codes for player vs computer. but in hear the only difference is random inputs are taken
 * according to time from the computer*/
void playerVScomputer() {

    draw();
    cout<<"Enter the player 1's name:  "<<endl;
    cin>>playerOne;
    playerTwo="Computer "; //define the player two as computer

    cout<<"Enter the "<<playerOne<<"'s marker (X or O)"<<endl;
    cin>>marker1;

    if(marker1=='X' || marker1=='x')
    {
        marker1='X';
        marker2='O';
    }
    else if(marker1=='O' || marker1=='o')
    {
        marker1='O';
        marker2='X';
    }

    for(int i=0;i<9;i++) {
        if (marker1 == 'X' || marker1 == 'x') {
            marker1 = 'X';
            marker2 = 'O';
        } else if (marker1 == 'O' || marker1 == 'o') {
            marker1 = 'O';
            marker2 = 'X';
        } else if (marker1 != 'X' || marker1 != 'x' || marker1 != 'O' || marker1 != 'o') {
            cout << "Invalid marker..... Enter the marker again(X or O)" << endl;
            i = i - 1;
            continue;
        }

        //player One
        cout << playerOne << "'s turn---" << endl;
        cout << "Enter the slot number(1 to 9) :  " << endl;
        cin >> slotNumber;
        isSwap();

        if(a==1)
        {
            cout<<"This slot is already taken try an other slot"<<endl;
            i=i-1;
            continue;
        }

        if (slotNumber < 1 || slotNumber > 9) {
            cout << " Invalid slot number please enter again(1 to 9): " << endl;
            i = i - 1;
            continue;

        }
        replaceMarker(slotNumber, 1);
        draw();
        isWin();

        //Computer
        cout << playerTwo << "'s turn---" << endl;
        srand(time(NULL)); // a function in stdlib.h to take different random numbers according to time
        slotNumber=rand()%9+1; // taking random numbers from computer as the slot number
        isSwap();

        if(a==1)
        {
            cout<<"This slot is already taken try an other slot"<<endl;
            i=i-1;
            continue;
        }


        if (slotNumber < 1 || slotNumber > 9) {
            cout << " Invalid slot number please enter again(1 to 9): " << endl;
            i = i - 1;
            continue;
        }
        replaceMarker(slotNumber, 2);
        draw();
        isWin();

    }
}
int main() {

    cout<<"-----------------------THIS IS TIC TAC TOE GAME----------------------------------"<<endl;
    int t;
    cout<<"Enter 1 for player1 vs player2 game play <<<<<>>>>>> Enter any other number for palyer1 vs computer game play:"<<endl;
    cin>>t;

    // if user input 1 playing the player vs player and if any other number playing the player vs computer game
    if(t==1)
    {playerVSplayer();}
    else
    {playerVScomputer();}

    return 0;
}