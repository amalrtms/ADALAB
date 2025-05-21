#include <stdio.h>
#include <stdlib.h>
typedef struct item {
    int value, weight;
} Item;
int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    return item2->value * item1->weight - item1->value * item2->weight;
}
double fractionalKnapsack(int W, Item arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);
    double finalValue = 0.0
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    return 0;
}
