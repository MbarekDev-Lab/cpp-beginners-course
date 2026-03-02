//============================================================================
// Lesson 20: SDL Basics - Comprehensive Guide
// Author      : M'Barek Benraiss
// Description : Understanding SDL (Simple DirectMedia Layer) basics
//               including initialization, windows, events, and rendering
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

// ============================================================================
// SECTION 1: Basic SDL Initialization and Cleanup
// ============================================================================
/*
SDL Initialization:
- SDL_Init() must be called before using any SDL functions
- Pass subsystems to initialize: SDL_INIT_VIDEO, SDL_INIT_AUDIO, etc.
- Always call SDL_Quit() before program exits
- Check return value (0 = success, negative = failure)

Pattern:
1. SDL_Init(flags)
2. Use SDL
3. SDL_Quit()
*/

void section1_BasicInitialization()
{
    cout << "\n=== SECTION 1: SDL Initialization ===" << endl;

    cout << "Initializing SDL with video subsystem..." << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL initialization failed: " << SDL_GetError() << endl;
        return;
    }

    cout << "SDL initialized successfully!" << endl;
    cout << "SDL Version: " << SDL_MAJOR_VERSION << "."
         << SDL_MINOR_VERSION << "." << SDL_PATCHLEVEL << endl;

    cout << "\nQuerying video drivers:" << endl;
    int numDrivers = SDL_GetNumVideoDrivers();
    cout << "Available video drivers: " << numDrivers << endl;
    for (int i = 0; i < numDrivers; i++)
    {
        cout << "  " << i << ": " << SDL_GetVideoDriver(i) << endl;
    }

    SDL_Quit();
    cout << "SDL cleanup completed" << endl;
}

// ============================================================================
// SECTION 2: Creating Windows
// ============================================================================
/*
Creating an SDL Window:
- SDL_CreateWindow(title, x, y, width, height, flags)
- x, y: Window position (can use SDL_WINDOWPOS_CENTERED)
- width, height: Dimensions in pixels
- flags: SDL_WINDOW_SHOWN, SDL_WINDOW_FULLSCREEN, etc.
- Returns SDL_Window* pointer
- Must free with SDL_DestroyWindow()

Window flags:
- SDL_WINDOW_SHOWN: Window visible
- SDL_WINDOW_HIDDEN: Window hidden
- SDL_WINDOW_FULLSCREEN: Fullscreen mode
- SDL_WINDOW_RESIZABLE: Allow resizing
- SDL_WINDOW_BORDERLESS: No window border
*/

void section2_CreatingWindows()
{
    cout << "\n=== SECTION 2: Creating Windows ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL init failed" << endl;
        return;
    }

    cout << "Creating window (800x600)..." << endl;

    SDL_Window *window = SDL_CreateWindow(
        "SDL Basic Window",     // Title
        SDL_WINDOWPOS_CENTERED, // X position
        SDL_WINDOWPOS_CENTERED, // Y position
        800,                    // Width
        600,                    // Height
        SDL_WINDOW_SHOWN        // Flags
    );

    if (window == nullptr)
    {
        cerr << "Window creation failed: " << SDL_GetError() << endl;
        SDL_Quit();
        return;
    }

    cout << "Window created successfully!" << endl;

    // Get window properties
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    cout << "Window size: " << w << "x" << h << endl;

    Uint32 flags = SDL_GetWindowFlags(window);
    cout << "Window is shown: " << ((flags & SDL_WINDOW_SHOWN) ? "YES" : "NO") << endl;

    // Simulate a small delay to show window
    SDL_Delay(1000); // 1 second

    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "Window destroyed and SDL cleaned up" << endl;
}

// ============================================================================
// SECTION 3: Rendering and Drawing
// ============================================================================
/*
SDL Rendering:
- SDL_CreateRenderer() creates rendering context
- SDL_RenderClear() clears the screen
- SDL_RenderPresent() shows the rendered frame
- SDL_SetRenderDrawColor() sets drawing color (RGBA)

Typical render loop:
1. SDL_RenderClear(renderer)
2. Draw shapes/objects
3. SDL_RenderPresent(renderer)
*/

void section3_Rendering()
{
    cout << "\n=== SECTION 3: Rendering ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL init failed" << endl;
        return;
    }

    SDL_Window *window = SDL_CreateWindow(
        "SDL Rendering",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    if (!window)
    {
        cerr << "Window creation failed" << endl;
        SDL_Quit();
        return;
    }

    cout << "Creating renderer..." << endl;
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        cerr << "Renderer creation failed: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    cout << "Renderer created successfully!" << endl;

    // Set background color (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    cout << "Clearing screen and presenting..." << endl;
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "Rendering resources cleaned up" << endl;
}

