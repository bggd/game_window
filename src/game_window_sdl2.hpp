namespace gwin { namespace detail {

struct GameWindowSDL2 : GameWindowBase {

  SDL_Window* win = NULL;
  SDL_GLContext glc = NULL;

  bool open(const char* title, const GameWindowOptionOpenGL& opt) override;
  void close() override;

  GameWindowOptionOpenGL get_info() override;

  void make_current() override;
  void flip() override;

};

}} // namespace gwin::detail
