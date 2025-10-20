#include "node.hpp"
#include <iostream>
using namespace std;

Node::Node(int std_num, string first_name, string last_name, vector<string> user_neworder) {
    data = new neworder(std_num, first_name, last_name, user_neworder);
    prev = nullptr;
    next = nullptr;
}

Node::~Node() {
    int val;
    val=data->Order_Delivered();
    if (val>60){
            cout << "Node not change " << endl;
        }
    else{  
          cout << "delete node"<< endl;
          delete data;
    }
}