// ============================================================================
// SECTION 4: Drawing Shapes - Rectangles
// ============================================================================
/*
Drawing Rectangles:
- SDL_Rect: Represents rectangle (x, y, w, h)
- SDL_RenderFillRect(): Draw filled rectangle
- SDL_RenderDrawRect(): Draw rectangle outline
- Set color with SDL_SetRenderDrawColor first

Color values: RGBA (0-255)
- Red:   (255, 0, 0, 255)
- Green: (0, 255, 0, 255)
- Blue:  (0, 0, 255, 255)
*/

void section4_DrawingRectangles()
{
    cout << "\n=== SECTION 4: Drawing Rectangles ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "SDL Rectangles",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    cout << "Drawing rectangles..." << endl;

    // Clear background (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw red filled rectangle
    SDL_Rect redRect = {50, 50, 100, 100};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &redRect);

    // Draw green outlined rectangle
    SDL_Rect greenRect = {200, 50, 100, 100};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &greenRect);

    // Draw blue filled rectangle
    SDL_Rect blueRect = {125, 150, 150, 100};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &blueRect);

    SDL_RenderPresent(renderer);

    cout << "Displayed rectangles for 2 seconds" << endl;
    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "Rectangle drawing demo completed" << endl;
}

// ============================================================================
// SECTION 5: Drawing Lines and Points
// ============================================================================
/*
Drawing Lines and Points:
- SDL_RenderDrawPoint(): Draw single pixel
- SDL_RenderDrawLine(): Draw line between two points
- SDL_RenderDrawPoints(): Draw multiple points
- SDL_RenderDrawLines(): Draw connected lines

Useful for:
- Grid lines
- Debug visualization
- Simple geometric patterns
*/

void section5_LinesAndPoints()
{
    cout << "\n=== SECTION 5: Lines and Points ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "SDL Lines and Points",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    cout << "Drawing lines and points..." << endl;

    // Clear background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw diagonal lines (white)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0, 0, 400, 300); // TL to BR
    SDL_RenderDrawLine(renderer, 400, 0, 0, 300); // TR to BL

    // Draw horizontal line (red)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, 150, 400, 150);

    // Draw vertical line (green)
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, 200, 0, 200, 300);

    // Draw point (yellow)
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawPoint(renderer, 200, 150);

    SDL_RenderPresent(renderer);

    cout << "Displayed lines and points for 2 seconds" << endl;
    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "Lines and points demo completed" << endl;
}

// ============================================================================
// SECTION 6: Event Handling Basics
// ============================================================================
/*
SDL Events:
- SDL_Event: Union containing all event types
- SDL_PollEvent(): Check for pending events (non-blocking)
- SDL_WaitEvent(): Wait for event (blocking)

Common event types:
- SDL_QUIT: Window close button
- SDL_KEYDOWN: Keyboard key pressed
- SDL_KEYUP: Keyboard key released
- SDL_MOUSEMOTION: Mouse moved
- SDL_MOUSEBUTTONDOWN: Mouse button pressed
- SDL_MOUSEBUTTONUP: Mouse button released
*/

