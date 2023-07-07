#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/
class Solution {
public:
    int minSwaps(string s) {
        int count =0;
        int j = s.length()-1;
        int open =0;
        int close = 0;
        for(int i =0;i<s.length();i++){
            if(s[i] == '[') open++;
            else close++;
            if(close>open){
                while(s[j] != '[') j--;
                swap(s[i],s[j]);
                count++;
                open++;
                close--;
                // cout<<"now s is "<<s<<endl;
            }
        }
        return count;
    }
};