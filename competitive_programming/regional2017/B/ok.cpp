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

int main()
{
    string s;
    cin >> s;
    int n_vow = 0;
    int n = s.size();
    forn
    {
        n_vow += is_vowel(s[i]);
    }
    if (n_vow >= 1 && !is_vowel(s[0]))
    {
        cout << 0 << endl;
        return 0;
    }
    if (n_vow == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    while (n_vow > 1)
    {
        if (!is_vowel(s.back()))
        {
            // cout << s.back() << wp;
            s.pop_back();
        }
        else
        {
            reverse(s.begin(), s.end());
            // cout << s.back() << wp;
            s.pop_back();
            n_vow--;
        }
    }
    cout << s.size() << endl;
}