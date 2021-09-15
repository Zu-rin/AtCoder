#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, q, k, x;
	queue<int> que;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> q;
	rep(i, q) {
		cin >> k;
		if (k == 1) {
			cin >> x;
			que.push(x);
		}
		else if (k == 2) {
			if (pq.size()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else {
			while (!que.empty()) {
				pq.push(que.front());
				que.pop();
			}
		}
	}
	return 0;
}