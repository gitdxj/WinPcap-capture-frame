#include "na_qt_test1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NA_Qt_test1 w;
	w.show();
	return a.exec();
}
//we need to create a thread for the capture
//once the Adapter list is clicked
//we pass the currentline to our capture thread
//the capture thread give the packet information back 
//we show the packet information on CaptureInfo