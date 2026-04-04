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
    unordered_map<int, int> p;
    vector<int> indexedp;
    unordered_map<int, int> marks;
    int tempp;

    for (int zt = 0; zt < t; zt++) {
        int n;
        cin >> n;
        for (int zn = 1; zn <= n; zn++) {
            cin >> tempp;
            p[tempp] = zn;
            indexedp.push_back(tempp);
        }
        
        int sits = 0;
        for (int i = 1; i <= n; i++) {
            if (marks[i] == 1) {
                break;
            }
            if (!(indexedp.at(i-1) == i+1)) {
                sits++;
                marks[indexedp.at(i-1)] = 1;
            }
        }
        cout << sits << "\n";
        indexedp.clear();
        marks.clear();
        p.clear();
        
    }
}

