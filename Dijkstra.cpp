#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;
const int INF = INT_MAX;
int q; // 顶点数量
vector<vector<int> > m; // 邻接矩阵
void dijkstra(int vs, int f, int prev[], int dist[]) {
    int k, min, tmp;
    vector<bool> flag(q, false);
    for(int i = 0; i < q; i++) {
        prev[i] = vs;
        dist[i] = m[vs][i];
    }
    flag[vs] = true;
    for(int i = 1; i < q; i++) {
        min = INF;
        for(int j = 0; j < q; j++) {
            if(!flag[j] && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        flag[k] = true;
        if(k == f) break;
        for(int j = 0; j < q; j++) {
            tmp = (m[k][j] == INF ? INF : (min + m[k][j]));
            if(!flag[j] && tmp < dist[j]) {
                prev[j] = k;
                dist[j] = tmp;
            }
        }
    }
}
int main() {
    cout << "请输入顶点数量: ";
    cin >> q;
    // 初始化邻接矩阵
    m.resize(q, vector<int>(q, INF));
    for(int i = 0; i < q; i++) {
        m[i][i] = 0;
    }
    cout << "请输入边的数量: ";
    int edgeCount;
    cin >> edgeCount;
    cout << "请输入每条边的起点、终点和权重:" << endl;
    for(int i = 0; i < edgeCount; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        m[u][v] = w;
        m[v][u] = w; // 无向图，双向设置权重
    }
    int start, end;
    cout << "请输入起点和终点: ";
    cin >> start >> end;
    // 创建前驱节点数组和距离数组
    vector<int> prev(q);
    vector<int> dist(q);
    dijkstra(start, end, prev.data(), dist.data());
    // 输出结果
    cout << "从顶点 " << start << " 到顶点 " << end << " 的最短距离为: " << dist[end] << endl;
    // 输出路径
    cout << "路径为: ";
    stack<int> path;
    int node = end;
    while(node != start) {
        path.push(node);
        node = prev[node];
    }
    path.push(start);
    while(!path.empty()) {
        cout << path.top();
        path.pop();
        if(!path.empty()) cout << " -> ";
    }
    cout << endl;
    return 0;
}
