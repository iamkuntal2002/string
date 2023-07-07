#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = accumulate(neededTime.begin(), neededTime.end(),0);
        int len = neededTime.size();
        int rcost = 0;
        int curr =0;
        while(curr < len){
            int col = colors[curr];
            int maxcost = neededTime[curr];
            int temp = curr;
            while(temp<len && colors[temp] == col){
                maxcost = max(maxcost,neededTime[temp]);
                temp++;
            }
            if(temp>curr){
                rcost += maxcost;
            }
            curr = temp;
        }
        return total - rcost;
    }
};