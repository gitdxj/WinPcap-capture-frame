#ifndef CAPTHREAD_H
#define CAPTHREAD_H

#include <QThread>
#include "packetHeader.h"
#include <pcap.h>
#include <string>

class capThread : public QThread
{
	Q_OBJECT

public:
	explicit capThread(QObject *parent);
	~capThread();
	void run();
	void setPara(pcap_if_t *);
	void set_stop(bool);
	void tcp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void udp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void icmp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void arp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void ip_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void ethernet_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
signals:
	void getPcaket(QString);
private:
	pcap_if_t *d;
	char errbuf[PCAP_ERRBUF_SIZE];
	bool stop;
	char m_captureInfo[1000];
	std::string s_captureInfo;
	
};

//std::string int_to_hex(int i);

#endif // CAPTHREAD_H
