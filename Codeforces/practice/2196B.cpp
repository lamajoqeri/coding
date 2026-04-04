#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <cmath>
using namespace std;

int main()
{
    
    int t = min(0,1);
    cin >> t;
    vector<long long> a;
    long long tempa;    
    for (int zt = 0; zt < t; zt++) {
        int n;
        cin >> n;

        int ans = 0;

        for (int zn = 0; zn < n; zn++) {
            cin >> tempa;
            a.push_back(tempa);
        }

        for (int i = 0; i < n; i++) {
            for (long long j = i - a[i]; j > max(i - (static_cast<long long>(a[i]) * (a[i])), static_cast<long long>(-1)); j -= a[i]) {
                //cout << "i: " << i << " j: " << j << " a[i]: " << a[i] << " a[j]: " << a[j] << " ";
                if (i - j == a[j] * a[i]) {
                    //cout << " BOOM BACK ";
                    ans++;
                }
            }
            for (long long j = i + a[i]; j < min(i + (static_cast<long long>(a[i]) * a[i]) + 1, static_cast<long long>(n)); j += a[i]) {
                //cout << "i: " << i << " j: " << j << " a[i]: " << a[i] << " a[j]: " << a[j];
                if (j - i == a[j] * a[i]) {
                    //cout << " BOOM FORWARD ";
                    ans++;
                }
            }
            //cout << "\n";
        }

        cout << ans << "\n";

        a.clear();


    }
}
