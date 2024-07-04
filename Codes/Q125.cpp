#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int size = s.size();
    int mid = size / 2;
    int it_fwd = 0;
    int it_bwd = size - 1;
    // char a, b;
    while (it_fwd < (mid) && it_bwd >= (mid))
    {
        // a = s[it_fwd];
        // b = s[it_bwd];
        while (!((s[it_fwd] >= 48 && s[it_fwd] <= 57) || (s[it_fwd] >= 65 && s[it_fwd] <= 90) ||
                 (s[it_fwd] >= 97 && s[it_fwd] <= 122)))
        {
            it_fwd++;
            if (size > 1)
                size--;
            else
                return true;
        }
        while (!((s[it_bwd] >= 48 && s[it_bwd] <= 57) || (s[it_bwd] >= 65 && s[it_bwd] <= 90) ||
                 (s[it_bwd] >= 97 && s[it_bwd] <= 122)))
        {
            it_bwd--;
            if (size > 1)
                size--;
            else
                return true;
        }
        if (s[it_fwd] >= 65 && s[it_fwd] <= 90)
            s[it_fwd] += 32;
        if (s[it_bwd] >= 65 && s[it_bwd] <= 90)
            s[it_bwd] += 32;

        if (s[it_fwd] != s[it_bwd])
            return false;
        else
        {
            it_fwd++;
            it_bwd--;
            mid = ((it_fwd + it_bwd) / 2) + 1;
        }
    }
    return true;
}

int main()
{
    string s = "Marge, let's \"[went].\" I await {news} telegram.";
    cout << isPalindrome(s) << endl;
    return 0;
}