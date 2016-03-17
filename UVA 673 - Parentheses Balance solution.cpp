//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();
//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 673 - Parentheses Balance
	string s, res;
	stack<char> f;
	int t;
	getline(cin, s);
	stringstream(s) >> t;
	while (t--) {
		while (!f.empty())
			f.pop();
		res = "Yes";
		getline(cin, s);
		if (s.empty()) {
			res = "Yes";
			goto hell;
		}
		for (auto i : s)
			if (i == '(' || i == ')' || i == '[' || i == ']')
				if (i == '(' || i == '[')
					f.push(i);
				else if (f.empty()) {
					res = "No";
					break;
				} else {
					if (i == ')') {
						if (f.top() == '(')
							f.pop();
						else {
							res = 'No';
							break;
						}
					} else {
						if (f.top() == '[')
							f.pop();
						else {
							res = "No";
							break;
						}
					}
				}
		if (!f.empty())
			res = "No";
		hell: cout << res << endl;
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
