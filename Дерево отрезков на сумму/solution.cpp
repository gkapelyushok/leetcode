#include <iostream>
#include <vector>

using namespace std;

int x;
long long t[100000000];

void set(int i, int value, int v, int l, int r) {
    if (r == l + 1) {
        t[v] = value;
        return;
    }
    if (i < (l + r) / 2) {
        set(i, value, 2*v+1, l, (l+r)/2);
    } else {
        set(i, value, 2*v+2,(l+r)/2, r);
    }
    t[v] = t[2*v+1] + t[2*v+2];
}

long long get(int v,  int l, int r, int a, int b) {
    if (r <= a || l >= b) {
        return 0;
    } else if (l >= a && r <= b) {
        return t[v];
    } else {
        return get(2*v+1, l, (l+r)/2, a, b) +
               get(2*v+2, (l+r)/2, r, a, b);
    }
}

int main() {
    int m;
    int n;
    cin >> n >> m;
    int x = 1;
    while (x < n) {
        x *= 2;
    }
    for (int i = 0; i < n; i++) {
        cin >> t[x - 1 + i] ;
    }
    for (int i = x - 2; i >= 0; i--) {
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }

    for (int i = 0; i < m; i++) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int k, value;
            cin >> k >> value;
            set(k, value, 0, 0, x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << get(0, 0, x, a, b) << endl;
        }
    }

    return 0;
}
 
