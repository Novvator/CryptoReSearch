#include <iostream>
#include <chrono>

#include "Block.h"
#include "Blockchain.h"

int main()
{

    CryptoReSearch::Block block{1, std::string{"kati"}, std::chrono::system_clock::now(), std::string{" "}};

    std::cout << block.calculate_hash() << '\n';

    CryptoReSearch::Blockchain chen;
    chen.add_block(CryptoReSearch::Block(1, "prwtos", std::chrono::system_clock::now));

}