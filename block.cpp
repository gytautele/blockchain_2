#include "block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) { //block constructor
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1]; //array of characters
    for (uint32_t i = 0; i < nDifficulty; ++i) { //filling array with zero
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0'; //for the last element of array is given line end character

    string str(cstr); //converting to string

    do { //is repeated until the match is found
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str); //the front hash is compared to the string

    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const { //inline makes the code more efficient as the compiler places the method’s instructions inline wherever the method is called; this cuts down on separate method calls
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash; //aded all values to the stream

    return sha256(ss.str()); //returned output of the sha256 using the string output from the string stream
}