#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

pair<int, int> Search(int a, int b, int c) {
	if (c == 0)
		return make_pair(a, b);
	return Search(a + b, a, c - 1);
}

int main(void) {
	int k;
	cin >> k;
	pair<int, int> ans = Search(1, 1, k);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}