#include <iostream>

using namespace std;

int N, M, parent[1000010];

// a�� �θ� ������ �˷��� 
int findf(int a) {
	if (a == parent[a]) return a;
	// return findf(parent[a]); ��� -> �ð��ʰ�
	parent[a] = findf(parent[a]);
	return parent[a];
}

// a b ��ħ 
void unionf(int a, int b) {
	a = findf(a);
	b = findf(b);
	parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	while (M-- > 0) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			unionf(a, b);
		} else {
			if (findf(a) == findf(b)) {
				cout << "YES" << "\n";
			} else {
				cout << "NO" << "\n";
			}
		}
	}
    return 0;
}
