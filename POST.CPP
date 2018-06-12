#include <bits/stdc++.h>

using namespace std;

#define TASK "POST"
#define input_file TASK".INP"
#define output_file TASK".OUT"

int main() {
	#ifndef ONLINE_JUDGE
		freopen(input_file,"r",stdin);
		freopen(output_file,"w", stdout);
	#endif
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld", a + b);
}