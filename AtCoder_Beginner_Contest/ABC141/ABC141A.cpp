#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	string s;
	cin >> s;
	if (s == "Sunny")
		printf("Cloudy\n");
	else if (s == "Cloudy")
		printf("Rainy\n");
	else
		printf("Sunny\n");
	return 0;
}