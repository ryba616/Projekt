#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
	void drawWindow();

private:
	void initWindow();
	void drawBackground();
	void setBackground();

	BITMAP *bg;
};

#endif