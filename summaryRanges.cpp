#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/summary-ranges/
 vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int a = nums[0];
        for(int i =0;i<nums.size();i++){
            if(i==nums.size()-1 || nums[i+1]-1 != nums[i]){
                if(a != nums[i]) res.push_back(to_string(a)+"->"+to_string(nums[i]));
                else res.push_back(to_string(a));
                if(i != nums.size()-1) a = nums[i+1];
            }
        }
        return res;
    }
    int main(){
        vector<int> arr = {0,1,2,4,5,7};
        summaryRanges(arr);
    }