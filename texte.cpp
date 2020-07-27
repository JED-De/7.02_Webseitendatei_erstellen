#include <iostream> 
#include <string> 

void spalte_ab_erstem(std::string eingabe, char zeichen, std::string& erster_teil, std::string& zweiter_teil)
{
	int i = 0;
	for (; i < eingabe.size(); i++)
	{
		if (eingabe.at(i) == zeichen)
		{
			i++;
			break;
		}
		else
		{
			erster_teil += eingabe.at(i);
		}
	}

	for (; i < eingabe.size(); i++)
	{
		zweiter_teil += eingabe.at(i);
	}
}

std::string trimme(std::string s)
{
	std::string resultat = "";
	int anfangplus = 0;
	int endplus = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) != ' ')
		{
			break;
		}
		anfangplus++;
	}

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s.at(i) != ' ')
		{
			break;
		}
		endplus++;
	}

	for (int i = anfangplus; i < s.size() - endplus; i++)
	{
		resultat += s.at(i);
	}
	return resultat;
}

//alternative spalte_ab_erstem
/*
void spalte_ab_erstem(std::string input, char zeichen, std::string &output, std::string &output2)
{
	bool nachZeichen = false;
	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) == zeichen && nachZeichen == false)
		{
			nachZeichen = true;
		}
		else if (nachZeichen == false)
		{
			output += input.at(i);
		}
		else
		{
			output2 += input.at(i);
		}
	}
}
*/
