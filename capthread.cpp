#include "capthread.h"

capThread::capThread(QObject *parent)
	: QThread(parent)
{
	stop = true;
}

capThread::~capThread()
{

}

void capThread::setPara(pcap_if_t *d)
{
	this->d = d;
}

void capThread::set_stop(bool stop)
{
	this->stop = stop;
}

////convert int to hex
//std::string int_to_hex(int i)
//{
//	std::stringstream stream;
//	stream << std::hex << i;
//	std::string result( stream.str() );
//	return result;
//}



void capThread::run()
{
	pcap_t *adhandle;
	if ( (adhandle= pcap_open(this->d->name,          // name of the device
                              65536,            // portion of the packet to capture. 
                                                // 65536 guarantees that the whole packet will be captured on all the link layers
                              PCAP_OPENFLAG_PROMISCUOUS,    // promiscuous mode
                              1000,             // read timeout
                              NULL,             // authentication on the remote machine
                              errbuf            // error buffer
                              ) ) == NULL)
	{
		exit(1);
	}
	int res;
	struct pcap_pkthdr *header;
	const u_char *pkt_data;
	time_t local_tv_sec;
	struct tm ltime;
	char timestr[16];
	
	//capture begins
	while((res = pcap_next_ex( adhandle, &header, &pkt_data)) >= 0)
	{
		if(this->stop)
			continue;

        if(res == 0)
            /* Timeout elapsed */
            continue;
        

		/* convert the timestamp to readable format */
        local_tv_sec = header->ts.tv_sec;
        localtime_s(&ltime, &local_tv_sec);
        strftime( timestr, sizeof timestr, "%H:%M:%S", &ltime);

		//tranfer capinfo to QString
		std::string time = timestr;
		QString capInfo = QString::fromStdString(time);
		QString Qtv_usec = QString::number(header->ts.tv_usec);
		QString Qlen = QString::number(header->len);
		capInfo = capInfo + "  " + Qtv_usec + "  " + Qlen + "\n";

		//emit this->getPcaket(capInfo);

		ethernet_protocol_packet_callback(NULL, header, pkt_data);

}
}

/*  
=======================================================================================================================  
�����Ƿ���TCPЭ��ĺ���,�䶨�巽ʽ��ص�������ͬ  
=======================================================================================================================  
 */   
void capThread::tcp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    struct tcp_header *tcp_protocol;   
    /* TCPЭ����� */   
    u_char flags;   
    /* ��� */   
    int header_length;   
    /* ���� */   
    u_short source_port;   
    /* Դ�˿� */   
    u_short destination_port;   
    /* Ŀ�Ķ˿� */   
    u_short windows;   
    /* ���ڴ�С */   
    u_short urgent_pointer;   
    /* ����ָ�� */   
    u_int sequence;   
    /* ���к� */   
    u_int acknowledgement;   
    /* ȷ�Ϻ� */   
    u_int16_t checksum;   
    /* У��� */   
    tcp_protocol = (struct tcp_header*)(packet_content + 14+20);   
    /* ���TCPЭ������ */   
    source_port = ntohs(tcp_protocol->tcp_source_port);   
    /* ���Դ�˿� */   
    destination_port = ntohs(tcp_protocol->tcp_destination_port);   
    /* ���Ŀ�Ķ˿� */   
    header_length = tcp_protocol->tcp_offset *4;   
    /* ���� */   
    sequence = ntohl(tcp_protocol->tcp_sequence);   
    /* ������ */   
    acknowledgement = ntohl(tcp_protocol->tcp_acknowledgement);   
    /* ȷ�������� */   
    windows = ntohs(tcp_protocol->tcp_windows);   
    /* ���ڴ�С */   
    urgent_pointer = ntohs(tcp_protocol->tcp_urgent_pointer);   
    /* ����ָ�� */   
    flags = tcp_protocol->tcp_flags;   
    /* ��ʶ */   
    checksum = ntohs(tcp_protocol->tcp_checksum);   
    /* У��� */   
    printf("-------  TCPЭ��   -------\n");   
    printf("Դ�˿ں�:%d\n", source_port);   
    printf("Ŀ�Ķ˿ں�:%d\n", destination_port);   
    switch (destination_port)   
    {   
        case 80:   
            printf("�ϲ�Э��ΪHTTPЭ��\n");   
            break;   
        case 21:   
            printf("�ϲ�Э��ΪFTPЭ��\n");   
            break;   
        case 23:   
            printf("�ϲ�Э��ΪTELNETЭ��\n");   
            break;   
        case 25:   
            printf("�ϲ�Э��ΪSMTPЭ��\n");   
            break;   
        case 110:   
            printf("�ϲ�Э��POP3Э��\n");   
            break;   
        default:   
            break;   
    }   
    printf("������:%u\n", sequence);   
    printf("ȷ�Ϻ�:%u\n", acknowledgement);   
    printf("�ײ�����:%d\n", header_length);   
    printf("����:%d\n", tcp_protocol->tcp_reserved);   
    printf("���:");   
    if (flags &0x08)   
        printf("PSH ");   
    if (flags &0x10)   
        printf("ACK ");   
    if (flags &0x02)   
        printf("SYN ");   
    if (flags &0x20)   
        printf("URG ");   
    if (flags &0x01)   
        printf("FIN ");   
    if (flags &0x04)   
        printf("RST ");   
    printf("\n");   
    printf("���ڴ�С:%d\n", windows);   
    printf("У���:%d\n", checksum);   
    printf("����ָ��:%d\n", urgent_pointer);   
}   
/*  
=======================================================================================================================  
������ʵ��UDPЭ������ĺ���������������ص�������ͬ  
=======================================================================================================================  
 */   
