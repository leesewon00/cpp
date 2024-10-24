#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <ctype.h>

using namespace std;
int cnt;

// 백트래킹시 시간제한 걸린다.
// dp 사용 권장하는듯
int sumarr[31];
int result[31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	sumarr[1] = 1;
	for (int i = 2; i <= 30; i++) {
		sumarr[i] = 2 * sumarr[i - 1]+1;
	}

	result[1] = 3;
	for (int i = 2; i <= 30; i++) {
		result[i] = 1 + 2 * sumarr[i];
	}

	string str;
	cin >> str;

	int length = str.length();

	cout << result[length];
}
