#include "pch.h"
#include "CppUnitTest.h"
#include "../Vector/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Miit::Vector;

namespace VectorTest
{
	TEST_CLASS(VectorTest)
	{
	public:

		TEST_METHOD(OperatorIndex_IncorrectIndex_ExeptionExpected)
		{

			Assert::ExpectException<std::out_of_range>([]()
				{auto x = Vector({ 1, 2,3,4,5,6,7 }); x[7]; });
		}

		TEST_METHOD(Pop_WrongIndex_ExeptionExpected)
		{

			Assert::ExpectException<std::out_of_range>([]()
				{auto x = Vector({ 1, 2,3,4,5,6,7 }); x.deleteI(7); });
		}

		TEST_METHOD(EqualOperator_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			Vector vector2{ 1, 2,3,4,5,6,7 };
			Assert::IsTrue(vector1 == vector2);
		}

		TEST_METHOD(GetSize_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			Assert::IsTrue(vector1.getSize() == 7);
		}

		TEST_METHOD(ToString_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			Assert::IsTrue(vector1.toString() == "1 2 3 4 5 6 7 ");
		}

		TEST_METHOD(Append_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			vector1.addElement(8);
			Vector expected{ 1, 2,3,4,5,6,7,8 };
			Assert::IsTrue(vector1 == expected);
		}

		TEST_METHOD(Pop_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			vector1.deleteI(1);
			Vector expected{ 1,3,4,5,6,7 };
			Assert::IsTrue(vector1 == expected);
		}

		TEST_METHOD(Find_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			Assert::IsTrue(vector1.findI(1) == 0);
		}

		TEST_METHOD(OutputOperator_ValidData_Success)
		{
			std::stringstream sstring;
			Vector vector = Vector({ 1, 2,3,4,5,6,7 });
			sstring << vector;
			Assert::AreEqual(sstring.str(), vector.toString());
		}

		TEST_METHOD(IsEmpty_ValidData_Success)
		{
			Vector vector1{};
			Assert::IsTrue(vector1.isEmpty());
		}
		TEST_METHOD(CopyOperator_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			Vector vector2{ 2,3,4,5,6,7,8 };
			vector1 = vector2;
			Assert::IsTrue(vector1 == vector2);
		}

		TEST_METHOD(MoveOperator_ValidData_Success)
		{
			Vector vector1{ 1, 2,3,4,5,6,7 };
			Vector vector2{ 2,3,4,5,6,7,8 };
			vector1 = std::move(vector2);
			Vector expected{ 2,3,4,5,6,7,8 };
			Assert::IsTrue(vector1 == expected);
		}

	};
}
