#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int temp = k;
        stack<pair<char,int>> st;
        string ans = "";
        st.push({s[0],1});
        for(int i =1;i<s.size();i++){
            if(!st.empty()){
                //if same char as top then push it with prev_count + 1
                if(st.top().first == s[i]){
                    st.push({s[i],st.top().second+1});
                }
                //else push with count 1
                else st.push({s[i],1});
            }
            else st.push({s[i],1});
            //it top element count is equal to k then pop that sequence
            if(st.top().second == k){
                int temp = 0;
                while(!st.empty() && temp++ < k) st.pop();
            }
        }
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};  