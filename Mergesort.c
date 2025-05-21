#include <stdio.h>
#include <stdlib.h>
void merge(int B[], int C[], int A[], int p, int q) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k++] = B[i++];
        } else {
            A[k++] = C[j++];
        }
    }
    while (i < p) {
        A[k++] = B[i++];
    }
    while (j < q) {
        A[k++] = C[j++];
    }
}
void mergesort(int A[], int n) {
    if (n < 2) return;
    int mid = n / 2;
    int *B = (int*)malloc(mid * sizeof(int));
    int *C = (int*)malloc((n - mid) * sizeof(int));
    for (int i = 0; i < mid; i++) B[i] = A[i];
    for (int i = mid; i < n; i++) C[i - mid] = A[i];
    mergesort(B, mid);
    mergesort(C, n - mid);
    merge(B, C, A, mid, n - mid);
    free(B);
    free(C);
}
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *A = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Original array: ");
    printArray(A, n);
    mergesort(A, n);
    printf("Sorted array: ");
    printArray(A, n);
    free(A);
    return 0;
}