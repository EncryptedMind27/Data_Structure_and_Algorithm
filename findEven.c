#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* findEven(int[], int);

int main()
{
    srand(time(NULL));

    int length;
    printf("Size: ");
    scanf("%d", &length);
    int *arr = (int*)malloc(sizeof(int) * length);

    for (int x = 0; x < length; x++) {
        arr[x] = rand() % 100 + 1;
    }

    for (int x = 0; x < length; x++) {
        printf("%d ", arr[x]);
    }
    
    int newLength;
    int *newArr = findEven(arr, length);
    newLength = length;

    printf("\n");

    for (int x = 0; x < newLength; x++) {
        printf("%d ", newArr[x]);
    }

    // Free the dynamically allocated memory
    free(arr);
    free(newArr);

    return 0;
}

int* findEven(int arr[], int size) {
    int ctr = 0;
    for (int x = 0; x < size; x++)
        if (!(arr[x] % 2 == 0))
            ctr++;

    int *newArr = (int*)malloc(sizeof(int) * ctr);
    int ctr1 = 0;

    for (int x = 0; x < size; x++)
        if (!(arr[x] % 2 == 0))
            newArr[ctr1++] = arr[x];

    return newArr;
}
