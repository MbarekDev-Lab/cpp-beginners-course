# Lesson 20: SDL Basics - Comprehensive Guide

## Overview

SDL (Simple DirectMedia Layer) is a cross-platform development library that provides low-level access to audio, keyboard, mouse, and graphics hardware. It's widely used for game development and multimedia applications.

**Key Features:**

- Cross-platform (Windows, macOS, Linux)
- Hardware acceleration support
- Event handling (keyboard, mouse, joystick)
- 2D graphics rendering
- Audio capabilities
- Simple and stable API

**Installation:**

```bash
# macOS (Homebrew)
brew install sdl2

# Ubuntu/Debian
sudo apt-get install libsdl2-dev

# Windows
Download from libsdl.org or use package managers
```

---

## SDL Initialization and Cleanup

### Basic Pattern

```cpp
#include <SDL2/SDL.h>

int main() {
    // 1. Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL init failed: " << SDL_GetError() << endl;
        return 1;
    }

    // 2. Use SDL
    // ... window, rendering, events ...

    // 3. Cleanup
    SDL_Quit();
    return 0;
}
```

### Initialization Subsystems

```c
SDL_Init(SDL_INIT_VIDEO);           // Video/graphics
SDL_Init(SDL_INIT_AUDIO);           // Audio
SDL_Init(SDL_INIT_TIMER);           // Timer
SDL_Init(SDL_INIT_JOYSTICK);        // Joystick
SDL_Init(SDL_INIT_GAMECONTROLLER);  // Game controllers

// Combine with bitwise OR
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK);
```

**Return Value:**

- Returns 0 on success
- Returns negative value on error
- Use `SDL_GetError()` to get detailed error message

---

## Creating Windows and Renderers

### Window Creation

```cpp
SDL_Window* window = SDL_CreateWindow(
    "Window Title",           // Window title
    SDL_WINDOWPOS_CENTERED,   // X position (or specific value like 100)
    SDL_WINDOWPOS_CENTERED,   // Y position (or specific value like 100)
    800,                      // Width in pixels
    600,                      // Height in pixels
    SDL_WINDOW_SHOWN          // Flags (see below)
);

if (window == nullptr) {
    cerr << "Window creation failed: " << SDL_GetError() << endl;
    SDL_Quit();
    return 1;
}

// Get window properties
int w, h;
SDL_GetWindowSize(window, &w, &h);

// Destroy when done
SDL_DestroyWindow(window);
```

### Window Position Constants

```
SDL_WINDOWPOS_UNDEFINED   // Let OS decide position
SDL_WINDOWPOS_CENTERED    // Center on screen
100, 200                  // Specific pixel coordinates
```

### Window Flags

| Flag                            | Effect                           |
| ------------------------------- | -------------------------------- |
| `SDL_WINDOW_SHOWN`              | Window visible                   |
| `SDL_WINDOW_HIDDEN`             | Window hidden initially          |
| `SDL_WINDOW_FULLSCREEN`         | Fullscreen mode                  |
| `SDL_WINDOW_DESKTOP_FULLSCREEN` | Fullscreen at desktop resolution |
| `SDL_WINDOW_WINDOWED`           | Windowed mode                    |
| `SDL_WINDOW_RESIZABLE`          | User can resize window           |
| `SDL_WINDOW_BORDERLESS`         | No title bar or borders          |
| `SDL_WINDOW_ALWAYS_ON_TOP`      | Always on top of other windows   |

### Renderer Creation

```cpp
SDL_Renderer* renderer = SDL_CreateRenderer(
    window,                              // Target window
    -1,                                  // Driver index (-1 = auto)
    SDL_RENDERER_ACCELERATED |           // Flags
    SDL_RENDERER_PRESENTVSYNC
);

if (renderer == nullptr) {
    cerr << "Renderer creation failed" << endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}

// Destroy when done
SDL_DestroyRenderer(renderer);
```

### Renderer Flags

| Flag                         | Effect                                  |
| ---------------------------- | --------------------------------------- |
| `SDL_RENDERER_SOFTWARE`      | Software rendering (slow, always works) |
| `SDL_RENDERER_ACCELERATED`   | Hardware acceleration (faster)          |
| `SDL_RENDERER_PRESENTVSYNC`  | Synchronize with monitor refresh        |
| `SDL_RENDERER_TARGETTEXTURE` | Can render to texture                   |

---

## Drawing Primitives

### Colors

Colors in SDL use RGBA format (0-255 each):

```cpp
// Set drawing color (before drawing)
SDL_SetRenderDrawColor(renderer, RED, GREEN, BLUE, ALPHA);

// Common colors
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);        // Black
SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White
SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);      // Red
SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);      // Green
SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);      // Blue
SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);    // Yellow
```

### Rectangles

