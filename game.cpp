#include "game.hpp"

void Game::build_phase() {
	int ch;
	while((ch = getch()) != 27) {
		switch (ch) {
			case KEY_LEFT:
			case 'h':
				gui.move_cursor_left();
				break;
			case KEY_RIGHT:
			case 'l':
				gui.move_cursor_right();
				break;
			case KEY_UP:
			case 'k':
				gui.move_cursor_up();
				break;
			case KEY_DOWN:
			case 'j':
				gui.move_cursor_down();
				break;
			case 'b':
				this->build_tower(1);
			default:
				break;
		}
		gui.refresh();
	}
}

bool Game::build_tower(int tower_id) {
	Coord c = gui.get_cursor_pos();
	board.build_tower(c, tower_id);
	board.render(gui); //TODO move away from here
	return true;
}
