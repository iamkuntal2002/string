#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/bulls-and-cows/
class Solution {
public:
    string getHint(string secret, string guess) {
        int cows =0;
        int bulls =0;
        vector<int> no(10,0);
        for(int i =0;i<secret.length();i++){
            int s = secret[i]-'0';
            int g = guess[i]-'0';
            if(s == g) bulls++;
            else{
                if(no[s]<0) cows++;
                if(no[g]>0) cows++;
                // cows++;
                no[s]++;
                no[g]--;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};