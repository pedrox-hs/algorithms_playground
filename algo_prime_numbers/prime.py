#!/bin/env python

import sys
import math
import time

primes = []
limit = int(sys.argv[1])
quantity = 0
number = 1

def is_prime(number, primes, quantity):
    if not number % 2 and number != 2: return False
    sqrt = number**0.5
    if sqrt == math.floor(sqrt): return False
    divisor = prime_pos = 0
    while divisor < sqrt:
        prime_pos += 1
        if quantity <= prime_pos:
            break
        divisor = primes[prime_pos]
        if not number % divisor: return False
    return True

print ""
start_time = time.time()

while True:
    number += 1
    if is_prime(number, primes, quantity):
        primes.append(number)
        quantity += 1
        if quantity >= limit:
            break

print "\nElapsed time:", time.time() - start_time, "milliseconds"
print "Last prime number found:",primes[limit - 1];
