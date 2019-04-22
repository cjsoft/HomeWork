int api_openwin(char *buf, int xsiz, int ysiz, int col_inv, char *title);
void api_boxfilwin(int win, int x0, int y0, int x1, int y1, int col);
void api_initmalloc(void);
char *api_malloc(int size);
void api_point(int win, int x, int y, int col);
void api_end(void);

void HariMain(void)
{
	char *buf;
	int win, y, x;
	api_initmalloc();
	buf = api_malloc(150 * 100);
	win = api_openwin(buf, 150, 100, -1, "star1");
	api_boxfilwin(win,  6, 26, 143, 93, 0 /* çï */);
	for (y = 26; y <= 93; y += 2) {
        for (x = 6; x <= 143; x += 2) {
            api_point(win, x, y, 3);
        }
    }
	api_end();
}
