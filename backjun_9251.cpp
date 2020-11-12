#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string dt_1;
    string dt_2;
    cin >> dt_1 >> dt_2;
    for(int i = 0; i < dt_1.length(); ++i){
        if(dt_2.find(dt_1[i] ) == -1){
            dp[i][0] = 0;
            dp[i][1] = -1;
            } else{
            dp[i][0] = 1;
            dp[i][1] = dt_2.find(dt_1[i]);
            }
        for(int j = 0; j < i; ++j){
            if(dt_2.find(dt_1[i], dp[j][1]+1) != -1){
                if(dp[i][0] == dp[j][0]+1 && dp[j][1] != -1) dp[i][1] = min(dp[j][1], dp[i][1]);
                else if(dp[i][0] < dp[j][0] + 1){
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = dt_2.find(dt_1[i], dp[j][1]+1);
                }
            }
            else{
                if(dp[i][0] == dp[j][0] && dp[j][1] != -1) dp[i][1] = min(dp[j][1], dp[i][1]);
                else if(dp[i][0] < dp[j][0] + 1){
                    dp[i][0] = dp[j][0];
                    dp[i][1] = dp[j][1];
                }
            }
        }
    }
    cout << dp[dt_1.length()-1][0];
    return 0;
}
