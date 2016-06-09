#include "UspdPin.h"

#include <QDebug>
#include <QTextStream>

QString UspdPin::syspath = QString("/sys/class/gpio/");

UspdPin::UspdPin(QObject *parent) :
	QObject(parent), pin(0), state(0), pinPath("")
{
}
//------------------------------------------------------------------

void UspdPin::initPin(const quint8 port, const quint8 pin)
{
	this->pin = (port - 1) * 32 + pin;
	pinPath = syspath + QString("gpio%1/").arg(pin);
	state = 0;
}
//------------------------------------------------------------------

void UspdPin::open()
{
	QFileInfo pinFile(pinPath);
	if (!(pinFile.exists() && pinFile.isDir()))
	{
		qDebug() << "Not Exist";
		QFile expFile(QString("%1export").arg(syspath));
		if(expFile.open(QIODevice::WriteOnly))
		{
			qDebug() << "OK";
		}
		QTextStream s(&expFile);
		s << pin;
		expFile.close();
	}
	else
	{
		qDebug() << "Exist";
	}
	state = 1;
}
//------------------------------------------------------------------

void UspdPin::close()
{
	QFileInfo pinFile(pinPath);
	if ((pinFile.exists() && pinFile.isDir()))
	{
		qDebug() << "Exist";
		QFile expFile(QString("%1unexport").arg(syspath));
		expFile.open(QIODevice::WriteOnly);
		QTextStream s(&expFile);
		s << pin;
		expFile.close();
	}
	else
	{
		qDebug() << "Not Exist";
	}
	state = 0;
}
//------------------------------------------------------------------

void UspdPin::direction(const QString& d)
{
	if (state == 0)
		this->open();
	QFile direct(QString("%1direction").arg(pinPath));
	direct.open(QIODevice::WriteOnly);
	QTextStream s(&direct);
	s << d;
	direct.close();
}
//------------------------------------------------------------------

void UspdPin::setValue(quint8 v)
{
	if (state == 0)
		this->direction("out");
	QFile direct(QString("%1value").arg(pinPath));
	direct.open(QIODevice::WriteOnly);
	QTextStream s(&direct);
	s << v;
	direct.close();
}
//------------------------------------------------------------------
