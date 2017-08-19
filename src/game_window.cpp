namespace gwin {

bool GameWindow::open(const char* title, const GameWindowOptOpenGL& opt)
{
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, opt.debug_ctx ? SDL_GL_CONTEXT_DEBUG_FLAG : 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, opt.gles ? SDL_GL_CONTEXT_PROFILE_ES : SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, opt.major);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, opt.minor);

  uint32_t flags = SDL_WINDOW_OPENGL;
  if (opt.fullscreen) { flags |= SDL_WINDOW_FULLSCREEN_DESKTOP; }
  if (opt.resizable) { flags |= SDL_WINDOW_RESIZABLE; }
 
  this->win = SDL_CreateWindow(
      title,
      opt.set_pos ? opt.x : SDL_WINDOWPOS_UNDEFINED,
      opt.set_pos ? opt.y : SDL_WINDOWPOS_UNDEFINED,
      opt.w, opt.h,
      flags
  );

  if (this->win == NULL) { return false; }

  this->glc = SDL_GL_CreateContext(this->win);
  if (this->glc == NULL) {
    this->close();
    return false;
  }

  this->make_current();

  if (opt.vsync) {
    if (SDL_GL_SetSwapInterval(-1) < 0) { SDL_GL_SetSwapInterval(1); }
  }

  return true;
}

void GameWindow::close()
{
  if (this->glc) {
    SDL_GL_DeleteContext(this->glc);
    this->glc = NULL;
  }
  if (this->win) {
    SDL_DestroyWindow(this->win);
    this->win = NULL;
  }
}

GameWindowOptOpenGL GameWindow::get_info()
{
  GameWindowOptOpenGL info;

  info.fullscreen = SDL_GetWindowFlags(this->win) | SDL_WINDOW_FULLSCREEN_DESKTOP;
  info.resizable = SDL_GetWindowFlags(this->win) | SDL_WINDOW_RESIZABLE;
  info.set_pos = false;
  int32_t x, y;
  SDL_GetWindowPosition(this->win, &x, &y);
  info.x = x;
  info.y = y;
  SDL_GetWindowSize(this->win, &x, &y);
  info.w = x;
  info.h = y;
  int32_t v;
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, &v);
  info.gles = v | SDL_GL_CONTEXT_PROFILE_ES;
  int32_t major, minor;
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &major);
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &minor);
  info.major = major;
  info.minor = minor;
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_FLAGS, &v);
  info.debug_ctx = v | SDL_GL_CONTEXT_DEBUG_FLAG;
  info.vsync = SDL_GL_GetSwapInterval() == 1;

  return info;
}

void GameWindow::make_current()
{
  SDL_GL_MakeCurrent(this->win, this->glc);
}

void GameWindow::flip()
{
  SDL_GL_SwapWindow(this->win);
}

} // namespace gwin
