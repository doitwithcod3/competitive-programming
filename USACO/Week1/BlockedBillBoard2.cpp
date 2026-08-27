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

class Rectangle {
public:
	pair<int, int> length, breath;
	Rectangle(int x1, int y1, int x2, int y2) {
		length.first = min(x1, x2);
		length.second = max(x1, x2);
		breath.first = min(y1, y2);
		breath.second = max(y1, y2);
	}
	inline int getLength() {return length.second - length.first;}
	inline int getBreath() {return breath.second - breath.first;}

	inline int getArea() {
		return ((length.second - length.first) * (breath.second - breath.first));
	}
	int commonLength(Rectangle rect) {
		int start = max(length.first, rect.length.first);
		int end = min(length.second, rect.length.second);

		return max(0, end - start);
	}
	int commonBreath(Rectangle rect) {
		int start = max(breath.first, rect.breath.first);
		int end = min(breath.second, rect.breath.second);

		return max(0, end - start);
	}
};

void testcase() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	int p, q, r, s; cin >> p >> q >> r >> s;

	Rectangle r1(a, b, c, d);
	Rectangle r2(p, q, r, s);

	int commonLength = r1.commonLength(r2);
	int commonBreath = r1.commonBreath(r2);

	if (commonBreath == r1.getBreath() || commonLength == r1.getLength()) {
		cout << r1.getArea() - (commonBreath * commonLength);
	}
	else cout << r1.getArea();
}
/*

*/
int main() {
    ios_base::sync_with_stdio(false);

    freopen("billboard.in", "r", stdin);
    freopen("billbaord.out", "w", stdout);
    cout << fixed << setprecision(20);
    int t = 1;
    while (t--) {
        testcase();
    }
    return 0;
}