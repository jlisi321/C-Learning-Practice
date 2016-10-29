#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void printContactList(string contact[50]);
void addContact();
void openContact();
void deleteContact();
void editContact();

int main() {
    string contacts[50];
    char action;
    int loop = 1;
    
    while(loop == 1){
        
        printContactList(contacts);
        cout << "Action: ";
        cin >> action;
        
        if(action  == 'A' || action == 'a'){
            addContact();
        }
        else if(action == 'O' || action == 'o'){
            openContact();
        }
        else if(action == 'D' || action == 'd'){
            deleteContact();
        }
        else if(action == 'Q' || action == 'q'){
            loop = 2;
        }
        else if(action == 'E' || action == 'e'){
            editContact();
        }
        else {
            cout << "ERROR: Choose one of the options listed" << endl;
        }
    }
    
    return 0;
}

void printContactList(string contact[50]) {
    ifstream readContactFile;
    string line;
    readContactFile.open("contact.txt");
    
    cout << "\nContacts" << endl;
    
    
    int i = 0;
    if(readContactFile.is_open()){
        while (getline(readContactFile, contact[i])) {
            cout << contact[i] << endl;
            i++;
        }
        readContactFile.close();
    }
    else {
        cout << "Unable to open contacts" << endl;
    }
    
    cout << "\n- To add contact enter A" << endl;
    cout << "- To delete contact enter D" << endl;
    cout << "- To edit contact enter E" << endl;
    cout << "- To open up contact enter O" << endl;
    cout << "- To quit program enter Q" << endl;
}

void addContact(){
    cout << "\nContact Name: ";
    ofstream writeContactFile;
    writeContactFile.open("contact.txt", fstream::app);
    string contactName;
    getline(cin, contactName);
    getline(cin, contactName);
    writeContactFile << contactName << "\n";
    writeContactFile.close();
    
    string phoneNumber;
    string address;
    
    contactName = contactName + ".txt";
    
    writeContactFile.open(contactName);
    cout << "Phone Number: ";
    getline(cin, phoneNumber);
    writeContactFile << phoneNumber;
    
    cout << "Address: ";
    getline(cin, address);
    writeContactFile << "\n" << address;
    writeContactFile.close();

}

void openContact(){
    string name;
    string number;
    string address;
    string line;
    string fileName;
    int i = 1;
    cout << "Enter Name: ";
    getline(cin, name);
    getline(cin, name);
    
    fileName = name + ".txt";
    
    ifstream openContactData;
    openContactData.open(fileName);
    
    if(openContactData.is_open()){
        while (getline(openContactData, line)) {
            if(i == 1){
                number = line;
            }
            else if(i == 2){
                address = line;
            }
            
            i++;
        }
        
        cout << "\nContact: " << name << endl;
        cout << "Phone Number: " << number << endl;
        cout << "Address: " << address << endl;
    }
    else {
        cout << "Contact file couldn't be opened" << endl;
    }
    
    openContactData.close();
    
    char action;
    cout << "Enter M to go back to the menu" << endl;
    cout << "Action: ";
    cin >> action;
}

void deleteContact(){
    string contactName;
    string line;
    cout << "What contact would you like to delete?: ";
    getline(cin, contactName);
    getline(cin, contactName);
    
    string fileName = contactName + ".txt";
    
    ifstream readMyContacts;
    ofstream tempfile;
    readMyContacts.open("contact.txt");
    tempfile.open("temp.txt");
    
    while (getline(readMyContacts, line)) {
        if(line != contactName){
            tempfile << line << endl;
        }
    }
    
    cout << "This contact has been deleted" << endl;
    
    readMyContacts.close();
    tempfile.close();
    remove("contact.txt");
    remove(fileName.c_str());
    rename("temp.txt", "contact.txt");
}

