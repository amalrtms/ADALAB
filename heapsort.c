#include <stdio.h>
#include<time.h>

void swap(int *a, int *b) {
    int tempvar = *a;
    *a = *b;
    *b = tempvar;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
  
void heapify(int arr[], int n, int i) {
    int greatest = i;
    int leftSide = 2 * i + 1;
    int rightSide = 2 * i + 2;  
    if (leftSide < n && arr[leftSide] > arr[greatest])
      greatest = leftSide;  
    if (rightSide < n && arr[rightSide] > arr[greatest])
      greatest = rightSide;
    if (greatest != i) {
      swap(&arr[i], &arr[greatest]);
      heapify(arr, n, greatest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    printf("Max heap is:\n");
    printArray(arr,n);

    for (int i = n - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}  

int main() {
    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++){
	scanf("%d",&arr[i]); 
    } 
    clock_t start_time = clock();
    heapSort(arr, n);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array is \n");
    printArray(arr, n);
    printf("Time taken for Heap Sort: %f seconds\n", time_taken);
}
