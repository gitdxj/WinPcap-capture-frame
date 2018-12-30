#ifndef NA_QT_TEST1_H
#define NA_QT_TEST1_H

#include <QtWidgets/QMainWindow>
#include "ui_na_qt_test1.h"
#include "capthread.h"
#include  <pcap.h>

class NA_Qt_test1 : public QMainWindow, private Ui_NA_Qt_test1Class
{
	Q_OBJECT

public:
	NA_Qt_test1(QWidget *parent = 0);
	~NA_Qt_test1();

public slots:
	void on_AdapterList_clicked(const QModelIndex &index);
	void on_startButton_clicked();
	void on_stopButton_clicked();
	void ongetPcaket(QString);
private:
	//Ui::NA_Qt_test1Class ui;
	capThread *m_capThread;
	pcap_if_t *alldevs;
	char errbuf[PCAP_ERRBUF_SIZE];
};

std::string ifprint(pcap_if_t *d);
char *iptos(u_long in);

#endif // NA_QT_TEST1_H
