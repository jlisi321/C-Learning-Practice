#include <iostream>

using namespace std;

int menu();
void printWord(string correct_Word[20], int check_Letter[20]);

int main() {
    cout << "  HANG MAN " << endl;
    
    string correctWord[20] = {"a", "r", "s", "e", "n", "a", "l"};
    int checkLetter[20] = {0, 0, 0, 0, 0, 0, 0, 0};
    int menuChoice = menu();
    
    // WHEN THE USER DOESN'T ENTER ONE OF THE OPTIONS LISTED
    while(menuChoice == 0){
        cout << "ERROR: Choose one of the options listed" << endl;
        menu();
    }
    
    // WHEN THE GAME IS OPEN
    while(menuChoice != 2){
        printWord(correctWord, checkLetter);
        cin >> correctWord[20];
    }
    
    return 0;
}

int menu(){
    cout << "\n- Press 1 to play" << endl;

    cout << "- Press 2 to quit" << endl;
    
    int action;
    
    cout << "Action: ";
    cin >> action;
    
    if(action == 1){
        return 1;
    }
    else if(action == 2){
        return 2;
    }
    
    return 0;
}

void printWord(string correct_Word[20], int check_Letter[20]){
    for (int i = 0; i <= 20; i++) {
        if(check_Letter[i] == 1){
            cout << correct_Word[i] << " ";
        }
    }
    
    for (int i = 0; i <= 6; i++) {
        cout << "_" << " ";
    }
}