#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <stack>
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

class Stack {
	ll maxsize, size;
	stack<pp> st;

public:
	Stack(int max) {
		maxsize = max;
		size = 0;
	}

	int Push(int num, int d) {
		size += num;
		if (size > maxsize) {
			printf("FULL\n");
			return 0;
		}
		st.push(pp(num, d));
		return 1;
	}

	int Pop(int num) {
		if (size < num) {
			printf("EMPTY\n");
			return 0;
		}
		while (num > 0) {
			pp a = st.top();
			st.pop();
			if (a.first <= num) {
				num -= a.first;
				size -= a.first;
			}
			else {
				a.first -= num;
				size -= num;
				st.push(a);
				break;
			}
		}
		return 1;
	}

	int Top() {
		if (size == 0) {
			printf("EMPTY\n");
			return 0;
		}
		cout << st.top().second << "\n";
		return 1;
	}

	int Size() {
		cout << size << "\n";
		return 1;
	}
};

int main(void) {
	int num, i, k, a, b, ok;
	string s;
	cin >> num >> k;
	Stack st(k);
	rep(i, num) {
		cin >> s;
		if (s == "Push") {
			cin >> a >> b;
			ok = st.Push(a, b);
		}
		else if (s == "Pop") {
			cin >> a;
			ok = st.Pop(a);
		}
		else if (s == "Top")
			ok = st.Top();
		else
			ok = st.Size();
		if (!ok)
			break;
	}
	if(ok)
		printf("SAFE\n");
	return 0;
}