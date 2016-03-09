#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys\timeb.h>
#include <math.h>

int main(){
    long count = 0, number = 1, primePos;
    int isNotPrime = 0;
    double s;
    uint32_t *primes, limit, divisor;

    struct timeb start, end;
    long diff;

    printf("Enter the number of prime numbers required\n");
    scanf("%d",&limit);
    primes = malloc(limit * sizeof *primes);

    ftime(&start);

    while (number++){
        if (number % 2) {
            if ((s = sqrt(number)) == floor(s)) continue;
            primePos = isNotPrime = 0;
            while ((divisor = primes[++primePos]) && divisor < s)
                if (isNotPrime |= !(number % divisor)) break;
            if (isNotPrime) continue;
        } else if (number != 2) continue;
        primes[count++] = number;
        if (count >= limit) break;
    }
    ftime(&end);

    diff = (long) (1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));

    printf("Last number is %d\n", primes[limit - 1]);
    printf("\nOperation took %u milliseconds\n", diff);

    free(primes);

    //system("PAUSE");
    return 0;
}
