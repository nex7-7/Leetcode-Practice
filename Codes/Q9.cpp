#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int num = x;
    uint32_t reverse = 0;
    while (num != 0)
    {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    if (reverse == x)
        return true;
    else
        return false;
}

int main()
{
    bool a = isPalindrome(88888);
    cout << a;
}