void section6_EventHandling()
{
    cout << "\n=== SECTION 6: Event Handling ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "SDL Events",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED);

    cout << "Event handling demo (run for 3 seconds with window in focus)" << endl;
    cout << "Try: Click, move mouse, press keys" << endl;

    SDL_Event event;
    bool running = true;
    int eventCount = 0;
    Uint32 startTime = SDL_GetTicks();

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        while (SDL_PollEvent(&event))
        {
            eventCount++;

            switch (event.type)
            {
            case SDL_QUIT:
                cout << "Quit event received" << endl;
                running = false;
                break;
            case SDL_KEYDOWN:
                cout << "Key pressed: " << SDL_GetKeyName(event.key.keysym.sym) << endl;
                break;
            case SDL_MOUSEMOTION:
                cout << "Mouse at: " << event.motion.x << ", " << event.motion.y << endl;
                break;
            case SDL_MOUSEBUTTONDOWN:
                cout << "Mouse button pressed: " << (int)event.button.button << endl;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    cout << "Total events captured: " << eventCount << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// ============================================================================
// SECTION 7: Timing and Frame Rate
// ============================================================================
/*
SDL Timing:
- SDL_GetTicks(): Milliseconds since SDL_Init()
- SDL_Delay(ms): Pause for milliseconds
- Frame cap: Control frame rate

Frame timing pattern:
1. Record start time
2. Render frame
3. Calculate elapsed time
4. Delay if needed to maintain frame rate
*/

void section7_Timing()
{
    cout << "\n=== SECTION 7: Timing and Frame Rate ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "SDL Timing",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED);

    cout << "Running for 3 seconds, measuring frame time..." << endl;

    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS; // Milliseconds per frame

    Uint32 startTime = SDL_GetTicks();
    int frameCount = 0;
    Uint32 lastTime = startTime;

    while (SDL_GetTicks() - startTime < 3000)
    {
        Uint32 frameStart = SDL_GetTicks();

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        frameCount++;

        // Print frame info every 60 frames
        if (frameCount % 60 == 0)
        {
            Uint32 currentTime = SDL_GetTicks();
            double actualFPS = 60000.0 / (currentTime - lastTime);
            cout << "Frame " << frameCount << ", FPS: " << actualFPS << endl;
            lastTime = currentTime;
        }

        // Cap frame rate
        int frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    Uint32 totalTime = SDL_GetTicks() - startTime;
    double avgFPS = (frameCount * 1000.0) / totalTime;
    cout << "Total frames: " << frameCount << ", Average FPS: " << avgFPS << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// ============================================================================
// SECTION 8: Complete Game Loop Pattern
// ============================================================================
/*
Standard Game Loop:
1. Initialize SDL, window, renderer
2. Loop until quit:
   a. Handle events
   b. Update game state
   c. Render graphics
3. Cleanup resources

This is the foundation for all games built with SDL
*/

void section8_GameLoop()
{
    cout << "\n=== SECTION 8: Complete Game Loop ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Game Loop Demo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    cout << "Game loop running for 3 seconds..." << endl;

    bool running = true;
    Uint32 startTime = SDL_GetTicks();

    SDL_Rect playerRect = {50, 50, 50, 50};

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        // 1. Handle Events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // 2. Update (move player rectangle slowly)
        playerRect.x = 50 + (SDL_GetTicks() - startTime) / 10;
        playerRect.y = 50 + ((SDL_GetTicks() - startTime) / 20) % 100;

        // 3. Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &playerRect);

        SDL_RenderPresent(renderer);
    }

    cout << "Game loop completed" << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// ============================================================================
// SECTION 9: Keyboard Input and Movement
// ============================================================================
/*
Keyboard Input Patterns:
1. Poll events and check SDL_KEYDOWN events
2. Use SDL_GetKeyboardState() for current key states
3. Map keysyms to game actions

Common keys:
- SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT
- SDL_SCANCODE_W, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D
- SDL_SCANCODE_SPACE, SDL_SCANCODE_RETURN
*/

void section9_KeyboardInput()
{
    cout << "\n=== SECTION 9: Keyboard Input ===" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Keyboard Input",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED);

    cout << "Keyboard input demo (run for 3 seconds, try pressing arrow keys)" << endl;

    SDL_Rect sprite = {200, 150, 30, 30};
    const int SPEED = 5;

    Uint32 startTime = SDL_GetTicks();
    bool running = true;

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        // Get current keyboard state
        const Uint8 *keystate = SDL_GetKeyboardState(nullptr);

        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Update position based on keys
        if (keystate[SDL_SCANCODE_UP])
        {
            sprite.y -= SPEED;
        }
        if (keystate[SDL_SCANCODE_DOWN])
        {
            sprite.y += SPEED;
        }
        if (keystate[SDL_SCANCODE_LEFT])
        {
            sprite.x -= SPEED;
        }
        if (keystate[SDL_SCANCODE_RIGHT])
        {
            sprite.x += SPEED;
        }

        // Clamp to screen
        if (sprite.x < 0)
            sprite.x = 0;
        if (sprite.y < 0)
            sprite.y = 0;
        if (sprite.x + sprite.w > 400)
            sprite.x = 400 - sprite.w;
        if (sprite.y + sprite.h > 300)
            sprite.y = 300 - sprite.h;

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &sprite);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    cout << "Keyboard input demo completed" << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "============= SDL Basics - Complete Overview =============" << endl;

    section1_BasicInitialization();
    section2_CreatingWindows();
    section3_Rendering();
    section4_DrawingRectangles();
    section5_LinesAndPoints();
    section6_EventHandling();
    section7_Timing();
    section8_GameLoop();
    section9_KeyboardInput();

    cout << "\n============= All Sections Completed =============" << endl;

    return 0;
}
