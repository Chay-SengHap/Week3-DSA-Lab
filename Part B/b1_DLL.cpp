#include "../utils/dll.hpp"
#include <functional>
//time for function parameter
    void DLL_Observe(std::function<void()> func, string msg){
    auto t0 = clk::now();
    func(); 
    auto t1 = clk::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
    };

int main() {
    
    DLL tray(1);
    for(int i = 0; i < 5; i++)
    {
        DLL_Observe([&tray](){ tray.insertFront(42); }, "Insert 42");
    }
    return 0;
}
