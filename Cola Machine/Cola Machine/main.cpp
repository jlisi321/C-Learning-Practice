#include <string>
#include <iostream>
using namespace std;

int main() {
    
    int choice;
    
    cout << "Sprite(1) Coca Cola(2) Dr Pepper(3) Orange Crush(4) Lemonade (5)" << endl;
    cout << "What beverage would you like?(Choose by number)" << endl;
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "You choose sprite!" << endl;
            break;
        case 2:
            cout << "You choose Coca Cola!" << endl;
            break;
        case 3:
            cout << "You choose Dr Pepper!" << endl;
            break;
        case 4:
            cout << "You choose Orange Crush!" << endl;
            break;
        case 5:
            cout << "You chhoose Lemonade!" << endl;
            break;
            
        default:
            cout << "Error, invalid option." << endl;
            break;
    }
    
    
    return 0;
}
