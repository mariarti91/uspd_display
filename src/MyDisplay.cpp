#include "MyDisplay.h"

#include <QDataStream>
#include <QFile>
#include <QDebug>

MyDisplay::MyDisplay(QObject *parent) : QObject(parent)
{
}
//------------------------------------------------------------

void MyDisplay::foo()
{
	QFile dispFile("/dev/fb0");
	if(!dispFile.open(QIODevice::WriteOnly))
	{
		qDebug() << "NOOOOOOOOOOOOO!!!";
		return;
	}
	QDataStream dispStream(&dispFile);
	for(int i = 0; i < 200; i++)
		dispStream << 0xff;
}
//------------------------------------------------------------
