#include <stdio.h>
#include <stdlib.h>

void eingabe(int *arr, int size) {

    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

}

void sort(int *arr, int size) {

    int tmp;

    for(int i = 1; i < size; i++) {

        for(int j = 0; j < size - i; j++) {

          if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

}

void smallestdifference(int *arr1, int *arr2, int size1, int size2) {

    sort(arr1, size1);
    sort(arr2, size2);

    int i = 0, j = 0;
    int a = 0, b = 0;
    int minDiff = abs(arr1[0] - arr2[0]);

    while (i < size1 && j < size2) {

        int currentDiff = abs(arr1[i] - arr2[j]);

        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            a = arr1[i];
            b = arr2[j];
        }

        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    printf("%d (%d, %d)", abs(a - b), a, b);
}

int main () {

    int size1, size2;

    scanf("%d", &size1);
    int arr1[size1];

    scanf("%d", &size2);
    int arr2[size2];

    printf(": ");
    eingabe(arr1, size1);
    eingabe(arr2, size2);

    smallestdifference(arr1, arr2, size1, size2);

    return 0;
}
