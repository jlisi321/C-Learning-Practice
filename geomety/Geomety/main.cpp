#include <iostream>
using namespace std;

int main() {
    char action;
    cout << "Are you entering radius(R), diameter(D), or area(A) of the circle?" << endl;
    cout << "Enter: ";
    cin >> action;
    
    int radius = 0;
    int diameter = 0;
    int area = 0;
    
    if(action == 'R' || action == 'r'){
        cout << "Enter radius: ";
        cin >> radius;
    }
    else if(action == 'D' || action == 'd'){
        cout << "Enter diameter: ";
        cin >> diameter;
    }
    else if(action  == 'A' || action == 'a'){
        cout << "Enter area: ";
        cin >> area;
    }
    else {
        cout << "ERROR: Invalid action" << endl;
    }
    
    if(radius > 0){
        diameter = radius * 2;
        area = diameter * 3.14;
    }
    else if(diameter > 0){
        radius = diameter / 2;
        area = radius * 3.14;
    }
    else if(area > 0){
        diameter = area / 3.14;
        radius = diameter / 2;
    }
    else {
        cout << "ERROR: Couldn't complete math" << endl;
    }
    
    if(radius > 0 && diameter > 0 && area > 0){
        cout << "Radius = " << radius << endl;
        cout << "Diamter = " << diameter << endl;
        cout << "Area = " << area << endl;
    }
    else {
        cout << "ERROR: Couldn't complete math" << endl;
    }
    
    return 0;
}
