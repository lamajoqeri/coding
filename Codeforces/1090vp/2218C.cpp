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
    int t;
    cin >> t;

    for (int zt = 0; zt < t; zt++) {

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cout << i << " " << (3*n) - 2*((i-1)) << " " << (3*n) - 2*((i-1)) - 1 << " ";
        }
        cout << "\n";
    }
}