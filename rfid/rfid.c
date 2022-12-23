#include "rfid.h"

unsigned char *head = buffer, *msg_version = buffer+1, *msg_tag = buffer +3, *msg_checksum = buffer + 11, tail = buffer + 13;
long tag_id = 0;
long arrayMapOfTagId[2] = {3681980,3939460};
unsigned char rfid_index = 0;
unsigned char admin_index = 0;

unsigned char check_rfid()
{
    int i;
    long checksum = 0;
    if(index_buffer < 14) return 0;
    index_buffer = 0;
    for(i = 0; i < 10; i += 2){
        checksum ^= hexstr2l(msg_version + i,2);
    }
    if(checksum != hexstr2l(msg_checksum, 2)) return 0;
    tag_id = hexstr2l(msg_tag,8);
    for(i = 0; i < 2; i++)
    {
        if(tag_id == arrayMapOfTagId[i])
        {
            rfid_index = i;
            return 1;
        }
    }
    return 0;
}

long hexstr2l(unsigned char* str, int size){
    long result = 0;
    int i = 0;
    int temp = 0;
    for(i = 0; i < size; i++){
        if(*(str+i) >= 'A') result = result*16 + (*(str+i) - 'A' + 10);
        else result = result*16 + *(str+i) - '0';
    }
    return result;
}