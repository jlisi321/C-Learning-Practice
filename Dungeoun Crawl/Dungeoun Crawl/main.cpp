#include <iostream>
using namespace std;

int main() {
    void printboard(char gameboard[7][10]);
    void movePlayer(char gameboard[7][10], int x, int y);
    int gameOver(char gameboard[7][10]);
    
    char gameboard[7][10] = {{'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','T','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','T','.','.','.','.','.'},
        {'.','.','.','.','.','.','T','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','X'},};
    
    int game_Over = 0;
    int x = 0;
    int y = 1;
    
    cout << "Instructions: Your player is equal to 'G'. To move your player, use WASD. Make sure to not hit any of the bombs, the bombs are represented with 'T'. To beat the game move your player all the way to 'X'. Good luck!\n" << endl;
    
    while(game_Over == 0){
        movePlayer(gameboard, x, y);
        printboard(gameboard);
        game_Over = gameOver(gameboard);
    }
    
    if (game_Over == 1) {
        cout << "You blew up!" << endl;
    }
    
    return 0;
}

void printboard(char gameboard[7][10]){
    
    for (int i = -1; i <= 9; i++) {
        cout << gameboard[0][i];
    }
    cout << endl;
    
    for (int i = -1; i <= 9; i++) {
        cout << gameboard[1][i];
    }
    cout << endl;
    
    for (int i = -1; i <= 9; i++) {
        cout << gameboard[2][i];
    }
    cout << endl;
    
    for (int i = -1; i <= 9; i++) {
        cout << gameboard[3][i];
    }
    cout << endl;
    
    for (int i = -1; i <= 9; i++) {
        cout << gameboard[4][i];
    }
    cout << endl;
    
    for (int i = -1; i <= 9; i++) {
        cout << gameboard[5][i];
    }
    cout << endl;
    
    for (int i = -1; i <= 9; i++) {
        cout << gameboard[6][i];
    }
    cout << endl;
}

void movePlayer(char gameboard[7][10], int x, int y){
    char choice;
    
    
    cout << "Move(WASD): ";
    cin >> choice;
    
    if(choice == 'W' || choice == 'w'){
        y--;
    }
    else if(choice == 'S' || choice == 's'){
        y++;
    }
    else if(choice == 'A' || choice == 'a'){
        x--;
    }
    else if(choice == 'D' || choice == 'd'){
        x++;
    }
    
    
    gameboard[y][x] = 'G';
}

int gameOver(char gameboard[7][10]){
    if(gameboard[2][6] == 'G'){
        return 1;
    }
    else if(gameboard[4][4] == 'G'){
        return 1;
    }
    else if(gameboard[5][7] == 'G'){
        return 1;
    }
    else {
        return 0;
    }
}
