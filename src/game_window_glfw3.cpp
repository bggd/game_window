namespace gwin { namespace detail {

bool GameWindowGLFW3::open(const char* title, const GameWindowOptionOpenGL& opt)
{
  if (glfwInit() == GLFW_FALSE) { return false; }

  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, opt.debug_ctx ? GLFW_TRUE : GLFW_FALSE);
  glfwWindowHint(GLFW_CLIENT_API, opt.gles ? GLFW_OPENGL_ES_API : GLFW_OPENGL_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opt.major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opt.minor);

  glfwWindowHint(GLFW_RESIZABLE, opt.resizable ? GLFW_TRUE : GLFW_FALSE);

  this->win = glfwCreateWindow(opt.w, opt.h, title, NULL, NULL);

  if (this->win == NULL) { return false; }

  this->make_current();

  if (opt.vsync) { glfwSwapInterval(1); }

  if (opt.set_pos) { glfwSetWindowPos(this->win, opt.x, opt.y); }

  return true;
}

void GameWindowGLFW3::close()
{
  if (this->win) {
    glfwDestroyWindow(this->win);
    this->win = NULL;
  }
}

GameWindowOptionOpenGL GameWindowGLFW3::get_info()
{
  GameWindowOptionOpenGL info;

  info.resizable = glfwGetWindowAttrib(this->win, GLFW_RESIZABLE);
  int32_t x, y;
  glfwGetWindowPos(this->win, &x, &y);
  info.x = x;
  info.y = y;
  glfwGetWindowSize(this->win, &x, &y);
  info.w = x;
  info.h = y;
  info.gles = (glfwGetWindowAttrib(this->win, GLFW_CLIENT_API) == GLFW_OPENGL_ES_API);
  info.major = glfwGetWindowAttrib(this->win, GLFW_CONTEXT_VERSION_MAJOR);
  info.minor = glfwGetWindowAttrib(this->win, GLFW_CONTEXT_VERSION_MINOR);
  info.debug_ctx = glfwGetWindowAttrib(this->win, GLFW_OPENGL_DEBUG_CONTEXT);


  return info;
}

void GameWindowGLFW3::make_current()
{
  glfwMakeContextCurrent(this->win);
}

void GameWindowGLFW3::flip()
{
  glfwSwapBuffers(this->win);
}

}} // namespace gwin::detail
