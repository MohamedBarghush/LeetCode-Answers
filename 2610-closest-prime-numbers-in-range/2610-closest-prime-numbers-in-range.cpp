class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime(right + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= right; j += i)
                    is_prime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = max(2, left); i <= right; i++) {
            if (is_prime[i]) primes.push_back(i);
        }

        if (primes.size() < 2) return { -1, -1 }; // Only one or no prime numbers

        int minL = 0;
        int minSoFar = INT_MAX;
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minSoFar) {
                minL = i;
                minSoFar = diff;
            }
        }

        return { primes[minL - 1], primes[minL] };
    }
};
