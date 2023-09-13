// Problem: B. Customising the Track
// Contest: Codeforces - Codeforces Round 730 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1543/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: well goal is make all elements in the array equal,
// but life isn't so easy, notice that the sum of the elements in the
// array doesn't change, at the end we will have elements will
// value t, and other with value t-1,

/*
digamos que la suma de los elementos del array es S, entonces

m*t + (n-m)*(t-1) = S
n*t + (m-n) = S
(t-1)*n = S-m

tengo S, tengo n, tengo t,  necesito hallar (m,t) de forma que se maximize el producto m*(n-m)

m es congruente con el resto de S entre (t-1)*n,


S - m tiene que ser divisible por n, y además 0 <= m <= n, porue m es la cantidad de nḿeros
*/

//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    long long n;
    cin >> n;
    long long a[n];
    long long max = -1;
    long long min = 1000000001;
    long long sum = 0;
    forn
    {
        cin >> a[i];
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
        sum += a[i];
    }
    long long m = sum % (n);
    cout << m * (n - m) << endl;

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
