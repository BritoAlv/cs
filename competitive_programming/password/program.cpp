#include <bits/stdc++.h>
using namespace std;

int kmp_password(string &s)
{
    vector<int> indexes(s.size(), 0);
    vector<int> pi(s.size(), 0);
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int k = pi[i - 1];
        while (k > 0)
        {
            if (s[i] == s[k])
            {
                break;
            }
            else
            {
                k = pi[k - 1];
            }
        }
        if (s[i] == s[k])
        {
            pi[i] = k + 1;
        }
        if (i != s.size() - 1)
        {
            indexes[pi[i]] = i;
        }
    }
    if (s.size() > 2)
    {
        int start = pi[s.size() - 1];
        while (start > 0)
        {
            if (indexes[start] > 0)
            {
                return start;
            }
            start = pi[start - 1];
        }
    }
    return -1;
}

int z_password(string &s)
{
    vector<int> z(s.size(), 0);
    int l = 0;
    int maxz = 0;
    z[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        z[i] = min(z[i - l], max(0, l + z[l] - i));
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > l + z[l])
        {
            l = i;
        }
        if (z[i] == s.size() - i && maxz >= (s.size() - i))
        {
            return s.size() - i;
        }
        maxz = max(maxz, z[i]);
    }
    return -1;
}

int main()
{
    string input;
    cin >> input;
    int result = kmp_password(input);
    if (result == -1)
    {
        cout << "Just a legend";
    }
    else
    {
        for (int i = 0; i < result; i++)
        {
            cout << input[i];
        }
    }
}
