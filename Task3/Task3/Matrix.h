#pragma once
#include <iostream>
#include <vector>

namespace miit::matrix 
{
	class Matrix 
	{
	public:
		Matrix(int rows, int columns, std::initializer_list<int> list);

	private:
		int rows;
		int columns;
		std::vector<std::vector<int>> array;

	};
}