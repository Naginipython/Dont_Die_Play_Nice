#include "gl_renderer.h"

static PFNGLCREATEPROGRAMPROC glCreatProgram_ptr;


void gl_load_functions() {
    PROC proc = wglGetProcAddress("glCreateProgram");
    if (!proc) {
        SM_ASSERT(false, "Failed to load gl function %s", "glCreateProgram");
    }

    glCreatProgram_ptr = (PFNGLCREATEPROGRAMPROC) proc;
}

GLAPI GLuint APIENTRY glCreateProgram(void) {
    return glCreatProgram_ptr();
}