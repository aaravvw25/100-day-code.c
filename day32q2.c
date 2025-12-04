//Q64: Find the digit that occurs the most times in an integer number.

/*
Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7

*/
 #include <stdio.h>
 
 int main() {
        int num, digit, maxDigit = 0, maxCount = 0;
        int count[10] = {0}; 
        

        scanf("%d", &num);
        
        
        while(num > 0) {
            digit = num % 10;
            count[digit]++;
            num /= 10;
        }
        
        
        for(digit = 0; digit < 10; digit++) {
            if(count[digit] > maxCount) {
                maxCount = count[digit];
                maxDigit = digit;
            }
        }
        
        
        printf("%d\n", maxDigit);  
    return 0;
 }