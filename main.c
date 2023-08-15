#include <stdio.h>
#define KRISGUI_IMPLEMENTATION
#include "krisgui.h"

int main(void) {
	krisgui_framebuffer_t framebuffer = {
		.width = 800,
		.height = 600,
		.buffer = NULL,
	};
	krisgui_init(&framebuffer);

	krisgui_deinit();
	return 0;
}