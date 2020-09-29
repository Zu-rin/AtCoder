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

int Judge(vector<string> & s) {
	int i, j, k, ok;
	vector<string> smp = {
		".###..#..###.###.#.#.###.###.###.###.###.",
		".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
		".#.#..#..###.###.###.###.###...#.###.###.",
		".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
		".###.###.###.###...#.###.###...#.###.###." };
	rep(k, 10) {
		ok = true;
		rep(i, 5) {
			rep(j, 4) {
				if (s[i][j] != smp[i][4 * k + j]) {
					ok = false;
					break;
				}
			}
		}
		if (ok)
			return k;
	}
}

int main(void) {
	int num, i, j;
	cin >> num;
	vector<string> s(5);
	rep(i, 5)
		cin >> s[i];
	rep(i, num) {
		vector<string> a(5);
		rep(j, 5) {
			a[j] = s[j].substr(4 * i, 4);
		}
		cout << Judge(a);
	}
	printf("\n");
	return 0;
}