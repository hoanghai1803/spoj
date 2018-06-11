#include <bits/stdc++.h>

using namespace std;

#define TASK "HSPC14J"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define X first
#define Y second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();i++)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)
#define MAX_HEAP(t) priority_queue<t>
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >
#define FORU(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define FOR(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
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

const int N = 1e3+3;

int n, k;
bool chk[N + 1];
int cnt;

int Eratosthene() {
	cnt = 0;
	FORU(i, 1, n) chk[i] = true;
	FORU(i, 2, n)
		if(chk[i]) {
			cnt++;
			if(cnt == k) return i;
			int j = i + i;
			while(j <= n) {
				if(!chk[j]) {
					j += i;
					continue;
				}
				chk[j] = false, cnt++;
				if(cnt == k) return j;
				j += i;
			}
		}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    while(scanf("%d%d", &n, &k) != EOF)
	    printf("%d\n", Eratosthene());
}