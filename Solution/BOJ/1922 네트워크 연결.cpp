#include <iostream>
// #include <vector>
// #include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, parent[1001];
//vector<pair<int, int>> adj[1001];
struct Info {
	int a, b, c;
	Info() {}
};

Info edge[100001];

int findf(int a) {
	if (a == parent[a]) return a;
	parent[a] = findf(parent[a]);
	return parent[a];
}

void unionf(int a, int b) {
	a = findf(a);
	b = findf(b);
	parent[a] = b;
}

int comp(Info a, Info b) {
	return a.c < b.c;
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i].a = a;
		edge[i].b = b;
		edge[i].c = c;
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	// ���� ũ�� ������ ����
	sort(edge, edge + m, comp);
	// ũ�罺Į �˰��� - ������ ����� ���� �� ���� Ʈ�� ���� 
	// ������ �������� Ʈ�� ����
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		a = edge[i].a;
		b = edge[i].b;
		c = edge[i].c;
		if (findf(a) != findf(b)) {
			unionf(a, b);
			answer += c; // ��� ���
            //count++; // Ʈ�� ���� üũ 
		}
	}
	//  if (cnt != n - 1) ? Ʈ�� ������ �ƴ�
	cout << answer << endl;
	return 0;
} 
