#include "Testing.h"

#include "Portal.h"
#include "Physical.h"
#include "Object.h"
#include "Tunnel.h"

void portal_hit_test1() {
	std::shared_ptr<Tunnel> tunnel1(new Tunnel(Tunnel::NORMAL));
	tunnel1->pos = Vector3(-2.4f, 0, -1.8f);
	tunnel1->scale = Vector3(1, 1, 4.8f);

	std::shared_ptr<Portal> portal1(new Portal());
	tunnel1->SetDoor1(*portal1);

	std::shared_ptr<Portal> portal3(new Portal());
	tunnel1->SetDoor2(*portal3);
	Physical phy;

	assert(phy.TryPortal(*portal1) == false);
}

void portal_hit_test2() {
	
	std::shared_ptr<Tunnel> tunnel1(new Tunnel(Tunnel::NORMAL));
	tunnel1->pos = Vector3(-2.4f, 0, -1.8f);
	tunnel1->scale = Vector3(1, 1, 4.8f);

	std::shared_ptr<Tunnel> tunnel2(new Tunnel(Tunnel::NORMAL));
	tunnel2->pos = Vector3(2.4f, 0, 0);
	tunnel2->scale = Vector3(1, 1, 0.6f);


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

	Physical phy;
	phy.pos = Vector3(1, 1, 1);
	phy.pos = Vector3(1, 1, 1);
	phy.SetPosition(portal1->GetBump(portal1->pos));

	assert(phy.TryPortal(*portal1) == false);
}

void oncollide_test1() {
	Object o;
	Physical phy;

	o.pos = Vector3(0, 0, 0);
	phy.pos = Vector3(0, 0, 0);

	phy.OnCollide(o, Vector3(10, 10, 10));

	assert(phy.pos.x != 0 && phy.pos.y != 0 && phy.pos.z != 0);
}

void oncollide_test2() {
	Object o;
	Physical phy;

	o.pos = Vector3(5, 5, 5);
	phy.pos = Vector3(0, 0, 0);

	phy.OnCollide(o, Vector3(00, 00, 00));

	assert(phy.pos.x == 0 && phy.pos.y == 0 && phy.pos.z == 0);
}

void physical_update() {
	Physical phy;

	phy.pos = Vector3(0, 0, 0);
	phy.Update();
	phy.Update();
	phy.Update();

	assert(phy.pos.x != 0 || phy.pos.y != 0 || phy.pos.z != 0);
}

void physical_reset() {
	Physical phy;

	phy.pos = Vector3(0, 0, 0);
	phy.Update();
	phy.Update();
	phy.Update();
	phy.Reset();

	assert(phy.pos.x == 0 && phy.pos.y == 0 && phy.pos.z == 0);
}

void collider_tests() {
	Collider c(Vector3(-1, 0, -1), Vector3(-1, 0, 1), Vector3(1,0,1));
	Matrix4 m;
	m.MakeIdentity();
	Vector3 v;
	v = Vector3(0, 0, 0);
	assert(c.Collide(m, v) == true);
}

void Intersects_test() {
	std::shared_ptr<Portal> portal1(new Portal());
	printf("x %f y %f z %f", portal1->Forward().x, portal1->Forward().y, portal1->Forward().z);
	printf("x %f y %f z %f", portal1->pos.x, portal1->pos.y, portal1->pos.z);
}

void tests() {
	portal_hit_test1();
	portal_hit_test2();
	oncollide_test1();
	oncollide_test2();
	physical_update();
	physical_reset();
	Intersects_test();
	collider_tests();
}