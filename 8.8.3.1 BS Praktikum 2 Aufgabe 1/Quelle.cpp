#include <iostream>
#include <thread>

using namespace std;

void thread1(int zahl) {
    while (zahl < 100) {
        cout << zahl << endl;
        zahl++;
    }
}

void thread2(int zahl) {
    while (zahl > 0) {
        cout << zahl << endl;
        zahl--;
    }
}

int main()
{
    cout << "Hallo User :) !" << endl;
    cout << "Gib eine Zahl zwischen 0 und 100 ein: " ;
    int zahl = 0;
    cin >> zahl;

    thread t1(thread1, zahl);
    thread t2(thread2, zahl);


    t1.join();
    t2.join();


    system("pause");
}