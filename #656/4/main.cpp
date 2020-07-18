#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int n;
char s[131100];


// lo inclusive, hi exclusive
int min_change(int lo, int hi, char target){
    if(lo + 1 == hi){
        return s[lo] != target;
    }

    int mid = (lo + hi) / 2;
    int i, j, k;
    
    int res_l=0;
    int res_r=0;
    
    for(i=lo; i<mid; i++){
        res_l += (s[i] != target);
    }
    res_l += min_change(mid, hi, target+1);

    for(i=mid; i<hi; i++){
        res_r += (s[i] != target);
    }
    res_r += min_change(lo, mid, target+1);

    return min(res_l, res_r);
}

int main()
{
    int t;
    int i, j, k;
    int x, y, z;

    cin >> t;
    while(0 < t--){
        cin >> n;
        for(i=0;i<n;i++){
            cin >> s[i];
        }
        cout << min_change(0, n, 'a') << endl;
    }
    

    return 0;
}