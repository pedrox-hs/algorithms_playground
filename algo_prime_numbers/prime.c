#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <math.h>

int main(int argc, char *argv[]){
    long count = 0, number = 1, primePos, diff;
    int isNotPrime = 0;
    double s;

    uint32_t *primes, limit, divisor;
    struct timeb start, end;

    printf("Enter the number of prime numbers required: ");
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

    printf("\nElapsed time: %u milliseconds\n", diff);
    printf("Last prime number found: %d\n", primes[limit - 1]);

    free(primes);

    //system("PAUSE");
    return 0;
}
