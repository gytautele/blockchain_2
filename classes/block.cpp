#include "../headers/header.h"

MyBlock::MyBlock(uint32_t IndexIn, vector<Transaction> &DataIn) : Index_(IndexIn)
{
	for (int i = 0; i < DataIn.size(); i++)
	{
		Data_.push_back(DataIn[i]);
	}
	Nonce_ = -1;
	Time_ = time(nullptr);
	CreateMerkel();
}

string MyBlock::GetHash()
{
	return Hash_;
}

void MyBlock::MineBlock(uint32_t Difficulty)
{
	Nonce_++;
	Hash_ = CalculateHash();
}

inline string MyBlock::CalculateHash() const
{
	stringstream ss;

	ss << Index_ << Time_;

	for (int i = 0; i < Data_.size(); i++)
	{
		ss << Data_[i].GetFrom() << Data_[i].GetTo() << Data_[i].GetAmount();
	}

	ss << Nonce_ << prev_;

	return sha256(ss.str());

	// string temp = ss.str();

	// char input[temp.length()];

	// for(int i = 0; i < temp.length(); i++)
	// {
	// 	input[i] = temp[i];
	// }

	// return Convertion(input);
}

string Convertion(char input[])
{
	std::stringstream stream;
	int t[256];
	for (int i = 0; input[i] != '\0'; i++)
	{
		t[i] = input[i];
		stream << std::hex << t[i];
	}
	string output(stream.str());
	return output;
}

void MyBlock::CreateMerkel()
{
	vector<string> merkle;

	for(int i = 0; i < Data_.size(); i++)
	{
		merkle.push_back(Data_[i].GetID());
	}

	if(merkle.size() == 0)
	{
		merkle_ = "0000000000000000000000000000000000000000000000000000000000000000";
		return;
	}

	if(merkle.size() == 1)
	{
		merkle_ = merkle[0];
		return;
	}

	while (merkle.size() > 1)
	{
		if(merkle.size() % 2 != 0)
			merkle.push_back(merkle.back());

		vector<string> new_merkle;

		for(auto it = merkle.begin(); it != merkle.end(); it += 2)
		{
			string concat = (*it) + (*(it+1));
			string hash = sha256(concat);
			new_merkle.push_back(hash);
		}

		merkle = new_merkle;
	}
	merkle_ = merkle[0];
	return;
}