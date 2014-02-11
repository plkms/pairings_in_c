/*
 * bench_util.c
 *
 *  Benchmarking utilities.
 *
 *  Created on: May 14, 2013
 *      Author: thomas
 */

#include "bench_util.h"
#include "util.h"
#include <stdio.h>

bm_time_t bm_start;
bm_time_t bm_stop;
long long bm_result;

#if ARCHITECTURE==ARCH_CORTEXM0
#define BENCH_OVERHEAD 26
#else
#define BENCH_OVERHEAD 0
#endif

/**
 * Start a benchmark.
 */
void benchmark_start() {
#if (BENCHMARK_SRC == BM_CYCLE)
	bm_start = get_cycles();
#elif (BENCHMARK_SRC == BM_CLOCK)
	clock_gettime(CLOCK_REALTIME, &bm_start);
#endif
}

/**
 * Stop a benchmark.
 */
void benchmark_stop() {
#if (BENCHMARK_SRC == BM_CYCLE)
	bm_stop = get_cycles();
#elif (BENCHMARK_SRC == BM_CLOCK)
	clock_gettime(CLOCK_REALTIME, &bm_stop);
#endif
}

/**
 * Compute the mean of all benchmarks for a given count of iterations.
 * @param iterations the number of benchmark iterations
 */
void benchmark_compute(int iterations) {
#if (BENCHMARK_SRC == BM_CYCLE)
	bm_result = (bm_stop - bm_start - BENCH_OVERHEAD) / iterations;
#elif (BENCHMARK_SRC == BM_CLOCK)
	bm_result = ((long)bm_stop.tv_sec - (long)bm_start.tv_sec) * 1000000000;
	bm_result += (bm_stop.tv_nsec - bm_start.tv_nsec);
	bm_result = bm_result / iterations;
#endif
}

/**
 * Computes the result of the previously executed benchmark.
 */
void benchmark_compute_single() {
#if (BENCHMARK_SRC == BM_CYCLE)
	bm_result = (bm_stop - bm_start - BENCH_OVERHEAD);
#elif (BENCHMARK_SRC == BM_CLOCK)
	bm_result = ((long)bm_stop.tv_sec - (long)bm_start.tv_sec) * 1000000000;
	bm_result += (bm_stop.tv_nsec - bm_start.tv_nsec);
#endif
}

/**
 * Print the result of the recent benchmark.
 * @param msg a message to be additionally printed
 */
void benchmark_print(const char *msg) {
	char buf[20];	// is only used in benchmark configs

#if (BENCHMARK_SRC == BM_CYCLE)
	sprintf(buf, "%u cycles\n", (unsigned) bm_result);
#elif  (BENCHMARK_SRC == BM_CLOCK)
	sprintf(buf, "%lld ns\n", bm_result);
#endif

	print(msg);
	print(buf);
}
