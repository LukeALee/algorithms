#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result=0;
        int sLen=triangle.size();
        if(sLen<1)return result;
        if(sLen==1 and triangle[0].size()==1)return triangle[0][0];
        //int minVal=0;
        vector<int> dp(sLen,triangle[0][0]);
        vector<int> tmp(sLen,triangle[0][0]);
        for(int i=1;i<sLen;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0)tmp[j]+=triangle[i][0];
                else if(j==triangle[i].size()-1)tmp[j]=dp[j-1]+triangle[i][j];
                else{
                    tmp[j]=min(dp[j-1],dp[j])+triangle[i][j];
                }
                
            }
            dp = tmp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};

int main(){
    string s1 = "abcdefg";
    for (int i = 0; i < s1.size();i++)
    {
        int int_i = s1[i];
        cout << int_i << endl;
    }
    cout << min(2,min(1, 2))<<endl;
    Solution sol;
    vector<vector<int>> triangle = {{2}, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
    int result;
    result = sol.minimumTotal(triangle);
    return 0;
}