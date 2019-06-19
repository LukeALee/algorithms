#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> array_;
    int n;
    cin>>n;
    int gap=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        array_.push_back(tmp);
        gap+=tmp;
    }
    sort(array_.begin(),array_.end());
    int total=n*(array_[0]+array_[0]+n-1)/2;
    cout << total-gap << endl;
}