#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //使用变量声明数组
    const int aLen = 5;
    vector<vector<int>> dp(aLen,vector<int>(aLen,1));
    cout << (0 ^ 1 ^ 0) << endl;
    cout << (1 ^ 1 ^ 0) << endl;
    cout << (0 ^ 0 ^ 1) << endl;
    cout << (1 ^ 0 ^ 1) << endl;
    cout << (1 ^ 1 ^ 1) << endl;
    // vector<int> nums1 = {1,3, 5, 6, 7, 9};
    // vector<int> nums2 = {2,4, 6, 8};
    // cout << *lower_bound(nums1.begin(), nums1.end(), 6) << endl;
    // vector<int>::iterator iter=nums1.begin();
    // cout << *(iter + 1);
    // vector<vector<int> > res(aLen,vector<int>(aLen,0));
    // int array[aLen]{0};
    // int *pReg = new int[aLen]{1};
    // cout << *(array+1) << endl;
    // cout << *pReg << endl;
    // vector<vector<int>> matrix;
    // for (int i = 0; i < 3;i++){
    //     for (int j = 0; j < 4;j++){
    //         matrix[i].push_back(i + j);
    //     }
    // }
    // cout << matrix.size();
    // cout << "This is the end!";

    //位移运算不改变原值
    int n = 7;
    int mvn = n >> 1;
    cout << n << endl;
    cout << mvn << endl;
    return 0;
}