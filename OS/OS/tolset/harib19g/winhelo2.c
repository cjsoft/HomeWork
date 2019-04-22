int api_openwin(char *buf, int xsiz, int ysiz, int col_inv, char *title);
void api_putstrwin(int win, int x, int y, int col, int len, char *str);
void api_boxfilwin(int win, int x0, int y0, int x1, int y1, int col);
void api_end(void);

char buf[150 * 50];

void HariMain(void)
{
	int win;
	win = api_openwin(buf, 150, 150, -1, "test");
	api_boxfilwin(win,  8, 24, 142, 142, 3 /* â© */);
	api_putstrwin(win, 28, 28, 0 /* çï */, 12, "test and set");
	api_end();
}
