#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";
        if(k == 0) return num;
        stack<char> st;
        string res = "";
        st.push(num[0]);

        for(int i =1;i<num.size();i++){
            //if the prev character is greater than the curr then pop it out
            while(k>0 && !st.empty() && num[i]<st.top()){
                --k;
                st.pop();
            }
            st.push(num[i]);
            //to remove the leading zeros
            if(st.size()==1 && num[i] == '0' && k>0) st.pop();
        }
        while(k-- && !st.empty()){
            st.pop();
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i = 0;
        //if there is leading zeros
        while(res[i] == '0' && i<res.size()) i++;
        if(res.substr(i).size() == 0) return "0";
        return res.substr(i);
    }
};