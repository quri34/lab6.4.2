#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab6.4.2\lab6.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest642
{
	TEST_CLASS(UnitTest642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1,2,3,4 };
			int t;
			t = Max(a, 4, 1, a[0]);
			Assert::AreEqual(4, t);
		}
	};
}
