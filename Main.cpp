#include <iostream>
#include <chrono>

#include "CryptoReSearch/Block.h"
#include "CryptoReSearch/Blockchain.h"
#include "CryptoReSearch/Player.h"

int main()
{
    CryptoReSearch::Block block{0, "", std::chrono::system_clock::now(), "", 0, ""};

    CryptoReSearch::Blockchain chain;
    chain.add_block(block);

    CryptoReSearch::Player player{0};

    std::cout << chain.get_chain()[0].get_date() << '\n';
}