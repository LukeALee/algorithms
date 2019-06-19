#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int sLen=days.size();
        vector<long long> dp(sLen,INT_MAX);
        dp[sLen-1]=min(min(costs[0],costs[1]),costs[2]);
        int gap[3]={sLen-1,sLen-1,sLen-1};
        for(int i=sLen-2;i>=0;i--){
            while(gap[0]<sLen-1 && (days[gap[0]]-days[i]<1))gap[0]++;
            while(gap[1]<sLen-1 && (days[gap[1]]-days[i]<7))gap[1]++;
            while(gap[2]<sLen-1 && (days[gap[2]]-days[i]<30))gap[2]++;
            dp[i]=min(min(dp[gap[0]]+costs[0],dp[gap[1]]+costs[1]),dp[gap[2]]+costs[2]);
            gap[0]=gap[1]=gap[2]=i;
        }
        return dp[0];
    }
};

int main(){
    vector<int> days = {1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29};
    vector<int> costs = {3,14,50};
    Solution sol;
    int result;
    result = sol.mincostTickets(days, costs);
    cout << result << endl;
    return 0;
}