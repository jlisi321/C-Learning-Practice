
#include <iostream>
using namespace std;

int main() {
    
    int factorial;
    int answer;
    
    cout << "Choose a number: ";
    cin >> factorial;
    
    answer = factorial;
    
    while(factorial > 1){
        answer = answer * (factorial - 1);
        factorial --;
    }
    
    cout << answer << endl;
    
    return 0;
}
