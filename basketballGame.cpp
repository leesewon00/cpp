#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int t;
int n;
//map<string, int>name_score;
//vector<string>team_name[2]; //0:인덕 1:비룡

int main() {
	cin >> t;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (t--) {
		cin >> n;

		// 벡터 초기화
		//for (int i = 0; i < 2; i++) {
		//	team_name[i].clear();
		//}
		//name_score.clear();

		int aScore, bScore;
		string name;
		map<string, int>name_score;
		vector<string>team_name[2]; //0:인덕 1:비룡

		
		// 이름에 따른 팀도 저장해야해
		cin >> aScore >> bScore;
		cin >> name;
		if (aScore == 0) {
			// b팀인셈
			team_name[1].push_back(name);
			name_score[name] += bScore;
		}
		else {
			// a팀인셈
			team_name[0].push_back(name);
			name_score[name] += aScore;
		}

		int beforeA, beforeB;
		beforeA = aScore;
		beforeB = bScore;

		int winnerTeam;
		for (int i = 1; i < n; i++) {
			cin >> aScore >> bScore;
			cin >> name;

			if (aScore == beforeA) {
				// b팀이 점수 얻은 상황
				team_name[1].push_back(name); // 이름 중복저장됨에 유의
				name_score[name] += (bScore-beforeB);
			}
			else {
				team_name[0].push_back(name); // 이름 중복저장됨에 유의
				name_score[name] += (aScore - beforeA);
			}

			// before변수 갱신 필수
			beforeA = aScore;
			beforeB = bScore;

			if (i == n - 1) {
				// final 승자 정해짐
				if (aScore > bScore) {
					winnerTeam = 0;
				}
				else {
					winnerTeam = 1;
				}
			}
		}

		//cout << "winner: " << winnerTeam << " " <<  team_name[winnerTeam].size() << endl;

		//winner team member scan
		// 정렬하면 스캔안해도돼.
		string mvp_name;
		int mvp_score = -1;
		for (int i = 0; i < team_name[winnerTeam].size(); i++) {
			string name = team_name[winnerTeam][i];
			int score = name_score[name];

			if (score > mvp_score) {
				mvp_name = name;
				mvp_score = score;
			}
		}
		cout << mvp_name << " " << mvp_score << '\n';
	}
}
