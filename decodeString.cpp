#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/decoded-string-at-index/description/
    string decodeAtIndex(string s, int k) {
       long long size = 0;
        string ans = "";
        for (auto &c : s) size = isdigit(c) ? size * (c - '0') : ++size;
        for (int i = s.size() - 1; i >= 0; --i){
            k %= size;
            if (isalpha(s[i]) && !k) return ans += s[i];
            if (isdigit(s[i])) size /= s[i] - '0';
            else --size;
        }
        return ans;
    }
    int main(){
        string s = "leet2code3";
        decodeAtIndex(s,10);
    }