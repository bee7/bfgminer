#ifndef __LIBBITFURY_INT_H__
#define __LIBBITFURY_INT_H__

struct bitfury_payload {
	unsigned char midstate[32];
	unsigned int junk[8];
	unsigned m7;
	unsigned ntime;
	unsigned nbits;
	unsigned nnonce;
	struct work * work;
	int nnonces;
	int snonces;
	uint32_t nonces[16];
};

struct bitfury_device {
	unsigned osc6_req;
	unsigned osc6_bits;
	unsigned osc6_bits_setpoint;
	unsigned oldbuf[17];
	int job_switched;

	struct bitfury_payload *payload;
	struct bitfury_payload *opayload;
	struct bitfury_payload *o2payload;
	struct bitfury_payload payloads[3];
	
	time_t stat_ts[BITFURY_STAT_N];
	unsigned int stat_counter;
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
	unsigned mhz,mhz2;
	uint32_t counter, counter2;
	struct timespec time;
};

void work_to_payload(struct bitfury_payload *p, struct work *w);

#endif
