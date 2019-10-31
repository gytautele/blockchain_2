#include "../headers/header.h"

int main()
{
	MyChain Blocky = MyChain();
	vector <User> vartotojai;
	vector <Transaction> Visos;
	vector <Transaction> Atrinktos;
	skaitymas(vartotojai);

	uint32_t index = 2;

	bool error = false, found = false;

	kurimas(vartotojai, Visos);

	while (Visos.size() > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			BlokoKurimas(Visos, Blocky, index, found);
			if (found)
			{
				index++;
				break;
			}
		}
		if (!found)
			cout << "Nepavyko iskasti naujo bloko" << endl;
		found = false;
	}
}