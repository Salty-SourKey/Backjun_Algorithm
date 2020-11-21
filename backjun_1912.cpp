#include <iostream>
using namespace std;
int pSum[100001];
int Max(int a, int b){
    return a > b ? a: b;
}
int Min(int a, int b){
    return a < b ? a: b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, temp, result = -1000000, temp_min = 1000;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> temp;
        pSum[i+1] = pSum[i] + temp;
    }
    for(int i = 0; i < N; ++i){
        temp_min = Min(temp_min, pSum[i]);
        result = Max(pSum[i+1]-temp_min, result);
    }
    cout << result;
    return 0;
}