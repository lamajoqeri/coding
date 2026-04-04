// my second program in C++
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

  vector<int> locs;

  for (int zt = 0; zt < t; zt++)
  {
    cin >> n;
    cin >> s;
    m = 0;
    zeros = 0;
    ones = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '0')
      {
        zeros++;
      }
    }

    for (int i = 0; i < zeros; i++)
    {
      if (s[i] == '1')
      {
        m++;
        locs.push_back(i+1);
      }
    }
    if (m == 0)
    {
      cout << "Bob";
      goto bob_won;
    }

    for (int i = zeros; i < n; i++)
    {
      if (s[i] == '0')
      {
        locs.push_back(i+1);
      }
    }
    cout << "Alice" << "\n";
    cout << (m * 2) << "\n";
    for (int i = 0; i < locs.size(); i++)
    {
      cout << locs.at(i) << " ";
    }
    bob_won:
    cout << "\n";
    locs.clear();
  }
}