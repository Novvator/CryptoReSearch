#include <iostream>
#include <chrono>

#include "Block.h"
#include "Blockchain.h"

int main()
{

    CryptoReSearch::Block block{1, std::string{"kati"}, std::chrono::system_clock::now()};

    std::cout << block.calculate_hash() << '\n';

    CryptoReSearch::Blockchain chen;
    CryptoReSearch::Block temp_block{1, std::string{"prwtos"}, std::chrono::system_clock::now()};
    chen.add_block(temp_block);

    std::cout << chen.is_chain_valid() << '\n';

}