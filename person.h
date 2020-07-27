#ifndef PERSON_H
#define PERSON_H
struct Person { 
	std::string nachname;
	std::string vorname;
	std::string geburtsdatum;
};
Person extrahiere_person(std::string eingabezeile);
#endif // !PERSON_H
