//Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

/*
Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0

*/
#include <stdio.h>

int main() {
    int arr[] = {-8, 2, 3, -6, 10};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<=n-k; i++) {
        int firstNeg = 0; 
        for(int j=0; j<k; j++) {
            if(arr[i+j] < 0) {
                firstNeg = arr[i+j];
                break;
            }
        }
        if(i != 0) {
            printf(" ");
        }
        printf("%d", firstNeg);
    }
    printf("\n");
                        
    return 0;
}   
//Q112: Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.

/*
Sample Test Cases:
Input 1:
arr[] = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11

Input 2:
arr[] = [-2, -4]
Output 2:
-2

Input 3:
arr[] = [5, 4, 1, 7, 8]
Output 3:
25

*/
#include <stdio.h>

int main() {
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    for(int i=1; i<n; i++) {
        if(maxEndingHere + arr[i] > arr[i]) {
            maxEndingHere += arr[i];
        } else {
            maxEndingHere = arr[i];
        }
        if(maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
        }
    }
    printf("%d\n", maxSoFar);
                        
    return 0;
}   
// Q113: Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.

/*
Sample Test Cases:
Input 1:
arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output 1:
5

Input 2:
arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output 2:
7

*/
#include <stdio.h>

int main()
{
    int arr[] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("%d\n", arr[k - 1]);


    return 0;
}
//Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

/*
Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram

*/
#include <stdio.h>

int main() {
    char s[1000], t[1000];
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("Enter the second string: ");    
    scanf("%s", t);
    int count[26] = {0};    
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }                                           
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i] - 'a']--; 
    }           
    int isAnagram = 1;  
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            isAnagram = 0;
            break;
        }
    }               
    if (isAnagram) {
        printf("Anagram\n");    
    } else {    
        printf("Not Anagram\n");    
    }   


       return 0;
}
//Q116: Write a program to take an integer array nums which contains only positive integers, and an integer target as inputs. The goal is to find two distinct indices i and j in the array such that nums[i] + nums[j] equals the target. Assume exactly one solution exists and return the indices in any order. Print the two indices separated by a space as output. If no solution exists, print "-1 -1".

/*
Sample Test Cases:
Input 1:
nums = [2,7,11,15], target = 9
Output 1:
0 1

Input 2:
nums = [3,2,4], target = 6
Output 2:
1 2

Input 3:
nums = [3,3], target = 6
Output 3:
0 1

*/
#include <stdio.h>

int main() {
    int nums[1000], n, target;
    int i, j, found = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);    
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Enter the target value: ");
    scanf("%d", &target);
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                found = 1;
                break;
            }
        }
        if(found) {
            break;
        }
    }
    if(!found) {
        printf("-1 -1\n");
    }     
    return 0;
}   
//Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number

/*
Sample Test Cases:
Input 1:
nums1 = [0,3,2,4]
Output 1:
1

Input 2:
nums1 = [1,2,3]
Output 2:
0

Input 3:
nums1 = [0,4,3,1,5]
Output 3:
2

*/
#include <stdio.h>

int main() {
    int nums1[1000], n;
    int i, total_sum, array_sum;    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }
    total_sum = n * (n + 1) / 2;
    array_sum = 0;
    for(i = 0; i < n; i++) {
        array_sum += nums1[i];
    }   
    printf("The missing number is: %d\n", total_sum - array_sum); 
    return 0;
}
//Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

/*
Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1

*/
#include <stdio.h>

int main() {
    int nums1[1000], n;
    int i;
    printf("Enter the number of elements in the array: ");  
    scanf("%d", &n);    
    printf("Enter the elements of the array: ");    
    for(i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }   
    int seen[1000] = {0};   
    for(i = 0; i < n; i++) {
        if(seen[nums1[i]] == 1) {
            printf("The repeated element is: %d\n", nums1[i]);
            break;
        }
        seen[nums1[i]] = 1;
    }
                                    
    return 0;
}
//Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

/*
Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1

*/
#include <stdio.h>

int main() {
    int nums1[1000], n;
    int i;  
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }       
    int seen[1000] = {0};   
    for(i = 0; i < n; i++) {
        if(seen[nums1[i]] == 1) {
            printf("The repeated element is: %d\n", nums1[i]);
            break;
        }
        seen[nums1[i]] = 1;
    }       
        return 0;
}
//Q120: Write a program to take a string input. Change it to sentence case.

/*
Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.

*/
#include <stdio.h>

int main() {
    char str[1000];
    int i = 0;  
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int new_word = 1;   
    while(str[i] != '\0') {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            new_word = 1;
        } else {
            if(new_word && str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - ('a' - 'A');
            } else if(!new_word && str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + ('a' - 'A');
            }
            new_word = 0;
        }
        i++;
    }
    printf("Sentence case string: %s", str);
        
    return 0;
}