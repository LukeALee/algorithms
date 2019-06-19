#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        if(N<=1)return false;
        dp[0]=0;
        for(int i = 1;i<=N/2;i++){
            if(N%i==0){
                if(dp[N-1-i]==0)return true;
                else if(dp[N-1-i]==-1){
                    dp[N-1-i]=divisorGame(N-i);
                    if(dp[N-1-i]==0)return true;
                }
            }
        }
        return false;
    }
private:
    vector<int> dp=vector<int>(1000,-1);
};

int main(){
    int N = 4;
    bool result;
    Solution sol;
    for (int i = 1; i < 10;i++){
        result = sol.divisorGame(i);
        cout << result << endl;
    }
        
}