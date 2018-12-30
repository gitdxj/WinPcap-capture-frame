#ifndef PACKET_HEADER
#define PACKET_HEADER

#include <stdio.h>
#include <pcap.h>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
/*  
-----------------------------------------------------------------------------------------------------------------------  
WinPcap头文件 ;  
以下是以太网协议格式的定义  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct ether_header   
{   
    u_int8_t ether_dhost[6];   
    /* 目的以太网地址 */   
    u_int8_t ether_shost[6];   
    /* 源以太网地址 */   
    u_int16_t ether_type;   
    /* 以太网类型 */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
下面是ARP协议格式的定义  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct arp_header   
{   
    u_int16_t arp_hardware_type;   
    /* 硬件类型 */   
    u_int16_t arp_protocol_type;   
    /* 协议类型 */   
    u_int8_t arp_hardware_length;   
    /* 硬件地址长度 */   
    u_int8_t arp_protocol_length;   
    /* 协议地址长度 */   
    u_int16_t arp_operation_code;   
    /* 操作码 */   
    u_int8_t arp_source_ethernet_address[6];   
    /* 源以太网地址 */   
    u_int8_t arp_source_ip_address[4];   
    /* 源IP地址 */   
    u_int8_t arp_destination_ethernet_address[6];   
    /* 目的以太网地址 */   
    u_int8_t arp_destination_ip_address[4];   
    /* 目的IP地址 */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
下面是IP协议格式的定义  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct ip_header   
{   
    #if defined(WORDS_BIGENDIAN)   
        u_int8_t ip_version: 4,   
        /* 版本 */   
        ip_header_length: 4;   
        /* 首部长度 */   
    #else   
        u_int8_t ip_header_length: 4, ip_version: 4;   
    #endif   
    u_int8_t ip_tos;   
    /* 服务质量 */   
    u_int16_t ip_length;   
    /* 长度 */   
    u_int16_t ip_id;   
    /* 标识 */   
    u_int16_t ip_off;   
    /* 偏移 */   
    u_int8_t ip_ttl;   
    /* 生存时间 */   
    u_int8_t ip_protocol;   
    /* 协议类型 */   
    u_int16_t ip_checksum;   
    /* 校验和 */   
    struct in_addr ip_souce_address;   
    /* 源IP地址 */   
    struct in_addr ip_destination_address;   
    /* 目的IP地址 */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
下面是UDP协议格式定义  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct udp_header   
{   
    u_int16_t udp_source_port;   
    /* 源端口号 */   
    u_int16_t udp_destination_port;   
    /* 目的端口号 */   
    u_int16_t udp_length;   
    /* 长度 */   
    u_int16_t udp_checksum;   
    /* 校验和 */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
下面是TCP协议格式的定义  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct tcp_header   
{   
    u_int16_t tcp_source_port;   
    /* 源端口号 */   
    u_int16_t tcp_destination_port;   
    /* 目的端口号 */   
    u_int32_t tcp_sequence;   
    /* 序列号 */   
    u_int32_t tcp_acknowledgement;   
    /* 确认序列号 */   
    #ifdef WORDS_BIGENDIAN   
        u_int8_t tcp_offset: 4,   
        /* 偏移 */   
        tcp_reserved: 4;   
        /* 未用 */   
    #else   
        u_int8_t tcp_reserved: 4,   
        /* 未用 */   
        tcp_offset: 4;   
        /* 偏移 */   
    #endif   
    u_int8_t tcp_flags;   
    /* 标记 */   
    u_int16_t tcp_windows;   
    /* 窗口大小 */   
    u_int16_t tcp_checksum;   
    /* 校验和 */   
    u_int16_t tcp_urgent_pointer;   
    /* 紧急指针 */   
};   
/*  
-----------------------------------------------------------------------------------------------------------------------  
下面是ICMP协议格式的定义  
-----------------------------------------------------------------------------------------------------------------------  
 */   
struct icmp_header   
{   
    u_int8_t icmp_type;   
    /* ICMP类型 */   
    u_int8_t icmp_code;   
    /* ICMP代码 */   
    u_int16_t icmp_checksum;   
    /* 校验和 */   
    u_int16_t icmp_id;   
    /* 标识符 */   
    u_int16_t icmp_sequence;   
    /* 序列码 */   
};   





#endif