#include <iostream>
#include <chrono>
#include <string>
#include "node.hpp"
using namespace std;
class SLL{
    public: 
    SNode* head;
    SNode* current;
    int size;

    SLL(): head(nullptr), size(0){};

};

// void SLL_observe(SLL* obj, void (SLL::*method)(), string msg){
//     auto t0 = clk::now();

//     (obj->*method)(); // perform operation

//     auto t1 = clk::now();

//     auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
//     cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
// }