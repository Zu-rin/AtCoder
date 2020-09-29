#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1 << 30
using namespace std;

int num, g;

int Search(vector<int> &p, vector<int> &c, int cmp, int sum, int score, int id) {
	if (id == num) {
		if (score >= g)
			return sum;
		for (int i = num - 1; i >= 0; i--) {
			if ((cmp & (1 << i)) == 0) {
				if ((p[i] - 1) * (i + 1) * 100 + score >= g) {
					sum += (g - score) / ((i + 1) * 100);
					if ((g - score) % ((i + 1) * 100) > 0)
						sum++;
					return sum;
				}
				break;
			}
		}
		return INF;
	}
	int ans = Search(p, c, cmp, sum, score, id + 1);
	cmp = cmp | (1 << id);
	score += p[id] * (id + 1) * 100 + c[id];
	ans = min(ans, Search(p, c, cmp, sum + p[id], score, id + 1));
	return ans;
}

int main(void) {
	int i = 0, cmp = 0;
	cin >> num >> g;
	vector<int> p(num), c(num);
	for (; i < num; i++)
		scanf_s("%d%d", &p[i], &c[i]);
	int ans = Search(p, c, cmp, 0, 0, 0);
	printf("%d\n", ans);
	return 0;
}