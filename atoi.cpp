#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/string-to-integer-atoi/description/?
int atoi(string s)
{
    long long int val = 0;
    int sign = 1;
    int i = 0;
    while (s[i] == ' ' && i < s.length())
        i++;
    if (s[i] == '-' || s[i] == '+')
        sign = 44 - s[i++];
    while (i < s.size())
    {
        if (isdigit(s[i]))
            val = 10 * val + s[i++] - '0';
        else
            return val * sign;
        if (val > INT_MAX)
            return sign == -1 ? INT_MIN : INT_MAX;
    }
    return val * sign;
}