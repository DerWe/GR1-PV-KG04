#include<iostream>
using namespace std;

int main(){
	int i, j;
	
	i = 0; j = 0;
	if (i++ || j++) ++i; // Das logische oder pr�ft ob I oder J ungleich 0 ist. Da I anfangs 0 ist, ist der erste Teil false und er wertet weiter aus. J ist dann ungleich 0 --> True... Im Zuge der jeweiligen Auswertung werden I und J nachtr�glich um 1 Erh�ht.
						// Da die 2. Bedingung True war, f�hrt er auch den Body von IF aus und erh�ht i wiederrum um 1
	cout << i << ',' << j << endl;

	i = 1; j = -5;
	if (i++ || j++) ++i; // Das logische oder pr�ft ob I oder J ungleich 0 ist. Da I anfangs 1 ist, ist der erste Teil bereits true und er wertet nicht weiter aus. Im Zuge der Auswertung wird I nachtr�glich um 1 Erh�ht. J Wird nicht ausgewertet und damit auch nicht um 1 Erh�ht
						// Da die 1. Bedingung True war, f�hrt er auch den Body von IF aus und erh�ht i wiederrum um 1
	cout << i << ',' << j << endl;

	i = 0; j = -5;
	if (i++ && j++) ++i; // Das logische Und pr�ft ob I und J ungleich 0 sind. Da I anfangs 0 ist, ist der erste Teil bereits false und er wertet nicht weiter aus. Im Zuge der Auswertung wird I nachtr�glich um 1 Erh�ht. J Wird nicht mehr ausgewertet und damit auch nicht um 1 Erh�ht
						// Da die 1. Bedingung false war, f�hrt er auch den Body von IF nicht aus und erh�ht i nicht nochmal um 1
	cout << i << ',' << j << endl;

	i = 1; j = -5;
	if (i++ && j++) ++i; // Das logische Und pr�ft ob I und J ungleich 0 sind. Da I anfangs 1 ist, ist der erste Teil true und er wertet weiter aus. J ist dann auch ungleich 0 --> True... Im Zuge der jeweiligen Auswertung werden I und J nachtr�glich um 1 Erh�ht.
						// Da die beide Bedingungen true waren, f�hrt er den Body von IF aus und erh�ht i nochmals um 1
	cout << i << ',' << j << endl;
}