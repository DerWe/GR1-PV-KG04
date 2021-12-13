
int main() {
	int i, k, n;

	i = 101, k = 5, n = 10;
	while (i > 0) k = 2 * k; // Bedingung i > 0 Erfüllt, da 101 > 0 --> Schleife wird ausgeführt. Darin wird k unendlich oft mit 2 Multipliziert und wieder in k gespeichert, da eine Abbruchbedingung fehlt. --> Schleife läuft unendlich

	i = 101, k = 5, n = 10;
	while (i != 0) i = i - 2; // Bedingung i ungleich 0 Erfüllt --> Schleife wird ausgeführt. Darin wird So lange 2 von i abgezogen, bis i == 0 ist. Da I initial ungerade ist, wird die Abbruchbedingung aber nie Erfüllt --> Schleife läuft unendlich

	i = 101, k = 5, n = 10;
	while (n != i) { // Bedingung n ungleich i Erfüllt --> Schleife wird ausgeführt. Darin wird i Erhöht und anschließend n das doppelte von i zugewiesen. Da n immer 2 mal i ist, wird n immer ungleich i bleiben --> Schleife läuft unendlich
		++i;
		n = 2 * i;
	}
}