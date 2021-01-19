#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, build_time[501], indegree[501], answer[501], before_max[501];
vector<int> adj[501];
queue<int> q;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> build_time[i];
		while (true) {
			int a;
			cin >> a;
			if (a == -1) break;
			adj[a].push_back(i);
			indegree[i]++;	
		} 
	}
	
	//���������� ���ؼ�, ������ = ������ ������ ���� �͵� 
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	// ������ �ǹ��� �������� �ּ� �ð� => answer
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		// curró��
		answer[curr] = before_max[curr] + build_time[curr];
		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i];
			--indegree[next];
			if (before_max[next] < answer[curr]) {
				before_max[next] = answer[curr];
			}
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << answer[i] << endl;
	}
}
