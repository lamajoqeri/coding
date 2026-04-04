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

        int tempa;
        int sum = 0;
        int max = -70;
        for (int i = 0; i < 7; i++) {
            cin >> tempa;
            if (tempa > max) {
                max = tempa;
            }
            sum -= tempa;
        }

        sum += 2 * max;

        cout << sum << "\n";
    }
}