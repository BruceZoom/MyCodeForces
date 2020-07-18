#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


int a[200005];
int main()
{
    int t, n;
    int i, j, k;
    int x, y, z;
    int low, high;

    cin >> t;
    while(0<t--){
        cin >> n;
        for(i=0; i<n; i++){
            cin >> a[i];
        }
        i=n-1;
        while(i>0 && a[i-1] >= a[i]) i--;
        while(i>0 && a[i-1] <= a[i]) i--;
        cout << i << endl;
    }

    return 0;
}