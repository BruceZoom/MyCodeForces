#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool cands[100000];
vector<int> primes;

void init(){
    memset(cands, 1, sizeof(cands));
    primes.clear();
    for(int i=2; i<100000; i++){
        if(!cands[i]) continue;
        // cout << i << endl;
        primes.push_back(i);
        int j=2;
        while(i*j < 100000){
            cands[i*j] = 0;
            j++;
        }
    }
}

int main()
{
    int t, n;
    int i, j, k;
    int x, y, z;

    init();

    cin >> t;
    while(0 < t--){
        cin >> n;
        i = 0;
        while(i<primes.size() && n % primes[i]) i++;
        if(i < primes.size()) x = primes[i];
        else x = n;
        // cout << i << " " << x << endl;
        cout << n / x << " " << n - n / x << endl;
    }
    
    return 0;
}
