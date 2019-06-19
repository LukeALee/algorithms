#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sLen=nums.size();
        if(sLen==0)return 0;
        if(sLen==1)return nums[0];
        vector<int> dp(sLen+1,0);
        dp[1] = nums[0];
        for(int i=2;i<=sLen;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[sLen];
    }
};


int main(){
    vector<int> prices = {1,2,3,1};
    Solution sol;
    int result;
    result = sol.rob(prices);
    cout << result;
}