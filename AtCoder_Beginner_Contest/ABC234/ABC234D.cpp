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
	int num, i, k, a;
	priority_queue<int, vector<int>, greater<int>> que;
	cin >> num >> k;
	rep(i, k) {
		cin >> a;
		que.push(a);
	}
	cout << que.top() << "\n";
	rep(i, num - k) {
		cin >> a;
		que.push(a);
		que.pop();
		cout << que.top() << "\n";
	}
	return 0;
}