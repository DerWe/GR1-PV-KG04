#include <iostream>
#include <chrono>
#include <thread>

using namespace std;


// Thread um bis 30 zu zählen
void count_to_30() {
	for (int i = 1; i <= 30; i++) {										//for Schleife um bis 30 zu zählen
		thread::id thread_id = this_thread::get_id();					//thread ID auslesen
		cout << "Durchlauf: " << i << " Name : " << thread_id << endl;	//Alles in der Konsole ausgeben

		this_thread::sleep_for(chrono::seconds(1));						//1 Sekunde warten
	}
}

//Thread, der einfach nur seine Thread ID ausgibt
void print_threadID() {
	thread::id thread_id = this_thread::get_id();						//thread ID auslesen
	cout << "Thread ID: " << thread_id << endl;							//Alles in der Konsole ausgeben
}

int main()
{
	// Beide zusaetzliche Threads werden erzeugt und gestartet.
	thread t1(print_threadID);
	thread t2(count_to_30);
	
	// Die main-Methode wartet an dieser Stelle auf die Beendigung von t1
	// thread und main werden wieder zusammengefuehrt.

	t1.join();
	cout << "Der Thread t1 (count_to_30) wurde beendet" << endl;

	// Die main-Methode wartet an dieser Stelle auf die Beendigung von t2
	// thread und main werden wieder zusammengefuehrt.
	t2.join();
	cout << "Der Thread t2 (print_threadID) wurde beendet" << endl;

	system("pause");
	
	return 0;
}