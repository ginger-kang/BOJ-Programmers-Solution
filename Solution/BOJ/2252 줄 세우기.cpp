#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, indegree[32001]; 
vector<int> adj[32001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
    	int a, b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	indegree[b]++; // b�� ������ ��� �߰� 
	}
	
	// indegree�� 0�� ���� ã�´�.
	// ť�� ���� ��Ƴ��´�. 
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	
	// ��Ƴ��� ���� �ϳ��� ť�� �����鼭 ���
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " "; 
		// ����� �͵��� ������ �ϳ��� �ٿ��ش�. 
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
 			}
		}
	}
}
