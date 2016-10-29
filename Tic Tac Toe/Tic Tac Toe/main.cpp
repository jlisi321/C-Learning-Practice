#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    void printboard(char gameboard[9]);
    void playerone(char gameboard[9]);
    void playertwo(char gameboard[9]);
    void computer(char gameboard[9]);
    int winCheck(char gameboard[9], int opponent);
    
    char playagain = 'y';
    int opponent = 0;
    
    while(playagain == 'y'){
    char gameboard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    cout << "\n\nTic Tac Toe" << endl;
    cout << "Play against a computer(1) or player(2)" << endl;
    cin >> opponent;
        
    int winner = 0;
    
    while(winner != 1 && winner != 2){
        
        if(winner != 1 && winner != 2){
            printboard(gameboard);
            playerone(gameboard);
        }
        
        winner = winCheck(gameboard, opponent);
        
        
        if(winner != 1 && winner != 2 && opponent == 2){
            printboard(gameboard);
            playertwo(gameboard);
        }
        else if(winner != 1 && winner != 2 && opponent == 1){
            computer(gameboard);
        }
        
        winner = winCheck(gameboard, opponent);
        
    }
        cout << "Want to play another game?(y/n)" << endl;
        cin >> playagain;
    }
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}

void printboard(char gameboard[9]) {
    
    cout << "\n\nPlayer 1 (X) - Player 2 (O)" << endl;
    cout << "     :     :     " << endl;
    cout << "  " << gameboard[0] << "  :  " << gameboard[1] << "  :  " << gameboard[2] << "  " << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  " << gameboard[3] << "  :  " << gameboard[4] << "  :  " << gameboard[5] << "  " << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  " << gameboard[6] << "  :  " << gameboard[7] << "  :  " << gameboard[8] << "  " << endl;
    cout << "     :     :     " << endl;
}

void playerone(char gameboard[9]){
    int choice;
    cout << "Player 1, enter a number: " << endl;
    cin >> choice;
    
    if(choice == 1){
        gameboard[0] = 'X';
    }
    else if(choice == 2){
        gameboard[1] = 'X';
    }
    else if(choice == 3){
        gameboard[2] = 'X';
    }
    else if(choice == 4){
        gameboard[3] = 'X';
    }
    else if(choice == 5){
        gameboard[4] = 'X';
    }
    else if(choice == 6){
        gameboard[5] = 'X';
    }
    else if(choice == 7){
        gameboard[6] = 'X';
    }
    else if(choice == 8){
        gameboard[7] = 'X';
    }
    else if(choice == 9){
        gameboard[8] = 'X';
    }
}


void playertwo(char gameboard[9]){
    int choice;
    cout << "Player 2, enter a number: " << endl;
    cin >> choice;
    
    if(choice == 1){
        gameboard[0] = 'O';
    }
    else if(choice == 2){
        gameboard[1] = 'O';
    }
    else if(choice == 3){
        gameboard[2] = 'O';
    }
    else if(choice == 4){
        gameboard[3] = 'O';
    }
    else if(choice == 5){
        gameboard[4] = 'O';
    }
    else if(choice == 6){
        gameboard[5] = 'O';
    }
    else if(choice == 7){
        gameboard[6] = 'O';
    }
    else if(choice == 8){
        gameboard[7] = 'O';
    }
    else if(choice == 9){
        gameboard[8] = 'O';
    }
}

void computer(char gameboard[9]){
    srand (time(NULL));
    
    int loop = 0;
    
    while(loop == 0){
        int choice = rand() % 8 + 0;
        
        if(choice == 1){
            if(gameboard[0] != 'X' && gameboard[0] != 'O'){
                gameboard[0] = 'O';
                loop = 1;
            }
        }
        else if(choice == 2){
            if(gameboard[1] != 'X' && gameboard[1] != 'O'){
                gameboard[1] = 'O';
                loop = 1;
            }
        }
        else if(choice == 3){
            if(gameboard[2] != 'X' && gameboard[2] != 'O'){
                gameboard[2] = 'O';
                loop = 1;
            }
        }
        else if(choice == 4){
            if(gameboard[3] != 'X' && gameboard[3] != 'O'){
                gameboard[3] = 'O';
                loop = 1;
            }
        }
        else if(choice == 5){
            if(gameboard[4] != 'X' && gameboard[4] != 'O'){
                gameboard[4] = 'O';
                loop = 1;
            }
        }
        else if(choice == 6){
            if(gameboard[5] != 'X' && gameboard[5] != 'O'){
                gameboard[5] = 'O';
                loop = 1;
            }
        }
        else if(choice == 7){
            if(gameboard[6] != 'X' && gameboard[6] != 'O'){
                gameboard[6] = 'O';
                loop = 1;
            }
        }
        else if(choice == 8){
            if(gameboard[7] != 'X' && gameboard[7] != 'O'){
                gameboard[7] = 'O';
                loop = 1;
            }
        }
        else if(choice == 9){
            if(gameboard[8] != 'X' && gameboard[8] != 'O'){
                gameboard[8] = 'O';
                loop = 1;
            }
        }
    }
}

int winCheck(char gameboard[9], int opponent){
    void printboard(char gameboard[9]);
    
    
    if(gameboard[0] == 'X' && gameboard[1] == 'X' && gameboard[2] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    else if(gameboard[3] == 'X' && gameboard[4] == 'X' && gameboard[5] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    else if(gameboard[6] == 'X' && gameboard[7] == 'X' && gameboard[8] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    else if(gameboard[0] == 'X' && gameboard[3] == 'X' && gameboard[6] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    else if(gameboard[1] == 'X' && gameboard[4] == 'X' && gameboard[7] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    else if(gameboard[2] == 'X' && gameboard[5] == 'X' && gameboard[8] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    else if(gameboard[0] == 'X' && gameboard[4] == 'X' && gameboard[8] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    else if(gameboard[2] == 'X' && gameboard[4] == 'X' && gameboard[6] == 'X'){
        printboard(gameboard);
        cout << "Player 1 has won!" << endl;
        return 1;
    }
    
    if(gameboard[0] == 'O' && gameboard[1] == 'O' && gameboard[2] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    else if(gameboard[3] == 'O' && gameboard[4] == 'O' && gameboard[5] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    else if(gameboard[6] == 'O' && gameboard[7] == 'O' && gameboard[8] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    else if(gameboard[0] == 'O' && gameboard[3] == 'O' && gameboard[6] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    else if(gameboard[1] == 'O' && gameboard[4] == 'O' && gameboard[7] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    else if(gameboard[2] == 'O' && gameboard[5] == 'O' && gameboard[8] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    else if(gameboard[0] == 'O' && gameboard[4] == 'O' && gameboard[8] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    else if(gameboard[2] == 'O' && gameboard[4] == 'O' && gameboard[6] == 'O'){
        printboard(gameboard);
        if(opponent == 1){
            cout << "The computer has beat you";
        }
        else if(opponent == 2){
            cout << "Player 2 has won!" << endl;
        }
        return 2;
    }
    
    return 0;
}

