#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <TCHAR.h>
#include <eglew.h>

static BOOL TestEGLError(HWND hWnd, char* pszLocation)
{
    EGLint iErr = eglGetError();
    if (iErr != EGL_SUCCESS)
    {
        TCHAR pszStr[256];
        _stprintf(pszStr, _T("%s failed (%d).\n"), pszLocation, iErr);
        MessageBox(hWnd, pszStr, _T("Error"), MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        // Handles the close message when a user clicks the quit icon of the window
    case WM_CLOSE:
        PostQuitMessage(0);
        return 1;

    default:
        break;
    }

    // Calls the default window procedure for messages we did not handle
    return DefWindowProc(hWnd, message, wParam, lParam);
}



#define EGLEWTest(func) \
    if (func == 0)\
{\
    fprintf(stderr, "Function: %s has not received an address\n", #func);\
    ret = -1;\
}\
    \

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, TCHAR *lpCmdLine, int nCmdShow)
{
    // Windows variables
    HWND				hWnd	= 0;
    HDC					hDC		= 0;

    // EGL variables
    EGLDisplay			eglDisplay	= 0;
    EGLConfig			eglConfig	= 0;
    EGLSurface			eglSurface	= 0;
    EGLContext			eglContext	= 0;
    NativeWindowType	eglWindow	= 0;
    EGLint				pi32ConfigAttribs[128];
    unsigned int nWidth;
    unsigned int nHeight;
    ATOM registerClass ;
    RECT	sRect;
    EGLint iMajorVersion, iMinorVersion;
    EGLint iConfigs;
    int i;

    int ret = 0;
    // Register the windows class
    WNDCLASS sWC;
    sWC.style = CS_HREDRAW | CS_VREDRAW;
    sWC.lpfnWndProc = WndProc;
    sWC.cbClsExtra = 0;
    sWC.cbWndExtra = 0;
    sWC.hInstance = hInstance;
    sWC.hIcon = 0;
    sWC.hCursor = 0;
    sWC.lpszMenuName = 0;
    sWC.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    sWC.lpszClassName = _T("eglewTest");
    nWidth = 640;
    nHeight = 480;

    registerClass = RegisterClass(&sWC);
    if (!registerClass)
    {
        MessageBox(0, _T("Failed to register the window class"), _T("Error"), MB_OK | MB_ICONEXCLAMATION);
    }

    // Create the eglWindow
    SetRect(&sRect, 0, 0, nWidth, nHeight);
    AdjustWindowRectEx(&sRect, WS_CAPTION | WS_SYSMENU, FALSE, 0);
    hWnd = CreateWindow( _T("eglewTest"), _T("eglewTest"), WS_VISIBLE | WS_SYSMENU,
        0, 0, nWidth, nHeight, NULL, NULL, hInstance, NULL);
    eglWindow = hWnd;

    // Get the associated device context
    hDC = GetDC(hWnd);
    if (!hDC)
    {
        MessageBox(0, _T("Failed to create the device context"), _T("Error"), MB_OK|MB_ICONEXCLAMATION);
        return -1;
    }

    eglDisplay = eglGetDisplay((NativeDisplayType) hDC);

    if(eglDisplay == EGL_NO_DISPLAY)
        eglDisplay = eglGetDisplay((NativeDisplayType) EGL_DEFAULT_DISPLAY);

    if (!eglInitialize(eglDisplay, &iMajorVersion, &iMinorVersion))
    {
        MessageBox(0, _T("eglInitialize() failed."), _T("Error"), MB_OK|MB_ICONEXCLAMATION);
        return -1;
    }


    i = 0;
    pi32ConfigAttribs[i++] = EGL_RED_SIZE;
    pi32ConfigAttribs[i++] = 5;
    pi32ConfigAttribs[i++] = EGL_GREEN_SIZE;
    pi32ConfigAttribs[i++] = 6;
    pi32ConfigAttribs[i++] = EGL_BLUE_SIZE;
    pi32ConfigAttribs[i++] = 5;
    pi32ConfigAttribs[i++] = EGL_ALPHA_SIZE;
    pi32ConfigAttribs[i++] = 0;
    pi32ConfigAttribs[i++] = EGL_SURFACE_TYPE;
    pi32ConfigAttribs[i++] = EGL_WINDOW_BIT;
    pi32ConfigAttribs[i++] = EGL_NONE;


    if (!eglChooseConfig(eglDisplay, pi32ConfigAttribs, &eglConfig, 1, &iConfigs) || (iConfigs != 1))
    {
        MessageBox(0, _T("eglChooseConfig() failed."), _T("Error"), MB_OK|MB_ICONEXCLAMATION);
        return -1;
    }
    eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, eglWindow, NULL);

    if(eglSurface == EGL_NO_SURFACE)
    {
        eglGetError(); // Clear error
        eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, NULL, NULL);
    }

    if (!TestEGLError(hWnd, "eglCreateWindowSurface"))
    {
        return -1;
    }

    eglContext = eglCreateContext(eglDisplay, eglConfig, NULL, NULL);
    if (!TestEGLError(hWnd, "eglCreateContext"))
    {
        return -1;
    }


    eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
    if (!TestEGLError(hWnd, "eglMakeCurrent"))
    {
        return -1;
    }
    eglewInit();
    EGLEWTest(glCurrentPaletteMatrixOES);
    EGLEWTest(glLoadPaletteFromModelViewMatrixOES	);
    EGLEWTest(glMatrixIndexPointerOES );
    EGLEWTest(glWeightPointerOES );
    EGLEWTest(glBlendEquationOES );
    EGLEWTest(glBlendEquationSeparateOES  );
    EGLEWTest(glClipPlanexIMG );
    EGLEWTest(glClipPlanefIMG );
    EGLEWTest(glVertexAttribPointerARB );
    EGLEWTest(glEnableVertexAttribArrayARB );
    EGLEWTest(glDisableVertexAttribArrayARB );
    EGLEWTest(glProgramStringARB );
    EGLEWTest(glBindProgramARB );
    EGLEWTest(glDeleteProgramsARB );
    EGLEWTest(glIsProgramARB );
    EGLEWTest(glGenProgramsARB );
    EGLEWTest(glVertexAttrib4fvARB );
    EGLEWTest(glVertexAttrib4xvIMG );
    EGLEWTest(glProgramLocalParameter4xIMG );
    EGLEWTest(glProgramLocalParameter4xvIMG );
    EGLEWTest(glProgramEnvParameter4xIMG );
    EGLEWTest(glProgramEnvParameter4xvIMG );
    EGLEWTest(glProgramEnvParameter4fARB );
    EGLEWTest(glProgramEnvParameter4fvARB );
    EGLEWTest(glProgramLocalParameter4fARB );
    EGLEWTest(glProgramLocalParameter4fvARB );
    EGLEWTest(glDrawTexiOES );
    EGLEWTest(glDrawTexivOES );
    EGLEWTest(glDrawTexsOES );
    EGLEWTest(glDrawTexsvOES );
    EGLEWTest(glDrawTexxOES );
    EGLEWTest(glDrawTexxvOES );
    EGLEWTest(glDrawTexfOES );
    EGLEWTest(glDrawTexfvOES );
    EGLEWTest(glGetTexStreamDeviceAttribivIMG );
    EGLEWTest(glTexBindStreamIMG );
    EGLEWTest(glGetTexStreamDeviceNameIMG );
    EGLEWTest(glMultiDrawElementsEXT );
    EGLEWTest(glMultiDrawArraysEXT );
    EGLEWTest(glMapBufferOES );
    EGLEWTest(glUnmapBufferOES );
    EGLEWTest(glGetBufferPointervOES );
    EGLEWTest(glIsRenderbufferOES );
    EGLEWTest(glBindRenderbufferOES );
    EGLEWTest(glDeleteRenderbuffersOES );
    EGLEWTest(glGenRenderbuffersOES );
    EGLEWTest(glRenderbufferStorageOES );
    EGLEWTest(glGetRenderbufferParameterivOES );
    EGLEWTest(glIsFramebufferOES );
    EGLEWTest(glBindFramebufferOES );
    EGLEWTest(glDeleteFramebuffersOES );
    EGLEWTest(glGenFramebuffersOES );
    EGLEWTest(glCheckFramebufferStatusOES );
    EGLEWTest(glFramebufferTexture2DOES );
    EGLEWTest(glFramebufferRenderbufferOES );
    EGLEWTest(glGetFramebufferAttachmentParameterivOES );
    EGLEWTest(glGenerateMipmapOES );
    EGLEWTest(glPointSizePointerOES );
    EGLEWTest(glQueryMatrixxOES );
    EGLEWTest(glDiscardFramebufferEXT );
    EGLEWTest(glBindVertexArrayOES );
    EGLEWTest(glDeleteVertexArraysOES );
    EGLEWTest(glGenVertexArraysOES );
    EGLEWTest(glIsVertexArrayOES )
        return ret;
}