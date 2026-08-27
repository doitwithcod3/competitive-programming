#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_A = 1e5 + 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &num : A) cin >> num;
    
    int max_A = *max_element(A.begin(), A.end());
    vector<vector<int>> elements_for_g(max_A + 1);
    for (int num : A) {
        for (int d = 1; d * d <= num; ++d) {
            if (num % d == 0) {
                elements_for_g[d].push_back(num);
                if (d != num / d) elements_for_g[num / d].push_back(num);
            }
        }
    }
    
    vector<int> count(max_A + 1);
    for (int g = 1; g <= max_A; ++g) {
        auto &A_g = elements_for_g[g];
        if (A_g.empty()) continue;
        
        vector<int> sorted_unique = A_g;
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());
        unordered_map<int, int> rank_map;
        for (int i = 0; i < sorted_unique.size(); ++i) rank_map[sorted_unique[i]] = i + 1;
        
        vector<int> fenwick(sorted_unique.size() + 2);
        auto update = [&](int idx, int val) {
            for (; idx <= sorted_unique.size(); idx += idx & -idx)
                fenwick[idx] = (fenwick[idx] + val) % MOD;
        };
        auto query = [&](int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx)
                res = (res + fenwick[idx]) % MOD;
            return res;
        };
        
        int total = 0;
        for (int num : A_g) {
            int r = rank_map[num];
            int sum_less = query(r - 1);
            int current = (1 + sum_less) % MOD;
            update(r, current);
            total = (total + current) % MOD;
        }
        count[g] = total;
    }
    
    vector<int> exact(max_A + 1);
    int res = 0;
    for (int g = max_A; g >= 1; --g) {
        exact[g] = count[g];
        for (int multiple = 2 * g; multiple <= max_A; multiple += g)
            exact[g] = (exact[g] - exact[multiple] + MOD) % MOD;
        res = (res + 1LL * g * exact[g]) % MOD;
    }
    
    cout << res << '\n';
    return 0;
}