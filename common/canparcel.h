#ifndef __CANPARCEL_H__
#define __CANPARCEL_H__

class Payload;

class CanParcel
{
public:
	virtual ~CanParcel() {};
	virtual Payload *parcel() = 0;
};

#endif
