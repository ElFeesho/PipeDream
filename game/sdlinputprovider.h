//
// Created by Christopher Sawczuk on 02/04/2015.
//

#ifndef PIPEDREAM_SDLINPUTPROVIDER_H
#define PIPEDREAM_SDLINPUTPROVIDER_H

#include "../common/inputprovider.h"

class SDLInputProvider : public InputProvider
{
public:
	SDLInputProvider();
	~SDLInputProvider();

	virtual void addUpPressHandler(buttonPressHandler handler) override;

	virtual void addDownPressHandler(buttonPressHandler handler) override;

	virtual void addLeftPressHandler(buttonPressHandler handler) override;

	virtual void addRightPressHandler(buttonPressHandler handler) override;

	virtual void addAttackPressHandler(buttonPressHandler handler) override;

	virtual void addInventoryPressHandler(buttonPressHandler handler) override;

	virtual void addActionPressHandler(buttonPressHandler handler) override;

	virtual void addItemPressHandler(buttonPressHandler handler) override;

	virtual void addUpReleaseHandler(buttonPressHandler handler) override;

	virtual void addDownReleaseHandler(buttonPressHandler handler) override;

	virtual void addLeftReleaseHandler(buttonPressHandler handler) override;

	virtual void addRightReleaseHandler(buttonPressHandler handler) override;

	virtual void addAttackReleaseHandler(buttonPressHandler handler) override;

	virtual void addInventoryReleaseHandler(buttonPressHandler handler) override;

	virtual void addActionReleaseHandler(buttonPressHandler handler) override;

	virtual void addItemReleaseHandler(buttonPressHandler handler) override;

	virtual void update() override;
private:
	buttonPressHandler upPressHandler;
	buttonPressHandler downPressHandler;
	buttonPressHandler leftPressHandler;
	buttonPressHandler rightPressHandler;
	buttonPressHandler attackPressHandler;
	buttonPressHandler inventoryPressHandler;
	buttonPressHandler actionPressHandler;
	buttonPressHandler itemPressHandler;

	buttonPressHandler upReleaseHandler;
	buttonPressHandler downReleaseHandler;
	buttonPressHandler leftReleaseHandler;
	buttonPressHandler rightReleaseHandler;
	buttonPressHandler attackReleaseHandler;
	buttonPressHandler inventoryReleaseHandler;
	buttonPressHandler actionReleaseHandler;
	buttonPressHandler itemReleaseHandler;
};

#endif //PIPEDREAM_SDLINPUTPROVIDER_H
