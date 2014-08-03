/*
* Copyright (C) 2013 by Francois Coulombe
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "eglew.h"
#include <string.h>

PFNGLCURRENTPALETTEMATRIXOES			glCurrentPaletteMatrixOES=0;
PFNGLLOADPALETTEFROMMODELVIEWMATRIXOES	glLoadPaletteFromModelViewMatrixOES=0;
PFNGLMATRIXINDEXPOINTEROES				glMatrixIndexPointerOES=0;
PFNGLWEIGHTPOINTEROES					glWeightPointerOES=0;

PFNGLCLIPPLANEFIMG	glClipPlanefIMG=0;
PFNGLCLIPPLANEXIMG	glClipPlanexIMG=0;

PFNGLVERTEXATTRIBPOINTERARB			glVertexAttribPointerARB=0;
PFNGLENABLEVERTEXATTRIBARRAYARB		glEnableVertexAttribArrayARB=0;
PFNGLDISABLEVERTEXATTRIBARRAYARB	glDisableVertexAttribArrayARB=0;
PFNGLPROGRAMSTRINGARB				glProgramStringARB=0;
PFNGLBINDPROGRAMARB					glBindProgramARB=0;
PFNGLDELETEPROGRAMSARB				glDeleteProgramsARB=0;
PFNGLGENPROGRAMSARB					glGenProgramsARB=0;
PFNGLISPROGRAMARB					glIsProgramARB=0;
PFNGLPROGRAMENVPARAMETER4FARB		glProgramEnvParameter4fARB=0;
PFNGLPROGRAMENVPARAMETER4FVARB		glProgramEnvParameter4fvARB=0;
PFNGLPROGRAMLOCALPARAMETER4FARB		glProgramLocalParameter4fARB=0;
PFNGLPROGRAMLOCALPARAMETER4FVARB	glProgramLocalParameter4fvARB=0;
PFNGLVERTEXATTRIB4FVARB				glVertexAttrib4fvARB=0;
PFNGLVERTEXATTRIB4XVIMG				glVertexAttrib4xvIMG=0;
PFNGLPROGRAMLOCALPARAMETER4XIMG		glProgramLocalParameter4xIMG=0;
PFNGLPROGRAMLOCALPARAMETER4XVIMG	glProgramLocalParameter4xvIMG=0;
PFNGLPROGRAMENVPARAMETER4XIMG		glProgramEnvParameter4xIMG=0;
PFNGLPROGRAMENVPARAMETER4XVIMG		glProgramEnvParameter4xvIMG=0;
PFNGLDRAWTEXIOES					glDrawTexiOES=0;
PFNGLDRAWTEXIVOES					glDrawTexivOES=0;
PFNGLDRAWTEXSOES					glDrawTexsOES=0;
PFNGLDRAWTEXSVOES					glDrawTexsvOES=0;
PFNGLDRAWTEXXOES					glDrawTexxOES=0;
PFNGLDRAWTEXXVOES					glDrawTexxvOES=0;
PFNGLDRAWTEXFOES					glDrawTexfOES=0;
PFNGLDRAWTEXFVOES					glDrawTexfvOES=0;

PFNGLGETTEXSTREAMDEVICEATTRIBIVIMG	glGetTexStreamDeviceAttribivIMG=0;
PFNGLTEXBINDSTREAMIMG				glTexBindStreamIMG=0;
PFNGLGETTEXSTREAMDEVICENAMEIMG		glGetTexStreamDeviceNameIMG=0;

PFNGLMULTIDRAWELEMENTS				glMultiDrawElementsEXT=0;
PFNGLMULTIDRAWARRAYS				glMultiDrawArraysEXT=0;


PFNGLMAPBUFFEROES                   glMapBufferOES=0;
PFNGLUNMAPBUFFEROES                 glUnmapBufferOES=0;
PFNGLGETBUFFERPOINTERVOES           glGetBufferPointervOES=0;


PFNGLISRENDERBUFFEROES glIsRenderbufferOES=0;
PFNGLBINDRENDERBUFFEROES glBindRenderbufferOES=0;
PFNGLDELETERENDERBUFFERSOES glDeleteRenderbuffersOES=0;
PFNGLGENRENDERBUFFERSOES glGenRenderbuffersOES=0;
PFNGLRENDERBUFFERSTORAGEOES glRenderbufferStorageOES=0;
PFNGLGETRENDERBUFFERPARAMETERIVOES glGetRenderbufferParameterivOES=0;
PFNGLISFRAMEBUFFEROES glIsFramebufferOES=0;
PFNGLBINDFRAMEBUFFEROES glBindFramebufferOES=0;
PFNGLDELETEFRAMEBUFFERSOES glDeleteFramebuffersOES=0;
PFNGLGENFRAMEBUFFERSOES glGenFramebuffersOES=0;
PFNGLCHECKFRAMEBUFFERSTATUSOES glCheckFramebufferStatusOES=0;
PFNGLFRAMEBUFFERTEXTURE2DOES glFramebufferTexture2DOES=0;
PFNGLFRAMEBUFFERRENDERBUFFEROES glFramebufferRenderbufferOES=0;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVOES glGetFramebufferAttachmentParameterivOES=0;
PFNGLGENERATEMIPMAPOES glGenerateMipmapOES=0;

#ifndef GL_OES_point_size_array
/* GL_OES_point_size_array */
PFNGLPOINTSIZEPOINTEROES glPointSizePointerOES=0;
#endif
PFNGLQUERYMATRIXXOES    glQueryMatrixxOES=0;

