#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long int64;
typedef long double float128;

const int64 is_query = -(1LL<<62), inf = 1e18;

struct Line {
    int64 m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        int64 x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (float128)(x->b - y->b)*(z->m - y->m) >= (float128)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(int64 m, int64 b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }

    int64 eval(int64 x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

int main() {
    int n, k; cin >> n >> k;

    vector<int> els(n + 1);
    for (int i = 1; i <= n; i += 1) {
        cin >> els[i];
    }

    vector<int64> dp(n + 1, +inf);
    dp[0] = 0;

    for (int j = 0; j < k; j += 1) {
        vector<int64> current_dp(n + 1, inf);

        HullDynamic hd;
        for (int j = 1; j <= n; j += 1) {
            hd.insert_line(2 * els[j], -(1LL * els[j] * els[j] + dp[j - 1]));
            auto best = -hd.eval(els[j]) + 1LL * els[j] * els[j];
            best = min(best, inf);
            current_dp[j] = best;
        }

        dp = current_dp;
    }

    cout << dp[n] << '\n';
    return 0;
}
