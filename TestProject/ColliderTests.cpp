#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\NonEuclidean\Tunnel.h"
#include "..\NonEuclidean\Portal.h"
#include "..\NonEuclidean\Physical.h"
#include "..\NonEuclidean\Player.h"
#include "..\NonEuclidean\Resources.h"
#include "..\NonEuclidean\Ground.h"
#include "..\NonEuclidean\Engine.h"

#include <windows.h>
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(ColliderTests)
	{

	public:
		TEST_METHOD(Constructor_Test_1)
		{
			Engine *e = new Engine;

			Collider c(Vector3(-1, 0, -1), Vector3(-1, 0, 1), Vector3(1, 0, 1));
			Matrix4 m;
			m.MakeIdentity();
			Vector3 v = Vector3(0, 0, 0);
			Assert::IsTrue(c.Collide(m, v));
		}

		TEST_METHOD(Collide_Test)
		{
			Engine *e = new Engine;

			Collider c(Vector3(-1, 0, -1), Vector3(-1, 0, 1), Vector3(1, 0, 1));
			Matrix4 m;
			m.Fill(1.f);
			Vector3 v = Vector3(10, 10, 10);
			Assert::IsFalse(c.Collide(m, v));
		}
	};
}