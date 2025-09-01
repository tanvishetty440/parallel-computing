//Modify the prgm to find the largest prime number less than n

#include <stdio.h>
#include <math.h>
#include <omp.h>
int is_prime(int num) {
    if (num < 2) return 0;
    int limit = (int)sqrt(num);
    for (int i = 2; i <= limit; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n <= 2) {
        printf("Error: There is no prime number less than 2.\n");
        return 0;
    }
    int largest_prime = -1;
    for (int i = n - 1; i >= 2; i--) {
        if (is_prime(i) == 1) {
            largest_prime = i;
            break; 
        }
    }
    if (largest_prime != -1) {
        printf("The largest prime number less than %d is %d.\n", n, largest_prime);
    } else {
        printf("No prime number found.\n");
    }
    return 0;
}

