#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dif = 10000000;
    int sum = a + b + c + d;
    dif = min(dif, abs(sum - 2 * (a + b)));
    dif = min(dif, abs(sum - 2 * (a + c)));
    dif = min(dif, abs(sum - 2 * (a + d)));
    cout << dif << endl;
}