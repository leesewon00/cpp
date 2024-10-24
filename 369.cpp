#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int cnt[3]; // 3 6 9 의 개수가 순서대로 들어간다.

void init() {
	for (int i = 0; i < 3; i++) {
		cnt[i] = 0;
	}
}

bool is369(char c) {
	if (c == '3') {
		return true;
	}
	if (c == '6'){
		return true;
	}
	if (c == '9') {
		return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		init();

		int x; int y;
		cin >> x >> y;

		string str;
		cin >> str;

		int costSum = 0;

		for (int i = 0; i < str.length(); i++) {
			char cur = str[i];

			if (cur == '3') {
				cnt[0]++;
			}
			else if (cur == '6') {
				cnt[1]++;
			}
			else if (cur == '9') {
				cnt[2]++;
			}
			else {
				// length check

				int length = 0;
				for (int pos = i; pos < str.length(); pos++) {
					char poschar = str[pos];
					if (is369(poschar)) {
						// break;
						break;
					}
					else {
						length++;
					}
				}

				// 비용 비교
				int cost1 = length * x;
				int cost2 = x + y;

				if (cost1 < cost2) {
					costSum += cost1;
				}
				else {
					costSum += cost2;
				}

				// i갱신
				i = i + length - 1;
			}
		}

		//output
		int cnt369 = 0;
		cnt369 = min(cnt[0], cnt[1]);
		cnt369 = min(cnt369, cnt[2]);

		cout << costSum << " " << cnt369 << '\n';
	}
}
