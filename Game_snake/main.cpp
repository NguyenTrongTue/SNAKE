#include "snake.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include "SDL_utils.h"
 // đuôi .hpp chỉ dùng cho c++, còn đuôi .h có thể dùng cho cả c và c++
// thuc chat la dung mang hai chieu nhung khong ke o
using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const char WINDOW_TITLE[] = "Snake Game";


SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		if (texture == nullptr){
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP");
	}
	return texture;
}

int main(int argc, char **argv)
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  // chèn ảnh vào vào game

    SDL_Texture *background = loadTexture("images.bmp", renderer);

    if (background == nullptr){ // nếu biến background == nullptr thì giải phóng biến vào thoát  SDL.
        SDL_DestroyTexture(background);

        quitSDL(window, renderer);
    }

    //Xoá màn hình
    SDL_RenderClear(renderer);

    //Vẽ ảnh nền vào toàn bộ cửa sổ
    renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_RenderPresent(renderer);

    waitUntilKeyPressed();

    //Giải phóng 2 biến texture đã dùng
    SDL_DestroyTexture(background);

      try // xác định khối mã SNAKE đã được kiểm tra trong khi nó chạy
      {
        Snake s;
        return s.exec();//bien dieu hanh
      } catch (std::exception &e) // cho phép khối mã sẽ được thực thi nếu có lỗi xảy ra trong khối try.
      {
        std::cerr << e.what() << std::endl;
     return 1;
      }
}
