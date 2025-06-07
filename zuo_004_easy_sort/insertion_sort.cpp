#include "function.h"

void insertion_sort(int *q, int size) {
    // sort the array and input every step
    print_array(q, size);
    if (q == NULL || size < 2) return ;
    for (int i = 0; i < size; i ++) {
        for (int j = i - 1; j >= 0 && q[j] > q[j + 1]; j--) {
            std::swap(q[j], q[j + 1]);
        }
        print_array(q, size);
    }
}