#include "linklist.hpp"
// #include <iostream>
// #include <vector>
#include <thread>
// #include <chrono>
// #include <limits>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstddef> 
#include <iomanip>
// using namespace std;
LinkedList list1;
void order(int std_num,string name,string last_name,vector<string> items){
        list1.addorder(std_num,name,last_name,items);
    }
string get_name() {
    string name;
    cout << "Please enter your name (3–20 letters): ";
    cin >> name;
    
}
int get_std_id(){
    cout << "Please enter your student ID: (your student ID should be 4 valid digit)  ";
    int st_num=0;
    cin>> st_num;
    if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "❌ Invalid input! Please enter numbers only.\n\n";
            return get_std_id(); // ask again
        }
    if (st_num >= 1000 && st_num <= 9999) {
        cout << " Student ID accepted!\n\n"; 
        return st_num;
    } 
    else {
            cout << "❌ Student ID must be exactly 4 digits. Try again.\n\n";
            return get_std_id();
        }
    }
struct MenuItem {
    string category;
    string name;
    double price;
};
vector<MenuItem> menu = {
    {"Appetizer", "Mirza Ghasemi", 6.00},
    {"Appetizer", "Kashk-e Bademjan", 5.50},
    {"Food", "Chelo Kabab", 14.00},
    {"Food", "Ghormeh Sabzi", 12.50},
    {"Food", "Fesenjan", 13.00},
    {"Drink", "Doogh", 2.00},
    {"Drink", "Saffron Tea", 2.50},
    {"Drink", "Pomegranate Juice", 3.50}
};
void showMenuOptions() {
    cout << "=========================================\n";
    cout << " 🍽️  Welcome to My Restaurant 🍹\n";
    cout << "=========================================\n";
    cout << " 1️⃣  Show Menu\n";
    cout << " 2️⃣  New Order\n";
    cout << " 3️⃣  Change Order\n";
    cout << " 4️⃣  Order Delivered\n";
    cout << " 5️⃣  Cancel Order\n";
    cout << " 0️⃣  Exit\n";
    cout << "-----------------------------------------\n";
    cout << "👉 Please enter your choice (0-5): ";
}

void sleep2seconds() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void showMenu(vector<MenuItem> menu) {
    cout << "\n=========== 📜 Restaurant Menu ===========\n";
    cout << left << setw(15) << "Category"
         << setw(25) << "Item"
         << right << "Price ($)" << endl;
    cout << "-------------------------------------------\n";

    for ( auto& item : menu) {
        cout << left << setw(15) << item.category
             << setw(25) << item.name
             << right << fixed << setprecision(2) << item.price << endl;
    }
    sleep2seconds();
    cout << "===========================================\n\n";
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    bool run_resturn=true;
    string user_choice;
    int choice;

    while (true) {
        showMenuOptions();

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n❌ Invalid input! Please enter a number between 0 and 5.\n\n";
            continue;
        }

        cout << endl;

        switch (choice) {
            case 1:
                cout << "📜 Showing the menu...\n\n";
                showMenu(menu);
                cout << "Press Enter to return to the main page...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cin.get();// get enter
                system("cls");
                break;
            case 2:
                int std_id=get_std_id();
                cout << "what is your firs name ? \n\n";

                cout << "🍽️  Garson is here! What do you need? 🍹\n\n";
                // order();
                break;
            case 3:
                cout << "✏️ Changing your order...\n\n";
                break;
            case 4:
                cout << "🚚 Your order has been delivered!\n\n";
                break;
            case 5:
                cout << "❌ Order canceled.\n\n";
                break;
            case 0:
                cout << "👋 Thank you for visiting! Goodbye!\n";
                return 0;
            default:
                cout << "⚠️  Invalid option! Try again.\n\n";
        }
    }
    return 0;
 } 