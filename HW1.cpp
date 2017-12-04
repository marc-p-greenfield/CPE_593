#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

//Sources : Thomas Wright

class CountPrimes {
    public:
    CountPrimes() {};
    void sieve(bool primes[], unsigned long long start, unsigned long long stop)
    {
        for (unsigned long long i = 3; i <= sqrt(stop); i += 2)
        {
            unsigned long long start2;
            if (i <= start || primes[i - start] == true)
            {
                if (start / i > 1)
                {
                    start2 = start / i * i;
                }
                else
                {
                    start2 = i*i;
                }

                if (start2 % 2 == 0)
                {
                    start2 += i;
                }

                for (unsigned long long j = start2; j < stop; j += 2*i)
                {
                    if (j >= start) primes[j - start] = false;
                }
            }
        }
    }

    void setPrimes(bool primes[], unsigned long long start, unsigned long long diff)
    {
        for (int i = start % 6; i < 6; i++)
        {
            if ((start + i - start % 6) % 2 == 0)
            {
                primes[i - start%6] = false;
            }
            else
            {
                primes[i - start%6] = true;
            }

            for (unsigned long long i = 6 - start%6; i < diff; i += 6)
            {
                primes[i] = false;
                primes[i+1] = true;
                primes[i+2] = false;
                primes[i+3] = false;
                primes[i+4] = false;
                primes[i+5] = true;
            }
        }
    }

    int countPrimes(bool primes[], unsigned long long start, unsigned long long stop, unsigned long long diff)
    {
        setPrimes(primes, start, diff);
        sieve(primes, start, stop);
        unsigned long long count = 0;
        for (unsigned long long i = 0; i < diff; i++)
        {
            if (primes[i]) count ++;
        }
        if (start == 2)
        {
            count++;
        }
        return count;
    }
};

int main()
{
    unsigned long long lower;
    unsigned long long upper;
    cout << "Enter lower value: ";
    cin >> lower;
    cout << "Enter upper value: ";
    cin >> upper;

    unsigned long long diff = upper - lower + 1;

    bool primes[diff];
    CountPrimes cp;
    cout << "The number of primes between " << lower << " and " << upper << ": " << cp.countPrimes(primes, lower, upper, diff) << endl;

    return 0;
}
