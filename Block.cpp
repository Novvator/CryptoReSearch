
#include "Block.h"

#include <sstream>

namespace CryptoReSearch{

    Block::Block(uint64_t index, std::string data, std::chrono::system_clock::time_point date, std::string previous_hash){

            _index = index;
            _data = data;
            _date = date;
            _previous_hash = previous_hash;
            _hash = calculate_hash();
    }

    std::string& Block::get_hash() {
        return _hash;
    }

    std::string& Block::get_previous_hash(){
        return _previous_hash;
    }

    std::string Block::calculate_hash(){

        std::stringstream output;

        time_t now_tt;

        {
            using namespace std::chrono;
            now_tt = system_clock::to_time_t(_date);
        }

        output << _index << _data << now_tt << _previous_hash;

        return sha256(output.str());
    }
    
    std::string Block::get_date() const{

        time_t now_tt;

        {
            using namespace std::chrono;
            now_tt = system_clock::to_time_t(_date);
        }

        return ctime(&now_tt);
    }


}
