//============================================================================
// Lesson 20: SDL Basics - Exercises
// Author      : M'Barek Benraiss
// Description : Progressive exercises for SDL initialization, windows,
//               rendering, events, and game loop fundamentals
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

// ============================================================================
// EXERCISE 1: SDL Initialization and Error Checking
// ============================================================================
/*
EXERCISE 1: Basic SDL initialization with proper error handling
- Initialize SDL with video subsystem
- Check for errors with SDL_GetError()
- Print version information
- Clean up with SDL_Quit()
*/

void exercise1()
{
    cout << "\n--- Exercise 1: SDL Initialization ---" << endl;

    cout << "Initializing SDL..." << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL initialization failed: " << SDL_GetError() << endl;
        return;
    }

    cout << "SDL initialized successfully!" << endl;
    cout << "SDL Version: " << SDL_MAJOR_VERSION << "."
         << SDL_MINOR_VERSION << "." << SDL_PATCHLEVEL << endl;

    SDL_Quit();
    cout << "SUCCESS: SDL initialized and cleaned up properly" << endl;
}

// ============================================================================
// EXERCISE 2: Create and Destroy a Window
// ============================================================================
/*
EXERCISE 2: Create window and query its properties
- Create window at centered position
- Get window size and flags
- Display properties
- Destroy window properly
*/

void exercise2()
{
    cout << "\n--- Exercise 2: Window Creation ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL init failed" << endl;
        return;
    }

    cout << "Creating window..." << endl;

    SDL_Window *window = SDL_CreateWindow(
        "Exercise Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        cerr << "Window creation failed: " << SDL_GetError() << endl;
        SDL_Quit();
        return;
    }

    cout << "Window created successfully!" << endl;

    // Query window properties
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    cout << "Window size: " << w << "x" << h << endl;

    Uint32 flags = SDL_GetWindowFlags(window);
    cout << "Window is shown: " << ((flags & SDL_WINDOW_SHOWN) ? "YES" : "NO") << endl;

    SDL_Delay(1000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Window created, displayed, and destroyed" << endl;
}

// ============================================================================
// EXERCISE 3: Create Renderer and Clear Screen
// ============================================================================
/*
EXERCISE 3: Create renderer and render a cleared screen
- Initialize SDL and window
- Create renderer with acceleration
- Clear screen with color
- Present to display
*/

void exercise3()
{
    cout << "\n--- Exercise 3: Renderer Creation ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Renderer Test",
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
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        cerr << "Renderer creation failed: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    cout << "Renderer created successfully!" << endl;

    // Clear screen with blue color
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    cout << "Screen cleared with blue color" << endl;
    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Renderer created and used" << endl;
}

// ============================================================================
// EXERCISE 4: Draw Rectangles with Different Colors
// ============================================================================
/*
EXERCISE 4: Draw multiple rectangles with different colors
- Draw filled rectangles (red, green, blue)
- Draw outlined rectangles
- Fill entire screen with color
- Demonstrate color control
*/

void exercise4()
{
    cout << "\n--- Exercise 4: Drawing Rectangles ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Rectangles",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED);

    cout << "Drawing rectangles..." << endl;

    // Clear background (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Red filled rectangle
    SDL_Rect rect1 = {50, 50, 80, 60};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect1);

    // Green filled rectangle
    SDL_Rect rect2 = {160, 50, 80, 60};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect2);

    // Blue outlined rectangle
    SDL_Rect rect3 = {270, 50, 80, 60};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawRect(renderer, &rect3);

    // Yellow rectangle
    SDL_Rect rect4 = {100, 150, 100, 80};
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect4);

    SDL_RenderPresent(renderer);

    cout << "Displayed rectangles for 2 seconds" << endl;
    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Multiple rectangles drawn" << endl;
}

// ============================================================================
// EXERCISE 5: Draw Lines and Points
// ============================================================================
/*
EXERCISE 5: Draw lines and points on canvas
- Draw diagonal lines
- Draw horizontal/vertical lines
- Draw individual points
- Create patterns with lines
*/

void exercise5()
{
    cout << "\n--- Exercise 5: Drawing Lines and Points ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Lines and Points",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Drawing lines and points..." << endl;

    // Black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // White diagonal lines forming X
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0, 0, 400, 300);
    SDL_RenderDrawLine(renderer, 400, 0, 0, 300);

    // Red horizontal line
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, 150, 400, 150);

    // Green vertical line
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, 200, 0, 200, 300);

    // Draw corners as points
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawPoint(renderer, 0, 0);
    SDL_RenderDrawPoint(renderer, 400, 0);
    SDL_RenderDrawPoint(renderer, 0, 300);
    SDL_RenderDrawPoint(renderer, 400, 300);

    SDL_RenderPresent(renderer);

    cout << "Displayed lines and points for 2 seconds" << endl;
    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Lines and points drawn" << endl;
}

// ============================================================================
// EXERCISE 6: Basic Event Handling (Quit Event)
// ============================================================================
/*
EXERCISE 6: Handle window quit event
- Create event loop
- Poll for SDL_QUIT event
- Exit loop on quit
- Run for maximum 3 seconds
*/

