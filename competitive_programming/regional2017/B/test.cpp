#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int is_vowel(char t)
{
    return vowels.find(t) != vowels.end();
}

deque<char> P;
int cur = 1;

char get_top()
{
    if (cur)
    {
        return P.back();
    }
    else
    {
        return P.front();
    }
}

void pop_top()
{
    if (cur)
    {
        // cout << P.back() << wp;
        P.pop_back();
    }
    else
    {
        // cout << P.front() << wp;
        P.pop_front();
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int n_vow = 0;
    forn
    {
        n_vow += is_vowel(s[i]);
        P.push_back(s[i]);
    }
    if(n_vow >= 1 && !is_vowel(P.front()))
    {
        cout << 0 << endl;
        return 0;
    }
    if(n_vow == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    while (n_vow > 1)
    {
        while (!is_vowel(get_top()))
        {
            pop_top();
        }
        n_vow--;
        cur = !cur;
        pop_top();
    }
    cout << P.size() << endl;
}