
int main() {
	int i, k, n;

	i = 101, k = 5, n = 10;
	while (i > 0) k = 2 * k; // Bedingung i > 0 Erf�llt, da 101 > 0 --> Schleife wird ausgef�hrt. Darin wird k unendlich oft mit 2 Multipliziert und wieder in k gespeichert, da eine Abbruchbedingung fehlt. --> Schleife l�uft unendlich

	i = 101, k = 5, n = 10;
	while (i != 0) i = i - 2; // Bedingung i ungleich 0 Erf�llt --> Schleife wird ausgef�hrt. Darin wird So lange 2 von i abgezogen, bis i == 0 ist. Da I initial ungerade ist, wird die Abbruchbedingung aber nie Erf�llt --> Schleife l�uft unendlich

	i = 101, k = 5, n = 10;
	while (n != i) { // Bedingung n ungleich i Erf�llt --> Schleife wird ausgef�hrt. Darin wird i Erh�ht und anschlie�end n das doppelte von i zugewiesen. Da n immer 2 mal i ist, wird n immer ungleich i bleiben --> Schleife l�uft unendlich
		++i;
		n = 2 * i;
	}
}