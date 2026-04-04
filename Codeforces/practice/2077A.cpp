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

    int n;

    int halfone;
    int halftwo;

    vector<int> b;
    int tempb;

    int missing;

    for (int zt = 0; zt < t; zt++) {
        cin >> n;
        for (int zn = 0; zn < (2*n); zn++) {
            cin >> tempb;
            b.push_back(tempb);
        }

        sort(b.begin(), b.end());

        halfone = 0;
        halftwo = 0;
        
        for (int i = 0; i < n; i++) {
            halfone += b[i];
        }

        for (int i = n; i < 2*n; i++) {
            halftwo += b[i];
        }

        if (halftwo - halfone > b[2*n-1]) {
            missing = halftwo - halfone;

            cout << missing;
            for (int i = 0; i < 2 *n; i++) {
                cout << " " << b[i];
            }
            cout << "\n";
        }
        

    }
}