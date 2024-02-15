#include <vector>
#include <iostream>

using namespace std;

class BackTracking
{
public:
  static int queens(int row,
	std::vector<int>& col,
	std::vector<int>& diag1,
	std::vector<int>& diag2) //8, 8x8 => n, nxn
  {
	// O(n!) --> 14
	// NP = Non - Polinomial
	// для задачи нет решения, которое бы составляло полиминиальное времяы
	const int n = (int)col.size();
	if (row == n)
	{
	  return 1;
	}
	int count = 0;
	for (int column = 0; column < n; ++column)
	{
	  if (col[column] == 0 && diag1[column + row] == 0 && diag2[row - column + (n - 1)] == 0)
	  {
		col[column] = diag1[column + row] = diag2[row - column + (n - 1)] = 1;
		count += queens(row + 1, col, diag1, diag2);
		col[column] = diag1[column + row] = diag2[row - column + (n - 1)] = 0;
	  }
	}
	return count;
  }

  /*
   * 00000000
   * 00000000
   * 00000000
   * 00000000
   * 00000000
   * 00000000
   * 00000000
   * 00000000
   */
};