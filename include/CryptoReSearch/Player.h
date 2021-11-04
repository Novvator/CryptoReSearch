
#pragma once
#ifndef _PLAYER_GUARD
#define _PLAYER_GUARD

#include <cstdint>
#include <string>

#include "Block.h"

namespace CryptoReSearch{

    class Player{
    
        uint64_t    _player_id; //Player id
        uint64_t    _nonce; //Nonce value
        uint64_t    _block_index;
    public:

        Player(uint64_t player_id);

        Block try_to_mine_block(std::string previous_hash, uint64_t difficulty);
    };
}

#endif // _PLAYER_GUARD
