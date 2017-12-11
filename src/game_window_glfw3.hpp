namespace gwin { namespace detail {

struct GameWindowGLFW3 : GameWindowBase {

  GLFWwindow* win = NULL;

  bool open(const char* title, const GameWindowOptOpenGL& opt) override;
  void close() override;

  GameWindowOptOpenGL get_info() override;

  void make_current() override;
  void flip() override;

};

}} // namespace gwin::detail
