#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool exist[100];

int main()
{
    int t, n;
    int i, j, k;
    int x, y, z;

    cin >> t;
    while(0 < t--){
        memset(exist, 0, sizeof(exist));
        cin >> n;
        for(i=0; i<2*n; i++){
            cin >> x;
            if(!exist[x]){
                cout << x << " ";
                exist[x] = 1;
            }
        }
        cout << endl;
    }
    
    return 0;
}
