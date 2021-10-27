
#pragma once
#ifndef _BLOCK_GUARD
#define _BLOCK_GUARD

#include <cstdint>
#include <chrono>

#include "sha256.h"

namespace CryptoReSearch{

    class Block{
        
        uint64_t                                _index;           // Chain position
        std::string                             _data;            // Data in the current block
        std::chrono::system_clock::time_point   _date;            // The date that the block was created
        std::string                             _hash;            // This block's hash
        std::string                             _previous_hash;   // Hash value of the previous block

    public:
        Block(uint64_t index, std::string data, std::chrono::system_clock::time_point date, std::string previous_hash = "");

        std::string calculate_hash();
        std::string& get_previous_hash();
        std::string get_hash();
    };
}

#endif // _BLOCK_GUARD
