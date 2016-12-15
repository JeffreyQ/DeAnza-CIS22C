/*
* Name:			Jeffrey Qiu
* Class:		CIS 22C
* Date:			08/05/2016
* Instructor:	Professor Eftekhari
* File Name:	Graph.cpp
*
* Description:	This is the implementation file for the Graph class.
*/


#include "Graph.h"



Graph::Graph(int dim = 5)
{
	if (dim < 2)
		dim = 5;

	arrDim = dim * dim;

	adjArr = new int*[arrDim];
	for (int i = 0; i < arrDim; i++)
	{
		adjArr[i] = new int[arrDim];
		for (int j = 0; j < arrDim; j++)
		{
			adjArr[i][j] = arrDim;
		}
	}
}



bool Graph::setNeighbors(int neighbor1, int neighbor2)
{
	bool ret = true;
	if ((neighbor1 >= 0 && neighbor1 < arrDim)
		&& (neighbor1 >= 0 && neighbor1 < arrDim))
	{
		adjArr[neighbor1][neighbor2] = 1;
		adjArr[neighbor2][neighbor1] = 1;
	}
	else
	{
		ret = false;
	}

	return ret;
}



bool Graph::isNeighbor(int neighbor1, int neighbor2)
{
	bool ret = true;
	if (neighbor1 < 0 || neighbor2 < 0 || neighbor1 >= arrDim || neighbor2 >= arrDim)
		ret = false;
	else if (adjArr[neighbor1][neighbor2] != 1)
		ret = false;

	return ret;
}



void Graph::printGraph()
{
	std::cout << "Contents of Graph" << std::endl;

	std::cout << "\t";
	for (int i = 0; i < arrDim; i++)
	{
		std::cout << "r" << i << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < arrDim; i++)
	{
		std::cout << "r" << i << "\t|";
		for (int j = 0; j < arrDim; j++)
		{
			if (adjArr[i][j] > 1)
				std::cout << "- ";
			else
				std::cout << "1 ";
		}

		std::cout << std::endl;
	}
}
