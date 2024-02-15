#include <string>
#include <iostream>

using namespace std;

class Hashing
{
public:
  static long long string_hashing(const string& s) // O(n)
  {
	const int p = 31;
	const int m = (int)1e9 + 7;
	long long hash = 0;
	long long prime_pow = 1;
	for (char ch : s)
	{
	  hash = (hash + (ch - 'a' + 1) * prime_pow) % m;
	  prime_pow = (prime_pow * p) % m;
	  cout << prime_pow << endl;
	}
	return hash;
  }
};