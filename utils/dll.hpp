
#include<iostream>
#include "node.hpp"
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
        void push_frontWithTail(int value){
        DNode* newNode = new DNode(value);
        if(!head){
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        newNode ->next = head;
        head->prev = newNode;
        head = newNode;

        size++;
    }
    
    
    void push_backWithTail(int value){
        DNode* newNode = new DNode(value);
        if(!head){
            push_frontWithTail(value);
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }
    void pop_frontWithTail(){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }
        DNode* temp = head;
        if(size == 1){
            head = tail = nullptr;
        }
        else{
            head = head->next;
            head->prev = nullptr;
        }    
        delete temp;
        size--;
    }
    void pop_backWithTail(){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }
        if(size == 1){
            pop_frontWithTail();
            return;
        }
        DNode* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        size--;
    }
    void measureAllocation(){
        int n = 100000;
        for(int i = 0; i < n; i++){
            insertFront(i);
        }
    }
    

    

};

void DLL_observe(DLL* obj, void (DLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}


