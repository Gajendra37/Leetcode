/*
Description:

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
  
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/

//Solution:

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define SIZE 10007

Node* table[SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(int key) {
    int h = hash(key);
    Node* curr = table[h];

    while (curr) {
        if (curr->key == key) {
            curr->value++;
            return;
        }
        curr = curr->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = table[h];
    table[h] = newNode;
}

int get(int key) {
    int h = hash(key);
    Node* curr = table[h];

    while (curr) {
        if (curr->key == key)
            return curr->value;
        curr = curr->next;
    }
    return 0;
}

int subarraySum(int* nums, int numsSize, int k) {
    for (int i = 0; i < SIZE; i++) table[i] = NULL;

    int sum = 0, count = 0;

    insert(0);  

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];

        count += get(sum - k);
        insert(sum);
    }

    return count;
}
