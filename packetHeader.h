#ifndef PACKET_HEADER
#define PACKET_HEADER

#include <stdio.h>
#include <pcap.h>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
/*  
-----------------------------------------------------------------------------------------------------------------------  
WinPcapͷ�ļ� ;  
��������̫��Э���ʽ�Ķ���  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct ether_header   
{   
    u_int8_t ether_dhost[6];   
    /* Ŀ����̫����ַ */   
    u_int8_t ether_shost[6];   
    /* Դ��̫����ַ */   
    u_int16_t ether_type;   
    /* ��̫������ */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
������ARPЭ���ʽ�Ķ���  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct arp_header   
{   
    u_int16_t arp_hardware_type;   
    /* Ӳ������ */   
    u_int16_t arp_protocol_type;   
    /* Э������ */   
    u_int8_t arp_hardware_length;   
    /* Ӳ����ַ���� */   
    u_int8_t arp_protocol_length;   
    /* Э���ַ���� */   
    u_int16_t arp_operation_code;   
    /* ������ */   
    u_int8_t arp_source_ethernet_address[6];   
    /* Դ��̫����ַ */   
    u_int8_t arp_source_ip_address[4];   
    /* ԴIP��ַ */   
    u_int8_t arp_destination_ethernet_address[6];   
    /* Ŀ����̫����ַ */   
    u_int8_t arp_destination_ip_address[4];   
    /* Ŀ��IP��ַ */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
������IPЭ���ʽ�Ķ���  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct ip_header   
{   
    #if defined(WORDS_BIGENDIAN)   
        u_int8_t ip_version: 4,   
        /* �汾 */   
        ip_header_length: 4;   
        /* �ײ����� */   
    #else   
        u_int8_t ip_header_length: 4, ip_version: 4;   
    #endif   
    u_int8_t ip_tos;   
    /* �������� */   
    u_int16_t ip_length;   
    /* ���� */   
    u_int16_t ip_id;   
    /* ��ʶ */   
    u_int16_t ip_off;   
    /* ƫ�� */   
    u_int8_t ip_ttl;   
    /* ����ʱ�� */   
    u_int8_t ip_protocol;   
    /* Э������ */   
    u_int16_t ip_checksum;   
    /* У��� */   
    struct in_addr ip_souce_address;   
    /* ԴIP��ַ */   
    struct in_addr ip_destination_address;   
    /* Ŀ��IP��ַ */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
������UDPЭ���ʽ����  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct udp_header   
{   
    u_int16_t udp_source_port;   
    /* Դ�˿ں� */   
    u_int16_t udp_destination_port;   
    /* Ŀ�Ķ˿ں� */   
    u_int16_t udp_length;   
    /* ���� */   
    u_int16_t udp_checksum;   
    /* У��� */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
������TCPЭ���ʽ�Ķ���  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct tcp_header   
{   
    u_int16_t tcp_source_port;   
    /* Դ�˿ں� */   
    u_int16_t tcp_destination_port;   
    /* Ŀ�Ķ˿ں� */   
    u_int32_t tcp_sequence;   
    /* ���к� */   
    u_int32_t tcp_acknowledgement;   
    /* ȷ�����к� */   
    #ifdef WORDS_BIGENDIAN   
        u_int8_t tcp_offset: 4,   
        /* ƫ�� */   
        tcp_reserved: 4;   
        /* δ�� */   
    #else   
        u_int8_t tcp_reserved: 4,   
        /* δ�� */   
        tcp_offset: 4;   
        /* ƫ�� */   
    #endif   
    u_int8_t tcp_flags;   
    /* ��� */   
    u_int16_t tcp_windows;   
    /* ���ڴ�С */   
    u_int16_t tcp_checksum;   
    /* У��� */   
    u_int16_t tcp_urgent_pointer;   
    /* ����ָ�� */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
������ICMPЭ���ʽ�Ķ���  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct icmp_header   
{   
    u_int8_t icmp_type;   
    /* ICMP���� */   
    u_int8_t icmp_code;   
    /* ICMP���� */   
    u_int16_t icmp_checksum;   
    /* У��� */   
    u_int16_t icmp_id;   
    /* ��ʶ�� */   
    u_int16_t icmp_sequence;   
    /* ������ */   
};   





#endif