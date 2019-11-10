#include <stdlib.h>

size_t maxSeq(int *array, size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int temp_arr[n];
    for (int k = 0; k < n; k++) {
        temp_arr[k] = 1;
    }

    size_t j = 0;
    size_t result;

    result = temp_arr[0];
    for (size_t i = 1; i < n; i++) {
        if (array[i] > array[i - 1]) {
            temp_arr[j] += 1;
        } else {
            j = j + 1;
        }
    }
    for (size_t i = 0; i < n; i++) {
        if (result < temp_arr[i]) {
            result = temp_arr[i];
        }
    }
    return result;
}