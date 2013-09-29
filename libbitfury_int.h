#ifndef __LIBBITFURY_INT_H__
#define __LIBBITFURY_INT_H__

struct bitfury_payload {
	unsigned char midstate[32];
	unsigned int junk[8];
	unsigned m7;
	unsigned ntime;
	unsigned nbits;
	unsigned nnonce;
};

struct bitfury_device {
	unsigned osc6_req;
	unsigned osc6_bits;
	unsigned osc6_bits_setpoint;
	unsigned newbuf[17];
	unsigned oldbuf[17];
	struct work * work;
	struct work * owork;
	struct work * o2work;
	int job_switched;
	struct bitfury_payload payload;
	struct bitfury_payload opayload;
	struct bitfury_payload o2payload;
	unsigned int results[16];
	int results_n;
	time_t stat_ts[BITFURY_STAT_N];
	unsigned int stat_counter;
	unsigned int future_nonce[16];
	unsigned int old_nonce[16];
	int future_num;
	int old_num;
	struct timespec timer1;
	struct timespec otimer1;
	struct timespec ts1;
	struct timespec predict1;
	int rate; //per msec
	int osc_slow;
	int osc_fast;
	unsigned slot;
	unsigned fasync;
	unsigned hw_errors;
	unsigned int matching_work;
	unsigned int nonces[32];
	int current_nonce;
	unsigned atrvec[20];
	unsigned mhz,mhz2;
	uint32_t counter, counter2;
	struct timespec time;
};

#endif