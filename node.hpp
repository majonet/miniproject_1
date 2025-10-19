#include "neworder.hpp"
class Node{
  public: 
    neworder* data;
    Node* next;
    Node* prev;
    
    Node(int std_num, string first_name, string last_name, vector<string> user_neworder); 
    ~Node();                     
};

