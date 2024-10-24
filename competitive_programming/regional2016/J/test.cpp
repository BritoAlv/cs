#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if(!(x % i))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    while (!is_prime(n))
    {
        n--;
    }
    cout << n << endl;
}