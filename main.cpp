#include "blockchain.h"

/* this one creates a new blockchain and informs the user that a block is being mined by printing to the output buffer then creates a new block and adds it to the chain;
the process for mining that block will then kick off until a valid hash is found.
Once the block is mined the process is repeated for two more blocks.*/

int main() {
    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1 Data"));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data"));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data"));

    return 0;
}