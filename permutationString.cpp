#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int len1 = s1.length();
        int len2 = s2.length();
        if(len2<len1) return false;
        for(int i =0;i<len2-len1 +1;i++){
            string temp = s2.substr(i,len1);
            sort(temp.begin(),temp.end());
            if(temp == s1) return true;
        }
        return false;
    }
};