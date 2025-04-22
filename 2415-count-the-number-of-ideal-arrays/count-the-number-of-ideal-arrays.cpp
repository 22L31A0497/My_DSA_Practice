class Solution {
public:
    using ll = long long;

    const ll MOD = 1e9 + 7;

    const ll MAX_MAX_VALUE = 1e4 + 10;

    const ll MAX_N = 1e4 + 10;  // Maximum input number
    const ll MAX_PRIME_FACTOR_COUNT = 14 + 10;  // max number of duplicate prime factors
    // worst case: prime factorization is all '2's
    // in that case, max count is log_2(maxValue)
    // which is between 13 and 14

    const ll MAX_COMB = MAX_N + MAX_PRIME_FACTOR_COUNT;
    

    int idealArrays(int n, int maxValue) {

        // for every 'last' number, 
        // get the set of prime factors (and counts)
        // do stars and bars on each
        ll ans = 0;
        for (ll last = 1; last <= maxValue; last++) {

            // total ways to place all primes
            ll total = 1;

            for (auto [primeFactor, count] : primeFactorization(last)) {
                // prime factor value is irrelelvant

                // stars and bars result for this one prime factor
                ll waysToPlacePrimes = combinations[n-1 + count][count];
                total = (total * waysToPlacePrimes) % MOD;

                // cout << waysToPlacePrimes << endl;
            }
            ans = (ans + total) % MOD;
        }

        return ans;

    }

    // use constructor to do preprocessing before all test cases
    Solution() {

        // preprocessing alr complete
        if (spf.size() != 0) return;

        sieve();

        precomputeCombinations();

        // init prime factorization cache to -1
        primeFactorizationCache.assign(MAX_MAX_VALUE + 1, {});

    }

    // generate smallest prime factor for every num (from 1 to maxValue)
    vector<ll> spf; // spf = smallest prime factor
    void sieve() {
        spf.resize(MAX_MAX_VALUE+1);

        // init spf to "itself", which means, if we reach this number and it was not changed, this number is prime
        for (ll i = 0; i <= MAX_MAX_VALUE; i++) {
            spf[i] = i;
        }

        // loop through all nums up to sqrt(max value)
            // we dont go past that because smallest prime factor is always before that 
        // if spf is self, then this is a prime
        // if spf is not self, then we already set spf to the correct value
        for (ll i = 2; i*i <= MAX_MAX_VALUE; i++) {

            // spf is already set by another prime
            if (spf[i] != i) {
                continue;
            }

            // i must be prime:
            // for every multiple m of i, set spf of m to i
            // we start at i*i instead of i*2 or i*3, because
            // those multiples are already covered by 2 or 3 etc
                // 2 or 3 etc would have been the smaller prime factor
            // in other words:
                // the smallest num with the smallest prime factor
                // of 'i' is i^2
            for (ll m = i*i; m <= MAX_MAX_VALUE; m += i) {
                // ONLY set spf[m] if it hasn't been set before
                // otherwise spf no longer stores the "smallest" prime factor
                // ...possible to write prime factorization code differently
                    // to make it work with any prime factor
                if (spf[m] == m) {
                    spf[m] = i;
                }
            }
        }
    }

    // for some number, generates prime factorization:
    // list of [number, count]
    vector<vector<pair<ll, ll>>> primeFactorizationCache;
    vector<pair<ll, ll>> primeFactorization(ll n) {

        // if alr cached, return that
        if (!primeFactorizationCache[n].empty()) {
            return primeFactorizationCache[n];
        }

        ll originalN = n;

        vector<pair<ll, ll>> factors;

        // once n is 1, we have all the facotrs
        while (n > 1) {
            ll factor = spf[n]; // get smallest prime factor
            n /= factor; // divide it out from n

            // we need to create a new entry if:
            // size is 0
            // previous entry's number is not the same 
            if (factors.size() == 0 || factors.back().first != factor) {
                factors.push_back({factor, 1}); // new factor with count=1
            }
            else {
                factors.back().second++;
            }
        }

        // cache it
        // use original n!
        primeFactorizationCache[originalN] = factors;

        return factors;
    }

    vector<vector<ll>> combinations;
    void precomputeCombinations() {
        combinations.assign(
            MAX_COMB + 1, 
            vector<ll>(MAX_PRIME_FACTOR_COUNT + 1, 0)
        );

        // Base case: C(n,0) = 1 for all n
        for (ll n = 0; n <= MAX_COMB; n++) {
            ll k = 0;
            combinations[n][k] = 1;
        }

        // Fill the combination table using Pascal's identity:
        // C(n,r) = C(n-1,r-1) + C(n-1,r)
        for (ll n = 1; n <= MAX_COMB; n++) {
            // min() because 
            // we can only choose up to n elements
            // so k must be less or equal to n
            for (ll k = 1; k <= min(n, MAX_PRIME_FACTOR_COUNT); k++) {
                // note that we mod here since this is multiplied to the 
                // final solution
                combinations[n][k] = (
                    combinations[n-1][k-1] + combinations[n-1][k]
                ) % MOD;
            }
        }
    }
};