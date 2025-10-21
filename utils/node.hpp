#ifndef NODE
#define NODE

class SNode{
    public:
        int data;
        SNode* next;

        SNode(int value){
            data = value;
            next = nullptr;
        }

};

class DNode{
    public:
        int data;
        DNode* next;
        DNode* prev;

        DNode(int value){
            data = value;
            next = nullptr;
            prev = nullptr;
        }

};


#endif