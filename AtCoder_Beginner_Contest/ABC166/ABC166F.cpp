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

int abc[3];

string Sim(vector<string> & s, int &ok) {
	int i, a, b;
	string ans = "";
	rep(i, s.size()) {
		a = abc[s[i][0] - 'A'];
		b = abc[s[i][1] - 'A'];
		if (a == 0 && b == 0) {
			ok = 0;
			return "";
		}
		if (a == 1 && b == 1 && s.size() - 1 > i) {
			int p = s[i + 1].find(s[i][0]);
			if (0 <= p && p < 2) {
				abc[s[i][0] - 'A']++; abc[s[i][1] - 'A']--;
				ans += s[i][0];
			}
			else {
				abc[s[i][0] - 'A']--; abc[s[i][1] - 'A']++;
				ans += s[i][1];
			}
		}
		else if (a <= b) {
			abc[s[i][0] - 'A']++; abc[s[i][1] - 'A']--;
			ans += s[i][0];
		}
		else {
			abc[s[i][0] - 'A']--; abc[s[i][1] - 'A']++;
			ans += s[i][1];
		}
	}
	return ans;
}

int main(void) {
	int num, i, ok = true;
	cin >> num;
	rep(i, 3)
		cin >> abc[i];
	string ans;
	vector<string> s(num);
	rep(i, num)
		cin >> s[i];
	ans = Sim(s, ok);
	if (ok) {
		printf("Yes\n");
		rep(i, num)
			cout << ans[i] << "\n";
	}
	else
		printf("No\n");
	return 0;
}