#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100000] = { 0 };

int Search(vector<int> const &data, int n, int num) {
	if (n >= num - 3)
		return abs(data[num - 1] - data[n]);
	if (dp[n] > 0)
		return dp[n];
	int a, b;
	a = abs(data[n] - data[n + 1]) + Search(data, n + 1, num);
	b = abs(data[n] - data[n + 2]) + Search(data, n + 2, num);
	return dp[n] = min(a, b);
}

int main(void) {
	int num, i = 0, ans;
	cin >> num;
	vector<int> data(num);
	for (; i < num; i++)
		scanf_s("%d", &data[i]);
	ans = Search(data, 0, num);
	cout << ans << "\n";
	return 0;
}