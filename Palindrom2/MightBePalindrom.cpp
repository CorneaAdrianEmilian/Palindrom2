#include "MightBePalindrom.h"

bool MightBePalindrom(std::string& text) {
	std::vector <char> elementeTestate;
	//testam daca sirul de caractere este impar sau par ca dimensiune
	//si aplicam codul potrivit in functie de rezultat (par sau impar)
	if (text.size() % 2 == 0)
	{
		//variabila in care stocam de cate ori se repeta un element in sir
		int dubluri = 1;
		//testam primul index ca sa avem  un element in vector
			for(int j=1;j<text.size();j++)
			{
				if (text[0] == text[j])
				{
					++dubluri;
				}
			}
			elementeTestate.push_back(text[0]);
			//daca intr un sir par exista un element care nu are pereche
			//sirul nu este palindrom
			if (dubluri % 2 == 1) { return false; }
			dubluri = 1;

			int primulNumar = 1;
			int alDoilea = 2;
			
			for (primulNumar; primulNumar < text.size() - 1; primulNumar)
			{
				
				int temp = 0;
				//testam daca urmatorul numar pe care il testam este deja
				//in vectorul cu elemente testate
				for (int test = 0; test < elementeTestate.size(); test++)
				{
					alDoilea = primulNumar + 1;
					if (elementeTestate[test] == text.at(primulNumar)) 
					{ ++primulNumar; ++alDoilea; ++temp; }
				}
				//daca indexul este deja testat se trece la rumatoarea iteratie fara
				//sa se execute codul de mai jos
				if (temp >= 1) { continue; }

				//trecem prin sir ca la inceput si testam daca sunt dubluri
				//folosim in loop urmatorul index fata de cel pe care il testam cu 
				//restul sirului ca sa nu iesim out of bounds
				for (alDoilea; alDoilea < text.size(); alDoilea++)
				{
					if (text[primulNumar] == text[alDoilea])
					{
						++dubluri;
					}
						
				}
					elementeTestate.push_back(text[primulNumar]);
					if (dubluri % 2 == 1) { return false; }
					dubluri = 1;
					//incrementam variabila din loop la final ca sa nu 
					//intervina in cazul in care se activeaza "continue"
					//in caz contrar se incrementeaza cu 2
					++primulNumar;
					

			}
			
		return true;
	}else
	{
		//in else testam sirurile impare
		//este asemanator cu o singura diferenta ca trebuie testat sa nu fie mai mult de 1
		// element fara pereche
		int dubluri = 1;
		int numereImpare = 0;
		std::vector <char> elementeTestate;
		for (int j = 1; j < text.size(); j++)
		{
			if (text.at(0) == text.at(j))
			{
				++dubluri;
			}
		}
		elementeTestate.push_back(text.at(0));
		if (dubluri % 2 == 1) { ++numereImpare; }
		if (numereImpare > 1) { return false; }

		int primulNumar = 1;
		int alDoilea = 2;

		for (primulNumar; primulNumar < text.size() - 1; primulNumar)
		{

			int temp = 0;
			for (int test = 0; test < elementeTestate.size(); test++)
			{
				alDoilea = primulNumar + 1;
				if (elementeTestate.at(test) == text.at(primulNumar))
				{
					++primulNumar; ++alDoilea; ++temp;
				}
			}

			if (temp >= 1) { continue; }

			for (alDoilea; alDoilea < text.size(); alDoilea++)
			{
				if (text[primulNumar] == text[alDoilea])
				{
					++dubluri;
				}

			}
			elementeTestate.push_back(text[primulNumar]);
			if (dubluri % 2 == 1) { ++numereImpare; }
			if (numereImpare > 1) { return false; }
			dubluri = 1;
			++primulNumar;


		}
		return true;
	}


}