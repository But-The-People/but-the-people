#pragma once
#ifndef TBB_COLO_H
#define TBB_COLO_H

#include "ThreadOverview.h"

// MULTICORE can be defined or undefined in ThreadOverview.h

#ifdef MULTICORE

#pragma push_macro("free")
#pragma push_macro("new")
#undef free
#undef new
#include "lib/tbb/atomic.h"
#include "lib/tbb/blocked_range.h"
#include "lib/tbb/cache_aligned_allocator.h"
#include "lib/tbb/parallel_for.h"
#include "lib/tbb/parallel_reduce.h"
#include "lib/tbb/mutex.h"
#include "lib/tbb/partitioner.h"
#include "lib/tbb/task_scheduler_init.h"
#pragma pop_macro("new")
#pragma pop_macro("free")

#else
// singlecore wrappers to allow TBB syntax

namespace tbb
{
	struct mutex
	{
		inline void lock() const {}
		inline void unlock() const {}
	};

	template<typename T>
	class blocked_range
	{
	public:
		blocked_range(T begin, T end, unsigned int grainsize = 1)
			: my_begin(begin)
			, my_end(end)
			, my_grainsize(grainsize)
		{}

		T begin() const { return my_begin; }
		T end() const { return my_end; }

	private:
		T my_begin;
		T my_end;
		unsigned int my_grainsize;
	};

	struct auto_partitioner {};
	struct simple_partitioner {};
	struct split {};

	template<typename T>
	struct atomic {
	public:
		// Default constructor initializes with default value of T.
		atomic() : m_value() {}

		// Construct with an initial value.
		atomic(const T& initial) : m_value(initial) {}

		// Implicit conversion to T.
		operator T() const { return m_value; }

		atomic<T>& operator=(const T& new_value) {
			m_value = new_value;
			return *this;
		}

	private:
		T m_value;
	};
}
#endif

struct Threads
{
	template<typename Range, typename Body, typename Partitioner>
	static void parallel_reduce(const Range& range, Body& body, const Partitioner& partitioner)
	{
#ifdef MULTICORE
		ThreadOverview.m_bMultithreaded = true;
		tbb::parallel_reduce(range, body, partitioner);
		ThreadOverview.m_bMultithreaded = false;
#else
		body(range);
#endif
}
	template<typename Range, typename Body, typename Partitioner>
	static void parallel_for(const Range& range, Body& body, const Partitioner& partitioner)
	{
#ifdef MULTICORE
		ThreadOverview.m_bMultithreaded = true;
		tbb::parallel_for(range, body, partitioner);
		ThreadOverview.m_bMultithreaded = false;
#else
		body(range);
#endif
	}
};

#endif
