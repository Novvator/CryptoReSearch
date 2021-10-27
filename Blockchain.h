
#pragma once
#ifndef _BLOCKCHAIN_GUARD
#define _BLOCKCHAIN_GUARD

#include <vector>
#include "Block.h"

namespace CryptoReSearch{

    class Blockchain{
        std::vector<Block> _chain;

    public:
        Blockchain();

        Block create_genesis_block();
        Block get_latest_block();
        void add_block(Block);
        bool is_valid();
    };
}
#endif //_BLOCKCHAIN_GUARD