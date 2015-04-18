#include "waveinfo.hpp"

Wave_info::Wave_info(int num_spawns) : wave(num_spawns, std::vector<int>()) {
}

int Wave_info::num_spawns() {
	return wave.size();
}

std::vector<int>& operator[](int ix) {
	return wave[ix];
}
