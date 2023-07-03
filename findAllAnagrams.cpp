#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        vector<int> res;
        if(p.size() > s.size()) return res;
        int len = s.size();
        int win = p.size();
        int left =0;
        int right =0;
        while(right < win){
            shash[s[right]-'a']++;
            phash[p[right]-'a']++;
            right++;
        }
        right--;
        while(right < len){
            if(phash == shash) res.push_back(left);
            right++;
            if(right != len){
                shash[s[right]-'a']++;
            }
            shash[s[left]-'a']--;
            left++;
        }
        return res;
    }
};