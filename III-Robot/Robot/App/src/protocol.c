#include "protocol.h"


void protocol_init(void)
{
	usart1_init();
}

static uint8_t calc_checksum(uint8_t* buf, int len) {
    uint16_t sum = 0;
    for (int i = 0; i < len; i++) {
        sum += buf[i];
    }
    unsigned char checksum = (unsigned char)(sum >> 8);
    return checksum;
}

unsigned char _data_check(unsigned char* buf, int len) 
{
    unsigned char checksum = calc_checksum(buf, len-2);
	if(checksum == buf[len-2])
		return 0;
	else return 1;
}

void protocol_send(eDEVICE device, unsigned char cmd, unsigned char *userdata)
{
	unsigned char buf[PROTOCOL_MSG_LEN] = {0};
	unsigned char *p = buf;

	*(p++) = FrameHeader0;
	*(p++) = FrameHeader1;
	*(p++) = device;
	*(p++) = R2PC;
	*(p++) = cmd;
	*(p++) = 0x00;
	*(p++) = userdata[0];
	*(p++) = userdata[1];
	*(p++) = userdata[2];
	*(p++) = userdata[3];
	*(p++) = calc_checksum(buf, 10);
	*p = 0xDD;

	usart1_send(buf, PROTOCOL_MSG_LEN);
}



#if 0

// gcc protocol.c -o protocol -I ../inc

#include <stdint.h>
#include <stdio.h>

int main() {
    uint8_t buf[] = {0xaa, 0x55, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xdd};
    int len = sizeof(buf) / sizeof(buf[0]);
    unsigned char result = _data_check(buf, len);
    if(result == 0) {
        printf("Data check succeeded.\n");
    } else {
        printf("Data check failed.\n");
    }
    return 0;
}

#endif

