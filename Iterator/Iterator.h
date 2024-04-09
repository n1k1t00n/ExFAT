#pragma once
template <class Type> class Iterator
{
protected:
	Iterator() {};
	Iterator(unsigned int) {}
public:
	virtual ~Iterator() {};
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Type GetCurrent() = 0;
};