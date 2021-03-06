
#pragma once
#ifndef _BLOCK_GUARD
#define _BLOCK_GUARD

#include <cstdint>
#include <chrono>
#include <string>

namespace CryptoReSearch{

    class Block{
        
        uint64_t                                _player_id;       // Chain position
        std::string                             _data;            // Data in the current block
        std::chrono::system_clock::time_point   _date;            // The date that the block was created
        std::string                             _hash;            // This block's hash
        std::string                             _previous_hash;   // Hash value of the previous block
        uint64_t                                _nonce;           // Nonce value

    public:
        Block(uint64_t player_id, std::string data, std::chrono::system_clock::time_point date,
              std::string hash, uint64_t nonce, std::string previous_hash = "");

        std::string calculate_hash();
        std::string& get_previous_hash();
        std::string& get_hash();
        std::string get_date() const;

    };
}

#endif // _BLOCK_GUARD
