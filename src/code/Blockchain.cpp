#include "Blockchain.h"
#include <chrono>
#include <iostream>

namespace CryptoReSearch{

    Blockchain::Blockchain(){
        _chain.push_back(create_genesis_block());        
    }

    Block Blockchain::create_genesis_block(){
        return Block(0, "Genesis Block", std::chrono::system_clock::now(),0,"0");
    }

    Block Blockchain::get_latest_block(){
        return _chain[_chain.size() - 1];
    }

    void Blockchain::add_block(Block new_block){
        new_block.get_previous_hash() = get_latest_block().get_hash();
        new_block.get_hash() = new_block.calculate_hash();
        _chain.push_back(new_block);
    }

    bool Blockchain::is_valid(){
        
        for(std::vector<Block>::size_type i = 1; i < _chain.size(); ++i){

            Block curr_block = _chain[i];
            Block prev_block = _chain[i - 1];

            //std::cout << "IS VALID METHOD: \n";
            //std::cout << curr_block.get_hash() << '\n' << curr_block.calculate_hash() << '\n';
            //std::cout << "END OF IS VALID METHOD\n";

            if(curr_block.get_hash() != curr_block.calculate_hash())
                return false;

            if(curr_block.get_previous_hash() != prev_block.get_hash())
                return false;
        }

        return true;
    }

    std::vector<Block> Blockchain::get_chain() const{
        return _chain;
    }

}