```cpp
// Define rectangle
SDL_Rect rect = {100, 50, 200, 150};  // x, y, width, height

// Draw filled rectangle
SDL_RenderFillRect(renderer, &rect);

// Draw rectangle outline
SDL_RenderDrawRect(renderer, &rect);

// Fill entire screen
SDL_RenderFillRect(renderer, nullptr);  // nullptr fills entire screen
```

### Lines and Points

```cpp
// Draw line from (x1,y1) to (x2,y2)
SDL_RenderDrawLine(renderer, 10, 10, 100, 100);

// Draw single pixel
SDL_RenderDrawPoint(renderer, 50, 50);

// Draw multiple points
SDL_Point points[] = {{10, 10}, {20, 20}, {30, 30}};
SDL_RenderDrawPoints(renderer, points, 3);

// Draw connected lines
SDL_RenderDrawLines(renderer, points, 3);
```

---

## Rendering Workflow

### Standard Game Render Loop

```cpp
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;  // 16ms per frame

bool running = true;
while (running) {
    Uint32 frameStart = SDL_GetTicks();

    // 1. CLEAR: Clear screen with background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);

    // 2. DRAW: Draw all objects
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &playerRect);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &enemyRect);

    // 3. PRESENT: Show the frame
    SDL_RenderPresent(renderer);

    // 4. DELAY: Cap frame rate
    int frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < FRAME_DELAY) {
        SDL_Delay(FRAME_DELAY - frameTime);
    }
}
```

**Important Order:**

1. `SDL_RenderClear()` - Clear previous frame
2. Draw all graphics
3. `SDL_RenderPresent()` - Show current frame

---

## Event Handling

### SDL_Event Union

```cpp
SDL_Event event;

// Option 1: Poll events (non-blocking)
while (SDL_PollEvent(&event)) {
    // Process event
}

// Option 2: Wait for event (blocking)
SDL_WaitEvent(&event);

// Option 3: Check event in queue
if (SDL_PollEvent(&event) == 1) {
    // Event received
}
```

### Common Event Types

| Event                 | Struct Member   | Info                    |
| --------------------- | --------------- | ----------------------- |
| `SDL_QUIT`            | `event.quit`    | Window close button     |
| `SDL_KEYDOWN`         | `event.key`     | Keyboard key pressed    |
| `SDL_KEYUP`           | `event.key`     | Keyboard key released   |
| `SDL_MOUSEMOTION`     | `event.motion`  | Mouse moved             |
| `SDL_MOUSEBUTTONDOWN` | `event.button`  | Mouse button pressed    |
| `SDL_MOUSEBUTTONUP`   | `event.button`  | Mouse button released   |
| `SDL_MOUSEWHEEL`      | `event.wheel`   | Mouse wheel scrolled    |
| `SDL_JOYAXISMOTION`   | `event.jaxis`   | Joystick axismotion     |
| `SDL_JOYBUTTONDOWN`   | `event.jbutton` | Joystick button pressed |

### Keyboard Event Handling

```cpp
SDL_Event event;
while (SDL_PollEvent(&event)) {
    if (event.type == SDL_KEYDOWN) {
        SDL_Keysym keysym = event.key.keysym;

        // Get key name (for display)
        const char* keyname = SDL_GetKeyName(keysym.sym);

        // Check specific keys
        if (keysym.sym == SDLK_ESCAPE) {
            // Escape pressed
        }
        if (keysym.sym == SDLK_SPACE) {
            // Space pressed
        }
    }
}
```

### Keyboard Scancodes

For game input, use scancodes (ignore keyboard layout):

```cpp
const Uint8* keystate = SDL_GetKeyboardState(nullptr);

if (keystate[SDL_SCANCODE_UP]) {
    // Up arrow pressed
}
if (keystate[SDL_SCANCODE_W]) {
    // W key pressed
}
if (keystate[SDL_SCANCODE_SPACE]) {
    // Space pressed
}

// Combine for diagonal movement
if (keystate[SDL_SCANCODE_UP] && keystate[SDL_SCANCODE_LEFT]) {
    // Moving up-left
}
```

### Mouse Event Handling

```cpp
if (event.type == SDL_MOUSEMOTION) {
    int x = event.motion.x;
    int y = event.motion.y;
}

if (event.type == SDL_MOUSEBUTTONDOWN) {
    Uint8 button = event.button.button;
    if (button == SDL_BUTTON_LEFT) {
        // Left click
    }
    if (button == SDL_BUTTON_RIGHT) {
        // Right click
    }
}
```

---

## Timing and Frame Rate Control

### Getting Current Time

```cpp
// Get milliseconds since SDL_Init()
Uint32 ticks = SDL_GetTicks();

// 64-bit version (safer for long-running apps)
Uint64 ticks64 = SDL_GetTicks64();
```

### Measuring Elapsed Time

