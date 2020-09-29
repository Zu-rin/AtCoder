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

class Kaburin {
	int step, num, combo;
	ll damage;
	queue<int> act, retn, retc, comn, comc;

public:
	Kaburin() {
		step = num = damage = combo = 0;
		act.push(1);
		retn.push(5);
		retc.push(0);
		int i;
		rep(i, 2) {
			comn.push(0);
			comc.push(0);
			comc.push(0);
		}
		rep(i, 6) {
			retn.push(0);
			retc.push(0);
		}
		retc.push(0);
		retc.push(0);
	}

	void Damage(ll a) {
		damage += a + (a / 10) * (combo / 10);
	}

	void Normal() {
		num--;
		act.push(1);
		comn.push(1);
		comc.push(0);
		retn.push(1);
		retc.push(0);
		Damage(10);
	}

	void Charge() {
		num -= 3;
		int i;
		rep(i, 2)
			act.push(0);
		act.push(1);
		comn.push(0);
		comc.push(1);
		retn.push(0);
		retc.push(3);
		Damage(50);
	}

	void end() {
		if(act.size() == 1)
			act.push(1);
		comn.push(0);
		comc.push(0);
		retn.push(0);
		retc.push(0);
	}

	void nextstep(char c) {
		step++;
		combo += comn.front() + comc.front();
		num += retn.front() + retc.front();
		comn.pop();
		comc.pop();
		retn.pop();
		retc.pop();
		if (c == 'N' && act.front()) {
			if (num < 1)
				end();
			else
				Normal();
		}
		else if (c == 'C' && act.front()) {
			if (num < 3)
				end();
			else
				Charge();
		}
		else {
			end();
		}
		act.pop();
	}

	ll ans() {
		return damage;
	}

};

int main(void) {
	int num, i;
	string s;
	Kaburin d;
	cin >> s;
	rep(i, s.size()) {
		d.nextstep(s[i]);
	}
	cout << d.ans() << "\n";
	return 0;
}