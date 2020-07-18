#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int m;

struct Edge{
    int x;
    int y;
    int t;
    Edge(int x, int y, int t):x(x),y(y),t(t){}
    void print(){
        cout << x << " " << y << " " << t << endl; 
    }
};

vector<Edge> edges;
// vector<bool> undirected;
vector<int> edge_idx[200005];
bool visited[200005];
int in_digree[200005];
queue<int> Q;

// int find_root(int begin){
//     int root = begin;
//     int i;
//     while(1){
//         visited[root] = 1;
//         for(i=0; i<edge_idx[root].size(); i++){
//             int idx = edge_idx[root][i];
//             if(edges[idx].t && edges[idx].y == root){
//                 root = edges[idx].y;
//                 break;
//             }
//         }
//         if(i >= edge_idx[root].size()) break;
//         if(visited[root]) return -1;
//     }
//     return root;
// }

int main()
{
    int i, j, k;
    int x, y, z;
    int t;

    cin >> t;
    while(0 < t--){
        edges.clear();
        // undirected.clear();
        while(!Q.empty()) Q.pop();
        for(i=0;i<n;i++) edge_idx[i].clear();
        memset(visited, 0, sizeof(visited));
        memset(in_digree, 0, sizeof(in_digree));

        cin >> n >> m;
        for(i=0;i<m;i++){
            cin >> z >> x >> y;
            x--; y--;
            Edge e(x, y, z);
            if(e.x != x || e.y != y || e.t != z) return -1;
            edge_idx[x].push_back(edges.size());
            edge_idx[y].push_back(edges.size());
            edges.push_back(e);
            // undirected.push_back(!z);
            if(z){
                in_digree[y] += 1;
            }
        }

        for(i=0; i<n; i++){
            if(in_digree[i] == 0){
                Q.push(i);
            }
        }
        // cout << Q.size() << endl;
        // cout << Q.front() << endl;
        int fail = Q.empty();
        while(!fail && !Q.empty()){
            x = Q.front(); Q.pop();
            if(in_digree[x] || visited[x]) continue;                // ??????
            visited[x] = 1;
            for(i=0; i<edge_idx[x].size(); i++){
                Edge e = edges[edge_idx[x][i]];
                z = -1;
                if(e.t == 0){
                    if(e.x == x){
                        edges[edge_idx[x][i]].t = 1;
                        if(visited[e.y]) {
                            fail = 1;
                            // cout << "fail 1\n";
                        }
                        if(in_digree[e.y] <= 0) z = e.y;
                        // Q.push(e.y);
                    }
                    else{
                        edges[edge_idx[x][i]].t = -1;
                        if(visited[e.x]) {
                            fail = 1;
                            // cout << "fail 2\n";
                        }
                        if(in_digree[e.x] <= 0) z = e.x;
                        // Q.push(e.x);
                    }
                }
                else if(e.t == 1 && e.x == x){
                    y = e.y;
                    if(visited[y]) {
                        fail = 1;
                        // cout << "fail 3\n";
                    }
                    z = y;
                    // Q.push(y);
                }
                else if(e.t == -1 && e.y == x){
                    y = e.x;
                    if(visited[y]) {
                        fail = 1;
                        // cout << "fail 4\n";
                    }
                    z = y;
                    // Q.push(y);                    
                }
                if(z != -1){
                    in_digree[z]--;
                    if(!in_digree[z]) Q.push(z);
                }
                if(fail) break;
            }
        }
        if(fail){
            // fail
            cout << "NO\n";
        }
        else{
            // succeed
            cout << "YES\n";
            // edges[0].print();
            for(i=0; i<edges.size(); i++){
                // if(undirected[i]){
                    Edge e = edges[i];
                    // e.print();
                    if(e.t == 1){
                        cout << e.x+1 << " " << e.y+1 << endl;
                    }
                    else{
                        cout << e.y+1 << " " << e.x+1 << endl;
                    }
                // }
            }
        }
    }

    return 0;
}