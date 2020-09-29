#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int ok = 0, N, S, W, E;
	string s;
	cin >> s;
	N = s.find('N');
	S = s.find('S');
	W = s.find('W');
	E = s.find('E');
	if (N >= 0 && S >= 0)
		ok++;
	else if (N < 0 && S < 0)
		ok++;
	if (W >= 0 && E >= 0)
		ok++;
	else if (W < 0 && E < 0)
		ok++;
	if (ok == 2)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}