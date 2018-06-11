#include <bits/stdc++.h>

using namespace std;

#define TASK "CPPSET"
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

set<int> S1, S2;

int id;
int x;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    while(1) {
        scanf("%d", &id);
        switch(id) {
            case 0:
                exit(0);
            case 1:
                scanf("%d", &x);
                S1.insert(x);
                S2.insert(-x);
                break;
            case 2:
                scanf("%d", &x);
                S1.erase(x);
                S2.erase(-x);
                break;
            case 3:
                if(S1.empty()) printf("empty\n");
                else printf("%d\n", *S1.begin());
                break;
            case 4:
                if(S1.empty()) printf("empty\n");
                else printf("%d\n", *S1.rbegin());
                break;
            case 5:
                scanf("%d", &x);
                if(S1.empty()) printf("empty\n");
                else
                    if(x >= *S1.rbegin()) printf("no\n");
                    else printf("%d\n", *S1.upper_bound(x));
                break;
            case 6:
                scanf("%d", &x);
                if(S1.empty()) printf("empty\n");
                else
                    if(x > *S1.rbegin()) printf("no\n");
                    else printf("%d\n", *(S1.lower_bound(x)));
                break;
            case 7:
                scanf("%d", &x);
                x = -x;
                if(S2.empty()) printf("empty\n");
                else
                    if(x >= *S2.rbegin()) printf("no\n");
                    else printf("%d\n", -*S2.upper_bound(x));
                break;
            case 8:
                scanf("%d", &x);
                x = -x;
                if(S2.empty()) printf("empty\n");
                else
                    if(x > *S2.rbegin()) printf("no\n");
                    else printf("%d\n", -*S2.lower_bound(x));
                break;
        }
    }
}
