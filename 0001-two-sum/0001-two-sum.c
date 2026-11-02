#include <stdlib.h>

// Helper structure to store the value and its original index
typedef struct {
    int val;
    int index;
} Element;

// Comparison function for qsort
int compare(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;
    if (elemA->val < elemB->val) return -1;
    if (elemA->val > elemB->val) return 1;
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the elements array
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }
    
    // Sort the array based on values - O(n log n)
    qsort(arr, numsSize, sizeof(Element), compare);
    
    // Use two pointers to find the target sum - O(n)
    int left = 0, right = numsSize - 1;
    while (left < right) {
        long long sum = (long long)arr[left].val + arr[right].val; // Prevent potential integer overflow
        
        if (sum == target) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = arr[left].index;
            result[1] = arr[right].index;
            *returnSize = 2;
            free(arr);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // Fallback (though constraints guarantee a solution exists)
    *returnSize = 0;
    free(arr);
    return NULL;
}