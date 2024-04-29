//
// Created by elias on 28/11/2022.
//

#ifndef MEATBOY_ABSTRACTWINDOW_H
#define MEATBOY_ABSTRACTWINDOW_H

/// pure virtual class voor de window
class AbstractWindow {
public:
	virtual bool isOpen() = 0;
	virtual void display() = 0;
	virtual void clear() = 0;
	virtual void checkEvent(char* keyReleases) = 0;
	virtual void close() = 0;
	virtual void checkKeyboardInput(char* keyPresses) = 0;
	virtual void drawBackground() = 0;
	virtual float getWindowWidth() = 0;
	virtual float getWindowHeight() = 0;
};

#endif // MEATBOY_ABSTRACTWINDOW_H
