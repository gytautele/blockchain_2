#include <cstdint>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

class Block {
public:
    string sPrevHash; //each block is linked to the previous block

    Block(uint32_t nIndexIn, const string &sDataIn); //const is used with & so that parameters can't be changed

    string GetHash();

    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const; //const this is for ensuring that the method can't change any of the variables
};