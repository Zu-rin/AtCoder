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
	int num, i, t, a, b;
	priority_queue<int, vector<int>, greater<int>> que;
	cin >> num >> t;
	for (i = 0; i < num; i++) {
		cin >> a >> b;
		if (b <= t)
			que.push(a);
	}
	if (que.size() == 0)
		printf("TLE\n");
	else
		cout << que.top() << "\n";
	return 0;
}