PFNGLBLENDEQUATIONOES             glBlendEquationOES=0;
PFNGLBLENDEQUATIONSEPARATEOES     glBlendEquationSeparateOES=0;

PFNGLDISCARDFRAMEBUFFEREXT			glDiscardFramebufferEXT=0;

PFNGLBINDVERTEXARRAYOES glBindVertexArrayOES=0;
PFNGLDELETEVERTEXARRAYSOES glDeleteVertexArraysOES=0;
PFNGLGENVERTEXARRAYSOES glGenVertexArraysOES=0;
PFNGLISVERTEXARRAYOES glIsVertexArrayOES=0;
void eglewInit()
{    
    const GLubyte *pszGLExtensions;

    /* Retrieve GL extension string */
    pszGLExtensions = glGetString(GL_EXTENSIONS);

    /* GL_OES_matrix_palette */
    if (strstr((char *)pszGLExtensions, "GL_OES_matrix_palette"))
    {
        glCurrentPaletteMatrixOES			= (PFNGLCURRENTPALETTEMATRIXOES)eglewGetProcAddress(glCurrentPaletteMatrixOES);
        glLoadPaletteFromModelViewMatrixOES	= (PFNGLLOADPALETTEFROMMODELVIEWMATRIXOES)eglewGetProcAddress(glLoadPaletteFromModelViewMatrixOES);
        glMatrixIndexPointerOES				= (PFNGLMATRIXINDEXPOINTEROES)eglewGetProcAddress(glMatrixIndexPointerOES);
        glWeightPointerOES					= (PFNGLWEIGHTPOINTEROES)eglewGetProcAddress(glWeightPointerOES);
    }

    /* GL_OES_draw_texture */
    if (strstr((char *)pszGLExtensions, "GL_OES_draw_texture"))
    {
        glDrawTexiOES = (PFNGLDRAWTEXIOES)eglewGetProcAddress(glDrawTexiOES);
        glDrawTexivOES = (PFNGLDRAWTEXIVOES)eglewGetProcAddress(glDrawTexivOES);
        glDrawTexsOES = (PFNGLDRAWTEXSOES)eglewGetProcAddress(glDrawTexsOES);
        glDrawTexsvOES = (PFNGLDRAWTEXSVOES)eglewGetProcAddress(glDrawTexsvOES);
        glDrawTexxOES = (PFNGLDRAWTEXXOES)eglewGetProcAddress(glDrawTexxOES);
        glDrawTexxvOES = (PFNGLDRAWTEXXVOES)eglewGetProcAddress(glDrawTexxvOES);
        glDrawTexfOES = (PFNGLDRAWTEXFOES)eglewGetProcAddress(glDrawTexfOES);
        glDrawTexfvOES = (PFNGLDRAWTEXFVOES)eglewGetProcAddress(glDrawTexfvOES);
    }

    /* GL_EXT_multi_draw_arrays */
    if (strstr((char *)pszGLExtensions, "GL_OES_mapbuffer"))
    {
        glMapBufferOES = (PFNGLMAPBUFFEROES)eglewGetProcAddress(glMapBufferOES);
        glUnmapBufferOES = (PFNGLUNMAPBUFFEROES)eglewGetProcAddress(glUnmapBufferOES);
        glGetBufferPointervOES = (PFNGLGETBUFFERPOINTERVOES)eglewGetProcAddress(glGetBufferPointervOES);
    }

    /* GL_OES_Framebuffer_object*/
    if (strstr((char *)pszGLExtensions, "GL_OES_framebuffer_object"))
    {
        glIsRenderbufferOES = (PFNGLISRENDERBUFFEROES)eglewGetProcAddress(glIsRenderbufferOES) ;
        glBindRenderbufferOES = (PFNGLBINDRENDERBUFFEROES)eglewGetProcAddress(glBindRenderbufferOES);
        glDeleteRenderbuffersOES = (PFNGLDELETERENDERBUFFERSOES)eglewGetProcAddress(glDeleteRenderbuffersOES);
        glGenRenderbuffersOES = (PFNGLGENRENDERBUFFERSOES)eglewGetProcAddress(glGenRenderbuffersOES);
        glRenderbufferStorageOES = (PFNGLRENDERBUFFERSTORAGEOES)eglewGetProcAddress(glRenderbufferStorageOES);
        glGetRenderbufferParameterivOES = (PFNGLGETRENDERBUFFERPARAMETERIVOES)eglewGetProcAddress(glGetRenderbufferParameterivOES);
        glIsFramebufferOES = (PFNGLISFRAMEBUFFEROES)eglewGetProcAddress(glIsFramebufferOES);
        glBindFramebufferOES = (PFNGLBINDFRAMEBUFFEROES)eglewGetProcAddress(glBindFramebufferOES);
        glDeleteFramebuffersOES = (PFNGLDELETEFRAMEBUFFERSOES)eglewGetProcAddress(glDeleteFramebuffersOES);
        glGenFramebuffersOES = (PFNGLGENFRAMEBUFFERSOES)eglewGetProcAddress(glGenFramebuffersOES);
        glCheckFramebufferStatusOES = (PFNGLCHECKFRAMEBUFFERSTATUSOES)eglewGetProcAddress(glCheckFramebufferStatusOES);
        glFramebufferTexture2DOES = (PFNGLFRAMEBUFFERTEXTURE2DOES)eglewGetProcAddress(glFramebufferTexture2DOES);
        glFramebufferRenderbufferOES = (PFNGLFRAMEBUFFERRENDERBUFFEROES)eglewGetProcAddress(glFramebufferRenderbufferOES);
        glGetFramebufferAttachmentParameterivOES = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVOES)eglewGetProcAddress(glGetFramebufferAttachmentParameterivOES);
        glGenerateMipmapOES = (PFNGLGENERATEMIPMAPOES)eglewGetProcAddress(glGenerateMipmapOES);
    }

