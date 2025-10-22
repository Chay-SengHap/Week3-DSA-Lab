#include <iostream>
#include <vector>
#include <chrono>
#include "../utils/sll.hpp"

using namespace std;
using namespace std::chrono;



int main()
{


    SLL list;
    cout << "Sll performent" << endl;
    SLL_observe(&list, list.insertFront,"Insert Front"); 
    SLL_observe(&list, list.pop_frontNoTail, "delete front"); 



    
    vector<int> stack;
    double duration = 0.0;
    for(int i=0; i<5; i++) {
        auto start = high_resolution_clock::now();
        stack.push_back(i);
        stack.pop_back();
        auto end = high_resolution_clock::now();
        cout << "test " << i << " Duration: " << duration_cast<nanoseconds>(end-start).count() << endl;
        duration += duration_cast<nanoseconds>(end-start).count();
    }
    cout << "Average: " << duration/5 << endl;

    return 0;
}