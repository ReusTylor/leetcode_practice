#include <iostream>
#include <vector>
using namespace std;

int get_euler(int n) {
    int res = n, a = n;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            res = res / i * (i - 1);
            while (a % i == 0)
                a = a / i;
        }
    }
    if (a > 1)
        res = res / a * (a - 1);
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int p;
        cin >> p;
        cout << get_euler(p - 1) << endl;
    }

    return 0;
}
