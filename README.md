# Assignment1

To run:
g++ -O3 findPrimes.cpp && ./a.out > primes.txt

# Proof of Correctness
My program simply splits the search space into 8 equal parts and runs each part on a different thread. Each prime is tested in O(sqrt(n)) by a simple prime check, however as a constant time optimization, My code makes use of wheel factorization https://en.wikipedia.org/wiki/Wheel_factorization with the first two primes.

# Efficiency
There exists faster prime finding algorithms than the one used here, such as Miller-Rabin or the Sieve of Eratosthenes, however the Miller-Rabin is a probabilistic prime finder, and I opted for a deterministic approach, and the Sieve of Eratosthenes does not parallelize well without thread pooling (which I assumed to be outside the scope of this assignment). The O(Nsqrt(N)) prime check is still much faster than the naive O(N^2) prime check. The work is not split mostly equally among the 8 threads

# Experimental Evaluation
Decreasing the number of threads significantly increases the runtime, almost perfectly inversely proportionally so that halving the number of threads almost doubles the runtime.

