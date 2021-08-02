#include "Rearanjeaza.h"

void rearanjeaza(std::string& sirul)
{
	//in functie de cate caractere are sirul procedam diferit (numar par sau impar de caractere)
	if(sirul.size()%2==0)
	{
	std::vector <char> primaJumatate;
	std::vector <char> aDouaJumatate;
	//vector in care stocam dublurile
	std::vector <char> stocare;
	//vom sterge din sir caractere deci folosim while
		while(sirul.size()!=0)
		{
			//parcurgem sirul, stocam dublurile si le stergem din sir
			int i = 0;
			for(int j=1;j<sirul.size();j++)
			{
				if (sirul.at(i) == sirul.at(j)) 
				{ stocare.push_back(sirul.at(j)); 
				sirul.erase(j, 1);
				//in cazul in care gasim dubluri decrementam ca sa nu sarim un index
				--j;
				}
			}
			//stocam in 2 vectori jumatate din numarul de dubluri
			// 1 vector o jumatate, celalalt alta
			stocare.push_back(sirul.at(i));
			sirul.erase(i, 1);
			for(int var=0;var<stocare.size()/2;var++)
			{
				primaJumatate.push_back(stocare.at(var));
			}
			for (int var2 = 0; var2 < stocare.size() / 2; var2++)
			{
				aDouaJumatate.push_back(stocare.at(var2));
			}
			while (stocare.size() != 0) { stocare.pop_back(); }
		}
		//variabila in care inversam indecsii
		std::string temp;
		for (int i = aDouaJumatate.size()-1; i >=0; i--) 
		{
			temp = temp + aDouaJumatate.at(i);
		}
		//asamblam palindromul
		for(int k=0;k<primaJumatate.size();k++)
		{
			sirul = sirul + primaJumatate.at(k);
		}
		for (int l = 0; l < temp.size(); l++)
		{
			sirul = sirul + temp.at(l);
		}
	}
	else
	{
		// in cazul in care avem sir cu numar impar avem nevoie de un mijloc
		//in rest e identic
		std::vector <char> primaJumatate;
		std::vector <char> aDouaJumatate;
		char mijloc=' ';
		std::vector <char> stocare;

		while (sirul.size() != 0)
		{
			int i = 0;
			for (int j = 1; j < sirul.size(); j++)
			{
				if (sirul.at(i) == sirul.at(j))
				{
					stocare.push_back(sirul.at(j));
					sirul.erase(j, 1);
					--j;
				}
			}
			stocare.push_back(sirul.at(i));
			sirul.erase(i, 1);
			if (stocare.size() % 2 == 0) {
				for (int var = 0; var < stocare.size() / 2; var++)
				{
					primaJumatate.push_back(stocare.at(var));
				}
				for (int var2 = 0; var2 < stocare.size() / 2; var2++)
				{
					aDouaJumatate.push_back(stocare.at(var2));
				}
				while (stocare.size() != 0) { stocare.pop_back(); }
			//gasim dublurile cu numar impar
			}else
			{
				for (int var = 0; var < stocare.size() / 2; var++)
				{
					primaJumatate.push_back(stocare.at(var));
				}
				for (int var2 = 0; var2 < stocare.size() / 2; var2++)
				{
					aDouaJumatate.push_back(stocare.at(var2));
				}
				//inainte sa stergem tot din vector setam mijlocul
				mijloc = stocare.at(0);
				while (stocare.size() != 0) { stocare.pop_back(); }
			}
		}
		std::string temp;
		for (int i = aDouaJumatate.size() - 1; i >= 0; i--)
		{
			temp = temp + aDouaJumatate.at(i);
		}
		for (int k = 0; k < primaJumatate.size(); k++)
		{
			sirul = sirul + primaJumatate.at(k);
		}
		sirul += mijloc;
		for (int l = 0; l < temp.size(); l++)
		{
			sirul = sirul + temp.at(l);
		}

	}

}
