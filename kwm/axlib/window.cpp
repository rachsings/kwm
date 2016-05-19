#include "window.h"
#include "element.h"

ax_window AXLibConstructWindow(ax_application *Application, AXUIElementRef WindowRef)
{
    ax_window Window = {};

    Window.Ref = WindowRef;
    Window.Application = Application;
    Window.ID = AXLibGetWindowID(WindowRef);
    Window.Movable = AXLibIsWindowMovable(WindowRef);
    Window.Resizable = AXLibIsWindowResizable(WindowRef);
    AXLibGetWindowRole(WindowRef, &Window.Type.Role);
    AXLibGetWindowSubrole(WindowRef, &Window.Type.Subrole);

    return Window;
}

void AXLibDestroyWindow(ax_window *AXWindow)
{
    CFRelease(AXWindow->Ref);
    CFRelease(AXWindow->Type.Role);
    CFRelease(AXWindow->Type.Subrole);
}
