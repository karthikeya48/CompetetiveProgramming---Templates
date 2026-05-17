#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n; 
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
    	
        int sq = sqrt(n);

        int num_blocks = (n + sq - 1) / sq;
        
        vector<int> blocks(num_blocks, LLONG_MIN); 

        auto build = [&]() -> void {
            for(int i = 0; i < n; i++) {
                blocks[i / sq] = max(blocks[i / sq], a[i]);
            }
        };

       
        build(); 

        auto query = [&](int l, int r) -> int {
            int left_block = l / sq;
            int right_block = r / sq;
            int mx = LLONG_MIN; 
            
            if(left_block == right_block) {
                for(int i = l; i <= r; i++) {
                    mx = max(mx, a[i]);
                }
            } else {
                int left_end = (left_block + 1) * sq - 1;
                for(int i = l; i <= left_end; i++) {
                    mx = max(mx, a[i]);
                }
                for(int i = left_block + 1; i < right_block; i++) {
                    mx = max(mx, blocks[i]);
                }
                int right_start = right_block * sq;
                for(int i = right_start; i <= r; i++) {
                    mx = max(mx, a[i]);
                }
            }
            return mx;
        };

        for(auto it : a) cout << it << " ";
        cout << endl;
    }
    return 0;
}
