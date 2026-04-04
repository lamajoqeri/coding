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
    int k;

    int m;

    vector<int> a;
    int tempa;
    vector<vector<int>> b;

    vector<int> solob;

    unordered_map<int, int> memory;

    bool oneDivisor = false;

    bool works = true;

    for (int zt = 0; zt < t; zt++)
    {
        cin >> n;
        cin >> k;
        for (int zn = 0; zn < n; zn++) {
            cin >> tempa;
            a.push_back(tempa);
        }

        sort(a.begin(), a.end());

        oneDivisor = false;

        for (int i = 0; i < a.size(); i++) {
            oneDivisor = false;
            if (!memory.count(a[i])) {
                memory[a[i]] = 1;

                for (int j = 0; j < b.size(); j++) {
                    if (a[i] % b[j][0] == 0) {
                        b[j][1] += 1;
                        oneDivisor = true;
                    }
                }

                if (!oneDivisor) {
                    if (k / a[i] > 1) {
                        b.push_back({a[i], 1});
                    } else {
                        solob.push_back(a[i]);
                    }
                    
                }
            } 
        }

        works = true;

        for (int i = 0; i < b.size(); i++) {
            if (b[i][1] != k / b[i][0]) {
                works = false;
            }
        }

        if (works) {
            cout << b.size() + solob.size() << "\n";
            for (int i = 0; i < b.size(); i++) {
                cout << b[i][0] << " ";
            }
            for (int i = 0; i < solob.size(); i++) {
                cout << solob[i] << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }

        a.clear();
        b.clear();
        solob.clear();
        memory.clear();
    }
}