# SDL_Cmake_Simp

A simple example of a **CMake project setup with SDL2**, demonstrating how to create a basic “Hello World” style application with SDL dependencies configured.

This project shows a minimal CMake workflow with external SDL libraries included manually via a `thirdparty` folder.

---

## Features

- CMake-based build system
- SDL2 integration
- SDL2_image integration
- Simple cross-folder build setup
- Automatic DLL copying after build

---

## Requirements

- CMake (3.16 or higher recommended)
- A C++ compiler (Visual Studio / MSVC recommended on Windows)

---

## How to Use

1. Clone or download this repository:
   ```bash
   git clone <repo-url>
   ```

2. Make sure CMake is installed and available in your PATH.

3. Configure the project:
   ```bash
   cmake -S . -B build
   ```
   - `-S` = source folder  
   - `-B` = build folder  

4. Build the project:
   ```bash
   cmake --build build
   ```

5. Run the executable from the build output folder.

---

## Notes

- This setup uses precompiled SDL2 libraries placed in the `thirdparty/` folder.
- Designed for learning purposes and simple project scaffolding.
- Can be extended to include more SDL modules (SDL_ttf, SDL_mixer, etc.).