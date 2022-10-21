#include <pcap.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char *dev_;
} Param;

Param param = {
    .dev_ = NULL};

void delete_char(char *str, char* ch)
{
    for (; *str != '\0'; str++)//NULL까지 반복
    {
        if (*str == *ch)//같은 글자라면
        {
            strcpy(str, str + 1);
            str--;
        }
    }
}

int main(int argc,char *argv[]){
    char *black_list[argc];
    unsigned char *Interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap = pcap_open_live(Interface, BUFSIZ, 1, 1000, errbuf);
    if (pcap == NULL)
    {
        fprintf(stderr, "pcap_open_live(%s) return null - %s\n", param.dev_, errbuf);
        return -1;
    }

    for(int i=2;i<argc;i++){
        delete_char(argv[i],":");
        black_list[i-1] = argv[i];
    }

}