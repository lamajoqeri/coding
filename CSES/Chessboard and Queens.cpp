
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

string n;
vector<vector<int>> board;

int totalVics;

vector<int> queentracker(8);

void placequeen(vector<vector<int>> chessboard, int queenCount, int zstart)
{
    vector<vector<int>> boardCopy;
    boardCopy = chessboard;

    int queenCountCopy;
    queenCountCopy = queenCount;
    for (int z = zstart; z < 64; z++)
    {
        int i = (z / 8);
        int j = z % 8;

        boardCopy = chessboard;
        queenCountCopy = queenCount;
        if (boardCopy.at(i).at(j) == 0)
        {
            queentracker.at(queenCountCopy) = z;
            queenCountCopy++;
            // cout << i << " " << j << "\n";
            // cout << queenCountCopy << "\n";

            boardCopy.at(i).at(j) = 1;
            for (int k = 0; k < 8; k++)
            {
                boardCopy.at(i).at(k) = 1;
                boardCopy.at(k).at(j) = 1;
            }
            for (int l = -1 * min(i, j); l < min(8 - i, 8 - j); l++)
            {
                boardCopy.at(i + l).at(j + l) = 1;
            }
            for (int l = -1 * min(7 - i, j); l < min(i, 8 - j); l++)
            {
                boardCopy.at(i - l).at(j + l) = 1;
            }
            /*
            for (int i = 0; i < 8; i++) {
                for (int j =0; j < 8; j++) {
                    cout << boardCopy.at(i).at(j);
                }
                cout << "\n";
            }*/

            if (queenCountCopy == 8)
            {
                totalVics++;
                /*
                for (int y = 0; y < 8; y++) {
                    cout << queentracker.at(y) << " ";
                }
                cout << "\n";
                */
            }
            else
            {
                placequeen(boardCopy, queenCountCopy, z + 1);
            }
        }
    }
}

int main()
{
    vector<int> placer(8);

    for (int i = 0; i < 8; i++)
    {
        board.push_back(placer);
    }
    for (int i = 0; i < 8; i++)
    {
        cin >> n;
        for (int j = 0; j < 8; j++)
        {
            if (n[j] == '.')
            {
                board.at(i).at(j) = 0;
            }
            else
            {
                board.at(i).at(j) = 1;
            }
        }
    }

    placequeen(board, 0, 0);

    cout << totalVics;
    /*

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board.at(i).at(j);
        }
        cout << "\n";
    }

    board.at(0).at(1) = 1;
    for (int k = 0; k < 8; k++)
    {
        board.at(0).at(k) = 1;
        board.at(k).at(1) = 1;
    }
    for (int l = -1 * min(0, 1); l < min(8 - 0, 7 - 1); l++)
    {
        board.at(0 + l).at(1 + l) = 1;
    }
    for (int l = -1 * min(7 - 0, 1); l < min(0, 7 - 1); l++)
    {
        board.at(0 - l).at(1 + l) = 1;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board.at(i).at(j);
        }
        cout << "\n";
    }
        */
}