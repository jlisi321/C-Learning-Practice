
#include <iostream>
using namespace std;


int main() {
    
    int number = 1;
    int iteration = 1;
    
    while(number != 5 && iteration <= 10){
        cout << "Enter any number other then 5!" << endl;
        cin >> number;
        
        iteration++;
    }
    
    if(number == 5){
        cout << "Hey you weren't supposed to enter 5!" << endl;
    }
    
    if(iteration == 11){
        cout << "Wow you're patient, you win!" << endl;
    }
    
    return 0;
}
