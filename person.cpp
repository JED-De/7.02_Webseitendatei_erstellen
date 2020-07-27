#include <iostream> 
#include <string> 
#include <fstream>
#include "texte.h"
#include "person.h"


Person extrahiere_person(std::string eingabezeile)
{
	Person p;
	std::string rest;
	spalte_ab_erstem(eingabezeile, ',', p.nachname, rest);
	spalte_ab_erstem(rest, ',', p.vorname, p.geburtsdatum);
	p.nachname = trimme(p.nachname);
	p.vorname = trimme(p.vorname);
	p.geburtsdatum = trimme(p.geburtsdatum);
	//std::cout << "Nachname: " << p.nachname << " Vorname: " << p.vorname << " Geburtsdatum: " << p.geburtsdatum << std::endl;
	return p;
}