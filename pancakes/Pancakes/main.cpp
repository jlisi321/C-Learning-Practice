#include <iostream>
using namespace std;

int main() {

    int person[4];
    int max = 0;
    int min = 0;
    
    for(int i = 1; i < 6; i++){
        cout << "What did person " << i << " eat?" << endl;
        cin >> person[i - 1];
    }
    
    for (int i = 1; i < 5; i++) {
        if(person[max] < person[i]){
            max = i;
        }
        if(person[min] > person [i]){
            min = i;
        }
    }
    
    cout << "Person " << max + 1 << " ate the most pancakes!" << endl;
    cout << "Person " << min + 1 << " at the least amount of pancakes!" << endl;
    
    
    return 0;
}
