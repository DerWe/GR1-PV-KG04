#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 2;		// Ganzzahl 2 wird der Variable a zugewiesen
	int b = 1;		// Ganzzahl 2 wird der Variable a zugewiesen
	
		a = b = 2;	// Ganzzahl 2 wird Variable a und b zugewiesen. a ist das slebe wie b und b ist 2
	a = 5 * 3 + 2;	// Ganzzahl 17 wird der Variable a zugewiesen. 5*3=15+2=17
	a = 5 * (3 + 2);	// Ganzzahl 25 wird der Variable a zugewiesen. 3+2=5*5=25
	a *= 5 + 5;		// Ganzzahl 250 wird der Variable a zugewiesen. 5+5=10*25
	a %= 2 * 3;		// Ganzzahl ? wird der Variable a zugewiesen. 3*2=6 250%6=4
	a = !(--b == 0);	// Ganzzahl 1 wird Variable a und b zugewiesen
	a = 0 && 0 + 2;	// Ganzzahl 0 wird Variable a zugewiesen
	a = b++ * 2;		// Ganzzahl 2 wird Variable a und b zugewiesen
	a = -5 - 5;		// Ganzzahl -10 wird Variable a zugewiesen
	a = -(+b++);	// Ganzzahl -2 wird Variable a und 3 wird b zugewiesen
		a = 5 == 5 && 0 || 1;	// Ganzzahl 1 wird Variable a zugewiesen
	a = ((((((b + b) * 2) + b) && b || b)) == b);	// Ganzzahl 0 wird Variable a zugewiesen
	a = b + ++b;		// Ganzzahl 8 wird Variable a und 4 wird der Variable b zugewiesen
	a = sizeof(int) * sizeof(a);// 4*4 = 16

		return 0;
	}