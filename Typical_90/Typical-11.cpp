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

struct Job {
	int d, c;
	ll x;
	friend bool operator<(Job& l, Job& r) {
		return l.d < r.d;
	}
};

int main(void) {
	int num, i, j;
	vector<ll> dp(5001, 0);
	cin >> num;
	vector<Job> job(num);
	rep(i, num)
		cin >> job[i].d >> job[i].c >> job[i].x;
	sort(job.begin(), job.end());
	for (Job& a: job){
		for (i = a.d; i >= a.c; i--)
			chmax(dp[i], dp[i - a.c] + a.x);
		rep(i, 5000)
			chmax(dp[i + 1], dp[i]);
	}
	cout << dp[5000] << "\n";
	return 0;
}