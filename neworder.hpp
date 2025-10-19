#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
class neworder
{
   
protected:
    int std_num;
    string first_name;
    string last_name;
    int order_num;
    vector<string> user_neworder;
    time_point<steady_clock> create_time;
    static int count;
public:
    neworder(int std_num,string first_name,string last_name,vector<string> user_neworder);

    ~neworder();
    int Order_Delivered();
    void Change_Order(int remove_index=-1,string add_item="");
    void Review();
    int get_ordernum();
};


