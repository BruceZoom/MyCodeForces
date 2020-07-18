#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int t, n;
    int a[200005];
    int i, j, k;
    int x, y, z;
    cin >> t;
    while(0<t--){
        cin >> n;
        x = 0;
        for(i=0; i<n; i++){
            cin >> a[i];
            if(x == 0 && a[i] != i+1) x = 1;
            if(x == 1 && a[i] == i+1) x = 2;
            if(x == 2 && a[i] != i+1) x = 3;
        }
        cout << (x+1)/2 << endl;
    }

    return 0;
}