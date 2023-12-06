#include "DEFS.h"
#include "GUI/UI_Info.h"

int getColorNumber(color color) {
	int size = UI.colors.size();
	for (int i = 0; i < size; i++) {
		if (UI.colors[i] == color)
			return i;
	}
	return 0;
}

color getColorByNumber(int n) {
	return UI.colors[n];
}