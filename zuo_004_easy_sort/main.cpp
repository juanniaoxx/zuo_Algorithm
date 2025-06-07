#include "./function.h"
using std::cout;
using std::cin; 
using std::endl;

int main(void) {
    int array_1[10] = {7, 23, 45, 58, 12, 89, 34, 76, 91, 3};
    cout << "Use selection_sort" << endl;
    selection_sort(array_1, 10);
    cout << "-----------------"<< endl;
    cout << "Use bubble_sort" << endl;
    int array_2[10] = {7, 23, 45, 58, 12, 89, 34, 76, 91, 3};
    bubble_sort(array_2, 10);
    cout << "-----------------"<< endl;
    cout << "Use insertion_sort" << endl;
    int array_3[10] = {7, 23, 45, 58, 12, 89, 34, 76, 91, 3};
    insertion_sort(array_3, 10);

    return 0;
}