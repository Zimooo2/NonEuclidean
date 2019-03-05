#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\NonEuclidean\Camera.h"
#include "..\NonEuclidean\Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Camera c;
			Player p;
			c.SetSize(10, 10,10,10);
		}

	};
}