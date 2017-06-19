namespace gwin {

bool GameWindow::open(const char* title, const GameWindowOptOpenGL& opt)
{
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, opt.debug_ctx ? SDL_GL_CONTEXT_DEBUG_FLAG : 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
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
    this->glc = nullptr;
  }
  if (this->win) {
    SDL_DestroyWindow(this->win);
    this->win = nullptr;
  }
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
