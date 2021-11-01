#include <iostream>
#include <chrono>

#include "Block.h"
#include "Blockchain.h"

int main()
{

    //CryptoReSearch::Block block{2, std::string{"kati"}, std::chrono::system_clock::now()};

    //std::cout << block.calculate_hash() << '\n';

    CryptoReSearch::Blockchain chen;
    //chen.add_block(CryptoReSearch::Block{1, "prwtos", std::chrono::system_clock::now()});
    //chen.add_block(block);

    std::cout << (chen.is_valid() ? "True" : "False") << '\n';
    std::cout << "Genesis block hash: " + (chen.get_chain()[0].get_hash()) << "\n";
    std::cout << "Genesis previous block hash: " + (chen.get_chain()[0].get_previous_hash()) << "\n";
    std::cout << "First block hash: " + (chen.get_chain()[1].get_hash()) << '\n';
    std::cout << "First previous block hash: " + (chen.get_chain()[1].get_previous_hash()) << "\n";
}