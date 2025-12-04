//Q65: Search in a sorted array using binary search.

/*
Sample Test Cases:
Input 1:
5
1 3 5 7 9
7
Output 1:
Found at index 3

Input 2:
5
1 3 5 7 9
6
Output 2:
-1

*/
 #include <stdio.h>
 
 int main() {
        int n, i, target, left, right, mid, foundIndex = -1;
        scanf("%d", &n);
        int arr[n];
        for(i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &target);
        
        left = 0;
        right = n - 1;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(arr[mid] == target) {
                foundIndex = mid;
                break;
            } else if(arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if(foundIndex != -1) {
            printf("Found at index %d\n", foundIndex);
        } else {
            printf("-1\n");
        }
          
    return 0;
 }