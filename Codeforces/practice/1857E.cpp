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
    vector<vector<long long>> map;
    vector<long long> results;
    unordered_map<long long, vector<int>> hasher;

    for (int zt = 0; zt < t; zt++) {
        int n;

        vector<pair<long long, int>> a;
        long long atemp;
        

        int leftlines;
        int rightlines;

        

        long long tempresult = 0;
        cin >> n;
        
        for (int zn = 0; zn < n; zn++) {
            cin >> atemp;
            a.push_back({atemp, zn});

            results.push_back(0);
        }

        

        /*
        for (int i = 0; i < a.size(); i++) {
            if (hasher.count(a[i])) {
                hasher[a[i]].push_back(i);
            } else {
                hasher[a[i]] = {i};
            }
        }
            */

        sort(a.begin(), a.end());

        /*
        map.push_back({a[0], 1});

        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i-1]) {
                map[map.size()-1][1]++;
            } else {
                map.push_back({a[i], 1});
            }
        }
        
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < hasher[map[i][0]].size(); j++) {
                map[i].push_back(hasher[map[i][0]][j]);
            }
        }
        */
        leftlines = 0;
        rightlines = n;

        for (int i = 0; i < a.size(); i++) {
            tempresult += (a[i].first - a[0].first + 1);
        }

        results[a[0].second] = tempresult;


        for (int i = 1; i < a.size(); i++) {
            if (a[i].first > a[i-1].first) {
                leftlines = i;
                rightlines = n - leftlines;
            }
            long long jump = 0;
            jump = a[i].first - a[i-1].first;

            tempresult += (leftlines - rightlines) * jump;

            
            results[a[i].second] = tempresult;
        }        



        /*
        for (int i = 0; i < map.size(); i++) {
            tempresult += (map[i][1]) * (map[i][0] - map[0][0] + 1);
        }

        for (int j = 0; j < hasher[map[0][0]].size(); j++) {
            results[hasher[map[0][0]][j]] = tempresult;
        }

        for (int i = 1; i < map.size(); i++) {
            long long jump = 0;
            jump = map[i][0] - map[i-1][0];
            tempresult += (leftlines - rightlines) * jump;

            rightlines -= map[i][1];
            leftlines += map[i][1];

            for (int j = 0; j < hasher[map[i][0]].size(); j++) {
                results[hasher[map[i][0]][j]] = tempresult;
            }
        }
            */
        

        for (int i = 0; i < results.size(); i++) {
            cout << results[i] << " ";
        }
        cout << "\n";

        map.clear();
        hasher.clear();
        results.clear();

    }
}