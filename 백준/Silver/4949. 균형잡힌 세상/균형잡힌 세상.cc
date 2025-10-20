#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (getline(cin, str) && str != ".") {
		stack<char> stk;
		for (char c : str) {
			if (c == '.') break;
			if (c != '(' && c != ')' && c != '[' && c != ']') continue;
			if (stk.size()) {
				if (stk.top() == '(' && c == ')') stk.pop();
				else if (stk.top() == '[' && c == ']') stk.pop();
				else stk.push(c);
			}
			else stk.push(c);
		}
		if (stk.size()) cout << "no" << "\n";
		else cout << "yes" << "\n";
	}
	return 0;
}