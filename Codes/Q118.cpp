#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascalTriangle;
    for (int i = 1; i <= numRows; i++)
    {
        vector<int> *row = new vector<int>;
        int element;
        for (int j = 0; j < i; j++)
        {
            if (j == 0 || j == (i - 1))
                element = 1;
            else
            {
                element =
                    pascalTriangle[i - 2][j - 1] + pascalTriangle[i - 2][j];
            }
            row->push_back(element);
        }
        pascalTriangle.push_back(*row);
    }
    return pascalTriangle;
}