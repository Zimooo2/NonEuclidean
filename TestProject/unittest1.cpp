#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\NonEuclidean\Camera.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Camera c;
			c.SetSize(10, 10,10,10);
		}

	};
}