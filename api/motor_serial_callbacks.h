#ifndef DARTT_INIT_H
#define DARTT_INIT_H

#include "cobs.h"
#include "dartt.h"
#include "dartt_sync.h"

namespace foc_motor {
    int tx_blocking(unsigned char addr, dartt_buffer_t * b, void * user_context, uint32_t timeout);
    int rx_blocking(dartt_buffer_t * buf, void * user_context, uint32_t timeout);
}

#endif
