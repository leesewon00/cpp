#include <iostream>
#include <string>

using namespace std;

// 단일 문자로 이루어져있는지 확인하는 함수
bool isValid(int start, int end, const string& str) {
    char s = str[start];
    for (int i = start + 1; i <= end; i++) {
        if (str[i] != s) {
            return false;
        }
    }
    return true;
}

void sol(int start, int end, const string& str, string& result) {
    // 종료 조건
    if (start == end) {
        result += str[start];
        return;
    }

    if (isValid(start, end, str)) {
        result += str[start];
        return;
    }

    // 압축 시점에 'B' 삽입
    result += 'B';

    // 좌우로 나누어서 재귀 호출
    int mid = (start + end) / 2;
    sol(start, mid, str, result);
    sol(mid + 1, end, str, result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;

        string result;
        sol(0, str.length() - 1, str, result);

        cout << result << '\n';
    }

    return 0;
}
