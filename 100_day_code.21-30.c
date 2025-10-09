#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// ---------- Small helpers ----------
static int is_prime(long long n){
    if(n<=1) return 0;
    if(n<=3) return 1;
    if(n%2==0) return 0;
    for(long long i=3; i*i<=n; i+=2) if(n%i==0) return 0;
    return 1;
}
static long long fact_digit(int d){
    static long long f[10] = {0};
    if(f[0]==0){ // init once
        f[0]=1;
        for(int i=1;i<=9;i++){ long long v=1; for(int k=2;k<=i;k++) v*=k; f[i]=v; }
    }
    return f[d];
}

// ====================== Day 21 ======================
void day21_q1(){ // Swap first and last digit
    long long n; if(scanf("%lld",&n)!=1) return;
    long long sign = (n<0)?-1:1; n = llabs(n);
    if(n<10){ printf("%lld\n", sign*n); return; }
    long long last = n%10;
    long long temp = n, pow10 = 1;
    while(temp>=10){ temp/=10; pow10*=10; }
    long long first = temp;
    long long middle = (n%pow10)/10;
    long long res = last*pow10 + middle*10 + first;
    printf("%lld\n", sign*res);
}
void day21_q2(){ // Perfect number
    long long n; if(scanf("%lld",&n)!=1) return;
    if(n<=1){ printf("Not perfect number\n"); return; }
    long long sum=1;
    for(long long i=2;i*i<=n;i++){ if(n%i==0){ sum+=i; if(i!=n/i) sum+=n/i; } }
    if(sum==n) printf("Perfect number\n"); else printf("Not perfect number\n");
}

// ====================== Day 22 ======================
void day22_q1(){ // Strong number
    long long n; if(scanf("%lld",&n)!=1) return;
    long long m = llabs(n), sum=0, t=m;
    if(t==0) sum = fact_digit(0);
    while(t>0){ sum += fact_digit((int)(t%10)); t/=10; }
    if(sum==m) printf("Strong number\n"); else printf("Not strong number\n");
}
void day22_q2(){ // Sum series 1+3/4+5/6+... up to n
    int n; if(scanf("%d",&n)!=1) return;
    double s=0.0;
    for(int k=1;k<=n;k++){ if(k==1) s+=1.0; else s+=(2.0*k-1.0)/(2.0*k); }
    printf("Approximate sum: %.1f\n", s);
}

// ====================== Day 23 ======================
void day23_q1(){ // Sum series 2/3+4/7+... up to n
    int n; if(scanf("%d",&n)!=1) return;
    double s=0.0;
    for(int k=1;k<=n;k++) s += (2.0*k)/(4.0*k-1.0);
    printf("Approximate sum: %.2f\n", s);
}
void day23_q2(){ // 5x5 stars
    for(int i=0;i<5;i++){ for(int j=0;j<5;j++) putchar('*'); putchar('\n'); }
}

// ====================== Day 24 ======================
void day24_q1(){ // Right triangle stars
    for(int i=1;i<=5;i++){ for(int j=1;j<=i;j++) putchar('*'); putchar('\n'); }
}
void day24_q2(){ // Numeric triangle
    for(int i=1;i<=5;i++){ for(int j=1;j<=i;j++) printf("%d", j); putchar('\n'); }
}

// ====================== Day 25 ======================
void day25_q1(){ // 5/45/345/2345/12345
    for(int start=5; start>=1; --start){ for(int x=start; x<=5; ++x) printf("%d", x); putchar('\n'); }
}
void day25_q2(){ // Right-aligned inverted stars
    int n=5; for(int i=n;i>=1;i--){ for(int s=0;s<n-i;s++) putchar(' '); for(int k=0;k<i;k++) putchar('*'); putchar('\n'); }
}

// ====================== Day 26 ======================
void day26_q1(){ // Right-aligned numeric
    for(int start=5; start>=1; --start){ for(int s=0; s<start-1; ++s) putchar(' '); for(int x=start; x<=5; ++x) printf("%d", x); putchar('\n'); }
}
void day26_q2(){ // Blocks of stars
    int blocks[] = {1,2,5,3,1}, nb=5;
    for(int b=0;b<nb;b++){ for(int i=0;i<blocks[b];i++) printf("*\n"); if(b!=nb-1) putchar('\n'); }
}

// ====================== Day 27 ======================
void day27_q1(){ // Full pyramid then down
    int n=5;
    for(int i=1;i<=n;i++){ for(int s=0;s<n-i;s++) putchar(' '); for(int k=0;k<2*i-1;k++) putchar('*'); putchar('\n'); }
    for(int i=n-1;i>=1;i--){ for(int s=0;s<n-i;s++) putchar(' '); for(int k=0;k<2*i-1;k++) putchar('*'); putchar('\n'); }
}
void day27_q2(){ // Centered diamond (n=4 top)
    int n=4;
    for(int i=1;i<=n;i++){ for(int s=0;s<n-i;s++) putchar(' '); for(int k=0;k<2*i-1;k++) putchar('*'); putchar('\n'); }
    for(int i=n-1;i>=1;i--){ for(int s=0;s<n-i;s++) putchar(' '); for(int k=0;k<2*i-1;k++) putchar('*'); putchar('\n'); }
}

