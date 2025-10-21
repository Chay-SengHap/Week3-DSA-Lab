#include <iostream>
#include <chrono>
#include "utils/node.hpp"
#include "utils/csll.hpp"
#include "utils/sll.hpp"
#include "utils/dll.hpp"
using namespace std;


int main(){
        CSLL csll;
        SLL sll;

    for(int i = 0 ; i<100; i++){
        csll.insertFront(i);
    }
    for(int i = 0 ; i < 5 ; i++){

        CSLL_observe(&csll, csll.printCSLL,"csll");
    }
    for(int i = 0 ; i<100; i++){
        sll.insertFront(i);
    }
    for(int i = 0 ; i < 5 ; i++){

        SLL_observe(&sll, sll.printSLL,"sll");
    }
    return 0;
}


