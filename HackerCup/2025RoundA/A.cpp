/*
ID: chshivm1
LANG: C++
TASK: test
*/

#include <bits/stdc++.h>    
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;

string printbinary(int num, int padding) {
	string result(padding, '0'); //result = "01010"
	int index = 0;			     //num = 1
	while (num > 0) {
		result[index++] = num % 2;
		num /= 2;
	}
	reverse(result.begin(), result.end());
	return result;
}

void testcase() {
	int n; cin >> n;
	for (int i = 0; i < (1 << n); ++i) {   
		cout << printbinary(i, n) << endl;
	}
}
/*
	2 - 0-3     -- 0 to (2^n) - 1
	3 - 0-7
	4 - 0-15

*/
int main() {
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("C:\\Users\\doitwithcod3\\Documents\\code\\InputOutput\\input.txt", "r", stdin);
    freopen("C:\\Users\\doitwithcod3\\Documents\\code\\InputOutput\\output.txt", "w", stdout);
    #endif
    cout << fixed << setprecision(20);
    int t = 1;
    cin >> t;
    while (t--) {
        testcase();
    }
    #ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}