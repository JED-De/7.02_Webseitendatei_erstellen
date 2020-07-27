#include <iostream> 
#include <string> 
#include <fstream> 
#include "person.h"

 //#include <windows.h> //fürs öffnen im Browser

using namespace std;

string br(string s)
{
	return s += "<br/>";
}

string b(string s)
{
	string result = "<b>";
	result += s;
	return result += "</b>";
}

string ersetze(string s, char vergleich, string ersatz)
{
	string result = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) == vergleich)
		{
			result += ersatz;
			i++;
		}
		if (i < s.size())
		{
			result += s.at(i);
		}
	}
	return result;
}

int main()
{
	string eingabezeile = "", kurztext = "", langtext = "";
	ifstream inFile; 
	inFile.open("personendaten.txt");

	if (inFile.fail())
	{
		cerr << "Error Opening personendaten.txt" << endl;
		system("PAUSE");
		exit(1);
	}

	while (!inFile.eof())
	{
		getline(inFile, eingabezeile);
		if (eingabezeile != "")
		{
			Person person = extrahiere_person(eingabezeile);
			kurztext += br(b(person.nachname) + ", " + person.vorname) + "\n";
			langtext += br(b(person.vorname + " " + person.nachname) + ", " + person.geburtsdatum) + "\n";
		}
	}
	inFile.close();

	ifstream inHTML;
	inHTML.open("webseite.html.tmpl");
	ofstream outFile;
	outFile.open("webseite.html");

	if (inHTML.fail())
	{
		cerr << "Error Opening webseite.html.tmpl" << endl;
		system("PAUSE");
		exit(1);
	}

	while (!inHTML.eof())
	{
		getline(inHTML, eingabezeile);
		eingabezeile = ersetze(eingabezeile, '%', kurztext);
		eingabezeile = ersetze(eingabezeile, '$', langtext);
		outFile << eingabezeile << "\n";
	}
	inHTML.close();
	outFile.close();
	//ShellExecute(NULL, "open", "webseite.html",NULL, NULL, SW_SHOWNA);
	//ShellExecute(0, "open", "notepad++.exe", "webseite.html",NULL,SW_SHOWNA);
	//system(("open "s + "webseite.html").c_str());
	return 0;
}

//Aufgabe 2 & 3
/*
#include <iostream> 
#include <string> 
#include <fstream> 
#include "person.h"

using namespace std;

string br(string s)
{
	return s += "<br/>";
}

string b(string s)
{
	string result = "<b>";
	for (int i = 0; i < s.size(); i++)
	{
		result += s.at(i);
	}
	return result += "</b>";
}


int main()
{
	string eingabezeile = "", kurztext ="", langtext ="";
	//Datendatei "personendaten.txt" als textuelle Eingabedatei öffnen;
	ifstream inFile; //Klasse erstellen
	inFile.open("personendaten.txt");

	if (inFile.fail())
	{
		cerr << "Error Opening File" << endl; //Error ausgabe
		exit(1);
	}

//	solange(eingabezeile aus Datendatei lesen)
//	{
//		Person person = extrahiere_person(eingabezeile);
//		Dann person.vorname, person.nachname,
//      person.geburtsdatum ausgeben     }
	
	
	while (!inFile.eof()) //eof ~ End of File
	{
		getline(inFile, eingabezeile);
		Person person = extrahiere_person(eingabezeile);
		cout << "Nachname: " << person.nachname << endl << "Vorname: " << person.vorname << endl << "Geburtsdatum: " << person.geburtsdatum << endl << endl;
		kurztext += br( b(person.nachname) + ", " + person.vorname) + "\n";
		langtext += br(b(person.vorname + " " + person.nachname) + ", " + person.geburtsdatum) + "\n";
	}
	cout << kurztext << endl << langtext;
	//Datendatei schließen;   
	inFile.close();
	system("PAUSE");
	return 0;
}
*/

//1. Schreiben Sie ein C++ Programm, welches die Datendatei personendaten.txt zeilenweise einliest und jede eingelesene Zeile wieder auf den Bildschirm ausgibt.
/*
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string eingabezeile;
	//Datendatei "personendaten.txt" als textuelle Eingabedatei öffnen;
	ifstream inFile; //Klasse erstellen
	inFile.open("personendaten.txt");

	if (inFile.fail())
	{
		cerr << "Error Opening File" << endl; //Error ausgabe
		exit(1);
	}

	//solange(eingabezeile aus Datendatei lesen) { eingabezeile ausgeben; }
	while (!inFile.eof()) //eof ~ End of File
	{
		getline(inFile, eingabezeile);
		cout << eingabezeile << endl;
	}

	//} Datendatei schließen;
	inFile.close();

	system("PAUSE");
	return 0;
	;
}
*/

/*
int main() {
	string eingabezeile;
	//Datendatei "personendaten.txt" als textuelle Eingabedatei öffnen;
	ifstream inFile; //Klasse erstellen
	inFile.open("personendaten.txt");
	ifstream inHTML;
	inHTML.open("webseite.html.tmpl");
	ofstream outFile;
	outFile.open("webseite.html");
	//Check For Error
	if (inFile.fail())
	{
		cerr << "Error Opening File" << endl; //Error ausgabe
		exit(1);
	}
	if (inHTML.fail())
	{
		cerr << "Error Opening HTML" << endl; //Error ausgabe
		exit(1);
	}


	//solange(eingabezeile aus Datendatei lesen) {
	//	eingabezeile ausgeben;

	//Read a file until you've reached the end
	while (!inFile.eof()) //eof ~ End of File
	{
		getline(inFile, eingabezeile);
		cout << eingabezeile << endl;
	}
	while (!inHTML.eof()) //eof ~ End of File
	{
		getline(inHTML, eingabezeile);
		for (int i = 0; i < eingabezeile.size(); i++)
		{
			if (eingabezeile.at(i) == '%')
			{
					outFile << "Hi" << endl;
			}
			else
			{
				outFile << eingabezeile.at(i);
			}
		}
		outFile << endl;
	}
	inFile.close();
	inHTML.close();
	outFile.close();
	system("PAUSE");
	//} Datendatei schließen;
	return 0;
	;
}
*/

/*
TUTORIALS angesehen:
https://www.youtube.com/watch?v=Iho2EdJgusQ

https://docs.microsoft.com/en-us/windows/desktop/api/shellapi/nf-shellapi-shellexecutea


*/