#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, a, b, c, d, p, q, y;
		cin >> n >> a >> b >> c >> d >> p >> q >> y;
		vector<int> x(n + 1);
		// use 1-based index for easier calculations below
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		// distance from City A to City B (walking)
		// this is the distance if Guru only walked
		int ab = abs(x[a] - x[b]) * p;
		// distance from City A to City (Walking)
		// this is the distance Guru needs to travel to go the train station
		int ac = abs(x[a] - x[c]) * p;
		// distance from City C to City D
		// this is the distance of the train
		int cd = abs(x[c] - x[d]) * q;
		// distance from City D to City B
		// this is used to check if the endpoint of the train is equal to City B
		// if not, it will store the distance that Guru needs to walk to arrive in City B from City D
		int db = abs(x[d] - x[b]) * p;
		// store the total walking time for checking below
		int total_time = ab;
		// check if Guru can make it in time if he walked to the train station
		if (y >= ac) {
			// if Guru makes it the train station, then add all the distances possible
			// y = time when the train starts
			total_time = y + cd + db;
			// check if the total time of riding in a train is not less than 
			// the total time in walking
			if (total_time > ab) {
				total_time = 	ab;
			}
		}
		cout << total_time << '\n';
	}
	return 0; 
}
