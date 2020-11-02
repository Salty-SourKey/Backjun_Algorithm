#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    dp[1] = 0;
    for(int x = 2; x <= N; ++x){
        if(x % 6 == 0) dp[x] = min(min(dp[x-1], dp[x/2]), dp[x/3])+1;
        else if(x % 3 == 0) dp[x] = min(dp[x-1], dp[x/3])+1;
        else if(x % 2 == 0) dp[x] = min(dp[x-1], dp[x/2])+1;
        else dp[x] = dp[x-1]+1;
    }
    cout << dp[N];
    return 0;
}
