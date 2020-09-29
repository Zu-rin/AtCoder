#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1 << 30

using namespace std;

int Num, A, B, C;

int Search(int a, int b, int c, const vector<int> &d, int e) {
	if (e == Num) {
		if (min(a, min(b, c)) > 0)
			return abs(A - a) + abs(B - b) + abs(C - c);
		else
			return INF;
	}
	int ans = INF;
	ans = min(ans, Search(a, b, c, d, e + 1));
	ans = min(ans, Search(a + d[e], b, c, d, e + 1) + 10);
	ans = min(ans, Search(a, b + d[e], c, d, e + 1) + 10);
	ans = min(ans, Search(a, b, c + d[e], d, e + 1) + 10);
	return ans;
}

int main(void) {
	cin >> Num >> A >> B >> C;
	vector<int> d(Num);
	for (int i = 0; i < Num; i++)
		scanf("%d", &d[i]);
	printf("%d\n", Search(0, 0, 0, d, 0) - 30);
	return 0;
}
