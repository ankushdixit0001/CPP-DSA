#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name;
    string phoneNumber;

    // Open file in append mode
    ofstream out("text.txt", ios::app); 

    if (!out) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }
    char ch;
    do{
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter telephone number: ";
        cin >> phoneNumber;

        // Write name and phone number to the file
        out << name << " " << phoneNumber << endl;

        // Check if the write operation was successful
        if (out.fail()) {
            cerr << "Error writing to file" << endl;
            return 1;
        }
        cout << "Do you want to add more records? (y/n): ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');
    out.close();
    cout << "Data written to file successfully" << endl;

    return 0;
}