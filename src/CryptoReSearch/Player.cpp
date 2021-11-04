
#include "CryptoReSearch/Player.h"

#include <sstream>
#include <chrono>

#include "sha256/sha256.h"

namespace CryptoReSearch{

    Player::Player(uint64_t player_id){
        _player_id = player_id;
        _nonce = 0;
        _block_index = 0;
    }

    Block Player::try_to_mine_block(std::string previous_hash, uint64_t difficulty)
    {
        std::stringstream zeroes;
        for (uint64_t i = 0; i < difficulty; i++)
        {
            zeroes << 0;
        }
        
        
        for (uint64_t i = 0; i < 100; i++)
        {
            std::stringstream output;

            time_t now_tt;

            auto date = std::chrono::system_clock::now();

            {
                using namespace std::chrono;
                now_tt = system_clock::to_time_t(date);
            }

            output << _player_id  << now_tt << previous_hash << _nonce;

            std::string new_hash = sha256(output.str());
            
            if(new_hash.substr(0, difficulty) == zeroes.str())
            {
                return Block{_player_id, "", date, new_hash, _nonce, previous_hash};
            }

            ++_nonce;
        
        }

        return Block{0, "", std::chrono::system_clock::now(), "", 0, ""};



    }


}
