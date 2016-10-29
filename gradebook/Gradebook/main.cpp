#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Stating variables
    string student_Name;
    int test;
    int homework;
    int projects;
    int overall_weighted_grade = (.50 * test) + (.15 * homework) + (projects * .35);
    
    // Getting Data
    cout << "------- Grade Book --------" << endl;
    cout << "Enter Students Name: ";
    cin >> student_Name;
    
    cout << "Tests: ";
    cin >> test;
    cout << "Homework: ";
    cin >> homework;
    cout << "Projects: ";
    cin >> projects;
    
    cout << "Overall Weighted Grade: " << overall_weighted_grade;
    
    
    
    
    return 0;
}

