#pragma once
#include<iostream>
#include<conio.h>
#include<math.h>
#include<string.h>
#include"OptimalBinaryTree.h"
using namespace std;


Tree::Tree()
{
 
}

Tree::~Tree()
{

}

void Tree:: OptimalBinarySearchTree(int *p, int n, int **S , int **R)
{
	// Reference : This function is taken by the Class notes 
	cout<<"N "<<n;
 int value ;
 for (int i = 1; i <= (n+1); i++)
 {
	 cout <<" p" << p[i]<<"\n";
	for (int j=0; j < (n+1); j++)
        { S[i][j] = 0;
	      R[i][j] = 0;
		  
	    } 
 }
 for (int i = 1; i <= n; i ++)
 {
	 S[i][i] = p[i]; 
     R[i][i] = i; 
 }

 for (int d = 1; d <= (n -1); d ++)
	{
		for (int i = 1; i <= (n-d); i ++)
	 {
		 long min_value = 9700000; double sum_p = 0;  int min_root = 0;
		int j = i + d;
		for (int k = i; k <= j; k ++)
		{
			sum_p += p[k];
			value = S[i][k -1] + S[k +1][ j];
		    //cout << "The value  " << value;
			// cout << "  i" << i;
			 //cout << "  k" << k<< "\n";
			if( value < min_value )
			{
			 min_value = value ;
			 min_root = k;
			 }
		 }
			 S[i][j] = sum_p + min_value ;
			 R[i][j] = min_root ;
	     }
	  }


};


void Tree:: PrintTree(int **root, int i, int j)
{    
	 if (j < i) return;
  outfile << "--"<<root[i][j]<<"\r\n";	// print root
  outfile << "\t"<<  "\r\n";
  PrintTree(root,i,root[i][j]-1);	// print left subtree
  PrintTree(root,root[i][j]+1,j);	// print right subtree
  outfile << "\t"<< "\r\n";
     
};
void Tree:: PrintTree_file(int **root, int i, int j)
{    
	outfile.open("pg0018_tree.txt", ofstream::binary);
	PrintTree(root , i, j);
	//PrintTree(root , i, j);
    outfile.close();   
};

