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
    int m;
    int k;

    int minWing;
    int smallWing;
    int bigWing;
    int leftOver;

    int newOnes;

    vector<int> fibvec;
    fibvec.push_back(1);
    fibvec.push_back(1);

    while (fibvec[fibvec.size() - 1] < 2000000)
    {
        fibvec.push_back(fibvec[fibvec.size() - 1] + fibvec[fibvec.size() - 2]);
    }
    int bsindex = 0;

    int mremaining = 0;

    for (int zt = 0; zt < t; zt++)
    {
        cin >> n;
        cin >> m;
        cin >> k;

        minWing = min(k - 1, n - k);

        bsindex = 0;
        while (fibvec[bsindex] < m + 1 && bsindex != fibvec.size())
        {
            bsindex++;
        }
        if (fibvec[bsindex] > m + 1)
        {
            bsindex--;
        }

        if (fibvec[bsindex] < 3)
        {
            smallWing = 0;
            bigWing = 1;
        }
        else if (fibvec[bsindex] < 4)
        {
            smallWing = 1;
            bigWing = 1;
        }
        else
        {
            smallWing = fibvec[bsindex - 3];
            bigWing = fibvec[bsindex - 2];
        }

        // cout << "sw " << smallWing << "\n";
        // cout << "bw " << bigWing << "\n";

        leftOver = 0;

        if (bigWing > minWing)
        {
            bsindex = 0;
            while (fibvec[bsindex] <= minWing)
            {
                bsindex++;
            }
            if (bsindex == 0)
            {
                bigWing = 0;
            }
            else
            {
                bigWing = fibvec[bsindex - 1];
            }

            if (bsindex < 2)
            {
                smallWing = 0;
            }
            else
            {
                smallWing = fibvec[bsindex - 2];
            }

            leftOver = minWing - bigWing + 1;
        }

        if (bigWing == 0)
        {
            mremaining = m - (smallWing + 2 * bigWing);
        }
        else
        {
            mremaining = m - (smallWing + 2 * bigWing) + 1;
        }

        newOnes = min(max((mremaining - smallWing), 0), leftOver) + (max((mremaining - smallWing - leftOver), 0)) / 2;

        
        cout << "sw " << smallWing << "\n";
        cout << "mw " << minWing << "\n";
        cout << "bw " << bigWing << "\n";
        cout << "no " << newOnes << "\n";
        cout << "mr " << mremaining << "\n";
        cout << "lo " << leftOver << "\n";
        

        if (zt == 184)
        {
            cout << n << m << k;
            cout << "sw" << smallWing;
            cout << "bw" << bigWing;
            cout << "no" << newOnes;
            cout << "mr" << mremaining;
            cout << "lo" << leftOver;
        }
        cout << min((smallWing + newOnes + bigWing + 1), n) << "\n";
    }
}