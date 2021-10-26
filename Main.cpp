#include <iostream>
#include <chrono>

#include "Block.h"

int main()
{

    CryptoReSearch::Block block{1, std::string{"kati"}, std::chrono::system_clock::now(), std::string{" "}};

    std::cout << block.calculate_hash() << '\n';

}