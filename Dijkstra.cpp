#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;
const int INF = INT_MAX;
int q; // ��������
vector<vector<int> > m; // �ڽӾ���
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
    cout << "�����붥������: ";
    cin >> q;
    // ��ʼ���ڽӾ���
    m.resize(q, vector<int>(q, INF));
    for(int i = 0; i < q; i++) {
        m[i][i] = 0;
    }
    cout << "������ߵ�����: ";
    int edgeCount;
    cin >> edgeCount;
    cout << "������ÿ���ߵ���㡢�յ��Ȩ��:" << endl;
    for(int i = 0; i < edgeCount; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        m[u][v] = w;
        m[v][u] = w; // ����ͼ��˫������Ȩ��
    }
    int start, end;
    cout << "�����������յ�: ";
    cin >> start >> end;
    // ����ǰ���ڵ�����;�������
    vector<int> prev(q);
    vector<int> dist(q);
    dijkstra(start, end, prev.data(), dist.data());
    // ������
    cout << "�Ӷ��� " << start << " ������ " << end << " ����̾���Ϊ: " << dist[end] << endl;
    // ���·��
    cout << "·��Ϊ: ";
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
