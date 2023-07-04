#include <bits/stdc++.h>
using namespace std;
// https : //leetcode.com/problems/largest-number/
static bool comp(string s1, string s2)
{
    return (s1 + s2) > (s2 + s1);
}
string largestNumber(vector<int> &nums)
{
    string res = "";
    vector<string> st;
    for (auto &val : nums)
        st.push_back(to_string(val));
    sort(st.begin(), st.end(), comp);
    for (auto &s : st)
        res += s;
    while (res.size() > 1 && res[0] == '0')
    {
        res.erase(res.begin());
    }
    return res;
}