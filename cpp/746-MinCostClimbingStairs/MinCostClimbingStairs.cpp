#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sLen=cost.size();
        vector<int> dp(sLen+1,0);
        if(sLen<=2)return *min_element(cost.begin(),cost.end());
        dp[1]=cost[0];//dp记录走到当前这一步的最小花费
        for(int i=2;i<sLen+1;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i-1];
        }
        return min(dp[sLen-1],dp[sLen]);
    }
};

int main(){
    vector<int> prices1 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> prices2 = {10, 15, 20};
    Solution sol;
    int result;

    result = sol.minCostClimbingStairs(prices2);
    cout << result;

    result = sol.minCostClimbingStairs(prices1);
    cout << result;
}