```cpp
Uint32 startTime = SDL_GetTicks();

// Do something...

Uint32 elapsedTime = SDL_GetTicks() - startTime;
cout << "Operation took " << elapsedTime << " ms" << endl;
```

### Frame Rate Control

```cpp
const int TARGET_FPS = 60;
const int FRAME_TIME = 1000 / TARGET_FPS;  // 16ms

Uint32 frameStart = SDL_GetTicks();

// Render frame...

int frameTime = SDL_GetTicks() - frameStart;
int delayTime = FRAME_TIME - frameTime;

if (delayTime > 0) {
    SDL_Delay(delayTime);  // Sleep to maintain 60 FPS
}
```

### Measuring Actual FPS

```cpp
int frameCount = 0;
Uint32 lastCheck = SDL_GetTicks();

while (running) {
    // Render frame...

    frameCount++;

    if (SDL_GetTicks() - lastCheck >= 1000) {
        cout << "FPS: " << frameCount << endl;
        frameCount = 0;
        lastCheck = SDL_GetTicks();
    }
}
```

---

## Complete Game Loop Structure

### Basic Template

```cpp
int main() {
    // INIT
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    // GAME LOOP
    bool running = true;
    while (running) {
        // 1. HANDLE EVENTS
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // 2. UPDATE GAME STATE
        // Update positions, check collisions, etc.

        // 3. RENDER
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw all objects

        SDL_RenderPresent(renderer);
    }

    // CLEANUP
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
```

---

## Common Patterns and Techniques

### 1. Game Object Class

```cpp
class GameObject {
public:
    SDL_Rect rect;
    int velocityX, velocityY;

    void update() {
        rect.x += velocityX;
        rect.y += velocityY;
    }

    void render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};
```

### 2. Frame Rate Independent Movement

```cpp
// Instead of: sprite.x += 5;
// Use: sprite.x += 100 * deltaTime;  // 100 pixels per second

Uint32 lastTime = SDL_GetTicks();

while (running) {
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    // Update with delta time
    sprite.x += velocity * deltaTime;
}
```

### 3. Input State Management

```cpp
struct InputState {
    bool up, down, left, right;
    bool fire;
};

InputState updateInput() {
    InputState input = {false, false, false, false, false};
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    input.up = keystate[SDL_SCANCODE_UP];
    input.down = keystate[SDL_SCANCODE_DOWN];
    input.left = keystate[SDL_SCANCODE_LEFT];
    input.right = keystate[SDL_SCANCODE_RIGHT];
    input.fire = keystate[SDL_SCANCODE_SPACE];

    return input;
}
```

### 4. Simple Collision Detection

```cpp
bool checkCollision(SDL_Rect a, SDL_Rect b) {
    return !(a.x + a.w < b.x || a.x > b.x + b.w ||
             a.y + a.h < b.y || a.y > b.y + b.h);
}

// Usage
if (checkCollision(playerRect, enemyRect)) {
    // Handle collision
}
```

---

## Error Handling Best Practices

### Always Check Return Values

```cpp
// ✓ Good: Check for failure
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "SDL init failed: " << SDL_GetError() << endl;
    return 1;
}

SDL_Window* window = SDL_CreateWindow(...);
if (window == nullptr) {
    cerr << "Window creation failed: " << SDL_GetError() << endl;
    SDL_Quit();
    return 1;
}

SDL_Renderer* renderer = SDL_CreateRenderer(...);
if (renderer == nullptr) {
    cerr << "Renderer creation failed: " << SDL_GetError() << endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}
```

### Proper Cleanup

```cpp
// Always cleanup in reverse order of creation
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
```

---

## Performance Tips

1. **Use SDL_RENDERER_ACCELERATED** for hardware acceleration
2. **Use SDL_RENDERER_PRESENTVSYNC** to sync with monitor (prevents tearing)
3. **Clear once per frame** with `SDL_RenderClear()`
4. **Present once per frame** with `SDL_RenderPresent()`
5. **Use double-buffering** (automatic with renderer)
6. **Minimize state changes** (color, texture, etc.)
7. **Cache SDL objects** (don't recreate each frame)
8. **Use scancode input** for games (faster than keysym)

---

## Summary

**SDL Workflow:**

1. Initialize with `SDL_Init()`
2. Create window with `SDL_CreateWindow()`
3. Create renderer with `SDL_CreateRenderer()`
4. Main loop:
   - Handle events with `SDL_PollEvent()`
   - Update game state
   - Clear screen with `SDL_RenderClear()`
   - Draw objects
   - Present with `SDL_RenderPresent()`
5. Cleanup with `SDL_DestroyRenderer()`, `SDL_DestroyWindow()`, `SDL_Quit()`

**Key Points:**

- SDL is event-driven (non-blocking event polling recommended)
- Always check return values for NULL/error conditions
- Use scancodes for consistent game input
- Control frame rate for consistent gameplay
- Render in correct order: clear → draw → present
