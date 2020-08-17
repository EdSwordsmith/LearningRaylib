#include "raylib.h"

#if __APPLE__
#include "CoreFoundation/CoreFoundation.h"
#endif

int main(void)
{
#if __APPLE__
    {
        CFURLRef url = CFBundleCopyResourcesDirectoryURL(CFBundleGetMainBundle());
        char path[PATH_MAX];
        if (!CFURLGetFileSystemRepresentation(url, true, (UInt8 *) path, sizeof(path)) || chdir(path) != 0)
            return -1;
        CFRelease(url);
    }
#endif

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Testing macOS App Bundle Resource handling");
    Texture2D texture = LoadTexture("assets/logo.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();
    UnloadTexture(texture);

    return 0;
}
