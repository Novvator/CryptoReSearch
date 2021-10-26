
#include <Block.h>

#include <sstream>

namespace CryptoReSearch{

    Block::Block(uint64_t index, std::string data, std::chrono::system_clock date, std::string previous_hash){

        my_index = index;
        my_data = data;
        my_date = date;
        my_previous_hash = previous_hash;

    }


    std::string Block::calculate_hash(){

        std::stringstream output;
        
        time_t now_tt;

        {
            using namespace std::chrono;
            
            system_clock::time_point now_tp = system_clock::now();
            now_tt = system_clock::to_time_t(now_tp);
        }
        
        output << my_index << ' ' << my_data << ' ' << ctime(&now_tt) << ' ' << my_previous_hash;

        return sha256(output.str());
    }


}