void exercise6()
{
    cout << "\n--- Exercise 6: Event Handling (Quit) ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Event Test",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Running event loop (try closing window or wait 3 seconds)..." << endl;

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();
    int eventCount = 0;

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        while (SDL_PollEvent(&event))
        {
            eventCount++;

            if (event.type == SDL_QUIT)
            {
                cout << "Quit event received!" << endl;
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    cout << "Total events processed: " << eventCount << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Event handling demonstrated" << endl;
}

// ============================================================================
// EXERCISE 7: Keyboard Input Detection
// ============================================================================
/*
EXERCISE 7: Detect keyboard key presses
- Listen for SDL_KEYDOWN events
- Print key names when pressed
- Detect specific keys
- Run for 3 seconds
*/

void exercise7()
{
    cout << "\n--- Exercise 7: Keyboard Input ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Keyboard Input",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Keyboard input test (press keys for 3 seconds)..." << endl;

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();
    int keyPresses = 0;

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                keyPresses++;
                SDL_Keysym keysym = event.key.keysym;
                cout << "Key pressed: " << SDL_GetKeyName(keysym.sym) << endl;

                if (keysym.sym == SDLK_ESCAPE)
                {
                    cout << "ESC pressed - exiting" << endl;
                    running = false;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    cout << "Total key presses: " << keyPresses << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Keyboard input detected" << endl;
}

// ============================================================================
// EXERCISE 8: Keyboard State (Arrow Keys)
// ============================================================================
/*
EXERCISE 8: Get current keyboard state for arrow keys
- Use SDL_GetKeyboardState()
- Check for held keys
- Display which keys are pressed
- Handle multiple simultaneous keys
*/

void exercise8()
{
    cout << "\n--- Exercise 8: Keyboard State ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Keyboard State",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Keyboard state test (hold arrow keys for 3 seconds)..." << endl;

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();
    int checks = 0;

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        const Uint8 *keystate = SDL_GetKeyboardState(nullptr);

        checks++;
        if (checks % 15 == 0)
        { // Print every 15 checks (~4 times per second)
            cout << "State: ";
            if (keystate[SDL_SCANCODE_UP])
                cout << "UP ";
            if (keystate[SDL_SCANCODE_DOWN])
                cout << "DOWN ";
            if (keystate[SDL_SCANCODE_LEFT])
                cout << "LEFT ";
            if (keystate[SDL_SCANCODE_RIGHT])
                cout << "RIGHT ";
            cout << endl;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Keyboard state checked" << endl;
}

// ============================================================================
// EXERCISE 9: Moving Rectangle with Keyboard
// ============================================================================
/*
EXERCISE 9: Move rectangle using arrow keys
- Create rectangle in center
- Handle arrow key input
- Update position each frame
- Keep rectangle in bounds
*/

void exercise9()
{
    cout << "\n--- Exercise 9: Moving Rectangle ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Moving Rectangle",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Use arrow keys to move rectangle (3 seconds)..." << endl;

    SDL_Rect player = {175, 135, 50, 30};
    const int SPEED = 5;

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        const Uint8 *keystate = SDL_GetKeyboardState(nullptr);

        // Update position
        if (keystate[SDL_SCANCODE_UP] && player.y > 0)
        {
            player.y -= SPEED;
        }
        if (keystate[SDL_SCANCODE_DOWN] && player.y + player.h < 300)
        {
            player.y += SPEED;
        }
        if (keystate[SDL_SCANCODE_LEFT] && player.x > 0)
        {
            player.x -= SPEED;
        }
        if (keystate[SDL_SCANCODE_RIGHT] && player.x + player.w < 400)
        {
            player.x += SPEED;
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Rectangle movement implemented" << endl;
}

// ============================================================================
// EXERCISE 10: Frame Rate Control
// ============================================================================
/*
EXERCISE 10: Implement frame rate control
- Target 60 FPS
- Measure actual frame time
- Delay to maintain rate
- Display frame statistics
*/

void exercise10()
{
    cout << "\n--- Exercise 10: Frame Rate Control ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Frame Rate",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Frame rate test (running for 3 seconds at 60 FPS target)..." << endl;

    const int TARGET_FPS = 60;
    const int FRAME_DELAY = 1000 / TARGET_FPS;

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();
    int frameCount = 0;

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        Uint32 frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        frameCount++;
        if (frameCount % 60 == 0)
        {
            Uint32 elapsed = SDL_GetTicks() - startTime;
            double actualFPS = (frameCount * 1000.0) / elapsed;
            cout << "Frame " << frameCount << " - Actual FPS: " << actualFPS << endl;
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        // Frame rate control
        int frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    cout << "Total frames rendered: " << frameCount << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Frame rate controlled" << endl;
}

// ============================================================================
// EXERCISE 11: Color Animation
// ============================================================================
/*
EXERCISE 11: Animated color changes
- Cycle through colors
- Use time-based animation
- Display smooth color transitions
- Create pulsing effect
*/

void exercise11()
{
    cout << "\n--- Exercise 11: Color Animation ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Color Animation",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Color animation (3 seconds)..." << endl;

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        Uint32 elapsed = SDL_GetTicks() - startTime;
        int colorCycle = (elapsed / 100) % 6; // Cycle every 100ms through 6 colors

        Uint8 r = 0, g = 0, b = 0;
        switch (colorCycle)
        {
        case 0:
            r = 255;
            break; // Red
        case 1:
            r = 255;
            g = 128;
            break; // Orange
        case 2:
            g = 255;
            break; // Green
        case 3:
            g = 255;
            b = 255;
            break; // Cyan
        case 4:
            b = 255;
            break; // Blue
        case 5:
            r = 255;
            b = 255;
            break; // Magenta
        }

        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect rect = {100, 100, 200, 100};
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Color animation displayed" << endl;
}

// ============================================================================
// EXERCISE 12: Multiple Moving Objects
// ============================================================================
/*
EXERCISE 12: Render and move multiple rectangles
- Create array of rectangles
- Move each with different velocities
- Bounce off edges
- Demonstrate managing multiple objects
*/

void exercise12()
{
    cout << "\n--- Exercise 12: Multiple Moving Objects ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Multiple Objects",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Multiple moving objects (3 seconds)..." << endl;

    // Create objects with position and velocity
    struct Object
    {
        SDL_Rect rect;
        int vx, vy;
        Uint8 r, g, b;
    };

    Object objects[] = {
        {{50, 50, 30, 30}, 3, 2, 255, 0, 0},    // Red
        {{200, 100, 40, 40}, -2, 3, 0, 255, 0}, // Green
        {{300, 200, 25, 25}, 2, -3, 0, 0, 255}  // Blue
    };

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();

    while (running && SDL_GetTicks() - startTime < 3000)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Update objects
        for (int i = 0; i < 3; i++)
        {
            objects[i].rect.x += objects[i].vx;
            objects[i].rect.y += objects[i].vy;

            // Bounce off edges
            if (objects[i].rect.x <= 0 || objects[i].rect.x + objects[i].rect.w >= 400)
            {
                objects[i].vx *= -1;
            }
            if (objects[i].rect.y <= 0 || objects[i].rect.y + objects[i].rect.h >= 300)
            {
                objects[i].vy *= -1;
            }
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 3; i++)
        {
            SDL_SetRenderDrawColor(renderer, objects[i].r, objects[i].g, objects[i].b, 255);
            SDL_RenderFillRect(renderer, &objects[i].rect);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Multiple objects animated" << endl;
}

// ============================================================================
// EXERCISE 13: Simple Game Loop with Collision Detection
// ============================================================================
/*
EXERCISE 13: Complete game loop with player and target
- Control player rectangle with arrow keys
- Target rectangle appears randomly
- Detect collision when player touches target
- Count collisions
- Simple game mechanics
*/

void exercise13()
{
    cout << "\n--- Exercise 13: Game Loop with Collision ---" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;

    SDL_Window *window = SDL_CreateWindow(
        "Simple Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 300,
        SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    cout << "Simple game (move with arrows to hit targets, 5 seconds)..." << endl;

    SDL_Rect player = {175, 250, 50, 30};
    SDL_Rect target = {150, 50, 40, 40};
    const int SPEED = 5;
    int collisions = 0;

    SDL_Event event;
    bool running = true;
    Uint32 startTime = SDL_GetTicks();

    while (running && SDL_GetTicks() - startTime < 5000)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Input
        const Uint8 *keystate = SDL_GetKeyboardState(nullptr);
        if (keystate[SDL_SCANCODE_LEFT] && player.x > 0)
            player.x -= SPEED;
        if (keystate[SDL_SCANCODE_RIGHT] && player.x + player.w < 400)
            player.x += SPEED;
        if (keystate[SDL_SCANCODE_UP] && player.y > 0)
            player.y -= SPEED;
        if (keystate[SDL_SCANCODE_DOWN] && player.y + player.h < 300)
            player.y += SPEED;

        // Collision detection
        if (!(player.x + player.w < target.x || player.x > target.x + target.w ||
              player.y + player.h < target.y || player.y > target.y + target.h))
        {
            collisions++;
            cout << "Hit! Collisions: " << collisions << endl;

            // Move target to random position
            target.x = (SDL_GetTicks() % 360) + 20;
            target.y = ((SDL_GetTicks() / 100) % 260) + 20;
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw player (green)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &player);

        // Draw target (yellow)
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &target);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    cout << "Final score: " << collisions << " collisions" << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "SUCCESS: Simple game with collision detection" << endl;
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "========== SDL Basics Exercises ==========" << endl;

    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    exercise6();
    exercise7();
    exercise8();
    exercise9();
    exercise10();
    exercise11();
    exercise12();
    exercise13();

    cout << "\n========== All Exercises Completed ==========" << endl;

    return 0;
}
