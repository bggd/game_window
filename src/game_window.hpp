namespace gwin {

struct GameWindowOptOpenGL {

  bool fullscreen;
  bool resizable;
  bool set_pos;
  int32_t x, y;
  uint32_t w, h;
  uint8_t major;
  uint8_t minor;
  bool gles;
  bool debug_ctx;
  bool vsync;

};

struct GameWindow {

  SDL_Window* win;
  SDL_GLContext glc;

  bool open(const char* title, const GameWindowOptOpenGL& opt);
  void close();

  void make_current();
  void flip();

};

} // namespace gwin
