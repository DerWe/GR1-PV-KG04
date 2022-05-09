/*======================================================*/
/* Dateiname:	playlist.cpp                            */
/* Inhalt:		Implemenation der Klasse playlist    	*/
/* Author:		Bernd Stock								*/
/* Erstellt am: Maerz 2019								*/
/* Geaendert:	                                        */
/*						                      		    */
/*======================================================*/


#include <iostream>
#include <string>
#include "playlist.h"
#include <fstream>

using namespace std;

// Hilfsmethode zur EIngabe eines Titels
void playlist::BenutzerdatenEingeben(string& titel, string& interpret, mkat& kategorie)
{

	char tmp;

	while (1)
	{
		// Ä:\x8e ä:\x84 Ö:\x99 ö:\x94 Ü:\x9A ü:\x81 ß:\xe1
		system("cls");
		cout << "\nGeben Sie den Namen des Titels ein: ";
		// Eingabepuffer leeren
		cin.seekg(0, std::ios::end);
		cin.clear();
		getline(cin, titel);
		cout << "\nName des/der Interpreten: ";
		getline(cin, interpret);

		cout << "\nZu welcher Musikkategorie geh\x94 \brt der Titel: " << endl <<
			"(k=Klassik, p=Pop, r=Rock, j=Jungle, h=HipHop, z=Jazz):";
		cin >> tmp;

		if (false == int_in_enummkat(tmp, kategorie))
		{
			system("cls");
			cout << "Ung\x81 \bltige Kategorie eingegeben!!";
			system("pause");
			// verlassen der Endlosschleife
		}
		else
			break;
	}
}

// Hilfsfunktion:
// Umwandlung eines Integerwertes in den Datentyp enum mkat
// Rückgabe true, wenn die Umwandlung funktioniert hat, sonst false
/*================================================================*/
bool playlist::int_in_enummkat(int eingabe, enum mkat& ausgabe)
/*================================================================*/
{
	switch (eingabe)
	{
	case 'k':
	case 'K':
		ausgabe = KLASSIK;
		break;
	case 'p':
	case 'P':
		ausgabe = POP;
		break;
	case 'r':
	case 'R':
		ausgabe = ROCK;
		break;
	case 'j':
	case 'J':
		ausgabe = JUNGLE;
		break;
	case 'h':
	case 'H':
		ausgabe = HIPHOP;
		break;
	case 'z':
	case 'Z':
		ausgabe = JAZZ;
		break;
	default:
		return false;
	}
	return true;

}

// Hilfsfunktion:
// Ausgabe von Befehlszeile über cout und Einlesen der Benutzereingabe in text

/*==============================================================================================*/
void playlist::ZeileEingeben(string befehlszeile, string& text)
/*==============================================================================================*/
{

	system("cls");
	cout << "\n" << befehlszeile;
	// Eingabepuffer leeren
	cin.seekg(0, std::ios::end);
	cin.clear();
	/* getline liest bis zum nächsten Carriage Return ein */
	getline(cin, text);

}

// Hilfsfunktion: Umwandlung des Aufzählungstyps enum mkat
// in einen C-string zur Ausgabe
/*=============================================================*/
const char* playlist::enumkat_in_string(mkat eingabe)
/*=============================================================*/
{
	static const char* kategorie[] = {
		"KLASSIK", "POP","ROCK", "JUNGLE", "HIPHOP", "JAZZ", "UNBEKANNTE_KATEGORIE" };

	switch (eingabe)
	{
	case KLASSIK:
		return kategorie[0];
	case POP:
		return kategorie[1];
	case ROCK:
		return kategorie[2];
	case JUNGLE:
		return kategorie[3];
	case HIPHOP:
		return kategorie[4];
	case JAZZ:
		return kategorie[5];
	default:
		return kategorie[6];
	}
	return NULL;
}

/*=====================================================================================*/
void playlist::TitelEinfuegen(string Name, string Interpret, mkat Kategorie)
/*=====================================================================================*/

{
	/* Titel zu der verketteten Liste hinzufügen */
	struct titel* ptr;

	if ((ptr = new titel) == NULL) {
		system("cls");
		cout << "kein Speicherplatz mehr vorhanden";
		system("pause");
		return;
	}
	else {
		ptr->name = Name;
		ptr->interpret = Interpret;
		ptr->kategorie = Kategorie;
		ptr->next = start_pointer;
		start_pointer = ptr;
		return;
	}

}


/*===========================================*/
bool playlist::TitelLoeschen(string Name)
/*===========================================*/

