#include <iostream>

using namespace std;

long long MOD = 1000000007;

struct Matrix {
    long long a, b, c, d;
};

Matrix cal(Matrix m1, Matrix m2) {
    Matrix res;
    res.a = (m1.a * m2.a + m1.b * m2.c) % MOD;
    res.b = (m1.a * m2.b + m1.b * m2.d) % MOD;
    res.c = (m1.c * m2.a + m1.d * m2.c) % MOD;
    res.d = (m1.c * m2.b + m1.d * m2.d) % MOD;
    return res;
}

// 주어진 행렬을 exp번 곱한 결과를 반환
// 점화식 기반으로 동작
Matrix matrixPower(Matrix base, long long exp) {
    // base case
    if (exp == 0) {
        return Matrix{1, 0, 0, 1};
    }

    // divide
    Matrix half = matrixPower(base, exp / 2);

    // conquer
    if (exp % 2 == 1) {
        return cal(cal(half,half),base);
    }
    return cal(half,half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N;
    cin >> T;

    while (T--) {
        Matrix M;
        cin >> M.a >> M.b >> M.c >> M.d;

        cin >> N;

        Matrix result = matrixPower(M, N);

        cout << result.a << " " << result.b << '\n';
        cout << result.c << " " << result.d << '\n';
    }

    return 0;
}
