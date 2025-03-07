// Consider a N X N matrix where each element is divided by a column number
// (integer division), i.e. mat[i][j] = floor((i+1)/(j+1)) where 0 &lt;= i &lt; n and 0 &lt;= j &lt; n.
// The task is to find the sum of all matrix elements.

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += (int)floor((i + 1) / (double)(j + 1));
        }
    }
    printf("The sum of all matrix elements is: %d\n", sum);
    return 0;
}
