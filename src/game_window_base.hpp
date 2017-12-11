namespace gwin {

struct GameWindowBase {

  virtual bool open(const char* title, const GameWindowOptOpenGL& opt) = 0;
  virtual void close() = 0;

  virtual GameWindowOptOpenGL get_info() = 0;

  virtual void make_current() = 0;
  virtual void flip() = 0;

};

} // namespace gwin
