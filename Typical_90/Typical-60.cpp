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

template<class T>
struct LongestIncreasingSubsequence {
	vector<T> lis;

	int Binary_search(T n) {
		// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦š‚ğ•Ô‚·
		// n < min(lis) : -1
		// max(lis) < n : lis.size() - 1
		auto tag = upper_bound(lis.begin(), lis.end(), n);
		return distance(lis.begin(), tag) - 1;
	}

	int Add(T newdata) {
		int k = Binary_search(newdata);
		if (k < 0 || newdata != lis[k]) {
			k++;
			if (k == lis.size())
				lis.push_back(newdata);
			else
				lis[k] = newdata;
		}
		return k;
	}

	int Size() {
		return (int)lis.size();
	}
};

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	vector<int> d(num), x(num), m(num);
	LongestIncreasingSubsequence<int> a, b;
	rep(i, num) {
		cin >> d[i];
		a.Add(d[i]);
		x[i] = a.Size();
		m[i] = *a.lis.rbegin();
	}
	for (i = num - 1; i >= 0; i--) {
		x[i] += b.Binary_search(m[i] - 1) + 1;
		b.Add(d[i]);
	}
	for(int c : x)
		chmax(ans, c);
	cout << ans << "\n";
	return 0;
}