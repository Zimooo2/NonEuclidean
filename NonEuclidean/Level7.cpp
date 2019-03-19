#include "Level7.h"
#include "Tunnel.h"
#include "Ground.h"
#include "PillarRoom.h"

void Level7::Load(PObjectVec& objs, PPortalVec& portals, Player& player) {
	std::shared_ptr<Tunnel> tunnel1(new Tunnel(Tunnel::NORMAL));
	tunnel1->pos = Vector3(-2.4f, 0, 0.0f);
	tunnel1->scale = Vector3(1, 1, 0.6f);
	objs.push_back(tunnel1);
	std::shared_ptr<Tunnel> tunnel2(new Tunnel(Tunnel::NORMAL));
	tunnel2->pos = Vector3(2.4f, 0, 0);
	tunnel2->scale = Vector3(1, 1, 0.6f);
	objs.push_back(tunnel2);

	std::shared_ptr<Tunnel> tunnel3(new Tunnel(Tunnel::NORMAL));
	tunnel3->pos = Vector3(7.2f, 0, 0.0f);
	tunnel3->scale = Vector3(1, 1, 0.6f);
	objs.push_back(tunnel3);

	std::shared_ptr<Ground> ground(new Ground());
	ground->scale *= 1.2f;
	objs.push_back(ground);

	std::shared_ptr<Portal> portal1(new Portal());
	tunnel1->SetDoor1(*portal1);
	portals.push_back(portal1);

	/*
	std::shared_ptr<Portal> portal2(new Portal());
	tunnel1->SetDoor2(*portal2);
	portals.push_back(portal2); */
	
	std::shared_ptr<Portal> portal3(new Portal());
	tunnel2->SetDoor1(*portal3);
	portals.push_back(portal3);

	std::shared_ptr<Portal> portal4(new Portal());
	tunnel2->SetDoor2(*portal4);
	portals.push_back(portal4);

	std::shared_ptr<Portal> portal5(new Portal());
	tunnel3->SetDoor1(*portal5);
	portals.push_back(portal5);

	/*
	std::shared_ptr<Portal> portal6(new Portal());
	tunnel3->SetDoor2(*portal6);
	portals.push_back(portal6); */

	Portal::Connect(portal3->front, portal1->back);
	Portal::Connect(portal1->front, portal3->back);
	Portal::Connect(portal4->front, portal5->back);
	//Portal::Connect(portal2, portal4);
	// Portal::Connect(portal4, portal5);
	/*
	Portal::Connect(portal1->front, portal3->back);
	Portal::Connect(portal4->front, portal2->back);

	Portal::Connect(portal2->front, portal5->back);
	Portal::Connect(portal6->front, portal1->back);*/

	player.SetPosition(Vector3(0, GH_PLAYER_HEIGHT, 5));
}
 