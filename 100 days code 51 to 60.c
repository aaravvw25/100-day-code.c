//Q101: Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.

/*
Sample Test Cases:
Input 1:
nums = [5,7,7,8,8,10], target = 8
Output 1:
3,4

Input 2:
 nums = [5,7,7,8,8,10], target = 6
Output 2:
-1,-1

Input 3:
 nums = [5,7,7,8,8,10], target = 10
Output 3:
5,5

*/
#include <stdio.h>

int main() {
    int nums[] = {5,7,7,8,8,10};
    int target = 8;
    int n = sizeof(nums)/sizeof(nums[0]);
    int first = -1, last = -1;
    for(int i=0; i<n; i++) {
        if(nums[i] == target) {
            if(first == -1) {
                first = i;
            }
            last = i;
        }
    }
    printf("%d,%d\n", first, last);
    
    return 0;
}   
//Q102: Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. This element is called the ceil of x. If such an element does not exist, print -1. Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

/*
Sample Test Cases:
Input 1:
arr = [1, 2, 8, 10, 11, 12, 19], x = 5
Output 1:
2

Input 2:
arr = [1, 2, 8, 10, 11, 12, 19], x = 20
Output 2:
-1

Input 3:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output 3:
0

Input 4:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 2
Output 4:
2

*/
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 8, 10, 11, 12, 19};
    int x = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ceilIndex = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] >= x) {
            ceilIndex = i;
            break;
        }
    }
    printf("%d\n", ceilIndex);
       
    return 0;
}
//Q103: Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.

/*
Sample Test Cases:
Input 1:
nums = [1,7,3,6,5,6]
Output 1:
3

Input 2:
nums = [1,2,3]
Output 2:
-1

Input 3:
nums = [2,1,-1]
Output 3:
0

*/
#include <stdio.h>

int main() {
    int nums[] = {1,7,3,6,5,6};
    int n = sizeof(nums)/sizeof(nums[0]);
    int totalSum = 0;
    for(int i=0; i<n; i++) {
        totalSum += nums[i];
    }
    int leftSum = 0;
    for(int i=0; i<n; i++) {
        if(leftSum == totalSum - leftSum - nums[i]) {
            printf("%d\n", i);
            return 0;
        }
        leftSum += nums[i];
    }
    printf("-1\n");
       
    return 0;
}
//Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.

/*
Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1

*/
#include <stdio.h>

int main() {
    int n = 8;
    int totalSum = n * (n + 1) / 2;
    for(int x = 1; x <= n; x++) {
        int leftSum = x * (x + 1) / 2;
        int rightSum = totalSum - (x * (x - 1) / 2);
        if(leftSum == rightSum) {
            printf("%d\n", x);
            return 0;
        }
    }
    printf("-1\n");
       
    return 0;
}
/Q105: Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.

/*
Sample Test Cases:
Input 1:
nums = [3,2,3]
Output 1:
3

Input 2:
nums = [2,2,1,1,1,2,2]
Output 2:
2

Input 3:
nums = [2,2,1,1,1,2,2,3]
Output 3:
-1

*/
#include <stdio.h>

int main() {
    int nums[] = {2,2,1,1,1,2,2};
    int n = sizeof(nums)/sizeof(nums[0]);
    int count[1000] = {0}; 
    for(int i=0; i<n; i++) {
        count[nums[i]]++;
    }
    int majorityElement = -1;
    for(int i=0; i<1000; i++) {
        if(count[i] > n/2) {
            majorityElement = i;
            break;
        }
    }
    printf("%d\n", majorityElement);

    return 0;
}
/*Q106: Write a program to take an array arr[] of integers as input, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1.

N.B:
- Print the output for each element in a comma separated fashion.
- Do not use Stack, use brute force approach (nested loop) to solve.
Sample Test Cases:
Input 1:
arr = [1, 3, 2, 4]
Output 1:
3, 4, 4, -1

Input 2:
arr = [6, 8, 0, 1, 3]
Output 2:
8, -1, 1, 3, -1

Input 3:
arr = [1, 2, 3, 5]
Output 3:
2, 3, 5, -1

Input 4:
arr = [5, 4, 3, 1]
Output 4:
-1, -1, -1, -1

*/
#include <stdio.h>

int main() {
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int nextGreater[n];
    for(int i=0; i<n; i++) {
        nextGreater[i] = -1; 
        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[i]) {
                nextGreater[i] = arr[j];
                break;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(i != 0) {
            printf(", ");
        }
        printf("%d", nextGreater[i]);
    }
    printf("\n");

    return 0;
}
//Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

/*
Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]

*/
#include <stdio.h>

int main() {
    int nums[] = {1,2,3,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    int answer[n];
    for(int i=0; i<n; i++) {
        int product = 1;
        for(int j=0; j<n; j++) {
            if(i != j) {
                product *= nums[j];
            }
        }
        answer[i] = product;
    }
    printf("[");
    for(int i=0; i<n; i++) {
        if(i != 0) {
            printf(", ");
        }
        printf("%d", answer[i]);
    }
    printf("]\n");
       
    return 0;
}
//Q109: Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.

/*
Sample Test Cases:
Input 1:
arr[100, 200, 300, 400] = , k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20] = , k = 4
Output 2:
39

Input 3:
arr[100, 200, 300, 400] = , k = 1
Output 3:
400

*/
#include <stdio.h>

int main() {
    int arr[] = {100, 200, 300, 400};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum = 0;
    for(int i=0; i<=n-k; i++) {
        int currentSum = 0;
        for(int j=0; j<k; j++) {
            currentSum += arr[i+j];
        }
        if(currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    printf("%d\n", maxSum);
    return 0;
}
//Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.

/*
Sample Test Cases:
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6] = , k = 3
Output 1:
3 3 4 5 5 5 6

Input 2:
arr[5, 1, 3, 4, 2] = , k = 1
Output 2:
5 1 3 4 2

*/
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<=n-k; i++) {
        int maxElem = arr[i];
        for(int j=1; j<k; j++) {
            if(arr[i+j] > maxElem) {
                maxElem = arr[i+j];
            }
        }
        if(i != 0) {
            printf(" ");
        }
        printf("%d", maxElem);
    }
    printf("\n");
       
    return 0;
}