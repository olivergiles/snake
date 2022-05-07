#include <iostream>
#include <ncurses.h>
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup()
{
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = std::rand() % width;
  fruitY = std::rand() % height;
  score = 0;
}
void Draw()
{
  std::system("clear");
  for (int i = 0; i < width + 1; i++)
    std::cout << "#";
  std::cout << std::endl;

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (j == 0)
        std::cout << "#";
      if (i == y && j == x)
        std::cout << "O";
      else if (i == fruitY && j == fruitX)
        std::cout << "F";
      else
        std::cout << " ";
      if (j == width - 1)
        std::cout << "#";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < width + 1; i++)
    std::cout << "#";
  std::cout << std::endl;
}
void Input()
{
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    if (true) {
      switch (getch())
      {
        case 'a':
          dir = LEFT;
          break;
        case 'd':
          dir = RIGHT;
          break;
        case 'w':
          dir = UP;
          break;
        case 's':
          dir = DOWN;
          break;
        case 'x':
          gameOver = true;
          break;
      }
    }
}
void Logic()
{
  switch (dir)
  {
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
    case UP:
      y++;
      break;
    case DOWN:
      y--;
      break;
    default:
      break;
  }
}
int main()
{
  Setup();
  while (!gameOver)
  {
    Draw();
    Input();
    Logic();
  }
}