#if !defined(GL_OES_point_size_array)
    /* GL_OES_point_size_array */
    if (strstr((char *)pszGLExtensions, "GL_OES_point_size_array"))
    {
        glPointSizePointerOES = (PFNGLPOINTSIZEPOINTEROES)eglewGetProcAddress(glPointSizePointerOES);
    }
#endif

#if !defined (TARGET_OS_IPHONE)
    /* GL_IMG_user_clip_plane */
    if (strstr((char *)pszGLExtensions, "GL_IMG_user_clip_plane"))
    {
        /* glClipPlanexIMG and glClipPlanefIMG */
        glClipPlanexIMG = (PFNGLCLIPPLANEXIMG)eglewGetProcAddress(glClipPlanexIMG);
        glClipPlanefIMG = (PFNGLCLIPPLANEFIMG)eglewGetProcAddress(glClipPlanefIMG);
    }

    /* GL_IMG_vertex_program */
    if (strstr((char *)pszGLExtensions, "GL_IMG_vertex_program"))
    {
        glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARB)eglewGetProcAddress(glVertexAttribPointerARB);
        glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARB)eglewGetProcAddress(glEnableVertexAttribArrayARB);
        glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARB)eglewGetProcAddress(glDisableVertexAttribArrayARB);
        glProgramStringARB = (PFNGLPROGRAMSTRINGARB)eglewGetProcAddress(glProgramStringARB);
        glBindProgramARB = (PFNGLBINDPROGRAMARB)eglewGetProcAddress(glBindProgramARB);
        glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARB)eglewGetProcAddress(glDeleteProgramsARB);
        glIsProgramARB = (PFNGLISPROGRAMARB)eglewGetProcAddress(glIsProgramARB);
        glGenProgramsARB = (PFNGLGENPROGRAMSARB)eglewGetProcAddress(glGenProgramsARB);
        glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARB)eglewGetProcAddress(glVertexAttrib4fvARB);
        glVertexAttrib4xvIMG = (PFNGLVERTEXATTRIB4XVIMG)eglewGetProcAddress(glVertexAttrib4xvIMG);
        glProgramLocalParameter4xIMG = (PFNGLPROGRAMLOCALPARAMETER4XIMG)eglewGetProcAddress(glProgramLocalParameter4xIMG);
        glProgramLocalParameter4xvIMG = (PFNGLPROGRAMLOCALPARAMETER4XVIMG)eglewGetProcAddress(glProgramLocalParameter4xvIMG);
        glProgramEnvParameter4xIMG = (PFNGLPROGRAMENVPARAMETER4XIMG)eglewGetProcAddress(glProgramEnvParameter4xIMG);
        glProgramEnvParameter4xvIMG = (PFNGLPROGRAMENVPARAMETER4XVIMG)eglewGetProcAddress(glProgramEnvParameter4xvIMG);
        glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARB)eglewGetProcAddress(glProgramEnvParameter4fARB);
        glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARB)eglewGetProcAddress(glProgramEnvParameter4fvARB);
        glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARB)eglewGetProcAddress(glProgramLocalParameter4fARB);
        glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARB)eglewGetProcAddress(glProgramLocalParameter4fvARB);
    }

    /* IMG_texture_stream */
    if (strstr((char *)pszGLExtensions, "GL_IMG_texture_stream"))
    {
        glGetTexStreamDeviceAttribivIMG = (PFNGLGETTEXSTREAMDEVICEATTRIBIVIMG)eglewGetProcAddress(glGetTexStreamDeviceAttribivIMG);
        glTexBindStreamIMG = (PFNGLTEXBINDSTREAMIMG)eglewGetProcAddress(glTexBindStreamIMG);
        glGetTexStreamDeviceNameIMG = (PFNGLGETTEXSTREAMDEVICENAMEIMG)eglewGetProcAddress(glGetTexStreamDeviceNameIMG);
    }

    /* GL_EXT_multi_draw_arrays */
    if (strstr((char *)pszGLExtensions, "GL_EXT_multi_draw_arrays"))
    {
        glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTS)eglewGetProcAddress(glMultiDrawElementsEXT);
        glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYS)eglewGetProcAddress(glMultiDrawArraysEXT);
    }

    /* GL_OES_query_matrix */
    if (strstr((char *)pszGLExtensions, "GL_OES_query_matrix"))
    {
        glQueryMatrixxOES = (PFNGLQUERYMATRIXXOES)eglewGetProcAddress(glQueryMatrixxOES);
    }

    /* GL_OES_blend_equation */
    if (strstr((char *)pszGLExtensions, "GL_OES_blend_subtract"))
    {
        glBlendEquationOES = (PFNGLBLENDEQUATIONOES)eglewGetProcAddress(glBlendEquationOES);
    }

    /* GL_OES_query_matrix */
    if (strstr((char *)pszGLExtensions, "GL_OES_blend_equation_separate"))
    {
        glBlendEquationSeparateOES = (PFNGLBLENDEQUATIONSEPARATEOES)eglewGetProcAddress(glBlendEquationSeparateOES);
    }

    /* GL_OES_vertex_array_object */
    if (strstr((char *)pszGLExtensions, "GL_OES_vertex_array_object"))
    {
        glBindVertexArrayOES = (PFNGLBINDVERTEXARRAYOES) eglewGetProcAddress(glBindVertexArrayOES);
        glDeleteVertexArraysOES = (PFNGLDELETEVERTEXARRAYSOES) eglewGetProcAddress(glDeleteVertexArraysOES);
        glGenVertexArraysOES = (PFNGLGENVERTEXARRAYSOES) eglewGetProcAddress(glGenVertexArraysOES);
        glIsVertexArrayOES = (PFNGLISVERTEXARRAYOES) eglewGetProcAddress(glIsVertexArrayOES);
    }
#endif

#if defined(GL_EXT_discard_framebuffer)
    /* GL_EXT_discard_framebuffer */
    if (strstr((char *)pszGLExtensions, "GL_EXT_discard_framebuffer"))
    {
        glDiscardFramebufferEXT = (PFNGLDISCARDFRAMEBUFFEREXT) eglewGetProcAddress(glDiscardFramebufferEXT);
    }
#endif
}
