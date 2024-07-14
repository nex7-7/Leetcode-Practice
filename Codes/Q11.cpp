#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int min = height[i] > height[j] ? height[j] : height[i];
    int area = min * (j - i);
    while (i != j)
    {
        if (height[i] == min)
        {
            i++;
        }
        else
        {
            j--;
        }
        min = height[i] > height[j] ? height[j] : height[i];
        if ((min * (j - i)) > area)
        {
            area = min * (j - i);
        }
    }
    return area;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}