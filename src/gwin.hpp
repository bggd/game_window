#pragma once

#include "game_window_opt_opengl.hpp"
#include "game_window_base.hpp"

#ifdef GAME_WINDOW_SDL2
#include "game_window_sdl2.hpp"
namespace gwin {
using GameWindow = detail::GameWindowSDL2;
}
#ifdef GAME_WINDOW_IMPLEMENTATION
#include "game_window_sdl2.cpp"
#endif
#endif

#ifdef GAME_WINDOW_GLFW3
#include "game_window_glfw3.hpp"
namespace gwin {
using GameWindow = detail::GameWindowGLFW3;
}
#ifdef GAME_WINDOW_IMPLEMENTATION
#include "game_window_glfw3.cpp"
#endif
#endif
