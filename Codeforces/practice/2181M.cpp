#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <cmath>
using namespace std;

void analyze(unordered_map<string, int> &memory, string xprime, string yprime, int switchesinput, int indexinput, int fullsize, int startind)
{
    int switches = switchesinput;
    int index = indexinput;
    string experimentalx = xprime;
    string experimentaly = yprime;
    bool moveForward = false;

    //cout << "s: " << switches << " i: " << index << " ex: " << experimentalx << " ey: " << experimentaly << "\n";

    if (startind == fullsize && switches != 0)
    {
        index++;
        string currentY = experimentaly[startind] + to_string(index);

        if (memory.count(currentY))
        {
            if (switches <= memory[currentY])
            {
                memory[currentY] = switches;
                moveForward = true;
            } else {
                return;
            }
        }
        else
        {
            memory[currentY] = switches;
            moveForward = true;
        }
    }

    if ((experimentalx[startind] != experimentaly[startind]) && index == 0)
    {
        switches++;

        
        string currentY = experimentaly[startind] + to_string(index);

        if (memory.count(currentY))
        {
            if (switches <= memory[currentY])
            {
                memory[currentY] = switches;
                moveForward = true;
            } else {
                return;
            }
        }
        else
        {
            memory[currentY] = switches;
            moveForward = true;
        }

        

        if (experimentalx[startind] == '1')
        {
            experimentalx[startind] = '0';
            analyze(memory, experimentalx, experimentaly, switches, index, fullsize, startind);
            experimentalx[startind] = '1';
        }
        else
        {
            experimentalx[startind] = '1';
            analyze(memory, experimentalx, experimentaly, switches, index, fullsize, startind);
            experimentalx[startind] = '0';
        }

        if (experimentaly[startind] == '1')
        {
            experimentaly[startind] = '0';
            analyze(memory, experimentalx, experimentaly, switches, index, fullsize, startind);
            experimentaly[startind] = '1';
        }
        else
        {
            experimentaly[startind] = '1';
            analyze(memory, experimentalx, experimentaly, switches, index, fullsize, startind);
            experimentaly[startind] = '0';
        }
    }
    else
    {
        for (int i = startind+1; i < fullsize; i++)
        {
            index++;
            string currentY = yprime[i] + to_string(index);
            moveForward = true;
            if (memory.count(currentY))
            {
                if (switches <= memory[currentY])
                {
                    memory[currentY] = switches;
                    moveForward = true;
                } else {
                    return;
                }
            }
            else
            {
                memory[currentY] = switches;
                moveForward = true;
            }

            if (moveForward)
            {
                if ((yprime[i] == yprime[i - 1] && xprime[i] == '1') || (yprime[i] != yprime[i - 1] && xprime[i] == '0'))
                {
                    switches++;

                    

                    if (experimentalx[i] == '1')
                    {
                        experimentalx[i] = '0';
                        analyze(memory, experimentalx, experimentaly, switches, index, fullsize, i);
                        experimentalx[i] = '1';
                    }
                    else
                    {
                        experimentalx[i] = '1';
                        analyze(memory, experimentalx, experimentaly, switches, index, fullsize, i);
                        experimentalx[i] = '0';
                    }

                    if (experimentaly[i] == '1')
                    {
                        experimentaly[i] = '0';
                        analyze(memory, experimentalx, experimentaly, switches, index, fullsize, i);
                        experimentaly[i] = '1';
                    }
                    else
                    {
                        experimentaly[i] = '1';
                        analyze(memory, experimentalx, experimentaly, switches, index, fullsize, i);
                        experimentaly[i] = '0';
                    }
                }
            }
        }

        string currentY = yprime[yprime.size()-1] + to_string(fullsize);

        if (memory.count(currentY))
        {
            if (switches <= memory[currentY])
            {
                memory[currentY] = switches;
                moveForward = true;
            }
        }
        else
        {
            memory[currentY] = switches;
            moveForward = true;
        }
    }
}

int main()
{

    int t = min(0, 1);
    cin >> t;
    string xprime;
    string yprime;

    unordered_map<string, int> memory;

    for (int zt = 0; zt < t; zt++)
    {
        cin >> xprime;
        cin >> yprime;

        analyze(memory, xprime, yprime, 0, 0, xprime.size(), 0);

        int result;

        /*
        for (auto it = memory.begin(); it != memory.end(); ++it)
        {
            cout << "Key: " << it->first << " Value: " << it->second << endl;
        } */

        if (memory.empty())
        {
            result = 0;
        }
        else
        {
            for (int i = xprime.size(); i > 0; i--)
            {
                if (memory.count("0" + to_string(i)) && memory.count("1" + to_string(i)))
                {
                    result = min(memory["0" + to_string(i)], memory["1" + to_string(i)]);
                    i = 0;
                }
                else
                {

                    if (memory.count("0" + to_string(i)))
                    {
                        result = memory["0" + to_string(i)];
                        i = 0;
                    }
                    else
                    {
                        if (memory.count("1" + to_string(i)))
                        {
                            result = memory["1" + to_string(i)];
                            i = 0;
                        }
                    }
                }
            }
        }

        cout << result << "\n";

        memory.clear();
    }
}