#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        stack <string> st;
        for (int i = 0; i < str.length(); i++) {
            // string scan
            if (str[i] == '<') {
                int curIdx = i + 1;
                if (str[curIdx] == '/') {
                    // pop case
                    string cur = st.top();
                    st.pop();
                    i += cur.length() + 2; // index 갱신
                } else {
                    // push case
                    string push = "";
                    while (str[curIdx] != '>') {
                        push += str[curIdx]; // 삽입할 문자열 생성
                        curIdx++;
                    }
                    st.push(push);
                    i += push.length() + 1; // index 갱신
                }
            }
        }

        // print result
        while (!st.empty()) {
            string tp = st.top();
            cout << "</" + tp + ">";
            st.pop();
        }
        cout << '\n';
    }
}
