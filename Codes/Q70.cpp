#include <iostream>
using namespace std;

int factorial(int n){
    int i = 1;
    while(n){
        i *= n;
        n--;
    }
    return i;
}

int climbStairs(int n) {
    int ways = 0;
    int mult = 1;
    for(int i = 0; i < (n/2); i++){
        for(int j = 0; j <= i; j++){
            mult *= ((n-i)-j);
        }
        ways += (mult/factorial(i));
    }
    return ways;
}

int main(){
    cout<<climbStairs(0)<<endl;
    cout<<climbStairs(1)<<endl;
    cout<<climbStairs(2)<<endl;
    cout<<climbStairs(3)<<endl;
    cout<<climbStairs(4)<<endl;
    return 0;
}