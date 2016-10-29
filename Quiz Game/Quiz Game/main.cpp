#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

char startMenu();
void questionDataBase(int questionNumber);
int pointDataBase(int questionNumber, char questionAnswer);
char helpScreen();
void highScore(int points);


int main() {
    
    int points = 0;
    char answer = 'A';
    char start_menu_response;
    
    do {
        start_menu_response = startMenu();
        if(start_menu_response == 'S'){
            points = 0;
            int questionNumber = 1;
            while (questionNumber <= 5) {
                questionDataBase(questionNumber);
                cout << "Answer: ";
                cin >> answer;
                points = points + pointDataBase(questionNumber, answer);
                questionNumber++;
                
                if(answer == 'Q' || answer == 'q'){
                    start_menu_response = 'Q';
                    break;
                }
                else if(answer == 'M' || answer == 'm'){
                    break;
                }
            }
            
            if(answer != 'Q' && answer != 'q' && answer != 'M' && answer != 'm'){
                cout << "\n\n                                                         Score                 " << endl;
                cout << "                                        ***************************************" << endl;
                cout << "                                                         " << points << endl;
                cout << "                                        ***************************************\n\n" << endl;
            }
        
        }
        else if(start_menu_response == 'Q'){
            break;
        }
        else if(start_menu_response == 'H'){
            if(helpScreen() == 'Q'){
                break;
            }
        }
        else if(start_menu_response == 'J'){
            highScore(points);
        }
        else {
            cout << "ERROR" << endl;
        }
        
    } while(start_menu_response != 'Q' && start_menu_response != 'q');
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}

char startMenu(){
    char menuChoice;
    
    cout << "                                                       QUIZ GAME" << endl;
    cout << "                                        ______________________________________" << endl;
    cout << "                                                  WELCOME TO THE GAME" << endl;
    cout << "                                        ______________________________________\n" << endl;
    
    cout << "                                         > Enter S to start the game" << endl;
    cout << "                                         > Enter Q to quit" << endl;
    cout << "                                         > Enter H for help" << endl;
    cout << "                                         > Enter J for high score" << endl;
    cout << "                                         > Enter: ";
    cin >> menuChoice;
    
    
    if (menuChoice == 'S' || menuChoice == 's') {
        return 'S';
    }
    else if(menuChoice == 'Q' || menuChoice == 'q'){
        return 'Q';
    }
    else if(menuChoice == 'H' || menuChoice == 'h'){
        return 'H';
    }
    else if(menuChoice == 'J' || menuChoice == 'j'){
        return 'J';
    }
    
    return 'E';
}

void questionDataBase(int questionNumber){
    
    if (questionNumber == 1) {
        cout << "\n\nWho is Arsenal's manager?\n" << endl;
        cout << "A. Pep Guardiola                 B. Roberto Manchini\n" << endl;
        cout << "C. Arsene Wenger                 D. Zinidine Zidane\n" << endl;
    }
    else if(questionNumber == 2) {
        cout << "\n\nWho is Arsenal's best goalie?\n" << endl;
        cout << "A. Petr Cech                 B. Diego Lopez\n" << endl;
        cout << "C. Joe Hart                  D. Aaron Ramsey\n" << endl;
    }
    else if(questionNumber == 3){
        cout << "\n\nWhat position does Oliver Giroud play?\n" << endl;
        cout << "A. Goalie                  B. Center Attacking Midfield\n" << endl;
        cout << "C. Striker                 D. Right Winger\n" << endl;
    }
    else if(questionNumber == 4){
        cout << "\n\nWhat player from Arsenal got in the PFA team of the year during 2015/2016?\n" << endl;
        cout << "A. Mesut Ozil                 B. Santi Cazorla\n" << endl;
        cout << "C. Petr Cech                  D. Hector Bellerin\n" << endl;
    }
    else if(questionNumber == 5){
        cout << "\n\nWhat player is from Germany on Arsenal?\n" << endl;
        cout << "A. Mesut Ozil                    B. Laurent Koscielny\n" << endl;
        cout << "C. Danny Welbeck                 D. Nacho Monreal\n" << endl;
    }
    
};

int pointDataBase(int questionNumber, char questionAnswer){
    if(questionNumber == 1){
        if(questionAnswer == 'C' || questionAnswer == 'c'){
            return 100;
        }
    }
    else if(questionNumber == 2){
        if(questionAnswer == 'A' || questionAnswer == 'a'){
            return 100;
        }
    }
    else if(questionNumber == 3){
        if(questionAnswer == 'C' || questionAnswer == 'c'){
            return 100;
        }
    }
    else if(questionNumber == 4){
        if(questionAnswer == 'D' || questionAnswer == 'd'){
            return 100;
        }
    }
    else if(questionNumber == 5){
        if(questionAnswer == 'A' || questionAnswer == 'a'){
            return 100;
        }
    }
    
    return 0;
}

char helpScreen(){
    char menu;
    
    cout << "\n\n                                        ***************************************" << endl;
    cout << "                                         Quiz game is a game that tests your" << endl;
    cout << "                                         knowledge on Arsenal. When asked a" << endl;
    cout << "                                         question just type in one of the " << endl;
    cout << "                                         letters that correspond to an answer." << endl;
    cout << "                                         Follow that up by hitting enter." << endl;
    cout << "                                         To go back to the menu Enter M, this" << endl;
    cout << "                                         works mid game as well. Good luck " << endl;
    cout << "                                         and have fun!" << endl;
    cout << "                                        ***************************************" << endl;
    cout << "                                        Enter: ";
    cin >> menu;
    cout << "\n\n";
    
    if(menu == 'Q' || menu == 'q'){
        return 'Q';
    }
    
    return 'M';
}

void highScore(int points){
    int high_score;
    string name;
    string line;
    ifstream readFile;
    ofstream writeFile;
    readFile.open("highscore.txt");
    
    readFile >> high_score >> name;
    
    if(points > high_score){
        high_score = points;
        
        cout << "\n\n                                              First Name: ";
        cin >> name;
    }
    
    readFile.close();
    
    writeFile.open("highscore.txt");
    
    writeFile << high_score << name;
    
    writeFile.close();
    
    cout << "\n\n                                                        HIGH SCORE" << endl;
    cout << "                                        ***************************************" << endl;
    cout << "                                                          " << name << endl;
    cout << "                                                           " << high_score << endl;;
    cout << "                                        ***************************************\n\n" << endl;
}

