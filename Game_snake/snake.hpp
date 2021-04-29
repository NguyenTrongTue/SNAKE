#include <SDL.h>
#include <deque>

// đưa toàn bộ phần xử lí rắn vào lớp, khởi tạo cửa sổ chơi.
// thuc chat la tro choi su dung linked_list va class
class Snake
{
public:
    Snake();
    ~Snake();
    int exec(); // ham dieu hanh chuong trinh
    bool tick(); // ham danh dau vi cac vi cua ran di qua
    void draw(); // ham ve
    static const auto HeadOpenMouth = 0;// phan ran ha mieng
    static const auto Tail = 1; // phan duoi
    static const auto Turn = 2;//phan ran re
    static const auto Straight = 3;//phan than thang
    static const auto Head = 4;//phan dau
    static const auto Fruit = 5;//moi ran
    const static auto Width = 1280; // chieu rong cua game
    const static auto Height = 640; // chieu dai cua gam
private: // khong the truy cap tu ngoai lop.
  SDL_Window *window; // khoi tao cua so choi game
  SDL_Renderer *renderer; // khoi tao but ve
  SDL_Texture *sprites; // khoi tao bien hinh anh
  // khoi tao danh sach phan doan cua phan ran
  std::deque<std::pair<int, int> > segmentsList; // luu danh sach phan doan cua ran nhu mot mang vao deque
  unsigned ticks = 0; // khoi tao bien danh dau cua cac doan ran
  int dx = 1;
  int dy = 0;
  int fruitX;//toa do x cua cherry
  int fruitY;//toa do y cua cherry
  void generateFruit(); // ham tao cherry
};


