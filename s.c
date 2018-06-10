
/*
  static voiddraw_line_params(t_coord *point1, t_coord *point2, double *tab)
  {
  tab[0] = fabs(point1->x - point2->x);//fabs == abs() but double type
  tab[1] = point1->x < point2->x ? 1 : -1;
  tab[2] = fabs(point1->y - point2->y);
  tab[3] = point1->y < point2->y ? 1 : -1;
  tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]);// * 0.5;
  }

  static voiddraw_point(t_coord *point, t_win *win, int color)
  {
  int i;
  i = ((int)point->x * 4) + ((int)point->y * win->size_line);
  win->ptr[i] = color;
  win->ptr[++i] = color >> 8;
  win->ptr[++i] = color >> 16;
  }

  static voiddraw_line(t_coord p1, t_coord p2, t_win *win)
  {
  doubletab[6];
  intstate;

  draw_line_params(&p1, &p2, tab), state = 1;
  while ((state == 1) && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
  {
  if (p1.x >= 0 && p1.x <= WIDTH && p1.y >= 0 && p1.y <= HEIGHT)
  draw_point(&p1, win, 0x0D6386);
  tab[5] = tab[4];
  state = 0;
  if (tab[5] > -tab[0] && (int)p1.x != (int)p2.x)
  {
  tab[4] -= tab[2];
  p1.x += tab[1];
  state = 1;
  }
  if (tab[5] < tab[2] && (int)p1.y != (int)p2.y)
  {
  tab[4] += tab[0];
  p1.y += tab[3];
  state = 1;
  }
  }
  }

  voiddraw_image(t_win *win)
  {
  intx;
  inty;
  t_coordv;

  y = 0;
  while (y < win->lines)
  {
  x = 0;
  while (x < win->chars)
  {
  v = get_coord(win, x, y);
  if (x + 1 < win->chars)
  draw_line(v, get_coord(win, x + 1, y), win);
  if (y + 1 < win->lines)
  draw_line(v, get_coord(win, x, y + 1), win);
  x++;
  }
  y++;
  }
  }
*/
