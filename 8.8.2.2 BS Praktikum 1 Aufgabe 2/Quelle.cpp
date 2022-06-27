#include <iostream>
#include <thread>

using namespace std;

int main()
{
    cout << "Die Thread ID lautet: " << this_thread::get_id() << endl;

    system("pause");
}