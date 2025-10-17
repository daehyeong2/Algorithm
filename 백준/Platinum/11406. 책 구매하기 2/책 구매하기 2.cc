#include <bits/stdc++.h>
using namespace std;

int n, m, in, ret, S = 0, E = 201, C[300][300], F[300][300], pre[300];
vector<vector<int>> D;

int main(){
    for (int i = 0; i < 300; i++) D.emplace_back();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> in;
        D[0].push_back(i);
        D[i].push_back(0);
        C[0][i] = in;
    }
    for (int i = 101; i <= m+100; i++) {
        cin >> in;
        D[i].push_back(201);
        D[201].push_back(i);
        C[i][201] = in;
    }
    for (int i = 101; i <= m+100; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> in;
            D[j].push_back(i);
            D[i].push_back(j);
            C[j][i] = in;
        }
    }
    while (true) {
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
                }
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
