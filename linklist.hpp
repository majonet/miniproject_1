#pragma once
#include "node.hpp"
class LinkedList {
private:
    Node* head;
    Node* tail;
    const int id;
    static int counter;
public:
    LinkedList();    
    ~LinkedList();    

    void addorder(int std_num,string first_name,string last_name,vector<string> user_neworder);
    void printall() const;
    Node* search(int se);
};
