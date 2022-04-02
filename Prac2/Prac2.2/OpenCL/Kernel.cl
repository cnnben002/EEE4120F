//Author:Benjamin Connolly
//Date: 28/03/2022

//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. 
//Global arguments are accessable by both host and this target device. 
//While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory

__kernel void matrixMultiplication(__global int* matrixA, __global int* matrixB, __global int* output)
{
	//TODO: program your kernel here

	//work item and work groups numbers
	int workItemNum = get_global_id(0); //Work item ID
	int workGroupNum = get_group_id(0); //Work group ID
	int size = get_local_size(0); //Number of work groups
	
	//memory buffers
	int* matA = matrixA;
	int* matB = matrixB;

	//calculating the matrix multiplication for a each point  of the matrix 
	int sum = 0;

	for(int i = 0; i < size; i ++)
	{
		sum += matA[size*workGroupNum+i] * matB[size*i+workItemNum%size];
	}
	
	//writing the sum to the output matrix
	output[workGroupNum*size+workItemNum%size] = sum;
}




