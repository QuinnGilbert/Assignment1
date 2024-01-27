#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if(x <= 1) return false;
    if(x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int i = 5; i *i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    int numThreads = 8;

    int N = 100'000'001;
    vector<bool> prime(N);

    vector<std::thread> threads(numThreads);
    for(int thread=0; thread<numThreads; thread++) {
        int start = N / numThreads * (thread);
        int end = N / numThreads * (thread+1);
        if(thread == numThreads-1) end = N;

        auto testPrimes = [&](int start, int end) {
            for(int i=start; i<end; i++) {
                if(isPrime(i)) {
                    prime[i] = true;
                }
            }
        };

        threads[thread] = std::thread(testPrimes, start, end);
    }
    
    for(int i=0;i<numThreads;i++) {
        threads[i].join();
    }

    int count = 0;
    long long sum = 0;
    vector<int> maxPrimes;
    for(int i=N-1;i>=0;i--) {
        if(prime[i]) {
            if(maxPrimes.size() < 10) maxPrimes.push_back(i);
            count++;
            sum += i;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    cout<<duration.count()/1000.0<<"s "<<count<<" "<<sum<<" "<<endl;
    for(int i=maxPrimes.size()-1;i>=0;i--) {
        cout<<maxPrimes[i]<<endl;
    }

}