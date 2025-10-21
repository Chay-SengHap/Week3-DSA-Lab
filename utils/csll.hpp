#include "node.hpp";

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