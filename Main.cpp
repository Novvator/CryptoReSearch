#include <iostream>
#include <chrono>

#include "Block.h"
#include "Blockchain.h"
#include "Player.h"

int main()
{

    CryptoReSearch::Block block{0, "", std::chrono::steady_clock::now(), 0, ""};
    CryptoReSearch::Blockchain chain;

    chain.add_block(block);

    CryptoReSearch::Player player{0};
}