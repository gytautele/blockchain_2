#include "../headers/header.h"

MyChain::MyChain()
{
	vector<Transaction> Genesis;

	for (int i = 0; i < 100; i++)
	{
		Genesis.push_back(Transaction());
		Genesis[i].SetTransaction(1, "Genesis", "Genesis");
	}

	Chain_.emplace_back(MyBlock(1, Genesis));
	Difficulty_ = 3;
}

void MyChain::AddBlock(MyBlock New)
{
	New.prev_ = GetLastBlock().GetHash();
	Chain_.push_back(New);
}

MyBlock MyChain::GetLastBlock() const
{
	return Chain_.back();
}
