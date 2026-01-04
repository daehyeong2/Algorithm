#include <bits/stdc++.h>
using namespace std;

int r, c, cnt = 1, firstL, secondL;
const int big = 1504 * 1504;
int d[1504][1504], visited[1504][1504], chunks[1504][1504], points[big], unf[big], dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char ch;

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    int fa = Find(a);
    int fb = Find(b);
    if(fa != fb) unf[fa] = fb;
}

void setComponent(int y, int x){
    if(d[y][x] == 2){
        if(!firstL) firstL = cnt;
        else secondL = cnt;
    }
    if(!points[cnt]){
        visited[y][x] = 1;
        points[cnt] = y * 1501 + x;
    }
    chunks[y][x] = cnt;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || chunks[ny][nx]) continue;
        if(d[ny][nx] == 0 || d[ny][nx] == 2){
            setComponent(ny, nx);
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> ch;
            if(ch == '0'){
                d[i][j] = 0;
            } else if(ch == 'X'){
                d[i][j] = 1;
            } else if(ch == 'L'){
                d[i][j] = 2;
            }
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if((d[i][j] == 0 || d[i][j] == 2) && !chunks[i][j]){
                setComponent(i, j);
                cnt++;
            }
        }
    }
    if(firstL == secondL){
        cout << 0 << "\n";
        exit(0);
    }
    for(int i = 1; i <= big; i++) unf[i] = i;
    queue<int> q;
    for(int i = 1; i < cnt; i++){
        q.push(points[i]);
    }
    while(!q.empty()){
        queue<int> q2;
        q2.push(q.front()); q.pop();
        while(!q2.empty()){
            int y = q2.front() / 1501;
            int x = q2.front() % 1501; q2.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if(!visited[ny][nx]){
                    if(d[ny][nx] == 1){
                        q.push(ny*1501 + nx);
                        d[ny][nx] = 0;
                        visited[ny][nx] = visited[y][x] + 1;
                        chunks[ny][nx] = chunks[y][x];
                    } else {
                        q2.push(ny*1501 + nx);
                        visited[ny][nx] = visited[y][x];
                        chunks[ny][nx] = chunks[y][x];
                    }
                } else if(chunks[ny][nx] != chunks[y][x] && Find(chunks[ny][nx]) != Find(chunks[y][x])){
                    Union(chunks[ny][nx], chunks[y][x]);
                    if(Find(firstL) == Find(secondL)){
                        cout << visited[ny][nx] - 1 << "\n";
                        exit(0);
                    }
                }
            }
        }
    }
    return 0;
}