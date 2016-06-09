#include <QCoreApplication>
#include "UspdPin.h"
#include "MyDisplay.h"

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);
	MyDisplay disp;
	disp.foo();
	return app.exec();
}
