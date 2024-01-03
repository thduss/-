#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    int c = a % b;
    while(c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b){
    return (a*b)/ gcd(a,b);
}
int main()
{   
    int M, N;
    cin >> N >> M;
    
    cout << gcd(N, M) << endl;
    cout <<lcm(N, M);
}
