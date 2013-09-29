/**
 * libbitfury.h - library for Bitfury chip/board
 *
 * Copyright (c) 2013 bitfury
 * Copyright (c) 2013 legkodymov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
**/

#ifndef __LIBBITFURY_H__
#define __LIBBITFURY_H__

#include "miner.h"

#define BITFURY_STAT_N 1024
#define BITFURY_MAXCHIPS 256
#define BITFURY_MAXBANKS 32
#define BITFURY_BANKCHIPS 8

#define BITFURY_API_STATS 300

struct bitfury_device;
struct bitfury_payload;
struct work;

int libbitfury_readHashData(unsigned int *res);
void libbitfury_sendHashData(struct thr_info *thr, struct bitfury_device *bf, int chip_n);
void work_to_payload(struct bitfury_payload *p, struct work *w);
struct timespec t_diff(struct timespec start, struct timespec end);
int libbitfury_detectChips(struct bitfury_device **devices);
int libbitfury_shutdownChips(struct bitfury_device *devices, int chip_n);
void send_reinit(int slot, int chip_n, int n);
void send_freq(int slot, int chip_n, int bits);
void send_shutdown(int slot, int chip_n);

int bitfury_set_clock_bits(struct cgpu_info *cgpu, int slot, int chip, int bits);

#endif /* __LIBBITFURY_H__ */
