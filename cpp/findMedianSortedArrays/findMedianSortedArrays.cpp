#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        int i=0,j=0;
        if(m>n){
            vector<int> nums=A;
            A=B;
            B=nums;
            int tmp=m;
            m=n;
            n=tmp;
        }
        int begin = 0, end = m, mid = (m + n + 1) / 2;
        while (begin <= end) {
            int i = (begin + end) / 2;
            int j = mid - i;
            if (i < end && B[j-1] > A[i]){//B[j-1] should be left to A[i]
                begin = i + 1; // i is too small
            }
            else if (i > begin && A[i-1] > B[j]) {//A[i-1] should be left to B[j]
                end = i - 1; // i is too big
            }
            else { // i is perfect
                int maxLeft = 0;
                if (i == 0) { maxLeft = B[j-1]; }
                else if (j == 0) { maxLeft = A[i-1]; }
                else { maxLeft = max(A[i-1], B[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                int minRight = 0;
                if (i == m) { minRight = B[j]; }
                else if (j == n) { minRight = A[i]; }
                else { minRight = min(B[j], A[i]); }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
        
};