#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findLargestRectangle(int n, int m, vector<vector<int>>& A) {
    vector<vector<int>> B(n, vector<int>(m, 0));

    // Khởi tạo giá trị cho hàng đầu tiên của ma trận B
    for (int j = 0; j < m; j++) {
        B[0][j] = A[0][j];
    }

    // Tính toán ma trận B dựa trên ma trận A
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1) {
                B[i][j] = B[i - 1][j] + 1;
            }
        }
    }

    int max_area = 0;

    // Tìm hình chữ nhật lớn nhất bằng cách duyệt qua từng hàng của ma trận B
    for (int i = 0; i < n; i++) {
        stack<int> st;
        int j = 0;
        while (j < m) {
            if (st.empty() || B[i][j] >= B[i][st.top()]) {
                st.push(j);
                j++;
            } else {
                int top = st.top();
                st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                max_area = max(max_area, B[i][top] * width);
            }
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int width = st.empty() ? j : j - st.top() - 1;
            max_area = max(max_area, B[i][top] * width);
        }
    }

    return max_area;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int result = findLargestRectangle(n, m, A);
    cout << result << endl;

    return 0;
}
