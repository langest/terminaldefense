#include "virus.hpp"

Virus::Virus(Coord start) : max_hp(10), cur_hp(10), stamina(0), stamina_increment(10), path(start) /*, TODO path() */{
	gfx.resize(1);
	gfx[0].resize(1);
	gfx[0][0] = '@';
}

Virus::Virus(const Virus & src) : path(src.path) {
	max_hp = src.max_hp;
	cur_hp = src.cur_hp;
	stamina = src.stamina;
	gfx = src.gfx;
}

Virus::~Virus() {
	//Currently nothing to do
}

Virus& Virus::operator=(const Virus & src) {
	max_hp = src.max_hp;
	cur_hp = src.cur_hp;
	stamina = src.stamina;
	gfx = src.gfx;
	path = src.path;
	return *this;
}

bool Virus::pathfind(){
	return true; //TODO
}

bool Virus::step(){
	stamina -= stamina_increment;
	return true; //TODO
}

Coord Virus::get_pos(){
	return path.get_curr_pos();
}

bool Virus::update(){
	stamina += stamina_increment;
	//TODO walk with as much stamina as possible
	step();
	return true;
}

bool Virus::draw(GUI & g){
	return g.draw_gfx(get_pos(), gfx, gfx.size(), gfx[0].size());
}