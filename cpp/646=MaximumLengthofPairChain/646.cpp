#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> v1,vector<int> v2){
        if(v1[0]<v2[0])return true;
        else return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int sLen = pairs.size();
        if(sLen<=1) return sLen;
        sort(pairs.begin(),pairs.end(),cmp);
        vector<int> dp(sLen,1);
        dp[0]=1;
        for(int i=1;i<sLen;i++){
            int j=i-1;
            while(j>=0 && (pairs[i][0]>=pairs[j][0])){
                if(pairs[i][0]>pairs[j][1])
                    dp[i]=max(dp[i],dp[j]+1);
                j--;
            }     
        }
        return dp[sLen-1];
    }
};

int main(){  
    vector<vector<int>> pairs = {{9,10}, {2,4}, {-4,4}, {6,10},  {3,10},{3,8 }, {6,8}};//{{-6, 9}, {1, 6}, {8, 10}, {-1, 4},  {-6, -2},{-9, 8 }, {-5, 3}, {0, 3}};
    Solution sol;
    int result = 0;
    result = sol.findLongestChain(pairs);
    return 0;
}