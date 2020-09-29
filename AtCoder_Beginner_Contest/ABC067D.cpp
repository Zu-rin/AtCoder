#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

void Search(int n, vector<list<int>> &d, vector<int> &p, vector<int> &s) {
	for (auto itr = d[n].begin(); itr != d[n].end(); itr++) {
		if (*itr != p[n]) {
			p[*itr] = n;
			Search(*itr, d, p, s);
			s[n] += s[*itr];
		}
	}
	return;
}

int main(void) {
	int num, i, a, b, len = 0;
	cin >> num;
	vector<list<int>> d(num + 1);
	vector<int> p(num + 1, 0), s(num + 1, 1);
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d%d", &a, &b);
		d[a].push_back(b);
		d[b].push_back(a);
	}
	Search(1, d, p, s);
	for (i = num; i != 1; len++)
		i = p[i];
	for (a = num, i = 0; i < (len - 1) / 2; i++)
		a = p[a];
	if (s[1] > (s[a] << 1))
		printf("Fennec\n");
	else
		printf("Snuke\n");
	return 0;
}