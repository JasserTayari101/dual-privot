#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    int compare_cnt = 0;
    int n;

    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // TODO    

    free(arr);
    return 0;
}
