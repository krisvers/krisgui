/*
	krisgui: An immediate mode, zero-dependency,
	software-rendering, single-header UI library

	If KRISGUI_IMPLEMENATION is defined,
	then this header will hold the source code implementation for krisgui
*/

#ifndef KRISVERS_KRISGUI_H
#define KRISVERS_KRISGUI_H

/* Framebuffer given to krisgui on initialization */
typedef struct KrisGUIFramebuffer {
	unsigned int width;
	unsigned int height;
	unsigned char * buffer;
} krisgui_framebuffer_t;

/*
	An enumeration for success and error values
	that are returned from krisgui functions

	NOTE: negative values are always errors, non-negative are always success
*/
typedef enum KrisGUISuccess {
	KRISGUI_ERROR_ASSERTION_FAILURE = -2,
	KRISGUI_ERROR_GENERIC = -1,
	KRISGUI_SUCCESS = 0,
} krisgui_success_enum;

/* Initialize krisgui */
int krisgui_init(krisgui_framebuffer_t * framebuffer);

/* Deinitialize krisgui */
int krisgui_deinit(void);

/*
	If KRISGUI_IMPLEMENATION is defined,
	then this header will hold the source code for krisgui
*/
#ifdef KRISGUI_IMPLEMENTATION

#include <stdio.h>

static krisgui_framebuffer_t * krisgui___internal___framebuffer;

#ifdef KRISGUI_ASSERTIONS
	#define KRISGUI_ASSERT(s, op, v)											\
	{																			\
		if (s op v) {} else {													\
			fprintf(stderr, "krisgui error: (%s %s %s) failed\n", #s, #op, #v);	\
		}																		\
	}
#else	/* #ifdef KRISGUI_ASSERTIONS */
	#define KRISGUI_ASSERT(s, op, v) { s; }
#endif	/* #ifdef KRISGUI_ASSERTIONS */

int krisgui_init(krisgui_framebuffer_t * framebuffer) {
	krisgui___internal___framebuffer = framebuffer;
	printf("init\n");
	return KRISGUI_SUCCESS;
}

void krisgui_draw(unsigned int x, unsigned int y, unsigned int value) {

}

int krisgui_deinit(void) {
	printf("deinit\n");
	return KRISGUI_SUCCESS;
}

#endif	/* #ifdef KRISGUI_IMPLEMENTATION */

#endif	/* #ifndef KRISVERS_KRISGUI_H */