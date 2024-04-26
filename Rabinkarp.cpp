#include <bits/stdc++.h>
using namespace std;

void rabinkarp(string s, string pattern)
{
    int hash = 13;
    int patternhash = 0;
    int stringhash = 0;
    int h = 1;
    int d = 10;
    for (int i = 0; i < pattern.length() - 1; i++)
    {
        h = (h * d) % hash;
    }
    for (int i = 0; i < pattern.length(); i++)
    {
        patternhash = (patternhash * d + pattern[i]) % hash;
        stringhash = (stringhash * d + s[i]) % hash;
    }

    for (int i = 0; i <= s.length() - pattern.length(); i++)
    {

        if (patternhash == stringhash)
        {
            int j;
            for (j = 0; j < pattern.length(); j++)
            {
                if (s[i + j] != pattern[j])
                    break;
            }
            if (j == pattern.length())
            {
                cout << "Pattern found at index : " << i << endl;
                return;
            }
        }

        if (i < s.length() - pattern.length())
        {

            stringhash = (d * (stringhash - s[i] * h) + s[i + pattern.length()]) % hash;

            if (stringhash < 0)
                stringhash += hash;
        }
    }
    cout << "Pattern not found";
}

int main()
{
    string s = "patternmatchingalgorithm";
    string pattern = "attern";
    rabinkarp(s, pattern);
}