void capThread::udp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    struct udp_header *udp_protocol;   
    /* UDPЭ����� */   
    u_short source_port;   
    /* Դ�˿� */   
    u_short destination_port;   
    /* Ŀ�Ķ˿ں� */   
    u_short length;   
    udp_protocol = (struct udp_header*)(packet_content + 14+20);   
    /* ���UDPЭ������ */   
    source_port = ntohs(udp_protocol->udp_source_port);   
    /* ���Դ�˿� */   
    destination_port = ntohs(udp_protocol->udp_destination_port);   
    /* ���Ŀ�Ķ˿� */   
    length = ntohs(udp_protocol->udp_length);   
    /* ��ó��� */   
    printf("----------  UDPЭ��    ----------\n");   
    printf("Դ�˿ں�:%d\n", source_port);   
    printf("Ŀ�Ķ˿ں�:%d\n", destination_port);   
    switch (destination_port)   
    {   
        case 138:   
            printf("�ϲ�Э��ΪNETBIOS���ݱ�����\n");   
            break;   
        case 137:   
            printf("�ϲ�Э��ΪNETBIOS���ַ���\n");   
            break;   
        case 139:   
            printf("�ϲ�Э��ΪNETBIOS�Ự����n");   
            break;   
        case 53:   
            printf("�ϲ�Э��Ϊ��������\n");   
            break;   
        default:   
            break;   
    }   
    printf("����:%d\n", length);   
    printf("У���:%d\n", ntohs(udp_protocol->udp_checksum));   
}   
/*  
=======================================================================================================================  
������ʵ�ַ���ICMPЭ��ĺ���������������ص�������ͬ  
=======================================================================================================================  
 */   
void capThread::icmp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    struct icmp_header *icmp_protocol;   
    /* ICMPЭ����� */   
    icmp_protocol = (struct icmp_header*)(packet_content + 14+20);   
    /* ���ICMPЭ������ */   
    printf("----------  ICMPЭ��    ----------\n");   
    printf("ICMP����:%d\n", icmp_protocol->icmp_type);   
    /* ���ICMP���� */   
    switch (icmp_protocol->icmp_type)   
    {   
        case 8:   
            printf("ICMP��������Э��\n");   
            printf("ICMP����:%d\n", icmp_protocol->icmp_code);   
            printf("��ʶ��:%d\n", icmp_protocol->icmp_id);   
            printf("������:%d\n", icmp_protocol->icmp_sequence);   
            break;   
        case 0:   
            printf("ICMP����Ӧ��Э��\n");   
            printf("ICMP����:%d\n", icmp_protocol->icmp_code);   
            printf("��ʶ��:%d\n", icmp_protocol->icmp_id);   
            printf("������:%d\n", icmp_protocol->icmp_sequence);   
            break;   
        default:   
            break;   
    }   
    printf("ICMPУ���:%d\n", ntohs(icmp_protocol->icmp_checksum));   
    /* ���ICMPУ��� */   
    return ;   
}   
/*  
=======================================================================================================================  
������ʵ��ARPЭ������ĺ���������������ص�������ͬ  
=======================================================================================================================  
 */   
