#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
 
map<int, vector<int>> mp;
int p = 0;
 
void Search(int pos, int par, vector<int> &ans, vector<int> &c) {
	ans[pos] = c[p++];
	for (int i = 0; i < mp[pos].size(); i++) {
		if (mp[pos][i] != par)
			Search(mp[pos][i], pos, ans, c);
	}
	return;
}
 
int main(void) {
	int num, a, b, i = 0, sum = 0;
	cin >> num;
	vector<int> c(num), ans(num);
	for (; i < num - 1; i++) {
		scanf("%d%d", &a, &b);
		mp[--a].push_back(--b);
		mp[b].push_back(a);
	}
	for (i = 0; i < num; i++)
		scanf("%d", &c[i]);
	sort(c.begin(), c.end(), greater<int>());
	for (i = 1; i < num; i++)
		sum += c[i];
	printf("%d\n", sum);
	Search(0, 0, ans, c);
	for (i = 0; i < num; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}