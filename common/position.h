//
// Created by Christopher Sawczuk on 28/03/2015.
//

#ifndef PIPEDREAM_POSITION_H
#define PIPEDREAM_POSITION_H

class Position
{
public:
	Position(int x, int y) : X(x), Y(y)
	{

	}
	~Position(){

	}

	int getX() {
		return X;
	}

	int getY() {
		return Y;
	}

	void setX(int x)
	{
		X = x;
	}

	void setY(int y)
	{
		Y = y;
	}

private:
	int X;
	int Y;
};

#endif //PIPEDREAM_POSITION_H

