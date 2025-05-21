#include <stdio.h>
#define MAX 10 
#define LEFT -1
#define RIGHT 1
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int next = i + dir[i];
        if (next >= 0 && next < n) {
            if (perm[i] > perm[next] && perm[i] > mobile) {
                mobile = perm[i];
            }
        }
    }
    return mobile;
}
int getIndex(int perm[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == mobile) {
            return i;
        }
    }
    return -1;
}
int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
int main() {
    int n;
    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX || n < 1) {
        printf("Invalid input. Please enter 1 to %d.\n", MAX);
        return 1;
    }
    int perm[MAX], dir[MAX];
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }
    int total = factorial(n);
    printPermutation(perm, n);
    for (int count = 1; count < total; count++) {
        int mobile = getMobile(perm, dir, n);
        int idx = getIndex(perm, n, mobile);
        int swapIdx = idx + dir[idx];
        int temp = perm[idx];
        perm[idx] = perm[swapIdx];
        perm[swapIdx] = temp;
        int tempDir = dir[idx];
        dir[idx] = dir[swapIdx];
        dir[swapIdx] = tempDir;
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile) {
                dir[i] = -dir[i];
            }
        }
        printPermutation(perm, n);
    }
    return 0;
}