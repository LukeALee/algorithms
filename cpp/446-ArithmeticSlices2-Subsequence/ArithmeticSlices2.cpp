#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#define LL long long
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        LL ans = 0;
        vector<map<LL, int>> cnt(n);//cnt 记录公差对应的弱等差子序列（长度大于等于2的子序列）数目
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                LL delta = (LL)A[i] - (LL)A[j];
                int sum = 0;
                if (cnt[j].find(delta) != cnt[j].end()) {
                    sum = cnt[j][delta];
                }
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution sol;
    int result;
    result = sol.numberOfArithmeticSlices(nums);
    cout << result << endl;
}