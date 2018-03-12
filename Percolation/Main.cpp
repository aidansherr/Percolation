#include "Main.h"
#include "UnionFind.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Main::Main()
{
}
Main::~Main()
{
}

void getNewCell(int & row, int & col, const int SIZE); // gets random row and column
int getCellNumber(int row, int col, const int SIZE);    // gets cell number connect

using namespace std;

int main()
{
	srand(time(0));
	const int SIZE = 40;
	int row;
	int col;
	double averageProbability = 0.0;				// 

	for (int i = 0; i < 1000; i++)			// run 1000 times
	{
		bool grid[SIZE][SIZE] = { false };  // initialize grid values to false
		UnionFind uf((SIZE * SIZE) + 2);	// pass size of grid plus two dummy nodes to uf (top & bottom)
		int nvacant = 0;					// set vacant cells to zero
		double p = 0.0;						// set probability to zero

		while (uf.isConnected(0, ((SIZE * SIZE) + 1)) == false)
		{
			do   // find cell that is not yet open
			{
				getNewCell(row, col, SIZE);
			} while (grid[row][col] == true);

			grid[row][col] = true;
			nvacant++;

			if (row == 0)					// if connected to top node
			{
				uf.unite(0, getCellNumber(row, col, SIZE));
			}
			if (row == (SIZE - 1))			// if connected to bottom node
			{
				uf.unite(getCellNumber(row, col, SIZE), ((SIZE * SIZE) + 1));
			}
			if ((row + 1) < (SIZE - 1))
			{
				if (grid[row + 1][col] == true) // if node above is open
				{
					uf.unite(getCellNumber(row, col, SIZE), getCellNumber((row + 1), col, SIZE));
				}
			}
			if ((row - 1) >= 0)
			{
				if (grid[row - 1][col] == true) // if node below is open
				{
					uf.unite(getCellNumber(row, col, SIZE), getCellNumber((row - 1), col, SIZE));
				}
			}
			if ((col + 1) < (SIZE - 1))
			{
				if (grid[row][col + 1] == true) //if node to right is open
				{
					uf.unite(getCellNumber(row, col, SIZE), getCellNumber(row, (col + 1), SIZE));
				}
			}
			if ((col - 1) >= 0)
			{
				if (grid[row][col - 1] == true) // if node to left is open
				{
					uf.unite(getCellNumber(row, col, SIZE), getCellNumber(row, (col - 1), SIZE));
				}
			}
		}

		cout << "nvacant = " << nvacant << endl;
		p = static_cast<double>(nvacant) / (SIZE*SIZE);  // percolation probability
		cout << "site vacancy probability (nvacant/(40x40)) = " << p << endl;

		averageProbability = averageProbability + p;	// keep sum of all probabilities 
	}

	averageProbability = averageProbability / 1000;		// average probability based on tests
	cout << endl << "average probability = " << averageProbability << endl;

	cin.get();
	
	return 0;
}

void getNewCell(int & row, int & col, const int SIZE)
{
	row = rand() % SIZE;
	col = rand() % SIZE;
}

int getCellNumber(int row, int col, const int SIZE)
{
	return ((row * SIZE) + col + 1);
}

