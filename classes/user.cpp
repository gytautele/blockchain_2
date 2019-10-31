#include "../headers/header.h"

User::User()
{
	name_ = "";
	surname_ = "";
	bling_ = 0;
	public_key = "";
}

void User::irasymas(std::istringstream& skaitymas)
{
	skaitymas >> name_;
	skaitymas >> surname_;
	skaitymas >> bling_;
	stringstream ss;
	ss << name_ << surname_ << bling_;
	public_key = sha256(ss.str());
}

void skaitymas(vector <User> &Users)
{
	std::ifstream in;
	in.open("vartotojai.txt");
	int temp = 0;
	string eilute;
	while (getline(in, eilute))
	{
		std::istringstream skaityti(eilute);
		Users.push_back(User());
		Users[temp].irasymas(skaityti);
		temp++;
	}
	in.close();
}

void kurimas(vector <User>& vartotojai, vector <Transaction>& Visos)
{
	std::random_device r;
	std::default_random_engine el(r());
	std::uniform_int_distribution<int> uniform_dist(1, 1000);

	int amount = 0, x, y;

	while (Visos.size() != 10000)
	{
		amount = uniform_dist(el);
		x = uniform_dist(el) - 1;
		do
		{
			y = uniform_dist(el) - 1;

		} while (x == y);

		if (vartotojai[x].GetBling() >= amount)
			Trans(vartotojai[x], vartotojai[y], amount, Visos);
	}
}

void atrinkimas(vector <Transaction>& Visos, vector <Transaction>& Atrinktos)
{
	std::random_device r;
	std::default_random_engine el(r());
	std::uniform_int_distribution<int> uniform_dist(0, Visos.size() - 1);

	int x;

	bool error = false;

	vector <Transaction> temp;

	while (Atrinktos.size() != 100)
	{
		x = uniform_dist(el);
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i].GetID() == Visos[x].GetID())
			{
				error = true;
				break;
			}
		}
		if (!error)
		{
			Atrinktos.push_back(Visos[x]);
			temp.push_back(Visos[x]);
		}
		else
			error = false;
	}
}

void BlokoKurimas(vector<Transaction>& Visos, MyChain& Blocky, uint32_t& index, bool& found)
{
fail:
	vector<Transaction> A;
	atrinkimas(Visos, A);
	bool error = false;
	int k = 0;
	string test;
	for (int i = 0; i < A.size(); i++)
	{
		stringstream ss;
		ss << A[i].GetFrom() << A[i].GetTo() << A[i].GetAmount();
		test = sha256(ss.str());
		if (A[i].GetID() == test)
			k++;
	}

	if (k < A.size())
	{
		error = true;
	}
	if (error)
	{
		cout << "Sugadinta tranakcija" << endl;
		error = false;
		goto fail;
	}

	MyBlock B(index, A);
	while (B.GetNonce() != MaxNonce)
	{
		B.MineBlock(Blocky.GetDiff());

		char cstr[Blocky.GetDiff() + 1];
		for (uint32_t i = 0; i < Blocky.GetDiff(); i++)
		{
			cstr[i] = '0';
		}
		cstr[Blocky.GetDiff()] = '\0';

		string str(cstr);

		if (B.GetHash().substr(0, Blocky.GetDiff()) == str)
		{
			Blocky.AddBlock(B);

			found = true;


			for (int i = 0; i < 100; i++)
			{
				for (int w = 0; w < Visos.size(); w++)
				{
					if (A[i].GetID() == Visos[w].GetID())
					{
						Visos.erase(Visos.begin() + w);
						w--;
						break;
					}
				}
			}
			cout << "MyBlock mined from B: " << B.GetHash() << endl;
			break;
		}
	}
}