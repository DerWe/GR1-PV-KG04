#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

// Funktion um eine Fibonacci-Folge zu bererchnen
int fibonacci(int n)
{
	if (n < 3) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);

}

//zusätzlicher Thread zur berechnung einer weiteren Fibonacci Zahl
void thread_fibonacci() {
	// Zwei Zeitpunkte zur Zeitmessung des Datentyps time_point --> laut doku Basierend auf der RTC (Real Time Clock) des Systems, beinhaltet einen Zeitpunkt
	time_point<system_clock> start, end;

	// start-Zeitpunkt die aktulle Uhrzeit zuweisen
	start = system_clock::now();
	// Fibonaccizahlen berechnen
	int result = fibonacci(42);
	// end-Zeitpunkt die aktuelle Uhrzeit zuweisen
	end = system_clock::now();
	// Berechnung der benoetigten Sekunden
	int elapsed_seconds = duration_cast<seconds>(end - start).count();
	// Ausgabe
	cout << "thread: " << result << " needed " << elapsed_seconds << " Seconds" << endl;
}

//das Programm berechnet im Grunde nur die Zeit, die die Berechnung einer Fibonacco Folge benötigt hat, indem Start- und Endzeit verglichen werden.

int main()
{
	//Start des zusätzlichen Threads
	thread t1(thread_fibonacci);

	// Zwei Zeitpunkte zur Zeitmessung des Datentyps time_point --> laut doku Basierend auf der RTC (Real Time Clock) des Systems, beinhaltet einen Zeitpunkt
	time_point<system_clock> start, end;

	// start-Zeitpunkt die aktulle Uhrzeit zuweisen
	start = system_clock::now();
	// Fibonaccizahlen berechnen
	int result = fibonacci(42);
	// end-Zeitpunkt die aktuelle Uhrzeit zuweisen
	end = system_clock::now();
	// Berechnung der benoetigten Sekunden
	int elapsed_seconds = duration_cast<seconds>(end - start).count();
	// Ausgabe
	cout << "main:   " << result << " needed " << elapsed_seconds << " Seconds" << endl;

	//Join des zusätzlichen Threads
	t1.join();

	// Blockieren des Prozesses
	system("pause");

	return 0;
}

/*
Welche Art der Berechnung ist schneller? Sind beide gleich schnell? Schreiben Sie Ihre Beobachtungen
und Vermutungen als Kommentar in ihren Quellcode

Beide Varianten sind gleich schnell. Die zusätzliche Berechnung im Thread hat keinen negativen Einflass auf die Ursprüngliche Rechendauer. Das hat die folgenden Gründe:
- Fibonacci Folge wird jeweils mit dem selben Verfahren rekursiv berechnet
- Eine einzelne Berechnung  ist nicht in mehrere Threads aufgeteilt, sondern erfolgt wie gehabt
- Die beiden Berechnungen laufen voneinender unabhängig parallel, haben also keinen Einfluss aufeinander so lange die CPU nicht ausgelastet ist und kein thread allzu lange warten muss

*/