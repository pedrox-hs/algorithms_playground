#!/bin/env php
<?php

error_reporting(E_ERROR);

$limit = $argv[1];
$primes = array();
$quantity = 0;
$number = 1;

function isPrime ($number, $primes) {
    if (!($number % 2) && $number !== 2) return false;
    elseif (($sqrt = sqrt($number)) == floor($sqrt)) return false;
    $primePos = 0;
    while (($divisor = $primes[++$primePos]) && $divisor < $sqrt)
        if (!($number % $divisor)) return false;
    return true;
}

$start = microtime(true);

while ($number++) {
    if (isPrime($number, $primes)) {
        $primes[] = $number;
        if (++$quantity >= $limit) break;
    }
}

echo "Time: " . (microtime(true) - $start) . "\n";
echo "Last number: " . end($primes);