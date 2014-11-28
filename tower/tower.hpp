#ifndef termd_tower
#define termd_tower

#ifndef termd_gui
#define termd_gui
#include "gui.hpp"
#endif //termd_gui

#ifndef termd_coord
#define termd_coord
#include "coord.hpp"
#endif //termd_coord

class Tower {
	private:
		
	protected:
		//Variables:
		Coord pos;			//Top-left

		bool** blocking; 	//Ground path blocking, children can change this
		char** gfx;			//The high-tech 3D model! Children can change this
		int size_rows;		//size of the tower y-wise, used by blocking and gfx
		int size_cols;		//size of the tower x-wise, used by blocking and gfx

		int sell_value;
		float sell_decrease;

		//Functions:
	public:
		Tower();
		Tower(const Tower &);
		~Tower();

		Tower& operator=(const Tower &);

		//Implemented:
		void draw(GUI &);
		const int get_sell_value() const;
		const bool get_blocking() const;
		const int get_size_rows() const;
		const int get_size_cols() const;

		//Virtual:
		virtual bool update() = 0;
		virtual bool end_of_wave_update() = 0;
};

#endif //termd_tower