#include "blockchain.h"
#include <iostream>

/* this one creates a new blockchain and informs the user that a block is being mined by printing to the output buffer then creates a new block and adds it to the chain;
the process for mining that block will then kick off until a valid hash is found.
Once the block is mined the process is repeated for two more blocks.*/

int main() {
    Blockchain bChain = Blockchain();

	int n=0;

    cout << "How many block should be mined?"<<endl;
    std::cin >> n;
    

    for (int i=1; i<=n; i++)
    {
    	cout << "Mining block " << i <<endl;
    bChain.AddBlock(Block(i, "Block Data"));
    }
    

    return 0;
}