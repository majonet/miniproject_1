#include "linklist.hpp"
LinkedList list1;
void order(int std_num,string name,string last_name,vector<string> items){
        list1.addorder(std_num,name,last_name,items);
    }
int main() {
    cout<<"welcome to my resturant this is my main page(1_show menu,2_new order,3_change order,4_Order Delivered,5_cancel order)"; 
    vector<string> items = {"Juice", "Cake"};
    
    // list1.addorder(2, "Sara", "Ahmadi", items);
    // list1.addorder(3, "Sd", "sd", items);
    order(3, "Sd", "sd", items);
    //list1.printall();
    list1.search(2);
    
    return 0;
}