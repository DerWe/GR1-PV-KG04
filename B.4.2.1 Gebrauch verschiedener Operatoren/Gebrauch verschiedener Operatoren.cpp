#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 2;		// Initialisierung der Variable a und Zuweisung der Ganzzahl 2 
	int b = 1;		// Initialisierung der Variable b und Zuweisung der Ganzzahl 1  
	
		a = b = 2;	// Ganzzahl 2 wird Variable a und b zugewiesen. a ist dasselbe wie b und b ist 2
	a = 5 * 3 + 2;	// Ganzzahl 17 wird der Variable a zugewiesen. 5*3=15+2=17
	a = 5 * (3 + 2);	// Ganzzahl 25 wird der Variable a zugewiesen. 3+2=5*5=25
	a *= 5 + 5;		// Ganzzahl 250 wird der Variable a zugewiesen. 5+5=10*25=250
	a %= 2 * 3;		// Ganzzahl ? wird der Variable a zugewiesen. 3*2=6 250%6=4 (% = Restwertoperator)
	a = !(--b == 0);	// Ganzzahl 1 wird Variable a und b zugewiesen. (b wird um 1 erniedrigt. Daher ist 1=0 falsch. Durch negierung des ! wird bool false zu true(1))
	a = 0 && 0 + 2;	// Ganzzahl 0 wird Variable a zugewiesen. 0+2=2 (&& log. operator AND) Vergleich der 0 und der 2 -> nicht definiert -> daher 0.
	a = b++ * 2;		// Ganzzahl 2 wird Variable a und b zugewiesen. 1*2=2 -> zuweisung a. Danach wird b erhöht und somit auch zu 2.
	a = -5 - 5;		// Ganzzahl -10 wird Variable a zugewiesen. -5+(-5)=-10.
	a = -(+b++);	// Ganzzahl -2 wird Variable a und 3 wird b zugewiesen. b wird negiert und der Wert wird a zugewiesen. Danach wird b um 1 erhöht.
		a = 5 == 5 && 0 || 1;	// Schritt1: 1 && 0 || 1; Schritt 2: 0 || 1; Schritt 3: a=1 (a=1; b=3)(SChritte folgen aus der Priorität der Boolschen Operatoren. Abarbeitung von links nach rechts)
	a = ((((((b + b) * 2) + b) && b || b)) == b);	//SChritt 1: ((((6*2)+b && b || b)) == b); Schritt 2: ((15 && b || b); Schritt 3: ((1|| 3) == 3); Schritt 4: (1 == 3)-->stimmt nicht-->(a=0; b=3)
	a = b + ++b;		// lang: (b+1) + (b+1) + (a=8; b=4)
	a = sizeof(int) * sizeof(a);// 4*4 = 16 (sizeof(int) = 4 da int standartmäßig 4 bites benötigt.)

		return 0;
	}