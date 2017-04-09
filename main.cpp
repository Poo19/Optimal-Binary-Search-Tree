#pragma once
#include <fstream>
#include"OptimalBinaryTree.h"
using namespace std;

void PrintTree_file(int **root, int i, int j);

void main ()
{
	ofstream outfile; 
	ofstream outfile1;
    ifstream infile;   
    int num;
	int i = 1;
	int number ;
    infile.open("input.txt", ifstream::binary);
    //-----------------------------------------------
    //  Reading numerical data as from a file
    //-----------------------------------------------
     infile >> number;
	 int  *probability = new int [number];
    while (infile.good())
    {
        infile >> num;
        //if(infile.good()) 
				probability[i]= num;
				i++;
		    
    }
	infile >> probability[i];
    infile.close();

	Tree Access; // Creating the object "Access"  for the class Tree. 

		// dynamic programming values
	 int *S[121];
	   for (int i=1; i<=(number+1); i++)
		   S[i] = new int [number+1];

	// dynamic programming roots

	 int *R[121];
	   for (int i=1; i<=(number+1); i++)
		   R[i] = new int [number];


	Access.OptimalBinarySearchTree(probability,number, S, R);// calling the function and passing the parameters
    Access.PrintTree_file(R, 1 , number);

	outfile.open("OptimalBinarySearch.txt", ofstream::binary);
	 //-----------------------------------------------
    //  Writing numerical data as  to a file
    //-----------------------------------------------
	outfile << " The dynamic programming values is " <<"\r\n";
	    outfile << "\t";

	for (int j = 0 ; j<= number; j++)
	{ outfile << j << "\t\n";}

	    outfile << "\r\n";

    for(int i=1; i<= (number+1) ; i++)
    {
		outfile << i << "\t\n";
		for (int j = 0; j< (number+1) ; j++)
		{ outfile << S[i][j]<<"\t\n"; }
		 outfile << "\r\n";

    }
	outfile << " The dynamic programming root is " <<"\r\n";
	for(int i=1; i< (number+1) ; i++)
    {
		outfile << "\r\n";
		for (int j = 0; j <(number+1) ; j++)
		outfile << R[i][j]<<"\t\n";
    }

    outfile.close();
	//outfile1.open("OptimalBinarySearchTree.txt", ofstream::binary);

	//outfile1.close();
	getchar();
    delete[] S;
	delete[] R;
 	
}

