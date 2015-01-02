#include "projectilemanager.hpp"

ProjectileManager::~ProjectileManager() {
	purge_projectiles();
}

void ProjectileManager::purge_projectiles() {
	for (Projectile* proj : projectiles) {
		delete proj;
	}
	projectiles.clear();
}

void ProjectileManager::update() {
	for (auto i = projectiles.begin(); i != projectiles.end(); ) {
		if((*i)->update() == false) {
			//Projectile flags removal (probably a hit)
			delete *i;
			i = projectiles.erase(i);
		} else {
			++i;
		}
	}
}

void ProjectileManager::draw_projectiles(GUI & gui) {
	for (Projectile* proj : projectiles) {
		proj->draw(gui);
	}
}
void ProjectileManager::add_projectile(Projectile* p) {
	projectiles.push_back(p);
}
