#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, S, E, ret, C[504][504], F[504][504], pre[504];
vector<vector<int>> D;

int main(){
    for (int i = 0; i < 504; i++) D.emplace_back();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        D[a].push_back(b);
        D[b].push_back(a);
        C[a][b] = c;
        C[b][a] = c;
    }
    cin >> S >> E;
    while (1) {
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            int here = q.front(); q.pop();
            for (int there : D[here]) {
                if (F[here][there] < C[here][there] && pre[there] == -1) {
                    pre[there] = here;
                    q.push(there);
                    if (there == E) break;
                };
            }
        }
        if (pre[E] == -1) break;
        int flow = 1e9;
        for (int i = E; i != S; i = pre[i]) flow = min(flow, C[pre[i]][i] - F[pre[i]][i]);
        for (int i = E; i != S; i = pre[i]) {
            F[pre[i]][i] += flow;
            F[i][pre[i]] -= flow;
        }
        ret += flow;
    }
    cout << ret << "\n";
    return 0;
}
