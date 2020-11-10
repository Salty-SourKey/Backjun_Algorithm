#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, result = 0;
    vector <int> temp_left;
    vector <int> temp_right;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j < i; ++j){
            if(arr[j] < arr[i]){
                if(temp_left.empty() == true || temp_left.back() < arr[j]) temp_left.push_back(arr[j]);
                else{
                    auto iter = lower_bound(temp_left.begin(), temp_left.end(), arr[j]);
                    *iter = arr[j];
                }
            }
        }
        for(int j = N; j > i; --j){
            if(arr[j] < arr[i]){
                if(temp_right.empty() == true||temp_right.back() < arr[j]) temp_right.push_back(arr[j]);
                else{
                    auto iter = lower_bound(temp_right.begin(), temp_right.end(), arr[j]);
                    *iter = arr[j];
                }
            }
        }
        result = max(result, int(temp_right.size()+temp_left.size())+1);
        temp_left.clear();
        temp_right.clear(); 
    }
    cout << result;
    return 0;
}