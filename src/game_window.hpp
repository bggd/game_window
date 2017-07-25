namespace gwin {

struct GameWindowOptOpenGL {

  bool fullscreen;
  bool resizable;
  bool set_pos;
  int32_t x, y;
  uint32_t w, h;
  bool gles;
  uint8_t major;
  uint8_t minor;
  bool debug_ctx;
  bool vsync;

};

struct GameWindow {

  SDL_Window* win = NULL;
  SDL_GLContext glc = NULL;

  bool open(const char* title, const GameWindowOptOpenGL& opt);
  void close();

  void make_current();
  void flip();

};

} // namespace gwin
