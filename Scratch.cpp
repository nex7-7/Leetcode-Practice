#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mrt()
{
    int n, ti, li, sum = 0, element = 0;
    vector<vector<int>> time;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ti >> li;
        time.push_back({li - ti, ti});
    }
    sort(time.begin(), time.end());
    for (int i = 0; i < n; i++)
    {
        element += time[i][0];
        sum += element + time[i][1];
    }
    return sum / n;
}

int main()
{
    cout << mrt();
}