#include "Matrix.h"

miit::matrix::Matrix::Matrix(int rows, int columns, std::initializer_list<int> list)
	:rows(rows), columns(columns)
{
	if (list.size() % rows != 0 && list.size() / rows  != columns)
	{
		throw std::out_of_range("Incorrect list");
	}
	
	int i = 0;
	int row_size = list.size() / rows;
	for (int value : list) 
	{
		int curr_vector = i / row_size;
		int curr_element = i % row_size;
		this->array[curr_vector][curr_element] = value;
		i++;
	}
}