void capThread::arp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    struct arp_header *arp_protocol;   
    u_short protocol_type;   
    u_short hardware_type;   
    u_short operation_code;   
    u_char *mac_string;   
    struct in_addr source_ip_address;   
    struct in_addr destination_ip_address;   
    u_char hardware_length;   
    u_char protocol_length;   
    printf("--------   ARPЭ��    --------\n");   
    arp_protocol = (struct arp_header*)(packet_content + 14);   
    hardware_type = ntohs(arp_protocol->arp_hardware_type);   
    protocol_type = ntohs(arp_protocol->arp_protocol_type);   
    operation_code = ntohs(arp_protocol->arp_operation_code);   
    hardware_length = arp_protocol->arp_hardware_length;   
    protocol_length = arp_protocol->arp_protocol_length;   
    printf("Ӳ������:%d\n", hardware_type);   
    printf("Э������ Protocol Type:%d\n", protocol_type);   
    printf("Ӳ����ַ����:%d\n", hardware_length);   
    printf("Э���ַ����:%d\n", protocol_length);   
    printf("ARP Operation:%d\n", operation_code);   
    switch (operation_code)   
    {   
        case 1:   
            printf("ARP����Э��\n");   
            break;   
        case 2:   
            printf("ARPӦ��Э��\n");   
            break;   
        case 3:   
            printf("RARP����Э��\n");   
            break;   
        case 4:   
            printf("RARPӦ��Э��\n");   
            break;   
        default:   
            break;   
    }   
    printf("Դ��̫����ַ: \n");   
    mac_string = arp_protocol->arp_source_ethernet_address;   
    printf("%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
    memcpy((void*) &source_ip_address, (void*) &arp_protocol->arp_source_ip_address, sizeof(struct in_addr));   
    printf("ԴIP��ַ:%s\n", inet_ntoa(source_ip_address));   
    printf("Ŀ����̫����ַ: \n");   
    mac_string = arp_protocol->arp_destination_ethernet_address;   
    printf("%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
    memcpy((void*) &destination_ip_address, (void*) &arp_protocol->arp_destination_ip_address, sizeof(struct in_addr));   
    printf("Ŀ��IP��ַ:%s\n", inet_ntoa(destination_ip_address));   
}   
/*  
=======================================================================================================================  
������ʵ��IPЭ������ĺ������亯��������ص�������ͬ  
=======================================================================================================================  
 */   
void capThread::ip_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    struct ip_header *ip_protocol;   
    /* IPЭ����� */   
    u_int header_length;   
    /* ���� */   
    u_int offset;   
    /* ƫ�� */   
    u_char tos;   
    /* �������� */   
    u_int16_t checksum;   
    /* У��� */   
    ip_protocol = (struct ip_header*)(packet_content + 14);   
    /* ���IPЭ������ */   
    checksum = ntohs(ip_protocol->ip_checksum);   
    /* ���У��� */   
    header_length = ip_protocol->ip_header_length *4;   
    /* ��ó��� */   
    tos = ip_protocol->ip_tos;   
    /* ��÷������� */   
    offset = ntohs(ip_protocol->ip_off);   
    /* ���ƫ�� */   
    printf("----------- IPЭ��    -----------\n");   
    printf("�汾��:%d\n", ip_protocol->ip_version);   
    printf("�ײ�����:%d\n", header_length);   
    printf("��������:%d\n", tos);   
    printf("�ܳ���:%d\n", ntohs(ip_protocol->ip_length));   
    printf("��ʶ:%d\n", ntohs(ip_protocol->ip_id));   
    printf("ƫ��:%d\n", (offset &0x1fff) *8);   
    printf("����ʱ��:%d\n", ip_protocol->ip_ttl);   
    printf("Э������:%d\n", ip_protocol->ip_protocol);   
    switch (ip_protocol->ip_protocol)   
    {   
        case 6:   
            printf("�ϲ�Э��ΪTCPЭ��\n");   
            break;   
        case 17:   
            printf("�ϲ�Э��ΪUDPЭ��\n");   
            break;   
        case 1:   
            printf("�ϲ�Э��ΪICMPЭ��ICMP\n");   
            break;   
        default:   
            break;   
    }   
    printf("У���:%d\n", checksum);   
    printf("ԴIP��ַ:%s\n", inet_ntoa(ip_protocol->ip_souce_address));   
    /* ���ԴIP��ַ */   
    printf("Ŀ��IP��ַ:%s\n", inet_ntoa(ip_protocol->ip_destination_address));   
    /* ���Ŀ��IP��ַ */   
    switch (ip_protocol->ip_protocol) /* ����IPЭ���ж��ϲ�Э�� */   
    {   
        case 6:   
            tcp_protocol_packet_callback(argument, packet_header, packet_content);   
            break;   
            /* �ϲ�Э����TCPЭ�飬���÷���TCPЭ��ĺ�����ע������Ĵ��� */   
        case 17:   
            udp_protocol_packet_callback(argument, packet_header, packet_content);   
            break;   
            /* �ϲ�Э����UDPЭ�飬���÷���UDPЭ��ĺ�����ע������Ĵ��� */   
        case 1:   
            icmp_protocol_packet_callback(argument, packet_header, packet_content);   
            break;   
            /* �ϲ�Э����ICMPЭ�飬���÷���ICMPЭ��ĺ�����ע������Ĵ��� */   
        default:   
            break;   
    }   
}   
/*  
=======================================================================================================================  
�����Ƿ�����̫��Э��ĺ�����Ҳ�ǻص�����  
=======================================================================================================================  
 */   
