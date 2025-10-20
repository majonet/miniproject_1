#include <iostream>
#include <chrono>
#include "neworder.hpp"
using namespace std;
using namespace std::chrono;
int neworder::count = 0;
neworder::neworder(int std_num,string first_name,string last_name,vector<string> user_neworder)
{
    create_time = steady_clock::now();
    count++;
    this-> order_num=count;
    this-> std_num=std_num;
    this-> first_name=first_name;
    this-> last_name=last_name;
    this-> user_neworder=user_neworder;
    cout<< "your order created with count "<<order_num <<endl;
    cout << "\nYour order is: ";
    for (int i = 0; i < user_neworder.size(); i++)
        cout << user_neworder[i] << "--";
    cout << endl;

}
int neworder::Order_Delivered() {
        auto age = duration_cast<seconds>(steady_clock::now() - create_time).count();
        if (age<60){
            cout << "Your order is being prepared :time to Order_Deliver " << 60 - age << " seconds" << endl;
        }
        else{
            cout << "Your order is Delivered: time ago --> " << age - 60 << " seconds" << endl;
        }
        return age;
             
    }
neworder::~neworder()
{
    int age = Order_Delivered();
    if (age > 60){
        cout<<"your order is Delivered not can cancel this."<<endl;
    }
    else {
        cout << "your order is cancelled successfully." << endl;
        user_neworder.clear();
        count--;
    }
}
void neworder::Change_Order(int remove_index, string add_item) {
        if (remove_index >= 0 && remove_index < user_neworder.size() ) {
            cout << "Removed item at index " <<user_neworder[remove_index] << endl;
            user_neworder.erase(user_neworder.begin() + remove_index);
        } else {
            cout << "Index " << remove_index << " is invalid, nothing removed." << endl;
        }
        if (add_item !=""){
            user_neworder.push_back(add_item);
            cout << "Added item: " << add_item << endl;
        }
    }
int neworder::get_ordernum(){
    return order_num;
}
void neworder::Review() {
    cout << "\n==================== ORDER REVIEW ====================\n";
    cout << "Student Number: " << std_num << endl;
    cout << "Name: " << first_name << " " << last_name << endl;
    cout << "Order Number: " << order_num << endl;
    cout << "Items: ";
    for (auto &item : user_neworder)
        cout << item << " ";
    cout << endl;
    auto age = duration_cast<seconds>(steady_clock::now() - create_time).count();
    if (age < 60)
        cout << "Status: Being prepared (" << 60 - age << " seconds to deliver)" << endl;
    else
        cout << "Status: Delivered (" << age - 60 << " seconds ago)" << endl;

    cout << "=======================================================\n";
}
