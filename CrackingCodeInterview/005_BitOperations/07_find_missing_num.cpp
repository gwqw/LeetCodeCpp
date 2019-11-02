/**
An array A[1... n] contains all the integers from 0 to n except for one number which is missing. 
In this problem, we cannot access an entire integer in A with a single operation. 
The elements of A are represented in binary,
 and the only operation we can use to access them is “fetch the jth bit of A[i]”, which takes constant time. 
Write code to find the missing integer. Can you do it in O(n) time?

bool fetch_ij(int i, int j);

n=1 [0 or 1] => check last bit
n=2 [0,1 or 0,2 or 1,2] => [00,01 or 00,10 or 01,10], 
    1,0 -> 0 => 
        check 2,0 
        if 0 => 1 is missing, 
        if 1 => 
            check 1,1 => ..

n:
    - check all 0bits and found if num is odd or event
        - check n/2 items for 1
            - checks n/4
            
n + n/2 + n/4 + ... = n * (1 + 1/2 + 1/4 + 1/8 + ...)
Sum(i from 0 to n-1): 1/2^n-1 * Sum(2^0 + ... + 2^n-1) = 2^n / 2^n-1 = 2


    

*/