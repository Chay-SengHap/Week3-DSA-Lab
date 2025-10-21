#include<iostream>
#include<chrono>
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




