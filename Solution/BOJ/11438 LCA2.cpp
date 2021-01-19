#include <iostream>
#include <vector>
using namespace std;

int n, m, depth[100010], an[100010][18]; // an -> ������(2^0, 2^1...2^17��° ����) 
vector<int> adj[100010];
bool visited[100010];

void dfs(int parent, int curr, int param_depth) {
	if (visited[curr]) return;
	visited[curr] = true;
	depth[curr] = param_depth;
	an[curr][0] = parent;
	for (int i = 0; i < adj[curr].size(); i++) {
		dfs(curr, adj[curr][i], param_depth + 1);
	}
}

int lca(int a, int b) {
	// a�� ���̰� b���� �� ��� ����(���� ó���ϱ� ����) 
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	// ���� ���̰� ���� �ٸ���
	if (depth[a] != depth[b]) {
		// a -> b���� ���̸� ����
		int diff = depth[a] - depth[b];
		for (int i = 0, j = 1; i <= 17; i++, j *= 2) {
			if (diff & j) {
				a = an[a][i];
			}
		} 
	}
	// depth[a] == depth[b]�� ����
	if (a == b) return a;
	
	for (int i = 17; i >= 0; i--) {
		if (an[a][i] != an[b][i]) {
			a = an[a][i];
			b = an[b][i];
		}
	}
	//LCA�� �ٷ� �Ʒ����� �� ����
	return an[a][0]; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		// �ϴ� ��������� �����Ѵ� 
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// LCA�� ���� �ڷ� ����: ����, 1/2/4/8...��° ���� 
	dfs(1, 1, 1);
	// 2^1, 2^2, 2^3....2^17 �����ϱ�(sparse table) 
	for (int i = 1; i <= 17; i++) { // 2^i��° ���� 
		for (int j = 1; j <= n; j++) { // 1�� ���...n����� 
			int tmp = an[j][i-1];
			an[j][i] = an[tmp][i-1];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}