void capThread::ethernet_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    u_short ethernet_type;   
    /* ��̫������ */   
    struct ether_header *ethernet_protocol;   
    /* ��̫��Э����� */   
    u_char *mac_string;   
    /* ��̫����ַ */   
    static int packet_number = 1;   
    /* ���ݰ���������̬���� */   
	sprintf(this->m_captureInfo,"%s","**************************************************\n");   
	emit this->getPcaket(this->m_captureInfo);

	sprintf(this->m_captureInfo,"#%d packet\n", packet_number);   
	emit this->getPcaket(this->m_captureInfo);

    sprintf(this->m_captureInfo,"%s","time: ");
	emit this->getPcaket(this->m_captureInfo);

	struct tm ltime;
	char timestr[16];
	time_t local_tv_sec = packet_header->ts.tv_sec;
    localtime_s(&ltime, &local_tv_sec);
    strftime( timestr, sizeof timestr, "%H:%M:%S", &ltime);

    sprintf(this->m_captureInfo,"%s\n", timestr);  
	emit this->getPcaket(this->m_captureInfo);
    /* ��ò������ݰ���ʱ�� */   


    sprintf(this->m_captureInfo,"%s","packet length: ");   
	emit this->getPcaket(this->m_captureInfo);

    sprintf(this->m_captureInfo,"%d\n", packet_header->len);   
	emit this->getPcaket(this->m_captureInfo);

    sprintf(this->m_captureInfo,"%s","--------   ethernet    --------\n");
	emit this->getPcaket(this->m_captureInfo);

    ethernet_protocol = (struct ether_header*)packet_content;   
    /* �����̫��Э������ */   
    sprintf(this->m_captureInfo,"%s","type: ");  
	emit this->getPcaket(this->m_captureInfo);

    ethernet_type = ntohs(ethernet_protocol->ether_type);   
    /* �����̫������ */   
    sprintf(this->m_captureInfo,"%04x\n", ethernet_type);   
    switch (ethernet_type) /* ������̫�������ж� */   
    {   
        case 0x0800:   
            sprintf(this->m_captureInfo,"%s","IP protocal\n");
			emit this->getPcaket(this->m_captureInfo);
            break;   
        case 0x0806:   
            sprintf(this->m_captureInfo,"%s","ARP protocal\n");   
			emit this->getPcaket(this->m_captureInfo);
            break;   
        case 0x8035:   
            sprintf(this->m_captureInfo,"%s","RARP protocal\n");  
			emit this->getPcaket(this->m_captureInfo);
            break;   
        default:   
            break;   
    }   
    sprintf(this->m_captureInfo,"%s","source MAC address: \n");   
	emit this->getPcaket(this->m_captureInfo);

    mac_string = ethernet_protocol->ether_shost;   
    sprintf(this->m_captureInfo,"%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
	emit this->getPcaket(this->m_captureInfo);
   
	/* ���Դ��̫����ַ */   
    sprintf(this->m_captureInfo,"%s","destination MAC address \n");   
	emit this->getPcaket(this->m_captureInfo);
   
	mac_string = ethernet_protocol->ether_dhost;   
    sprintf(this->m_captureInfo,"%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
	emit this->getPcaket(this->m_captureInfo);
	
	/* ���Ŀ����̫����ַ */   
    switch (ethernet_type)   
    {   
        case 0x0806:   
            arp_protocol_packet_callback(argument, packet_header, packet_content);   
            break;   
            /* �ϲ�Э��ΪARPЭ�飬���÷���ARPЭ��ĺ�����ע������Ĵ��� */   
        case 0x0800:   
            ip_protocol_packet_callback(argument, packet_header, packet_content);   
            break;   
            /* �ϲ�Э��ΪIPЭ�飬���÷���IPЭ��ĺ�����ע������Ĵ��� */   
        default:   
            break;   
    }   
    printf("**************************************************\n");   
    packet_number++;   
}   
