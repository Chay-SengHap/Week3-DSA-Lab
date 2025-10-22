#include <iostream>
#include <chrono>
#include <string>
#include "node.hpp"
using namespace std;

using clk = std::chrono::high_resolution_clock;
class SLL{
    public: 
    SNode* head;
    SNode* current;
    SNode* tail;
    int size;

    SLL(): head(nullptr), size(0){};
    void printSLL()
    {
        current = head;
        while(current)
        {
          
            current = current->next;
        }
        cout<<"NUll" <<endl;
    }
    void insertFront(int value){
        SNode* newNode = new SNode(value);
        if(!head){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }


    // A5
    void rotateRightSLL(){
        int k = 10;
        if(!head || k == 0 ){
            return;
        }
        SNode* tail = head;
        int length = 1;
        while(tail->next){
            tail = tail->next;
            length++;
        }

        k = k % length;

        int step = length - k - 1;
        SNode* newTail = head;
        for(int i = 0 ; i < step ; i++){
            newTail = newTail->next;
        }
        SNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        head = newHead;

    }
        void push_frontNoTail(int value){
        SNode* newNode = new SNode(value);
        if(!head){
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }
    void push_frontWithTail(int value){
        SNode* newNode = new SNode(value);
        if(!head){
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }
    void push_backNoTail(int value){
        SNode* newNode = new SNode(value);
        if(!head){
            push_frontNoTail(value);
            return;
        }
        current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newNode;
        size++;

    }
    void push_backWithTail(int value){
        SNode* newNode = new SNode(value);
        if(!head){
            push_frontWithTail(value);
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    void pop_frontNoTail(){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }
        SNode* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void pop_frontWithTail(){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }
        SNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        if(size == 0){
            tail = nullptr;
        }
    }
    void pop_backNoTail(){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }
        if(size == 1){
            pop_frontNoTail();
            return;
        }
        current = head;
        while(current->next->next){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
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
        current = head;
        while(current->next != tail){
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }

    void measureAllocation(){
        int n = 100000;
        for(int i = 0; i < n; i++){
            insertFront(i);
        }
    }


};

void SLL_observe(SLL* obj, void (SLL::*method)(), string mssg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(t1 - t0);
    cout<<mssg <<": "<<duration.count() <<" microsecond(s)" <<endl;
}

