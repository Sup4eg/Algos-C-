#include <stack>
#include <string>

using namespace std;

class DataStructures1 {
public:
  bool isOpen(char ch) {
	return ch == '{' || ch == '(' || ch == '[';
  }

  bool isPair(char open, char close) {
	return open == '{' && close == '}'
	  || open == '(' && close == ')'
	  || open == '[' && close == ']';
  }

  bool isBalanced(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); ++i) {
	  if (isOpen(s[i])) {
		st.push(s[i]);
	  }
	  else {
		if (!st.empty() && isPair(st.top(), s[i])) {
		  st.pop();
		}
		else {
		  return false;
		}
	  }
	}
	return st.empty();
  }
};