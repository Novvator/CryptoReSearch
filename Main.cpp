#include <iostream>
#include <chrono>

#include "Block.h"
#include "Blockchain.h"

int main()
{

    CryptoReSearch::Block block{2, std::string{"kati"}, std::chrono::system_clock::now()};

    std::cout << block.calculate_hash() << '\n';

    CryptoReSearch::Blockchain chen;
    chen.add_block(CryptoReSearch::Block{1, std::string{"prwtos"}, std::chrono::system_clock::now()});
    chen.add_block(block);

    std::cout << (chen.is_valid() ? "True" : "False") << '\n';

}