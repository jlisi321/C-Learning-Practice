#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test_score=0;
    char repeat = 'y';
    
    while (repeat == 'y') {
        cout << "What was your test score?" << endl;
        cin >> test_score;
        
    if (test_score == 100) {
        cout << "You got a perfect score!" << endl;
    }
    else if(test_score < 100 && test_score >= 93){
        cout << "You got an A!" << endl;
    }
    else if(test_score <= 92 && test_score >= 90){
        cout << "You got an A-!" << endl;
    }
    else if(test_score <= 89 && test_score >= 87){
        cout << "You got a B+!" << endl;
    }
    else if(test_score <= 86 && test_score >= 84){
        cout << "You got a B!" << endl;
    }
    else if(test_score <= 83 && test_score >= 80){
        cout << "You got a B-!" << endl;
    }
    else if(test_score <= 79 && test_score >= 77){
        cout << "You got a C+!" << endl;
    }
    else if(test_score <= 76 && test_score >= 74){
        cout << "You got a C!" << endl;
    }
    else if(test_score <= 73 && test_score >= 70){
        cout << "You got a C-!" << endl;
    }
    else if(test_score <= 69 && test_score >= 67){
        cout << "You got a D+!" << endl;
    }
    else if(test_score <= 66 && test_score >= 64){
        cout << "You got a D!" << endl;
    }
    else if(test_score <= 63 && test_score >= 60){
        cout << "You got a D-!" << endl;
    }
    else if(test_score <= 59){
        cout << "You got a F, call your self smiggs!" << endl;
    }
    else{
        cout << "You didn't enter a valid score." << endl;
    }
        
        cout << "Do you want to put in another test score?(y/n):" << endl;
        cin >> repeat;
        
    }
    
    cout << "Thanks for using my program!" << endl;
    
    return 0;
}
