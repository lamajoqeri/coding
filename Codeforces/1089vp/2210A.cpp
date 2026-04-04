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
        for (int i = n; i > 0; i--) {
            cout << i << " ";
        }
        cout << "\n";
    }
}