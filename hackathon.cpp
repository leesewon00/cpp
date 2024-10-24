#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int t;
int n, m;


int main() {

	//cout << "A-65=" << 'A' - 65 << endl;

	cin >> t;

	while (t--) {
		cin >> n >> m;
		// 학생수 n명 팀 수 m개

		vector<int>studentRate;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			studentRate.push_back(a);
		}

		vector<int>score;
		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			score.push_back(a);
		}

		//팀원 수와 팀원 이름 입력
		vector<char>team[26];
		for (int i = 0; i < m; i++) {
			int a; cin >> a;
			for (int j = 0; j < a; j++) {
				char name; cin >> name;
				team[i].push_back(name);
			}
		}

		vector<int>ans;

		// 팀 수는 M개이며 각 팀에서 최저 기여도를 가진 사람 찾기
		for (int i = 0; i < m; i++) {
			// 팀 순회

			int minIdx = 0;
			int minRate = studentRate[team[i][0] - 'A'];

			for (int j = 1; j < team[i].size(); j++) {
				char curName = team[i][j];
				int curRate = studentRate[curName - 'A'];
				if (curRate < minRate) {
					// 같다면? -> 입력으로 안들어오는듯
					minRate = curRate;
					minIdx = j;
				}
			}

			// minIdx와 minVal 갱신 완료
			int teamScore = minRate * score[i];
			ans.push_back(teamScore);
		}

		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
