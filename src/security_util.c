#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <openssl/rand.h> //include openssl

/* #include <stdio.h> */
/* #include <stdint.h> */

#include "error_handling.h"
#include "security_util.h"

uint32_t randNum()
{
    unsigned char seqNumBuf[sizeof(uint32_t)];
    if(RAND_bytes(seqNumBuf, sizeof(seqNumBuf)) != 1) {
    	error_handling("Failed to generate random bytes");
    }
    return *((uint32_t *)seqNumBuf);
}

