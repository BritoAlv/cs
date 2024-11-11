#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int mex(vector<int> const &A)
{
    set<int> b(A.begin(), A.end());

    int result = 0;
    while (b.count(result))
        ++result;
    return result;
}

template <typename T, typename A> int arg_max(std::vector<T, A> const &vec)
{
    return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}

int main()
{
    ll n, b, c;
    cin >> n >> b >> c;
    vector<int> Q(n);
    vector<int> P(n);
    forn
    {
        P[i] = i;
        Q[i] = b * i + c;
    }
    int it = 0;
    while (!is_permutation(Q.begin(), Q.end(), P.begin(), P.end()) && it <= 100000)
    {
/*         forn
        {
            cout << Q[i] << wp;
        }
        cout << endl; */
        int mexx = mex(Q);
        Q[arg_max(Q)] = mexx;
        it++;
    }
/*     forn
    {
        cout << Q[i] << wp;
    }
    cout << endl; */
    if(it == 100001)
    {
        it = -1;
    }
    cout << it << endl;
}