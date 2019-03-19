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
	TEST_CLASS(PortalTest)
	{
	public:
		TEST_METHOD(Portal_GetBump_Test)
		{
			Engine *e = new Engine;
			//This runs the init code
			std::shared_ptr<Portal> p(new Portal());
			Vector3 v2 = p->GetBump(Vector3(1.0f, 2.0f, 3.0f));
			Assert::AreEqual(v2.x, 0.0f);
			Assert::AreEqual(v2.y, 0.0f);
			Assert::AreEqual(v2.z, 1.0f);
			Vector3 v4 = p->GetBump(Vector3(-2.0f, -2.0f, -2.0f));
			Assert::AreEqual(v4.x, 0.0f);
			Assert::AreEqual(v4.y, 0.0f);
			Assert::AreEqual(v4.z, -1.0f);
		}
		TEST_METHOD(Portal_Test_Connect) 
		{
			std::shared_ptr<Portal> portal1(new Portal());
			std::shared_ptr<Portal> portal2(new Portal());
			Portal::Connect(portal1, portal2);
			Assert::AreEqual(portal1->front.delta.XAxis().Mag(), portal2->back.delta.XAxis().Mag());
			Assert::AreEqual(portal1->front.delta.YAxis().Mag(), portal2->back.delta.YAxis().Mag());
			Assert::AreEqual(portal1->front.delta.ZAxis().Mag(), portal2->back.delta.ZAxis().Mag());

			Assert::AreEqual(portal1->back.delta.XAxis().Mag(), portal2->front.delta.XAxis().Mag());
			Assert::AreEqual(portal1->back.delta.YAxis().Mag(), portal2->front.delta.YAxis().Mag());
			Assert::AreEqual(portal1->back.delta.ZAxis().Mag(), portal2->front.delta.ZAxis().Mag());
		}
		TEST_METHOD(Portal_Test_Intersects)
		{
			std::shared_ptr<Portal> portal1(new Portal());
			// Returns nullptr if no intersection otherwise warp
			const Portal::Warp *w;
			w = portal1->Intersects(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
			Assert::IsTrue(w != nullptr);
			w = portal1->Intersects(Vector3(10, 50, -100), Vector3(0, 0, 0), Vector3(0, 0, 0));
			Assert::IsTrue(w != nullptr);
			w = portal1->Intersects(Vector3(10, 50, 100), Vector3(10, 50, 20), Vector3(0, 0, 0));
			Assert::IsTrue(w == nullptr);
		}
		TEST_METHOD(Portal_Test_DistTo)
		{
			// Portal is positioned at (0, 0, -1)
			std::shared_ptr<Portal> portal1(new Portal());
			Vector3 v1(1.0f, 1.0f, 1.0f);
			Vector3 v2(-1.0f, -1.0f, -1.0f);
			Vector3 v3(5.0f, 6.0f, 10.0f);
			Vector3 v4(-5.0f, 12.0f, -100.0f);
			Assert::AreEqual(portal1->DistTo(v1), 1.0f);
			Assert::AreEqual(portal1->DistTo(v2), 1.0f);
			Assert::IsTrue(portal1->DistTo(v3) >= 11.0f && portal1->DistTo(v3) <= 12.0f);
			Assert::IsTrue(portal1->DistTo(v4) >= 100.0f && portal1->DistTo(v3) <= 100.7f);
		}
	};
}