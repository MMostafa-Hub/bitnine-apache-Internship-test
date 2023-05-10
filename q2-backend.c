/*
* I will provide three different implementations of the given piecewise recurrence relation F(n) = F(n−3) + F(n−2)
* with base cases F(0) = 0, F(1) = 1, and F(2) = 2 in C.
*
* The three implementations will be:
*	1. Recursive
*	2. Iterative(using an array)
*	3. Iterative(using variables)
*/

/*
1. Recursive implementation
* Advantages:
*   Simple and easy to understand.
* Disadvantages :
*   Inefficient due to repeated calculations of the same subproblems.
*/
#include <stdio.h>

int F_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return F_recursive(n - 3) + F_recursive(n - 2);
}

/*
2. Iterative implementation using an array
* Advantages:
*	More efficient than the recursive implementation due to no repeated calculations.
* Disadvantages :
*	Requires additional memory to store the array.
*/
#include <malloc.h>

int F_iterative_array(int n) {
    int* F = (int*)malloc((n + 1) * sizeof(int));
    F[0] = 0;
    F[1] = 1;
    F[2] = 2;
    for (int i = 3; i <= n; i++) {
        F[i] = F[i - 3] + F[i - 2];
    }
    return F[n];
}

/*
3. Iterative implementation using variables
* Advantages:
*  More efficient than the recursive implementation and uses less memory than the iterative array implementation.
* Disadvantages:
*	Slightly more complex than the other two implementations.
*/
#include <stdio.h>

int F_iterative_variables(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int F_n_minus_3 = 0;
    int F_n_minus_2 = 1;
    int F_n_minus_1 = 2;
    int F_n;
    for (int i = 3; i <= n; i++) {
        F_n = F_n_minus_3 + F_n_minus_2;
        F_n_minus_3 = F_n_minus_2;
        F_n_minus_2 = F_n_minus_1;
        F_n_minus_1 = F_n;
    }
    return F_n;
}

/*
* In summary:
*	- the recursive implementation is simple but inefficient.
*	- the iterative array implementation is more efficient but requires additional memory.
*	- the iterative variables implementation is the most efficient and uses the least memory but is slightly more complex.
*/
int main() {
    int n = 10;
    printf("F_recursive(%d) = %d\n", n, F_recursive(n));
    printf("F_iterative_array(%d) = %d\n", n, F_iterative_array(n));
    printf("F_iterative_variables(%d) = %d\n", n, F_iterative_variables(n));

    return 0;
}

