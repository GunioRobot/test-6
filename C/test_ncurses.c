#include <ncurses.h>

int main()
{
  initscr();
  printw("Hola mundo");
  getch();
  erase();
  
  printw("Escribe dos numeros para que sean sumados: ");
  int a;
  scanw("%d", &a);
  int b;
  scanw("%d", &b);
  int c = a + b;
  printw("El resultado de la suma es: %d\n", c);
  getch();

  endwin();
  return 0;
}
