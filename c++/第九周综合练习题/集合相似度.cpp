#include<cstdio>
#include<set>
#include<cstdlib>
using namespace std;
const int maxn = 55;
set<int> s[maxn];
int n;
int main() {
    while(~scanf("%d", &n)) {
        int cnt;
        for(int i = 0; i < n; i++) {
            if(!s[i].empty())s[i].clear();
            scanf("%d", &cnt);
            int x;
            for(int j = 0; j < cnt; j++) {
                scanf("%d", &x);
                s[i].insert(x);
            }
        }
        scanf("%d", &cnt);
        int u,v;
        for(int i = 0; i < cnt; i++) {
            scanf("%d%d", &u, &v);
            u--,v--;
            int same = 0;
            int size_s1 = s[u].size();
            int size_s2 = s[v].size();
            set<int>::iterator it;
            for(it = s[u].begin(); it != s[u].end(); it++) {
                if(s[v].find(*it) != s[v].end()) {
                    same++;
                }
            }
            int nc = same;
            int nt = size_s1+size_s2-same;
            double ans = (nc*1.0)/(nt*1.0)*100;
            printf("%.2lf%%\n", ans);
        }
    }
    return 0;
}
