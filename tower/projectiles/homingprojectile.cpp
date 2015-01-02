#include "homingprojectile.hpp"

HomingProjectile::HomingProjectile(Coord s, Virus& t) : pos(s), target(t), speed_curr(0), speed_increment(100), gfx('·') {
}

HomingProjectile::~HomingProjectile() {
	//TODO keep track if needed
}

HomingProjectile::HomingProjectile(const HomingProjectile & src) : pos(src.pos), target(src.target), speed_curr(src.speed_curr), speed_increment(src.speed_increment), gfx(src.gfx) {
}

void HomingProjectile::move() {
	while (step());
}

bool HomingProjectile::step() {
	delta = target.get_pos() - pos;

	if (delta.get_row() == 0 && delta.get_col() == 0) return false; //We already reached the target

	float angle = atan2(delta.row, delta.col) * 180 / PI;
	if (angle < 45.0f/2.0f) { //go right
		if (speed_curr >= STEPCOST) {
			speed_curr -= STEPCOST;
			pos.add_col(1);
			return true;
		}
	} else if (angle < 45.0f+45.0f/2.0f) { //go up right
		if (speed_curr >= STEPCOSTDIAGONAL) {
			speed_curr -= STEPCOSTDIAGONAL;
			pos.add_col(1);
			pos.add_row(-1);
			return true;
		}
	} else if (angle < 2*45.0f+45.0f/2.0f) { //go up
		if (speed_curr >= STEPCOST) {
			speed_curr -= STEPCOST;
			pos.add_row(-1);
			return true;
		}
	} else if (angle < 3*45.0f+45.0f/2.0f) { //go up left
		if (speed_curr >= STEPCOSTDIAGONAL) {
			speed_curr -= STEPCOSTDIAGONAL;
			pos.add_col(-1);
			pos.add_row(-1);
			return true;
		}
	} else if (angle < 4*45.0f+45.0f/2.0f) { //go left
		if (speed_curr >= STEPCOST) {
			speed_curr -= STEPCOST;
			pos.add_col(-1);
			return true;
		}
	} else if (angle < 5*45.0f+45.0f/2.0f) { //go down left
		if (speed_curr >= STEPCOSTDIAGONAL) {
			speed_curr -= STEPCOSTDIAGONAL;
			pos.add_col(-1);
			pos.add_row(1);
			return true;
		}
	} else if (angle < 6*45.0f+45.0f/2.0f) { //go down
		if (speed_curr >= STEPCOST) {
			speed_curr -= STEPCOST;
			pos.add_col(-1);
			return true;
		}
	} else if (angle < 7*45.0f+45.0f/2.0f) { //go down right
		if (speed_curr >= STEPCOSTDIAGONAL) {
			speed_curr -= STEPCOSTDIAGONAL;
			pos.add_col(1);
			pos.add_row(1);
			return true;
		}
	} else { //go right
		if (speed_curr >= STEPCOST) {
			speed_curr -= STEPCOST;
			pos.add_col(1);
			return true;
		}
	}
	return false;
}

HomingProjectile& HomingProjectile::operator=(const HomingProjectile & src) {
	pos = src.pos;
	target = src.target;
	speed_curr = src.speed_curr;
	speed_increment = src.speed_increment;
	gfx = src.gfx;
	return *this;
}

bool HomingProjectile::update() {
	if(pos == target.get_pos()){
		//hit target!
		//deal damage!
		return false; 
	}
	speed_curr += speed_increment;
	move();
	return true;
}
