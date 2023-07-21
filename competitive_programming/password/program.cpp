#include <bits/stdc++.h>
using namespace std;

int kmp_password(string &s)
{
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
    string input = "abcdabc";
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
