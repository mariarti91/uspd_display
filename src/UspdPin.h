#ifndef __USPD_PIN_H__
#define __USPD_PIN_H__

#include <QObject>
#include <QFileInfo>
#include <QFile>

class UspdPin : public QObject
{
	Q_OBJECT
public:
	explicit UspdPin(QObject *parent = 0);
	void initPin(const quint8 port, const quint8 pin);
	void open();
	void close();
	void direction(const QString& d);
	void setValue(quint8 v);

private:
	quint8 pin;
	quint8 state;
	static QString syspath;
	QString pinPath;
};

#endif//__USPD_PIN_H__
