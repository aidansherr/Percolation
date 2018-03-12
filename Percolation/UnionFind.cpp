#include "UnionFind.h"

using namespace std;

UnionFind::UnionFind(int N)			// initialize id array with each index id == index
{									// initialize size of each id tree at size 1
	MAX = N;
	int index = 0;

	for (int i = 0; i < MAX; i++)
	{
			id[i] = i;
			size[i] = 1;
	}
}

UnionFind::~UnionFind()
{
}

void UnionFind::unite(int p, int q)
{
	int i = findRoot(p);
	int j = findRoot(q);

	if (i == j)				// if id's equal, already in same union
	{
		return;
	}
	
	if (size[i] < size[j])	// if tree i is smaller than tree j, 
	{						// add tree i to tree j to keep tree minimal height
		id[i] = j;
		size[j] += size[i];
	}
	else					// if tree j is smaller than tree i, 
	{						// add tree j to tree i to keep tree minimal height
		id[j] = i;
		size[i] += size[j];
	}
}

int UnionFind::findRoot(int p)
{
	while (p != id[p])
	{
		p = id[p];
	}
	return id[p];
}

bool UnionFind::isConnected(int p, int q)
{
	if (findRoot(p) == findRoot(q))
	{
		return true;
	}
	else
	{
		return false;
	}
}
