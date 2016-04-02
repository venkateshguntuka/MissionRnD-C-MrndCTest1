/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int aProgression(int *arr, int len, int *result, int pos, int time){
	int cd1, i, count = 0, ap1pos1 = 0, ap1pos2;
	cd1 = arr[pos + 1] - arr[pos];
	for (i = 0; i<len; i++)
	{
		if (arr[i + 1] - arr[i] == cd1)
		{
			count++;
		}
		else
		{
			if (count>2)
			{
				ap1pos2 = i;
				if (time == 1)
				{
					result[0] = ap1pos1;
					result[1] = ap1pos2;
					break;
				}
				else
				{
					result[2] = ap1pos1;
					result[3] = ap1pos2;
					break;
				}
			}
			cd1 = arr[i + 1] - arr[i];
			ap1pos1 = i;
		}
	}
	return ap1pos2;

}
void gpProgression(int *arr, int len, int *result)
{
	int dt, i = 0, count = 0, gppos1 = 0, gppos2;
	dt = arr[i + 1] / arr[i];
	for (i = 0; i<len; i++)
	{
		if (arr[i + 1] / arr[i] == dt)
		{
			count++;
		}
		else
		{
			if (count>2)
			{
				gppos2 = i;
				result[4] = gppos1;
				result[5] = gppos2;
				break;

			}
			dt = arr[i + 1] / arr[i];
			gppos1 = i;
		}
	}

}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (len < 0 || arr == NULL)
		return NULL;
	int i, result[6] = { 0, 0, 0, 0, 0, 0 };
	int pos2, pos3;
	pos2 = aProgression(arr, len, result, 0, 1);
	pos3 = aProgression(arr, len, result, pos2, 2);
	gpProgression(arr, len, result);
	return result;
}
