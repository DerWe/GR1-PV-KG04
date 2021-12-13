#include<iostream>
using namespace std;

int main(){
	int i, j;
	
	i = 0; j = 0;
	if (i++ || j++) ++i; // Das logische oder prüft ob I oder J ungleich 0 ist. Da I anfangs 0 ist, ist der erste Teil false und er wertet weiter aus. J ist dann ungleich 0 --> True... Im Zuge der jeweiligen Auswertung werden I und J nachträglich um 1 Erhöht.
						// Da die 2. Bedingung True war, führt er auch den Body von IF aus und erhöht i wiederrum um 1
	cout << i << ',' << j << endl;

	i = 1; j = -5;
	if (i++ || j++) ++i; // Das logische oder prüft ob I oder J ungleich 0 ist. Da I anfangs 1 ist, ist der erste Teil bereits true und er wertet nicht weiter aus. Im Zuge der Auswertung wird I nachträglich um 1 Erhöht. J Wird nicht ausgewertet und damit auch nicht um 1 Erhöht
						// Da die 1. Bedingung True war, führt er auch den Body von IF aus und erhöht i wiederrum um 1
	cout << i << ',' << j << endl;

	i = 0; j = -5;
	if (i++ && j++) ++i; // Das logische Und prüft ob I und J ungleich 0 sind. Da I anfangs 0 ist, ist der erste Teil bereits false und er wertet nicht weiter aus. Im Zuge der Auswertung wird I nachträglich um 1 Erhöht. J Wird nicht mehr ausgewertet und damit auch nicht um 1 Erhöht
						// Da die 1. Bedingung false war, führt er auch den Body von IF nicht aus und erhöht i nicht nochmal um 1
	cout << i << ',' << j << endl;

	i = 1; j = -5;
	if (i++ && j++) ++i; // Das logische Und prüft ob I und J ungleich 0 sind. Da I anfangs 1 ist, ist der erste Teil true und er wertet weiter aus. J ist dann auch ungleich 0 --> True... Im Zuge der jeweiligen Auswertung werden I und J nachträglich um 1 Erhöht.
						// Da die beide Bedingungen true waren, führt er den Body von IF aus und erhöht i nochmals um 1
	cout << i << ',' << j << endl;
}