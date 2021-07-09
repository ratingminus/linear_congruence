#include "bits/stdc++.h"
using namespace std;

#ifdef FFS
#include "debug.h"
#else
#define debug(args...)
#endif

map <int, pair<int, int>> mp;

signed main() {
    printf("ax \u2261 b (mod m) ? Provide a, b and m\n");
    int x, y, b; scanf("%d %d %d", &y, &b, &x);
    int x0 = x, y0 = y;
    mp[x] = {1, 0}, mp[y] = {0, 1};
    printf("s\tt\trem   =   s - q\u00D7t\n");
    for(int i = 0; i < 69; ++i) printf("-");
    puts("");
    for(int rem = x % y; rem; rem = x % y) {
        int k = x / y;
        printf("%d\t%d\t%4d  =   %-2d -%2d\u00D7%d", x, y, rem, x, k , y);
        mp[rem] = {mp[x].first - k * mp[y].first, mp[x].second - k * mp[y].second};
        int now = mp[rem].first;
        printf(" = %d\u00D7%d %s %d\u00D7%d\n", mp[rem].second, y0, now > 0 ? "+" : "-", abs(now), x0);
        x = y, y = rem;
    }
    int now = mp[y].second;
    printf("\ngcd(%d, %d) = %d\u00D7%d %s %d\u00D7%d = %d\n", y0, x0, now, y0, mp[y].first > 0 ? "+" : "-", abs(mp[y].first), x0, y);
    if(b % y) {
        printf("%d does NOT divide %d so NO solution exists\n", y, b);
        return 0;
    }
    printf("\n%dx \u2261 %d \u21D2 x \u2261 %d", y0, y, now);
    if(now < 0) printf(" \u2261 %d", now += x0);
    printf(" (mod %d)\n", x0);
    printf("\n%dx \u2261 %d \u21D2 x \u2261 %d \u00D7 (%d / %d) \u2261 %d", y0, b, now, b, y, (now * b / y) % x0);
    printf(" (mod %d)\n", x0);
}