#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f; // 무한

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, f, arr[505][505];
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        fill(arr[i],arr[i]+1+n, INF);
    }

    //step 1. 채울 수 있는 것 모두 채우기
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = min(arr[a][b], c);
    }

    for(int i=1; i<=n; i++)
        arr[i][i] = 0;

    //step 2 ~ n
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][k] > arr[j][i] + arr[i][k]){
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }
    
    int ans = INF;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            ans = min(ans, arr[i][j] + arr[j][i]);
        }
    }
        
    if(ans == INF) ans = -1;
    cout << ans;
}