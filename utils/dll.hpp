
#include<iostream>
#include<chrono>
#include <string>
using namespace  std;
using clk=chrono::high_resolution_clock;
using namespace std;

class DLL{
    public:
    int data;
    DNode* head;
    DNode* tail;
    DNode* current;
    int size;
    DLL(int data){
        this->data = data;
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        size = 0;
    }

    int getSize(){return size;}

    void insertFront(int val){
        DNode* newNode = new DNode(val);
        if(!head || !tail){
            head = tail = newNode;
            return;
        }
        newNode ->next = head;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        size++;
    }


    void insertEnd(int val){
        if(!head){
            insertFront(val);
            return;
        }
        DNode* newNode = new DNode(val);
         tail->next = newNode;
         newNode->prev = tail;
         tail = newNode;
         size++;

    }
    

};

void DLL_observe(DLL* obj, void (DLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}


