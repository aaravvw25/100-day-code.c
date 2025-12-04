//Q66: Insert an element in a sorted array at the appropriate position.

/*
Sample Test Cases:
Input 1:
5
1 2 4 5 6
3
Output 1:
1 2 3 4 5 6

*/
 #include <stdio.h>
 
 int main() {
        int n, i, element, pos = -1;
        scanf("%d", &n);
        int arr[n + 1];
        for(i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &element);
        
        for(i = 0; i < n; i++) {
            if(arr[i] > element) {
                pos = i;
                break;
            }
        }
        
        if(pos == -1) {
            arr[n] = element;
        } else {
            for(i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
        }
        
        for(i = 0; i <= n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");  
    return 0;
 }