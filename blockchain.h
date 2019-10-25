#include <cstdint>
#include <vector>
#include <iostream>
#include <sstream>
#include "block.h"

using std::vector;
using std::cout;
using std::endl;
using std::stringstream;

class Blockchain {
public:
    Blockchain(); //constructor

    void AddBlock(Block bNew); //takes a parameter bNew which must be an object of the Block

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const; //const for denoting that the output of the function cannot be changed
};
