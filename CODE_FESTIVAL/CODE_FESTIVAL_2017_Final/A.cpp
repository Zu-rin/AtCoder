#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string b, s = "";
	int i;
	cin >> b;
	if (b.size() < 10) {
		for (i = 0; i < b.size(); i++) {
			if (b[i] == 'A') {
				if (i < b.size() - 1 && b[i + 1] == 'A')
					s += "A";
			}
			else if (i < b.size() - 2 && b[i] == 'K' && b[i + 1] == 'I' && b[i + 2] == 'H') {
				s += "!";
				i += 2;
			}
			else {
				s = s + b[i];
			}
		}
		if (s == "!BR") {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}