#pragma once

class UnionFind
{
public:
	UnionFind(int N);
	~UnionFind();

	void unite(int p, int q);
	int findRoot(int p);
	bool isConnected(int p, int q);

private:
	int MAX;
	int id[1602];
	int size[1602];
};

