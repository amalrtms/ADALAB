#include <stdio.h>
#include<time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int hoarePartition(int A[], int l, int r) {
    int p = A[l];
    int i = l - 1, j = r + 1;
    
    while (1) {
        do {
            i++;
        } while (A[i] < p);
        do {
            j--;
        } while (A[j] > p);
        if (i >= j) {
            return j;
        }
        swap(&A[i], &A[j]);
    }
}
void quicksort(int A[], int l, int r) {
    if (l < r) {
        int s = hoarePartition(A, l, r);
        quicksort(A, l, s);
        quicksort(A, s + 1, r);
    }
}
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main() {
    clock_t start,end;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Original array: ");
    printArray(A, n);
    start = clock();
    quicksort(A, 0, n - 1);
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    printArray(A, n);
    printf("Time taken to sort %d elements = %.6f seconds\n", n, time_taken);
    return 0;
}
