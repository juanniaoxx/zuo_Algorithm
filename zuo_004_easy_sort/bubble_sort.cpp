#include "function.h"

void bubble_sort(int *q, int size) {
    // sort the array and input every step
    print_array(q, size);
    for (int end = size - 1; end > 0 ; end--) {
        if (q == NULL || size < 2) {
            return ;
        }
        for (int i = 0; i < end; i ++) {
            if (q[i] > q[i + 1]) std::swap(q[i], q[i+1]);
        }
        print_array(q, size);
    }
}