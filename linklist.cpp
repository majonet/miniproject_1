#include "linklist.hpp"
#include <iostream>
using namespace std;
#include <fstream>
int LinkedList::counter = 0;

LinkedList::LinkedList() : id(++counter) {
    head = nullptr;
    tail = nullptr;
    cout << "ID" << id << endl;
}

LinkedList::~LinkedList() {
    Node* current = head;
    int val;
    val=current->data->Order_Delivered();
    if (val<60){
            cout << "Node not change " << endl;
        }
    else{
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    counter--;
    cout << "node" << id << " deleted." << endl;}

}

void LinkedList::addorder(int std_num,string first_name,string last_name,vector<string> user_neworder) {
    Node* newNode = new Node(std_num, first_name,last_name,user_neworder);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
Node* LinkedList::search(int se) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->get_ordernum() == se) {
            current->data->Review();
            cout << endl;
            return current;  // return the found node
        }
        current = current->next;
    }
    cout << "❌ No order found for ID " << se << endl;
    return nullptr;
}
void LinkedList::printall() const {
    Node* current = head;

    if (!current) {
        cout << "📭 The list is empty.\n";
        return;
    }

    cout << "🧾 List ID = " << id << ":\n";
    cout << "--------------------------------\n";

    while (current != nullptr) {
        current->data->Review(); 
        current = current->next;
    }

    cout << "--------------------------------\n";
}
