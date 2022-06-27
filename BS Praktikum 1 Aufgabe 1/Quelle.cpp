#include <iostream>
#include <thread>

using namespace std;

int main()
{
    const auto processor_count = thread::hardware_concurrency();
    cout << "Im System wurden ungefaehr " << processor_count << " Prozessorkerne gefunden." << endl;
    system("pause");
}