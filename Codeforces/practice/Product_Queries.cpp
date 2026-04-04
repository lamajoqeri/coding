#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    string s;

    int zeros = 0;
    int ones = 0;

    int m;

    vector<int> a;
    vector<int> results;

    unordered_map<int, int> factorMap;

    for (int zt = 0; zt < t; zt++)
    {
        cin >> n;
        factorMap.clear();
        results.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> m;
            factorMap[m] = 1;
        }

        bool found = false;
        int minFactors = 999999999;

        for (int prod = 1; prod < n + 1; prod++)
        {
            found = false;
            minFactors = 999999999;

            if (factorMap.count(prod))
            {
                results.push_back(factorMap[prod]);
                found = true;
            }

            if (!found)
            {
                for (int possibleFactor = 1; possibleFactor <= sqrt(prod) + 1; possibleFactor++)
                {

                    if (prod % possibleFactor == 0)
                    {
                        if (factorMap.count(prod / possibleFactor) && factorMap.count(possibleFactor))
                        {
                            if (factorMap[prod / possibleFactor] + factorMap[possibleFactor] < minFactors)
                            {
                                minFactors = factorMap[prod / possibleFactor] + factorMap[possibleFactor];
                            }
                            found = true;
                        }
                    }
                }
            }
            if (found && minFactors != 999999999)
            {
                factorMap[prod] = minFactors;
                results.push_back(minFactors);
            }
            if (!found)
            {
                results.push_back(-1);
            }
        }

        for (int i = 0; i < results.size(); i++)
        {
            cout << results.at(i) << " ";
        }
        cout << "\n";
    }
}