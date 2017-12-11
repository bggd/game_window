namespace gwin { namespace detail {

struct GameWindowSDL2 : GameWindowBase {

  SDL_Window* win = NULL;
  SDL_GLContext glc = NULL;

  bool open(const char* title, const GameWindowOptOpenGL& opt);
  void close();

  GameWindowOptOpenGL get_info();

  void make_current();
  void flip();

};

}} // namespace gwin::detail
