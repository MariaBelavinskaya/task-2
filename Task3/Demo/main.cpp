#include <iostream>
#include "../Task3/Matrix.h"

using namespace miit::matrix;

int main() 
{
	try
	{
		Matrix matrix;

	}
	catch (const std::exception& err)
	{
		std::cout << err.what();
	}
	return 0;
}