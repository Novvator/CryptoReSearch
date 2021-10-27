#include "Blockchain.h"
#include <chrono>

namespace CryptoReSearch{

    Blockchain::Blockchain(){
        _chain.push_back(create_genesis_block());        
    }

    Block Blockchain::create_genesis_block(){
        return Block(0, "Genesis Block", std::chrono::system_clock::now(),"0");
    }

    Block Blockchain::get_latest_block(){
        return _chain[_chain.size() - 1];
    }

    void Blockchain::add_block(Block& new_block){
        new_block.get_previous_hash() = get_latest_block().get_hash();
        new_block.get_hash() = new_block.calculate_hash();
        _chain.push_back(new_block);
    }

}