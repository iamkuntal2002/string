#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    bool isVowel(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int count = 0;
        for(int i =0;i<k;i++){
            if(isVowel(s[i])) count++;
        }
        ans = max(ans,count);
        int left =0;
        int right = k;
        while(right <s.size()){
            if(isVowel(s[right++])) count++;
            if(isVowel(s[left++])) count--;
            ans = max(ans,count);
        }
        return ans;
    }
};