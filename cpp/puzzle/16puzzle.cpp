#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000
using namespace std;

int main(){
    int a[6]={3,4,5,6,1,2};
    vector<int> v={3,4,5,6,1};
    // cout << binary_search(v.begin(), v.end(), v[0]) << endl;
    cout << *lower_bound(v.begin(), v.end(), v[v.size()-1]) << endl;
    cout << *upper_bound(v.begin(), v.end(), v[0]) << endl;
    // int MDT[16][16];
    // int n=1;
    // int m = 15;
    // for (int i = 0; i < 16;i++){
    //     for (int j = 0; j < 16;j++){
    //         MDT[i][j] = abs(i / 4 - j / 4) + abs(i % 4 - j % 4);
    //         cout <<MDT[i][j]<<',';
    //     }
    //     cout << endl;
    // }
    return 0;
}
