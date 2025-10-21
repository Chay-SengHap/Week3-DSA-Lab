#include "node.hpp";
#include <chrono>
using namespace  std;
using clk=chrono::high_resolution_clock;
#include <string>

void CSLL_observe(CSll* obj, void (Sll::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}

class CSLL{
    public:
        int data;
        Node* head;
        Node* tail;
        Node* current;
        int size;
        csll(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        void insertFront(int value){

            SNode* newNode = new Node()
            if(size == 0){
                head = newNode; 
                tail = head;      
            }
            newNode->next =head;
            head = newNode;
            tail->next = head;
        }
        void printCSLL(){
            current = head;
            while(current->next!= head){
                cout<<current->data;
                if(current->next!= tail){
                    cout<<" -> ";
                }
                current = current->next;
            }

        }

}