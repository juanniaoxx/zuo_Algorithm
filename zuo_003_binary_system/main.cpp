// test main function
#include "./function.h"

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    // test 1:print binary code
    cout << "Test 1:print binary" << '\n';
    int a = 0b1101;
    int b = 0xab;
    int c = -1111;
    print_binary(a);
    print_binary_bitset(b);
    print_binary(c);
    print_binary_bitset(c);
    cout << "--------------------" << '\n';
    // test 2:Commonly used symbols
    cout << "Test 2:Commonly used symbols" << '\n';
    cout << "The opposite of the number" << '\n';
    int d = 0b1111;
    cout << "a = ";
    print_binary(d);
    cout << "-a = ";
    print_binary(-d);
    // 整数最小值的特殊性
    cout << "The opposite of the minimum is still itself." << '\n';
    int min = 0x80000000;
    cout << "min = ";
    print_binary(min);
    cout << "-min = ";
    print_binary(-min);
    cout << "--------------------" << '\n';
    cout << "Shift right operation for signed numbers" << '\n';
    int h = 0xfa;
    int n = -0xfa;
    cout << h << " = ";
    print_binary(h);
    cout << "h >> 2 = ";
    print_binary(h >> 2);
    cout << n << " = ";
    print_binary(n);
    cout << "n >> 2 = ";
    print_binary(n >> 2);
    return 0;
}