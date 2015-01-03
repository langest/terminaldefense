#ifndef termd_game
#define termd_game

#include "definitions"
#include "gui.hpp"
#include "player.hpp"
#include "maps/gameboard.hpp"

namespace termd {

	class Game {
		private:
			GUI gui;
			Player player;
			GameBoard board;

			bool build_tower(int);
		public:
			Game();
			
			void intro();
			void outro();
			void build_phase();
			void invasion_phase();

			int get_player_hp() const;
			void unlock_tower(int);
	};

}

#endif //termd_game