{
	// nach der Titel mit dem eingegebenen Namen suchen und loeschen
	struct titel* ptr{ start_pointer }, * vorgaenger{ start_pointer };

	// nachschauen, ob der Titel in der verketteten Liste vorhanden ist 
	while (ptr != NULL && (ptr->name != Name))
	{
		vorgaenger = ptr;
		ptr = ptr->next;
	}

	// der gesuchte Titel wurde nicht gefunden 
	if (ptr == NULL) {
		return false;
	}
	else {
		// der gesuchte Titel ist der erste in der Liste 
		if (ptr == start_pointer)
			/* das nächste Element wird das erste in der Liste */
			start_pointer = ptr->next;
		else
			/* der next-Zeiger des Elementes vor dem zu loeschenden Element
			   wird auf das dem zu loeschenden folgende Element gesetzt */
			vorgaenger->next = ptr->next;
		// der gefundene Titel wird geloescht
		delete ptr;
		return true;
	}
}

/*=====================================*/
void playlist::AlleTitelAnzeigen()
/*=====================================*/

{
	/* ptr wird auf den Anfang der Liste gesetzt */
	struct titel* ptr = start_pointer;

	system("cls");
	cout << "\n Playlist " << name << endl << endl;

	if (ptr == NULL) {
		cout << "Die Playlist ist leer.\n";
		system("pause");
	}

	while (ptr != NULL)
	{
		/* Ausgabe der playlist */
		cout << ptr->name << "," << ptr->interpret << ",";
		cout << enumkat_in_string(ptr->kategorie) << endl;
		/* pointer auf das nächste Element setzen */
		ptr = ptr->next;
	}
	cout << "\n";
	system("pause");
}


/*=========================================================================*/
bool playlist::TitelSuchenundAnzeigen(string Name, string& i, mkat& k)
/*=========================================================================*/

{
	// nach dem Titel mit dem eingegebenen Namen suchen und anzeigen

	struct titel* ptr = start_pointer;

	/* nachschauen, ob der Titel in der verketteten Liste vorhanden ist */
	while (ptr != NULL && (ptr->name != Name))
		ptr = ptr->next;

	// der gesuchte Titel wurde nicht gefunden 
	if (ptr == NULL) {
		return false;
	}
	else {
		// Ausgabe des Titels
		i = ptr->interpret;
		k = ptr->kategorie;
		return true;
	}
}


/*========================================*/
void playlist::AlleTitelLoeschen(void)
/*========================================*/

{
	struct titel* ptr;
	struct titel* ptr_2;
	// loesche die verkettete Liste
	ptr = start_pointer;
	while (ptr != NULL)
	{
		ptr_2 = ptr->next;
		/* Platz auf dem Heap freigeben */
		delete ptr;
		ptr = ptr_2;
	}
	start_pointer = NULL;
}

/*====================================================*/
void playlist::PlaylistSpeichern()
/*====================================================*/
{
	/* ptr wird auf den Anfang der Liste gesetzt */
	struct titel* ptr = start_pointer;

	if (ptr == NULL) {
		cout << "Die Playlist ist leer!\n";
		system("pause");
	}

	ofstream Ziel;
	string full_name{ name };
	full_name += ".txt";
	Ziel.open(full_name.c_str(), ios_base::out);

	if (!Ziel) {
		cerr << "Datei kann nicht ge\x94 \bffnet werden!\n";
		system("pause");
		return;
	}

	// schreiben
	while (ptr != NULL)
	{
		/* schreiben eines Titels der Playlist */
		Ziel << ptr->name << endl;
		Ziel << ptr->interpret << endl;
		Ziel << static_cast<int>(ptr->kategorie) << endl;
		ptr = ptr->next;
	}

	Ziel.close();
}

/*====================================================*/
void playlist::PlaylistLaden()
/*====================================================*/
{

	titel tmp;
	ifstream Quelle;
	string hilfe{ name };

	hilfe += ".txt";

	Quelle.open(hilfe.c_str(), ios_base::in);

	if (!Quelle) {
		cerr << "Playlyist \"" << name << "\" kann nicht ge\x94 \bffnet werden!\n";
		system("pause");
		return;
	}

	// aktuelle Daten loeschen
	AlleTitelLoeschen();

	while (!Quelle.eof())
	{
		struct titel* ptr;
		getline(Quelle, hilfe);
		if (hilfe.length() == 0)
			break;
		if ((ptr = new titel) == NULL) {
			system("cls");
			cout << "kein Speicherplatz mehr vorhanden";
			system("pause");
			return;
		}
		else {

			ptr->name = hilfe;
			getline(Quelle, ptr->interpret);
			getline(Quelle, hilfe);
			ptr->kategorie = static_cast<mkat> (atoi(hilfe.c_str()));
			ptr->next = start_pointer;
			start_pointer = ptr;
		}
	}

	Quelle.close();
}