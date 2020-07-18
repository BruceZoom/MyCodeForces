#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    int x[3];
    cin >> t;
    while(0 < t--){
        cin >> x[0] >> x[1] >> x[2];
        sort(x, x+3);
        if(x[2] != x[1]){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES\n";
        cout << x[2] << " " << x[0] << " " << 1 << endl;
    }
    return 0;
}
