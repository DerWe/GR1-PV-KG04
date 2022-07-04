#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

void increment_counter() {
    
    int counter = 0;
    
    while (true) {
        cout << "Thread " << this_thread::get_id() << " run " << counter << " times since Startup!" << endl;
        counter++;
        this_thread::sleep_for(milliseconds(100));
    }
}

int main()
{

    thread t1(increment_counter);
    thread t2(increment_counter);
    thread t3(increment_counter);
    thread t4(increment_counter);
    thread t5(increment_counter);
    thread t6(increment_counter);
    thread t7(increment_counter);
    thread t8(increment_counter);
    thread t9(increment_counter);
    thread t10(increment_counter);
    thread t11(increment_counter);
    thread t12(increment_counter);
    thread t13(increment_counter);
    thread t14(increment_counter);

    system("pause");
}