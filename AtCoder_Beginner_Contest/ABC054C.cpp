#include <iostream>
#include <vector>
#define T true
#define F false

using namespace std;
int num, pth;

bool Complete(vector<bool> const &cmp) {
	int i;
	for (i = 0; i < num; i++)
		if (cmp[i] == F)
			break;
	if (i == num)
		return T;
	return F;
}

int Search(vector<vector<bool>> const &map, vector<bool> &cmp, int now) {
	if (Complete(cmp))
		return 1;
	int i = 0, ans = 0;
	for (; i < num; i++) {
		if (cmp[i] == F && map[now][i] == T) {
			cmp[i] = T;
			ans += Search(map, cmp, i);
			cmp[i] = F;
		}
	}
	return ans;
}

int main(void) {
	int i = 0, a, b;
	cin >> num >> pth;
	vector<vector<bool>> map(num, vector<bool>(num, F));
	vector<bool> cmp(num, F);
	for (; i < pth; i++) {
		scanf_s("%d%d", &a, &b);
		map[--a][--b] = T;
		map[b][a] = T;
	}
	cmp[0] = T;
	cout << Search(map, cmp, 0) << "\n";
	return 0;
}