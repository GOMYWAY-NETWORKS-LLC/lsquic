/* Copyright (c) 2017 LiteSpeed Technologies Inc.  See LICENSE. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "lsquic_int_types.h"
#include "lsquic_senhist.h"
#include "lsquic_logger.h"


int
main (void)
{
    struct lsquic_senhist hist = { 0
#if !LSQUIC_SENHIST_FATAL
        , 0
#endif        
    };
    lsquic_packno_t packno;

    lsquic_senhist_init(&hist);

    assert(0 == lsquic_senhist_largest(&hist));

    for (packno = 1; packno < 100; ++packno)
        lsquic_senhist_add(&hist, packno);

    assert(99 == lsquic_senhist_largest(&hist));

    lsquic_senhist_cleanup(&hist);

    return 0;
}
