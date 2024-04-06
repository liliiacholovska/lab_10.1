#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.1/lab10.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(FindThirdDotTest)
		{
            string filename = "t.txt";
            ofstream testFile(filename);
            Assert::IsTrue(testFile.is_open(), L"File should be open");

            testFile << "This is a test.\nNew line..";
            testFile.close();

            int line, position;
            bool result = findThirdDotPosition(filename, line, position);

            Assert::IsTrue(result, L"The function should find three dots");
            Assert::AreEqual(2, line, L"The third dot should be on the second line");
            Assert::AreEqual(11, position, L"The third dot should be at position 11 on the line");
		}
	};
}
