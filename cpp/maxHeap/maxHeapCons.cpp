#include<iostream>
#include<algorithm>
#define MAX 200
using namespace std;

int H, A[MAX + 1];
void maxHeapify(int i){
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;
    if(left<=H && A[left]>A[i]){
        largest = left;
    }else{
        largest = i;
    }
    if(right<=H && A[right]>A[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}
int main(){
    cin >> H;
    for (int i = 1; i <= H;i++){
        cin >> A[i];
    }
    for (int i = H / 2; i >= 1;i--){
        maxHeapify(i);
    }
    for (int i = 1; i <= H;i++){
        cout << " "<<A[i];
    }
    cout << endl;
    return 0;
}