#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle edge cases
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;

        // Initialization
        bool sign = (dividend < 0) ^ (divisor < 0);
        uint32_t uDividend = abs((long)dividend);
        uint32_t uDivisor = abs((long)divisor);

        if (uDividend < uDivisor)
            return 0;
        if (uDividend == uDivisor)
            return pow(-1, (uint8_t)sign);

        int count = countBits(uDividend);
        int count1 = count + 1;

        vector<bool> q = toBitVector(uDividend, count);
        vector<bool> a(count1, 0);
        vector<bool> m = toBitVector(uDivisor, count1);
        vector<bool> m2 = twoComplement(m, count1);

        while (count > 0)
        {
            a = leftShift(a, count1);
            a[0] = q[count1 - 2];
            q = leftShift(q, count1 - 1);
            a = bitAdd(a, m2, count1);

            if (a[count1 - 1])
            {
                q[0] = 0;
                a = bitAdd(a, m, count1);
            }
            else
            {
                q[0] = 1;
            }

            count--;
        }

        int ans = toInt(q, count1);
        return sign ? -ans : ans;
    }

    uint16_t countBits(uint32_t num) { return (uint16_t)log2(num) + 1; }

    bool fullAdder(bool b1, bool b2, bool &carry)
    {
        bool sum = (b1 ^ b2) ^ carry;
        carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
        return sum;
    }

    vector<bool> bitAdd(vector<bool> &x, vector<bool> &y, int count1)
    {
        bool carry = false;
        vector<bool> ans(count1, false);
        for (int i = 0; i < count1; i++)
        {
            ans[i] = fullAdder(x[i], y[i], carry);
        }
        return ans;
    }

    vector<bool> toBitVector(int num, int size)
    {
        vector<bool> bits(size, false);
        for (int i = 0; i < size; ++i)
        {
            bits[i] = (num & ((uint64_t)1 << i)) != 0;
        }
        return bits;
    }

    vector<bool> twoComplement(vector<bool> &bits, int count1)
    {
        vector<bool> ans = bits;
        for (int i = 0; i < count1; i++)
        {
            ans[i] = !ans[i];
        }
        vector<bool> one(count1, false);
        one[0] = true;
        ans = bitAdd(ans, one, count1);
        return ans;
    }

    vector<bool> leftShift(vector<bool> &bits, int size)
    {
        vector<bool> ans(size, false);
        for (int i = size - 1; i > 0; i--)
        {
            ans[i] = bits[i - 1];
        }
        return ans;
    }

    int toInt(vector<bool> &bits, int count1)
    {
        int num = 0;
        for (int i = 0; i < count1; i++)
        {
            if (bits[i])
            {
                num += (1 << i);
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(7, -3) << endl;
    // cout << s.divide(0, 1) << endl;
    cout << s.divide(1, 1) << endl;
    // cout << s.divide(1, 0) << endl;
    cout << s.divide(-1, 1) << endl;
    cout << s.divide(-1, -1) << endl;
}