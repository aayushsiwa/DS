#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int longestPalindromeSubsequence(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    char* arr = (char*)malloc(length * sizeof(char));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    current = head;
    int i = 0;
    while (current != NULL) {
        arr[i] = current->data;
        i++;
        current = current->next;
    }
    int dp[length][length];
    for (i = 0; i < length; i++) {
        dp[i][i] = 1;
    }
    for (int cl = 2; cl <= length; cl++) {
        for (i = 0; i < length - cl + 1; i++) {
            int j = i + cl - 1;
            if (arr[i] == arr[j] && cl == 2) {
                dp[i][j] = 2;
            } else if (arr[i] == arr[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = (dp[i][j - 1] > dp[i + 1][j]) ? dp[i][j - 1] : dp[i + 1][j];
            }
        }
    }
    int longestLength = dp[0][length - 1];
    free(arr);
    return longestLength;
}

int main() {
    struct Node* head = createNode('A');
    head->next = createNode('B');
    head->next->next = createNode('C');
    head->next->next->next = createNode('B');
    head->next->next->next->next = createNode('A');
    printf("Length of the longest palindrome subsequence: %d\n", longestPalindromeSubsequence(head));
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
