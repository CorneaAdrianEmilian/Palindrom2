#include "CouldBePalindrom.h"
bool CouldBePalindom(std::string& parola)
{
	int temp = 1; //variabila care stocheaza numarul aparitiei unui element din string

	int Impar = 0; //variabila care stocheaza numarul elementelor impare din string

	int Primulnumar = 0;  // primul index testat

	// vector ce stocheaza INDECSII de la elementele care se repeta
	std::vector <int> elementeTestate; 

	//loop care functioneaza atat timp cat sunt caractere in string
	//testeaza primul index cu restul indecsilor
	while(parola.length()!=0)
	{
		//conditie ca sa nu testam un string cu size de 1
		if (parola.length() != 1) 
		 {
			for (int j = 1; j < parola.length(); ++j)
			{
				if (parola[Primulnumar] == parola[j])
				{
					elementeTestate.push_back(j);//adaugam indecsii dublurilor in vector

					++temp;//pentru fiecare element identic  se incrementeaza
				}
			}
		}
		// daca este un numar impar de dubluri se incrementeaza variabila "Impar"
		if (temp % 2 == 1)
			++Impar;

		//daca sunt 2 numere fara pereche nu mai este un palindrom
		if (Impar > 1) { return false; }
		temp = 1; //resetam variabila temp pentru urmatoarea iteratie

		//stergem dublurile ca sa nu le testam din nou
		//loop ul functioneaza atat timp cat exista dubluri
		while(elementeTestate.size()!=0)
		{
			//stergem din string dublurile
			parola.erase(elementeTestate[elementeTestate.size()-1],1);
			//stergem din vector dublurile
			elementeTestate.pop_back();
		}
		//stergem din string primul element deja testat
		parola.erase(Primulnumar, 1);
	}
	//in cazul in care nu se returneaza false pana la iesirea din loop-ul principal
	//stringul este palindrom
	return true;
}