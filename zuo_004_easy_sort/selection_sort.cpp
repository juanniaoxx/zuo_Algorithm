#include "function.h"

void selection_sort(int *q, int size) {
    // sort the array and input every step
    print_array(q, size);
    for (int i = 0; i < size; i ++) {
        if (q == NULL || size < 2) {
            return ;
        }
        int MinIndex = i;
        for (int j = i; j < size; j ++) {
            if (q[j] < q[MinIndex]) MinIndex = j;
        }
        std::swap(q[i], q[MinIndex]);
        print_array(q, size);
    }
}