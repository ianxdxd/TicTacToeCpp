#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char board[3][3] =      {{'-', '-', '-'},
                        {'-', '-' , '-'},
                        {'-', '-' , '-'}};
int row = 0;
int col = 0;
char currentPlayer = 'X';
string winner = "none";

void outputBoard() {


    //output the board
    cout << "---" << "---" << "---" << endl;
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---" << "---" << "---" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---" << "---" << "---" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "---" << "---" << "---" << endl;

}

// get the player's input values between 1-9 and then
// transform them to rows and columns values
void getPlayerInput() {

    int value = 0;
    if(currentPlayer == 'X'){
        cout << currentPlayer << " enter your value:" << endl;
        cin >> value;
    }else if(currentPlayer == 'O'){
        cout << currentPlayer << " enter your value:" << endl;
        cin >> value;
    }

    while(value < 1 || value > 9){
        if(!cin.good()){
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "invalid value" << endl;
        cout << "Please enter a new one: " << endl;
        cin >> value;
    }


    if(value == 1){
        row = 0;
        col = 0;
    }else if(value == 2){
        row = 0;
        col = 1;
    }else if(value == 3){
        row = 0;
        col = 2;

    }else if(value == 4){
        row = 1;
        col = 0;
    }else if(value == 5){
        row = 1;
        col = 1;

    }else if(value == 6){
        row = 1;
        col = 2;

    }else if(value == 7){
        row = 2;
        col = 0;

    }else if(value == 8){
        row = 2;
        col = 1;

    }else if(value == 9){
        row = 2;
        col = 2;

    }

    if(currentPlayer == 'X' && board[row][col] != 'X' && board[row][col] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][col] = 'X';
    }else if(currentPlayer == 'O' && board[row][col] != 'X' && board[row][col] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][col] = 'O';
    }else {
        //if input position already filled
        cout << "Box already filled! Please choose another one!";
        getPlayerInput(); //ask for the input again.
    }


}

// switch the one who is playing
char switchPlayer(){

    if(currentPlayer == 'X'){
        currentPlayer = 'O';
    }else {
        currentPlayer = 'X';
    }

    return currentPlayer;
}

//check if the player choice is correct

bool checkHorizontal(){

    if(board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != '-'){
        winner = board[0][0];
        return true;
    }else if(board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != '-'){
        winner = board[1][0];
        return true;
    }else if(board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != '-'){
        winner = board[2][0];
        return true;
    }

    return false;
}

bool checkVertical(){

    if(board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != '-'){
        winner = board[0][0];
        return true;
    }else if(board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != '-'){
        winner = board[0][1];
        return true;
    }else if(board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != '-'){
        winner = board[0][2];
        return true;
    }

    return false;
}

bool checkDiagonal(){

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-'){
        winner = board[0][0];
        return true;
    }else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-'){
        winner = board[0][2];
        return true;
    }

    return false;
}

bool checkTie(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '-'){ // if there isn't a tie, then there will be tiles on the board.
                return false;
            }
        }
    }

    return true;
}

bool checkWinner(){

    if(checkHorizontal() || checkVertical() || checkDiagonal()){
        cout << " The winner is " << winner << endl;
        return true;
    }

    return false;
}

//Gather everything to execute the game.
//Main function
int main(){

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1: X" << endl;
    cout << "Player 2: O" << endl;

    while(!checkWinner()){
        outputBoard();
        getPlayerInput();
        if(checkWinner()){
            break;
        }
        if(checkTie()){
            cout << "It's a draw!" << endl;
            break;
        }

        system("cls"); // clear the console

        //second player.
        switchPlayer();
        outputBoard();
        if(checkWinner()){
            break;
        }
        if(checkTie()){
            cout << "It's a draw!" << endl;
            break;
        }

        system("cls"); // clear the console again

    }

    return 0;
}
