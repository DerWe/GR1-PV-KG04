#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// Diese Methode ist die Thread-Methode, d.h. alles was in ihr steht

// wird als Thread ausgefuehrt.
// Mehrere Threads koennen diese Methode unabhaengig voneinander
// gleichzeitig benutzen.

void count_to_30() {
	for (int i = 1; i <= 30; i++) {
		thread::id thread_id = this_thread::get_id();
		cout << "Durchlauf: " << i << " Name : " << thread_id << endl;

		this_thread::sleep_for(chrono::seconds(1));
	}
}

void print_threadID() {
	thread::id thread_id = this_thread::get_id();

	cout << "Thread ID: " << thread_id << endl;
}

int main()
{
	// Der zusaetzliche Thread t1 wird erzeugt und gestartet.
	thread t1(count_to_30);
	thread t2(print_threadID);
	
	// Die main-Methode wartet an dieser Stelle auf die Beendigung von t1
	// thread und main werden wieder zusammengefuehrt.

	while(t2.joinable()) {
		cout << "sdfsdfasdasdas" << endl;
		//if (t1.joinable()) {
		//	t1.join();
		//	cout << "Der Thread t1 (count_to_30) wurde beendet" << endl;
		//}
		//if (t2.joinable()) {
		//	t2.join();
		//	cout << "Der Thread t2 (print_threadID) wurde beendet" << endl;
		//}
	}

	system("pause");
	
	return 0;
}