//
// Created by Christopher Sawczuk on 02/04/2015.
//

#ifndef PIPEDREAM_INPUTPROVIDER_H
#define PIPEDREAM_INPUTPROVIDER_H

#include <functional>

typedef std::function<void()> buttonPressHandler;
typedef std::function<void()> buttonReleaseHandler;

class InputProvider
{
public:
	virtual ~InputProvider() {}

	virtual void addUpPressHandler(buttonPressHandler handler) = 0;
	virtual void addDownPressHandler(buttonPressHandler handler) = 0;
	virtual void addLeftPressHandler(buttonPressHandler handler) = 0;
	virtual void addRightPressHandler(buttonPressHandler handler) = 0;
	virtual void addAttackPressHandler(buttonPressHandler handler) = 0;
	virtual void addInventoryPressHandler(buttonPressHandler handler) = 0;
	virtual void addActionPressHandler(buttonPressHandler handler) = 0;
	virtual void addItemPressHandler(buttonPressHandler handler) = 0;

	virtual void addUpReleaseHandler(buttonPressHandler handler) = 0;
	virtual void addDownReleaseHandler(buttonPressHandler handler) = 0;
	virtual void addLeftReleaseHandler(buttonPressHandler handler) = 0;
	virtual void addRightReleaseHandler(buttonPressHandler handler) = 0;
	virtual void addAttackReleaseHandler(buttonPressHandler handler) = 0;
	virtual void addInventoryReleaseHandler(buttonPressHandler handler) = 0;
	virtual void addActionReleaseHandler(buttonPressHandler handler) = 0;
	virtual void addItemReleaseHandler(buttonPressHandler handler) = 0;

	virtual void update() = 0;
};

#endif //PIPEDREAM_INPUTPROVIDER_H
