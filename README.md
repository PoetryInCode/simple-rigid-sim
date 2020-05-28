# Simple Physics
This is a largely physics/math based project that was created for a school project. It is a rendering engine built on SDL that can simulate how rigid bodies interact with each other under gravity.

Currently due to time limitations on the project I didn't have enough time to make a full 3D pipeline, so its currently a 2D engine.
# Building
Building this project requires SDL2 to be installed on your computer.

By default the [Makefile](./Makefile) is configured to compile with clang. But can be configured to use another compiler by modifying the value at line 1.

Example:

`CC = clang` => `CC = gcc`

### Project Sources

These were used to learn how to use OpenGL:

https://learnopengl.com/

https://lazyfoo.net/tutorials/OpenGL/index.php

https://www.khronos.org/registry/OpenGL/index_gl.php

https://wiki.libsdl.org/