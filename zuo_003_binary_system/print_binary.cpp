#include "function.h"

// Plan 1 : 使用位掩码逐位打印
void print_binary(int number) {
    for (int i = sizeof(number) * 8 - 1; i >= 0; i --) {
        std::cout << ((number >> i) & 1);
        if (i % 4 == 0) std::cout << ' ';
    }
    std::cout << '\n';
}

// Plan 2 : Using bitset
#include <bitset>
void print_binary_bitset(int number) {
    std::cout << std::bitset<32>(number) << '\n';
}