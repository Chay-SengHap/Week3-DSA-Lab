#include "../utils/sll.hpp"
#include <functional>
#include <iostream>
using namespace std;
#include <chrono>
using clk = std::chrono::high_resolution_clock;


void SLL_Observe(function<void()> func, string mssg) {
    auto t0 = clk::now();
    func(); 
    auto t1 = clk::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << mssg << ": " << duration.count() << " nanosecond(s)" << endl;
}

int main() {
    SLL tray;
    for (int i = 0; i < 5; i++) {
        SLL_Observe([&tray]() { tray.insertFront(42); }, "Insert 42");
    }
    return 0;
}
