#ifndef __MY_DISPLAY_H__
#define __MY_DISPLAY_H__

#include <QObject>

class MyDisplay : public QObject
{
	Q_OBJECT
public:
	explicit MyDisplay(QObject *parent = 0);
	void foo();
};

#endif//__MY_DISPLAY_H__
