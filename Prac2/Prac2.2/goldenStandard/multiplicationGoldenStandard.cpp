//Author: Christopher Hill For the EEE4120F course at UCT
//Edited by Benjamin Connolly on 29/03/2022

#include<stdio.h>
#include<iostream>
using namespace std;

//creates a square matrix of dimensions Size X Size, with the values being the column number
void createKnownSquareMatrix(int Size, int* squareMatrix, bool displayMatrices)
{
	for(int i = 0; i<Size; i++){

		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = j + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
}

//creates a random square matrix of dimensions Size X Size, with values ranging from 1-100
void createRandomSquareMatrix(int Size, int* squareMatrix, bool displayMatrices)
{
	for(int i = 0; i<Size; i++){

		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = rand() % 100 + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
}

int main(void)
{
	//New code for prac 2.2
	bool displayMatrices = true;
	int Size = 3;
	int countA = Size*Size;
	int matrixA[countA];
	createRandomSquareMatrix(Size,matrixA, displayMatrices);
	cout<<"Number of elements in matrix 1: "<<countA<<"\n";
	cout<<"Dimensions of matrix 1: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 1 pointer: "<<matrixA<<"\n";

	int countB = Size*Size;
	int matrixB[countB];
	createRandomSquareMatrix(Size, matrixB, displayMatrices);
	cout<<"Number of elements in matrix 2: "<<countB<<"\n";
	cout<<"Dimensions of matrix 2: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 2 pointer: "<<matrixB<<"\n";

	int output[countA];

	//TODO: code your golden standard matrix multiplication here
	//Timing setup
	clock_t start, end;
	start = clock();

	//Calculating the matrix mutiplication output
	for (int i = 0; i < Size*Size; i++)
	{
		int sum = 0;
		for(int j = 0; j < Size; j++)
		{
			int row = 0;
			if(i/Size != 0)
			{
				row = i/Size;
				row *= Size;
			}
			sum += matrixA[row+j] * matrixB[i%Size+j*Size];
		}
		output[i] = sum;
	}

	//Calculating and printing the runtime
	end = clock();
	printf("Runtime: %0.8f sec \n", ((float)end-start)/CLOCKS_PER_SEC);

	//This if statement will display the matrix in output
	if(displayMatrices){
		printf("\nOutput in the output_buffer \n");
		for(int j=0; j<countA; j++) {
			printf("%i \t " ,output[j]);
			if(j%Size == (Size-1)){
				printf("\n");
			}
		}
	}

	return 0;
}
