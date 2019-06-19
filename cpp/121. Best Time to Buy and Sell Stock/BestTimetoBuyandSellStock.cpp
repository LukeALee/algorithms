#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    vector<vector<int>> profit; 
public:
    int maxProfit(vector<int>& prices) {
        int sLen=prices.size();
        if(sLen<=1)return 0;
        profit = vector<vector<int>>(sLen,vector<int>(sLen,0));
        int maxP=0;
        for(int i=0;i<sLen;i++){
            for(int j=i+1;j<sLen;j++){
                profit[i][j]=max(prices[j]-prices[i],profit[i][j-1]);
                maxP=max(maxP,profit[i][j]);
            }
        }
        return maxP;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    // vector<int> dp(5,0);
    cout << *min_element(prices.begin(), prices.end())<<endl;
    Solution sol;
    int result;
    result = sol.maxProfit(prices);
    cout << result;
}