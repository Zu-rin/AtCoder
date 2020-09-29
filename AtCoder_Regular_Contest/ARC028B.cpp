#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, a;
	cin >> num >> k;
	priority_queue<pair<int, int>> que;
	for (i = 1; i <= k; i++) {
		cin >> a;
		que.push(make_pair(a, i));
	}
	cout << que.top().second << "\n";
	for (; i <= num; i++) {
		cin >> a;
		if (a < que.top().first) {
			que.push(make_pair(a, i));
			que.pop();
		}
		cout << que.top().second << "\n";
	}
	return 0;
}