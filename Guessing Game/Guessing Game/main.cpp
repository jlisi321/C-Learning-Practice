#include <cstdlib>
#include <iostream>

using namespace std;

void UserGuessesNumber();
void ComputerGuessesNumber();

int main() {
    
    int choice;
    
    cout << "Would you like to guess the random number(1) or have your number guessed(2)?" << endl;
    
    cin >> choice;
    
    if(choice == 1){
        UserGuessesNumber();
    }
    else if(choice == 2){
        ComputerGuessesNumber();
    }
    

    
    return 0;
}

void UserGuessesNumber(){
    int answer = -1;
    int randomnumber = rand() % 100 + 1;
    int guesses = 0;
    
    
    while (answer != randomnumber) {
        cout << "Guess: ";
        cin >> answer;
        
        if(answer != randomnumber){
            if(answer < randomnumber){
                cout << "You guessed too low!" << endl;
            }
            else if(answer > randomnumber){
                cout << "You guessed too high!" << endl;
            }
            guesses ++;
        }
    }
    
    cout << "You won the game in " << guesses << " trys!" << endl;
}

void ComputerGuessesNumber(){
    
    int number = 0;
    int HighOrLow = 0;
    int UpperLim = 100;
    int LowerLim = 1;
    int computerguess;
    int i = 0;
    
    cout << "Enter your number between 1-100: ";
    cin >> number;

    do{
        i++;
        computerguess = rand() % (UpperLim - LowerLim) + LowerLim;
        
        if(computerguess == number){
            cout << "The computer has guessed " << number << "!" << endl;
            break;
        }
        
        cout << "Is " << computerguess << " too high(1) or low(2)?" << endl;
        cin >> HighOrLow;
        
        
        if(HighOrLow == 1){
            UpperLim = computerguess;
        }
        else if(HighOrLow == 2){
            LowerLim = computerguess;
        }
        
        
    }while(computerguess != number);
    
    cout << "The computer has won! It took " << i << " tries." << endl;
    
}