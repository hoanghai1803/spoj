#include <bits/stdc++.h>

using namespace std;

#define TASK "MSE07B"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define ST first
#define ND second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();i++)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)
#define MAX_HEAP(t) priority_queue<t>
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define FORS(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
#define abs(x) ((x)>=0?(x):-(x))
#define sqr(x) (x)*(x)
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

int id;
int p, k;

set<ii> Queue;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    while(1) {
        scanf("%d", &id);
        if(!id) return 0;
        if(id == 1) {
            scanf("%d%d", &k, &p);
            Queue.insert(ii(p, k));
        }
        if(id == 2) {
            if(!Queue.size()) {
                printf("0\n");
                continue;
            }
            p = (*Queue.rbegin()).ST, k = (*Queue.rbegin()).ND;
            printf("%d\n", k);
            Queue.erase(ii(p,k));
        }
        if(id == 3) {
            if(!Queue.size()) {
                printf("0\n");
                continue;
            }
            p = (*Queue.begin()).ST, k = (*Queue.begin()).ND;
            printf("%d\n", k);
            Queue.erase(ii(p,k));
        }
    }
}