// ====================== Day 28 ======================
void day28_q1(){ // Primes 1..n
    int n; if(scanf("%d",&n)!=1) return; int first=1;
    for(int i=2;i<=n;i++){ if(is_prime(i)){ if(!first) printf(" "); printf("%d", i); first=0; } }
    putchar('\n');
}
void day28_q2(){ // Read & print array
    int n; if(scanf("%d",&n)!=1) return; int a[1005];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){ if(i) printf(" "); printf("%d",a[i]); }
    printf("\n");
}

// ====================== Day 29 ======================
void day29_q1(){ // Sum of array
    int n; if(scanf("%d",&n)!=1) return; long long sum=0,x;
    for(int i=0;i<n;i++){ scanf("%lld",&x); sum+=x; }
    printf("%lld\n", sum);
}
void day29_q2(){ // Max & Min in array
    int n; if(scanf("%d",&n)!=1) return; if(n<=0){ printf("Invalid\n"); return; }
    int x; scanf("%d",&x); int mx=x, mn=x;
    for(int i=1;i<n;i++){ scanf("%d",&x); if(x>mx) mx=x; if(x<mn) mn=x; }
    printf("Max=%d, Min=%d\n", mx, mn);
}

// ====================== Day 30 ======================
void day30_q1(){ // Count even & odd
    int n; if(scanf("%d",&n)!=1) return; long long even=0, odd=0,x;
    for(int i=0;i<n;i++){ scanf("%lld",&x); if(x%2==0) even++; else odd++; }
    printf("Even=%lld, Odd=%lld\n", even, odd);
}
void day30_q2(){ // Count +/−/0
    int n; if(scanf("%d",&n)!=1) return; long long pos=0,neg=0,zer=0,x;
    for(int i=0;i<n;i++){ scanf("%lld",&x); if(x>0) pos++; else if(x<0) neg++; else zer++; }
    printf("Positive=%lld, Negative=%lld, Zero=%lld\n", pos, neg, zer);
}

// ====================== MAIN ======================
int main(void){
    int c; if(scanf("%d",&c)!=1) return 0;
    switch(c){
        case 1:  day21_q1(); break;  case 2:  day21_q2(); break;
        case 3:  day22_q1(); break;  case 4:  day22_q2(); break;
        case 5:  day23_q1(); break;  case 6:  day23_q2(); break;
        case 7:  day24_q1(); break;  case 8:  day24_q2(); break;
        case 9:  day25_q1(); break;  case 10: day25_q2(); break;
        case 11: day26_q1(); break;  case 12: day26_q2(); break;
        case 13: day27_q1(); break;  case 14: day27_q2(); break;
        case 15: day28_q1(); break;  case 16: day28_q2(); break;
        case 17: day29_q1(); break;  case 18: day29_q2(); break;
        case 19: day30_q1(); break;  case 20: day30_q2(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}

/* ================= SAMPLE INPUT/OUTPUT =================

Day 21 Q1 (swap digits)
Input: 1\n1234
Output: 4231
Input: 1\n1001
Output: 1001

Day 21 Q2 (perfect number)
Input: 2\n6
Output: Perfect number
Input: 2\n10
Output: Not perfect number

Day 22 Q1 (strong number)
Input: 3\n145
Output: Strong number
Input: 3\n123
Output: Not strong number

Day 22 Q2 (series 1+3/4+...)
Input: 4\n3
Output: Approximate sum: 3.3
Input: 4\n5
Output: Approximate sum: 4.4

Day 23 Q1 (series 2/3+...)
Input: 5\n3
Output: Approximate sum: 1.56
Input: 5\n5
Output: Approximate sum: 2.22

Day 23 Q2 (5x5 stars)
Input: 6
Output:
*****
*****
*****
*****
*****

Day 24 Q1 (right triangle stars)
Input: 7
Output:
*
**
***
****
*****

Day 24 Q2 (numeric triangle)
Input: 8
Output:
1
12
123
1234
12345

Day 25 Q1
Input: 9
Output:
5
45
345
2345
12345

Day 25 Q2
Input: 10
Output:
*****
 ****
  ***
   **
    *

Day 26 Q1
Input: 11
Output:
    5
   45
  345
 2345
12345

Day 26 Q2
Input: 12
Output:
*
(blank line)
*
*
(blank line)
*
*
*
*
*
(blank line)
*
*
*
(blank line)
*

Day 27 Q1
Input: 13
Output:
*
***
*****
*******
*********
*******
*****
***
*

Day 27 Q2
Input: 14
Output:
   *
  ***
 *****
*******
 *****
  ***
   *

Day 28 Q1
Input: 15\n10
Output: 2 3 5 7
Input: 15\n20
Output: 2 3 5 7 11 13 17 19

Day 28 Q2
Input: 16\n3\n10 20 30
Output: 10 20 30

Day 29 Q1
Input: 17\n4\n2 4 6 8
Output: 20

Day 29 Q2
Input: 18\n5\n2 9 1 4 7
Output: Max=9, Min=1

Day 30 Q1
Input: 19\n6\n1 2 3 4 5 6
Output: Even=3, Odd=3

Day 30 Q2
Input: 20\n5\n-1 0 1 2 -2
Output: Positive=2, Negative=2, Zero=1

====================================================== */
