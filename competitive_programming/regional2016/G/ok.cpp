#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> p(n);
    forn
    {
        cin >> p[i];
    }
    for (int i = 0; i <= s.size() - n; i++)
    {
        int works = 1;
        map<int, char> assigned;
        set<char> used;
        for (int j = i; j < i + n; j++)
        {
            if(assigned.find(p[j-i]) == assigned.end())
            {
                if(used.find(s[j]) == used.end())
                {
                    assigned[p[j-i]] = s[j];
                    used.insert(s[j]);
                }
                else
                {
                    works = 0;
                }
            }
            else
            {
                if(assigned[p[j-i]] != s[j])
                {
                    works = 0;
                }
            }
        }
        if(works)
        {
            cout << i << wp;
        }
    }
}