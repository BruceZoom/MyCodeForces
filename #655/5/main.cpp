#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int m;
vector<int> tile_l[100];
vector<int> tile_r[100];
int tile_idx[100][100];
int memo[100][100];

// l inclusive, r exclusive
int greedy_column(int l, int r, int i){
    int res, idx;
    res = 0;
    for(int row=0; row<n; row++){
        idx = tile_idx[row][i];
        res += (l <= tile_l[row][idx] && tile_r[row][idx] < r);
    }
    return res * res;
}

// i inclusive, j exclusive
int dp(int i, int j){
    if(i == j) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    
    int tmp, idx;

    if(i+1==j){
        memo[i][j] = greedy_column(i, j, i);
    }
    else{
        memo[i][j] = 0;
        for(int k=i; k<j; k++){
            memo[i][j] = max(
                memo[i][j],
                greedy_column(i, j, k) + dp(i, k) + dp(k+1, j)
            );
        }
    }
    // cout << i << " " << j << " " << memo[i][j] << endl;
    return memo[i][j];
}

int main()
{
    int i, j, k;
    int x, y, z;
    int t;

    memset(memo, -1, sizeof(memo));

    cin >> n >> m;
    for(i=0; i<n; i++){
        tile_l[i].clear();
        tile_r[i].clear();

        cin >> t;
        while(0<t--){
            cin >> x >> y;
            x--; y--;
            for(z=x; z<=y; z++){
                tile_idx[i][z] = tile_l[i].size();
            }
            tile_l[i].push_back(x);
            tile_r[i].push_back(y);
        }
    }

    cout << dp(0, m) << endl;

    return 0;
}