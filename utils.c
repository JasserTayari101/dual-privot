#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void print_array(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// TODO

int* partition(int data[], int l, int r, int* compare_cnt) {
    static int result[2]; // result[0] = left pivot index, result[1] = right pivot index

    if (data[l] < data[r]) { // Ensure left pivot >= right pivot (for decreasing order)
        int temp = data[l];
        data[l] = data[r];
        data[r] = temp;
    }

    int p1 = data[l]; // left pivot
    int p2 = data[r]; // right pivot

    int i = l + 1;
    int j = k;
    int k = r - 1;

    while (j <= k) {
        (*compare_cnt)++; // Always count the comparison

        if (data[j] > p1) { // Larger than left pivot
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
            j++;
        } else if (data[j] < p2) { // Smaller than right pivot
            int temp = data[j];
            data[j] = data[k];
            data[k] = temp;
            k--;
        } else {
            j++;
        }
    }

    i--; k++; // Move to final pivot positions

    // Swap pivots to their final positions
    int temp = data[l];
    data[l] = data[i];
    data[i] = temp;

    temp = data[r];
    data[r] = data[k];
    data[k] = temp;

    result[0] = i; // final position of left pivot
    result[1] = k; // final position of right pivot

    printf("%d %d ", data[i], data[k]); // Debugging output

    return result;
}


void quick_sort(int data[], int l, int r, int* compare_cnt)
{
    // TODO
    if (l < r)
    {
        int* pivot = partition(data, l, r, compare_cnt);
        quick_sort(data, l, pivot[0] - 1, compare_cnt);
        quick_sort(data, pivot[0] + 1, pivot[1] - 1, compare_cnt);
        quick_sort(data, pivot[1] + 1, r, compare_cnt);
    }

}
