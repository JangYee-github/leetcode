#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
// #include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <linux/if_arp.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <errno.h>

// 24 bytes
unsigned short pcap_header[] = {0xd4c3, 0xb2a1, 0x0200, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0100, 0x0000};

unsigned int per_pcap_head[] = {0x4aa0e161, 0x99760100, 0, 0};




void write2File(char *buf, unsigned short len, char* open_mod) {
	const char *filename = "pcap-simple.pcap";
	FILE * fp = fopen(filename, open_mod);
	fwrite(buf, len, 1, fp);
	fclose(fp);
}

void writePcapHead() {
	int i = 0;
	for (i = 0; i < 12; i++) {
		pcap_header[i] = ntohs(pcap_header[i]);
	}
	write2File((char*)pcap_header, 24, "w");
}

void writePerPcapHead() {
	write2File((char*)per_pcap_head, 16, "a");
}


int main() {
	// printf("eth_p_all is %x\n", ETH_P_ALL);
	int rawsock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (rawsock < 0) {
		perror("socket init error!\n");
		return -1;
	}
	printf("raw sorck is %d\n", rawsock);
	struct ifreq ifstruct;
	strcpy(ifstruct.ifr_name, "ens33");
	// 获取接口index
	ioctl(rawsock, SIOCGIFINDEX, &ifstruct);
	// 获取本地MAC地址
	ioctl(rawsock, SIOCGIFHWADDR, &ifstruct);
	// 获取网卡设置
	ioctl(rawsock, SIOCGIFFLAGS, &ifstruct);
	// 设置混杂模式
	ifstruct.ifr_flags |= IFF_PROMISC;

	unsigned short ret;
	struct sockaddr_ll sll;
	sll.sll_family = AF_PACKET;
	sll.sll_ifindex = ifstruct.ifr_ifindex;
	sll.sll_protocol = htons(ETH_P_ALL);
	sll.sll_hatype = ARPHRD_ETHER;
	sll.sll_pkttype = PACKET_OTHERHOST;
	sll.sll_halen = ETH_ALEN;
	sll.sll_addr[6] = 0;
	sll.sll_addr[7] = 0;
	bind(rawsock, (struct sockaddr *) &sll, sizeof(struct sockaddr_ll));
	char buf[1516];
	
	ret = read(rawsock, buf, sizeof(buf));

	unsigned short type_3 = ntohs(*(unsigned short *)(buf + 12));
	printf("type_3 is %x\n", type_3);
	if (type_3 != 0x0800)
		perror("this is ip protocol\n");
	if (ret < 18)
		perror("recv size letter than 18\n");
	unsigned short ip_totol_len = ntohs((*(unsigned short *)(buf + 16)));
	unsigned short cap_len = ip_totol_len + 14;
	if (cap_len > ret)
		perror(" cap_len > ret");
	writePcapHead();

	per_pcap_head[2] = cap_len;
	per_pcap_head[3] = cap_len;
	writePerPcapHead();

	write2File(buf, cap_len, "a");
	printf("recv size is %d\n", ret);
	printf("cap len is %d\n", cap_len);
	return 0;
}
