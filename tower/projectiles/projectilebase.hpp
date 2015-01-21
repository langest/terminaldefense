#ifndef termd_projectile_base
#define termd_projectile_base

namespace termd {
	struct Projectile_base {
		char gfx;
		int damage;
		int type;

		Projectile_base(char gf, int d, int t) :
		gfx(gf),
		damage(d),
		type(t) {}
	};

	struct Homing_projectile_base : public Projectile_base {
		int speed_increment;

		Homing_projectile_base(char gf, int d, int t, int speed) :
		Projectile_base(gf, d, t),
		speed_increment(speed) {}
	};

	struct Direction_projectile_base : public Projectile_base {
		int col_spd;
		int row_spd;

		Direction_projectile_base(char gf, int d, int t, int cs, int rs) :
		Projectile_base(gf, d, t),
		col_spd(cs),
		row_spd(rs) {}
	};
}

#endif