void editContact(){
    string contactName;
    string fileName;
    int action;
    string line;
    cout << "What contact would you like to edit?: ";
    getline(cin, contactName);
    getline(cin, contactName);
    
    fileName = contactName + ".txt";
    
    ofstream writeFile;
    ifstream readFile;
    ofstream tempFile;
    cout << "1 - Change Name" << endl;
    cout << "2 - Change Phone Number" << endl;
    cout << "3 - Change Address" << endl;
    cout << "Action: ";
    cin >> action;
    
    
        if(action == 1){
            string newName;
            cout << "New Name: ";
            getline(cin, newName);
            getline(cin, newName);
    
            readFile.open("contact.txt");
            tempFile.open("temp.txt");
            
            if(readFile.is_open() && tempFile.is_open()){
                while (getline(readFile, line)) {
                    if(line != contactName){
                        tempFile << line << endl;
                    }
                    else if(line == contactName){
                        tempFile << newName << endl;
                    }
                }
            }
            else {
                cout << "ERROR: Couldn't open contacts" << endl;
            }

            readFile.close();
            tempFile.close();
            
            newName = newName + ".txt";
            
            remove("contact.txt");
            rename("temp.txt", "contact.txt");
            rename(fileName.c_str(), newName.c_str());
        }
        else if(action == 2){
            string newPhoneNumber;
            string address;
            string lineNumber;
            string lineAddress;
            
            cout << "New Phone Number: ";
            cin >> newPhoneNumber;
            
            readFile.open(fileName);
            
            if(readFile.is_open()){
                getline(readFile, address);
                getline(readFile, address);
            }
            else {
                cout << "ERRROR: Couldn't open " << fileName << endl;
            }
            readFile.close();
            
            tempFile.open("temp.txt");
            
            if(tempFile.is_open()){
                tempFile << newPhoneNumber << endl;
                tempFile << address << endl;
            }
            else {
                cout << "ERROR: Couldn't open a TEMP file";
            }
            
            tempFile.close();
            
            remove(fileName.c_str());
            rename("temp.txt", fileName.c_str());
            
            readFile.open(fileName);
            
            getline(readFile, lineNumber);
            getline(readFile, lineAddress);
            
            
            if(lineNumber == newPhoneNumber && lineAddress == address){
                cout << "Phone number has been successfully changed" << endl;
            }
            else if(lineNumber == newPhoneNumber && lineAddress != address){
                cout << "ERROR: Couldn't transfer address to new file" << endl;
            }
            else if(lineNumber != newPhoneNumber && lineAddress == address){
                cout << "ERROR: Couldn't put new phone number into new file" << endl;
            }
            else {
                cout << "ERROR: Both address and phone number couldn't be changed" << endl;
            }
            
            readFile.close();
            
        }
        else if(action == 3){
            string phoneNumber;
            string newAddress;
            string lineNumber;
            string lineAddress;
            
            cout << "New Address: ";
            cin >> newAddress;
            
            readFile.open(fileName);
            
            if(readFile.is_open()){
                getline(readFile, phoneNumber);
            }
            else {
                cout << "ERROR: Coudln't open " << fileName << endl;
            }
            
            readFile.close();
            
            tempFile.open("temp.txt");
            
            if(tempFile.is_open()){
                tempFile << phoneNumber << endl;
                tempFile << newAddress << endl;
            }
            else {
                cout << "ERROR: Couldn't open temp file" << endl;
            }
            
            tempFile.close();
            
            remove(fileName.c_str());
            rename("temp.txt", fileName.c_str());
            
            readFile.open(fileName);
            
            getline(readFile, lineNumber);
            getline(readFile, lineAddress);
            
            
            if(lineNumber == phoneNumber && lineAddress == newAddress){
                cout << "Address has been successfully changed" << endl;
            }
            else if(lineNumber == phoneNumber && lineAddress != newAddress){
                cout << "ERROR: Couldn't put new address to new file" << endl;
            }
            else if(lineNumber != phoneNumber && lineAddress == newAddress){
                cout << "ERROR: Couldn't put phone number into new file" << endl;
            }
            else {
                cout << "ERROR: Both address and phone number couldn't be changed" << endl;
            }
            
            readFile.close();
            
        }
        else {
            cout << "ERROR: Pick one of the options listed" << endl;
        }
}