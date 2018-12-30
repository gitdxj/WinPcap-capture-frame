#include "na_qt_test1.h"
#include<string>

NA_Qt_test1::NA_Qt_test1(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);
	
	//create capture thread
	m_capThread = new capThread(this);

	//when a packet received, show packet information on CaptureInfo
	connect(m_capThread, &capThread::getPcaket, this, &NA_Qt_test1::ongetPcaket);

	//show all the devices in AdapterList
	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &(this->alldevs), errbuf) == -1)
		exit(1);
	pcap_if_t *d;
	int i = 1;
	for(d=alldevs; d; d=d->next)
    {
		if(d->name)
		{
			std::string dev_name = d->name;
			QString Qdev_name = QString::fromStdString(dev_name);
			QListWidgetItem *item = new QListWidgetItem;
			item->setText(Qdev_name);
			this->AdapterList->addItem(item);
		}
	}
}

NA_Qt_test1::~NA_Qt_test1()
{

}

void NA_Qt_test1::on_AdapterList_clicked(const QModelIndex &index)
{
	//if the former thread is running then stop it
	if(m_capThread->isRunning())
		m_capThread->terminate();

	//clear the AdapterInfo and CaptureInfo
	this->AdapterInfo->clear();
	this->CaptureInfo->clear();

	//get # of the selected line 
	int currentLine = this->AdapterList->currentRow();

	//let d point to the selected device
	pcap_if_t *d;
	int i;
	for(i = 0, d = this->alldevs; i < currentLine; i++, d = d->next);

	//get description of d and show it in AdapterInfo
	std::string desc = ifprint(d);
	QString qdesc = QString::fromStdString(desc);
	this->AdapterInfo->setText(qdesc);

	m_capThread->setPara(d);
	m_capThread->start();
}

void NA_Qt_test1::on_startButton_clicked()
{
	this->m_capThread->set_stop(false);
}

void NA_Qt_test1::on_stopButton_clicked()
{
	this->m_capThread->set_stop(true);
}

void NA_Qt_test1::ongetPcaket(QString capInfo)
{
	this->CaptureInfo->insertPlainText(capInfo);
}

#define IPTOSBUFFERS    12
char *iptos(u_long in)
{
    static char output[IPTOSBUFFERS][3*4+3+1];
    static short which;
    u_char *p;

    p = (u_char *)&in;
    which = (which + 1 == IPTOSBUFFERS ? 0 : which + 1);
    _snprintf_s(output[which], sizeof(output[which]), sizeof(output[which]),"%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
    return output[which];
}

/* Print all the available information on the given interface */
std::string ifprint(pcap_if_t *d)
{
  pcap_addr_t *a;

  std::string adapterInfo;

  /* Name */
  //printf("%s\n",d->name);
  std::string name = d->name;
  adapterInfo = adapterInfo + name + "\n";

  /* Description */
  if (d->description)
    //printf("\tDescription: %s\n",d->description);
  {
	  std::string description = d->description;
	  adapterInfo = adapterInfo + "Description: " + description + "\n";
  }

  /* Loopback Address*/
  //printf("\tLoopback: %s\n",(d->flags & PCAP_IF_LOOPBACK)?"yes":"no");

  /* IP addresses */
  std::string addr;
  for(a=d->addresses;a;a=a->next) {
    //printf("\tAddress Family: #%d\n",a->addr->sa_family);
	//addr = addr + "\tAddress Family: ";
    switch(a->addr->sa_family)
    {
      case AF_INET:
        //printf("\tAddress Family Name: AF_INET\n");
		addr = addr + "\tAddress Family Name: AF_INET\n";
        if (a->addr)
          //printf("\tAddress: %s\n",iptos(((struct sockaddr_in *)a->addr)->sin_addr.s_addr));
		{
			std::string address = iptos(((struct sockaddr_in *)a->addr)->sin_addr.s_addr);
			addr = addr + "\tAddress: " + address + "\n";
		}
        if (a->netmask)
          //printf("\tNetmask: %s\n",iptos(((struct sockaddr_in *)a->netmask)->sin_addr.s_addr));
		{
			std::string netmask = iptos(((struct sockaddr_in *)a->netmask)->sin_addr.s_addr);
			addr = addr + "\tNetmask: " + netmask + "\n";
		}
        if (a->broadaddr)
          //printf("\tBroadcast Address: %s\n",iptos(((struct sockaddr_in *)a->broadaddr)->sin_addr.s_addr));
		{
			std::string broadaddr = iptos(((struct sockaddr_in *)a->broadaddr)->sin_addr.s_addr);
			addr = addr + "\tBroadcast Address: " + broadaddr + "\n";
		}
        if (a->dstaddr)
          //printf("\tDestination Address: %s\n",iptos(((struct sockaddr_in *)a->dstaddr)->sin_addr.s_addr));
		{
			std::string dstaddr = iptos(((struct sockaddr_in *)a->dstaddr)->sin_addr.s_addr);
			addr = addr + "\tDestination Address: " + dstaddr + "\n";
		}
        break;
    }
  }
  adapterInfo = adapterInfo + addr + "\n";
  return adapterInfo;
}