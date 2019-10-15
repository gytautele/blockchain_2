#include "blockchain.h"

Blockchain::Blockchain() { //blockchain constructor
    _vChain.emplace_back(Block(0, "Genesis Block")); //genesis block is added to _vChain vector
    _nDifficulty = 6;
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}