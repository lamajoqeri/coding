#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

void SieveOfEratosthenes(vector<long long>& primes)
{

    bool IsPrime[110000];
    memset(IsPrime, true, sizeof(IsPrime));

    for (int p = 2; p * p < 110000; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < 110000; i += p) {
                IsPrime[i] = false;
            }   
        }
    }

    for (int p = 2; p < 110000; p++) {
        if (IsPrime[p]) {
            primes.push_back(p);
        }
    }
}






int main()
{
    int t;
    cin >> t;
    vector<long long> primes;

    SieveOfEratosthenes(primes);

    for (int zt = 0; zt < t; zt++) {

        int n;
        cin >> n;

        cout << 1 << " " << 2 << " ";
    
        for (int i = 0; i < n-2; i++) {
            cout << primes[i] * primes[i+1] << " ";
        }
        cout << "\n";
    }
}

