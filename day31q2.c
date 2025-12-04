//Q62: Reverse an array without taking extra space.

/*
Sample Test Cases:
Input 1:
4
1 2 3 4
Output 1:
4 3 2 1

*/
 #include <stdio.h>
 
 int main() {
        int n, i, temp;
        scanf("%d", &n);
        int arr[n];
        for(i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for(i = 0; i < n / 2; i++) {
            temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");  
        
    return 0;
 }