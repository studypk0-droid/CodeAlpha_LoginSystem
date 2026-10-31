#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password, u, p;
    cout << "\n--- REGISTER NEW USER ---\n";
    cout << "Enter username: ";
    cin >> username;

    // Check if username already exists in file
    ifstream read("users.txt");
    bool exists = false;
    while (read >> u >> p) {
        if (u == username) {
            exists = true;
            break;
        }
    }
    read.close();

    if (exists) {
        cout << "Error: Username pehle se maujood hai! Koi aur username try karein.\n";
        return;
    }

    // Take password and store securely in file
    cout << "Enter password: ";
    cin >> password;

    ofstream write("users.txt", ios::app);
    write << username << " " << password << endl;
    write.close();

    cout << "Success: Registration kamyaab ho gayi hai!\n";
}

// Function to login an existing user
void loginUser() {
    string username, password, u, p;
    cout << "\n--- USER LOGIN ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Verify credentials from file
    ifstream read("users.txt");
    bool found = false;
    while (read >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    read.close();

    if (found) {
        cout << "Success: Login kamyaab! Khush amdeed, " << username << "!\n";
    } else {
        cout << "Error: Ghalat username ya password darj kiya gaya hai!\n";
    }
}

// Main menu function
int main() {
    int choice;
    do {
        cout << "\n==============================\n";
        cout << "   LOGIN & REGISTRATION SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Apni choice enter karein (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Program exit ho raha hai. Allah Hafiz!\n";
                break;
            default:
                cout << "Ghalat choice! Dobara koshish karein.\n";
        }
    } while (choice != 3);

    return 0;
}