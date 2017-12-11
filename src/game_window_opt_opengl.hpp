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

} // namespace gwin
