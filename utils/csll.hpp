#include "node.hpp"
#include <chrono>
using namespace  std;
using clk=chrono::high_resolution_clock;
#include <string>
#include <iostream>



class CSLL{
    public:
        int data;
        SNode* head;
        SNode* tail;
        SNode* current;
        int size;
        CSLL(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        void measureAllocation()
        {
            int n = 100000;
            for (int i = 0; i < n; i++)
            {
                insertFront(i);
            }
        }
        void insertFront(int value){

            SNode* newNode = new SNode(value);
            if(size == 0){
                head = newNode; 
                tail = head;      
            }
            newNode->next =head;
            head = newNode;
            tail->next = head;
            size++;
        }
        void printCSLL(){
            current = head;
            while(current->next!= head){
                // cout<<current->data;
                // if(current->next!= tail){
                //     cout<<" -> ";
                // }
                current = current->next;
            }
            cout<<endl;

        }
        // A5
        void rotateRightCSLL(){
            int k = 10;
            if(!head || k==0 || k%size == 0 ){
                return;
            }
            k = k % size;

            int step = size - k ;

            for(int i = 0 ; i < step ; i++){
                head = head->next;
                tail = tail->next;
            }
        }

};
void CSLL_observe(CSLL* obj, void (CSLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" mircorsecond(s)" <<endl;
}