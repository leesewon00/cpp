#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <stack>

using namespace std;

int t, h, q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;

	while (t--) {
		cin >> h >> q;

		// 사실상 홀 짝 판별기
		while (q--) {
			int c; cin >> c;
			stack<char>st;
			
			while(c != 1) {
				if (c % 2 == 1) {
					// 좌상단으로 올라감 
					st.push('l');
				}
				else {
					// 우상단으로 올라감
					st.push('r');
				}
				c = c / 2;
			}

			while (!st.empty()) {
				//l 이면 오른쪽으로 내려가는것과 동일하다
				if (st.top() == 'l') {
					cout << 'R';
				}
				else {
					cout << 'L';
				}
				st.pop();
			}
			cout << '\n';

		}
	}
}
