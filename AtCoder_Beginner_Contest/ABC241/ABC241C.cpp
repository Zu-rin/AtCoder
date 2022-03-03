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

int num;

int Row(vector<vector<int>> &d) {
	int i, j;
	rep(i, num) {
		int s = 0;
		queue<int> q;
		rep(j, num) {
			s += d[i][j];
			q.push(d[i][j]);
			if (q.size() > 6) {
				s -= q.front();
				q.pop();
			}
			if (s >= 4)
				return 1;
		}
	}
	return 0;
}

int Col(vector<vector<int>>& d) {
	int i, j;
	rep(i, num) {
		int s = 0;
		queue<int> q;
		rep(j, num) {
			s += d[j][i];
			q.push(d[j][i]);
			if (q.size() > 6) {
				s -= q.front();
				q.pop();
			}
			if (s >= 4)
				return 1;
		}
	}
	return 0;
}

int Slant(vector<vector<int>>& d) {
	int i, j;
	rep(i, num - 5) {
		rep(j, num - 5) {
			int k = 0, s = 0, t = 0;
			rep(k, 6)
				s += d[i + k][j + k];
			rep(k, 6)
				t += d[i + k][j + 5 - k];
			if (s >= 4 or t >= 4)
				return 1;
		}
	}
	return 0;
}

int main(void) {
	int i, j;
	string s;
	cin >> num;
	vector<vector<int>> d(num, vector<int>(num, 0));
	rep(i, num) {
		cin >> s;
		rep(j, num) {
			if (s[j] == '#')
				d[i][j] = 1;
		}
	}
	if (Row(d) or Col(d) or Slant(d))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}