#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/design-underground-system/
class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkInMap;     //id,station,time
    unordered_map<string,pair<double,int>> route;       //route,totaltime,count

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto pr = checkInMap[id];
        checkInMap.erase(id);
        string routeName = pr.first+"_"+stationName;
        route[routeName].first += t-pr.second;
        route[routeName].second +=1; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation+"_"+endStation;
        auto pr = route[routeName];
        return pr.first/pr.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */