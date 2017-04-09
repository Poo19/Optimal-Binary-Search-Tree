#pragma once
#include<iostream>
#include<conio.h>
#include<math.h>
#include<string.h>
#include <fstream>
using namespace std;

/*struct TreeNode
{
    char Key[33];
    TreeNode *left;
	TreeNode *right; 
};
*/

class Tree 
{
  ofstream outfile;
public: 
	Tree();
	~Tree();
	void OptimalBinarySearchTree(int *p, int number, int **S , int **R);
	void PrintTree(int **root, int i, int j);
	void PrintTree_file(int **root, int i, int j);
};
