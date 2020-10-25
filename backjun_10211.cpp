#include <stdio.h>
#include <algorithm>
using namespace std;

int pSum[1000];
int array[1000];
int ans[1000];
int main(){
    int q,n, maximum;
    scanf("%d\n", &q);
    int t = q;
    while(t){
        scanf("%d\n", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
            pSum[i+1] = pSum[i] + array[i];
        }
        maximum = array[0];
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                maximum = max(maximum,pSum[j+1]-pSum[i]);
            }
        }
        ans[q-t] = maximum;
        t--;
    }
    for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}

