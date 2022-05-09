/*======================================================*/
/* Dateiname:	playlisttest.cpp                        */
/* Inhalt:		Benutzung der Klasse plylist           	*/
/* Author:		Bernd Stock								*/
/* Erstellt am: Maerz 2019								*/
/* Geaendert:	                                        */
/*						                      		    */
/*======================================================*/

#include "playlist.h"
#include<conio.h>
#include <windows.h> 

using namespace std;


/*=================*/
int menue(string);
/*=================*/

int main(void)
{

	playlist my_playlist;
	string Titel;
	string Interpret;
	mkat Kategorie;
	string temp{};

	int eingabe = -1;
	do {
		eingabe = menue(my_playlist.get_name());
		switch (eingabe) {
		case 1:
			my_playlist.BenutzerdatenEingeben(Titel, Interpret, Kategorie);
			/* einen neuen Titel in die Liste einfuegen */
			my_playlist.TitelEinfuegen(Titel, Interpret, Kategorie);
			break;
		case 2:
			// einen Titel aus der Liste loeschen 
			my_playlist.ZeileEingeben("Bitte den zu l\x94 \bschenden Titel eingeben:",
				Titel);
			if (my_playlist.TitelLoeschen(Titel) == false)
			{
				cout << "\nDer Titel \"" << Titel << "\" wurde nicht gefunden und konnte daher nicht gel\x94 \bscht werden\n";
				system("pause");
			}
			else
			{
				cout << "\nTitel \"" << Titel << "\" wurde gel\x94 \bscht.\n";
				system("pause");
			}
			break;
		case 3:
			/* Ausgabe der kompletten Liste */
			my_playlist.AlleTitelAnzeigen();
			break;
		case 4:
			// einen Titel suchen und anzeigen
			my_playlist.ZeileEingeben("Bitte den gesuchten Titel der Playlist eingeben:",
				Titel);
			if (my_playlist.TitelSuchenundAnzeigen(Titel, Interpret, Kategorie) == false)
			{
				cout << "\nDer gesuchte Titel \"" << Titel << "\" wurde nicht gefunden\n";
				system("pause");
			}
			else
			{
				cout << Titel << "," << Interpret << ",";
				cout << my_playlist.enumkat_in_string(Kategorie) << endl;
				system("pause");
			}
			break;
		case 5:
			// Playlist abspielen
			cout << "noch nicht implementiert" << endl;
			Sleep(2000);
			break;
		case 6:
			// Playlist speichern */
			my_playlist.ZeileEingeben("Bitte den Namen der Playlist eingeben:", temp);
			my_playlist.set_name(temp);
			my_playlist.PlaylistSpeichern();
			break;
		case 7:
			// Playlist laden */
			my_playlist.ZeileEingeben("Bitte den Namen der Playlist eingeben:",
				temp);
			my_playlist.set_name(temp);
			my_playlist.PlaylistLaden();
			break;
		case 8:
			break;
		default:
			cout << "\nFalsche Eingabe!!!\n";
			system("pause");
			break;
		}
	} while (eingabe != 8);

	return 1;
}

/*=====================*/
int menue(string pl)
/*=====================*/

{
	//int eingabe = -10;;
	// Bildschirm löschen
	system("cls");
	// Ä:\x8e ä:\x84 Ö:\x99 ö:\x94 Ü:\x9A ü:\x81 ß:\xe1
	// Menu anzeigen
	cout << "\nPlaylisten verwalten " << "\n====================\n\n";
	cout << "Name der aktuellen Playlist: " << pl << endl;
	cout << "Sie haben die folgende Auswahl:\n\n";
	cout << "Neuen Titel einf\x81 \bgen........1\n";
	cout << "Titel l\x94 \bschen...............2\n";
	cout << "Alle Titel auflisten........3\n";
	cout << "Titel suchen und anzeigen...4\n";
	cout << "Playlist abspielen..........5\n";
	cout << "Playlist speichern..........6\n";
	cout << "Playlist laden..............7\n";
	cout << "Programm beenden............8\n";
	cout << "\nBitte geben Sie eine Zahl ein:";
	// Eingabepuffer leeren
	cin.seekg(0, std::ios::end);
	cin.clear();
	char eingabe{ 'n' };
	//cin >> eingabe;
	char input[2];
	input[0] = _getche();
	input[1] = '\0';
	return atoi(input);
}