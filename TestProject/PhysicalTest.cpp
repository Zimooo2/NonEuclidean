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
	TEST_CLASS(PhysicalTest)
	{
	public:

		TEST_METHOD(Portal_Hit_Test)
		{
			//This runs the init code
			Engine e;

			glewExperimental = GL_TRUE;
			glewInit();

			std::shared_ptr<Tunnel> tunnel1(new Tunnel(Tunnel::NORMAL));
			tunnel1->pos = Vector3(-2.4f, 0, -1.8f);
			tunnel1->scale = Vector3(1, 1, 4.8f);

			std::shared_ptr<Tunnel> tunnel2(new Tunnel(Tunnel::NORMAL));
			tunnel2->pos = Vector3(2.4f, 0, 0);
			tunnel2->scale = Vector3(1, 1, 0.6f);

			std::shared_ptr<Ground> ground(new Ground());
			ground->scale *= 1.2f;

			std::shared_ptr<Portal> portal1(new Portal());
			tunnel1->SetDoor1(*portal1);

			std::shared_ptr<Portal> portal2(new Portal());
			tunnel2->SetDoor1(*portal2);

			std::shared_ptr<Portal> portal3(new Portal());
			tunnel1->SetDoor2(*portal3);

			std::shared_ptr<Portal> portal4(new Portal());
			tunnel2->SetDoor2(*portal4);

			Portal::Connect(portal1, portal2);
			Portal::Connect(portal3, portal4);

			Physical p;
			Assert::IsFalse(p.TryPortal(*portal1));
		}

	};
}