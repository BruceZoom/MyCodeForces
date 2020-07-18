#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int n;
long long a[100005][2];
// long long a[200005];
// long long **cv;
// map<int, map<int, long long> > cv;
// bool valid[200005];

// class cmp{
//     public:
//         bool operator()(const int i, const int j) const{
//             return a[i] > a[j];
//         }
// };

// priority_queue<int, vector<int>, cmp> idx;


int main()
{
    int i, j, k;
    int x, y, z;
    long long res;
    int n_odd, n_even;

    cin >> n;
    n_odd = n/2 + 1;
    n_even = n/2;
    // memset(valid, 1, sizeof(valid));
    for(i=0; i<n; i++){
        cin >> a[i/2][i%2];
        a[i/2][i%2] += (i<2?0:a[i/2-1][i%2]);
        // cin >> a[i];
        // idx.push(i);
    }

    // cout << a[0][0] << " " << a[1][0] << endl;
    // cout << a[0][1] << endl;

    res = max(
        a[0][0] + a[n_even-1][1],
        a[n_odd-1][0]
    );
    for(i=1; i<n-1; i++){
        if(i%2){
            // even
            res = max(res,
                a[i/2][1] + a[n_odd-1][0] - a[(i-1)/2][0]
            );
        }
        else{
            // odd
            res = max(res,
                a[i/2][0] + a[n_even-1][1] - a[(i-1)/2][1]
            );
        }
    }

    cout << res << endl;

    /* Greedy */
    // res = a[0];
    // for(k=n; k>1; k-=2){
    //     while(!valid[i = idx.top()]) idx.pop();
    //     // cout << a[i] << endl;
    //     for(j = (i - 1 + n) % n; !valid[j]; j = (j - 1 + n) % n);
    //     a[i] = a[j]; valid[j] = 0;
    //     for(j = (i + 1) % n; !valid[j]; j = (j + 1) % n);
    //     a[i] += a[j]; valid[j] = 0;
    //     res = a[i];
    //     idx.pop(); idx.push(i);
    // }

    // cout << res << endl;

    /* DP */
    // // cv = new long long*[n];
    // for(i=0; i<n; i++){
    //     cin >> a[i];
    //     // cv[i] = new long long[n];
    //     // cv[i] = new map<int, long long>();
    //     cv[i][i] = a[i];
    // }

    // for(int len=2; len<n; len+=2){
    //     for(i=0; i<n; i++){
    //         j = i + len;
    //         cv[i][j%n] = cv[i][i] + cv[(i+2)%n][j%n];
    //         if(len > 2){
    //             for(k=i+3; k<j; k+=2){
    //                 x = k-1; y = k+1;
    //                 cv[i][j%n] = max(cv[i][j%n], cv[i][x%n] + cv[y%n][j%n]);
    //             }
    //         }
    //     }
    // }

    // long long res = cv[0][n-1];
    // // cout << res;
    // for(i=1; i<n; i++){
    //     // cout << " " << cv[i][(i+n-1)%n];
    //     res = max(res, cv[i][(i+n-1)%n]);
    // }
    // // cout << endl;

    // cout << res << endl;


    // // for(i=0; i<n; i++){
    // //     delete cv[i];
    // // }
    // // delete cv;

    return 0;
}