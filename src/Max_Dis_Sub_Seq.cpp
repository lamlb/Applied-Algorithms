#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int t;
int n, c, a[MAXN];

bool check(int distance) {
    int count = 1;
    int last_position = a[1];
    
    for (int i = 2; i <= n; i++) {
        if (a[i] - last_position >= distance) {
            count++;
            last_position = a[i];
        }
    }
    
    return count >= c;
}

int maxDistance() {
    int left = 0, right = a[n] - a[1];
    int result = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while (t--) {
        cin >> n >> c;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        sort(a + 1, a + n + 1);
        
        int ans = maxDistance();
        cout << ans << endl;
    }
    
    return 0;
}
