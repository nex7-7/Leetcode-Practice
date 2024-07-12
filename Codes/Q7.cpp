#include <iostream>
#include <queue>
using namespace std;

int reverse(int x)
{
    uint32_t num = x;
    bool negative = false;
    queue<int> q;
    if (x < 0)
    {
        negative = true;
    }
    int ans = 0;
    while (num)
    {
        q.push(num % 10);
        num /= 10;
    }
    while (!q.empty())
    {
        if (negative && ans > INT32_MIN / 10)
        {
            ans = ans * 10 - q.front();
        }
        else if (!negative && ans < INT32_MAX / 10)
        {
            ans = ans * 10 + q.front();
        }
        else
        {
            return 0;
        }

        q.pop();
    }
    return ans;
}

int main()
{
    int x = -2147483412;
    cout << reverse(x) << endl;
    return 0;
}