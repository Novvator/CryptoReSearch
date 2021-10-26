
#pragma once
#ifndef _BLOCK_GUARD
#define _BLOCK_GUARD

#include <cstdint>
#include <chrono>

#include <sha256.h>

namespace CryptoReSearch{

    class Block{
        
        uint64_t my_index;
        std::string my_data;
        std::chrono::system_clock my_date;
        std::string my_previous_hash;

    public:
        Block(uint64_t index, std::string data, std::chrono::system_clock date, std::string previous_hash);

        std::string calculate_hash();
    };
}

#endif // _BLOCK_GUARD
