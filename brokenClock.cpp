// 최소공배수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 두개의 value 사이에서 최소 공배수 찾아내기 -> 반복 ㄱㄱㄱ
// 입력 받을때마다 하나하나 매번 공배수 갱신 ㄱㄱ

int sol(int a, int b) {

	int maxVal;
	int minVal;
	if (a > b) {
		maxVal = a;
		minVal = b;
	}
	else {
		maxVal = b;
		minVal = a;
	}

	int cur = 1;
	int curVal = maxVal*cur;
	int ans;
	while (1) {

		if (curVal % minVal == 0) {
			ans = curVal;
			break;
		}

		cur++;
		curVal = maxVal * cur;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		int before;
		int cur;
		int res;
		cin >> before;

		for (int i = 1; i < n; i++) {
			cin >> cur;
			res = sol(before, cur);
			before = res;
		}

		cout << res << endl;
	}
}
