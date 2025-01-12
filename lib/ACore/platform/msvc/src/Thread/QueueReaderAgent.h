

#ifndef THREAD__QUEUE__ReaderAgent_H
#define THREAD__QUEUE__ReaderAgent_H

#include "ACore.h"
#include "QueuePipe.h"
#include "QueueReaderAgentTarget.h"

#include <agents.h>
#include <concrt.h>

namespace Thread {

namespace Queue {

class ACORE_DLL_EXPORT ReaderAgent : public Concurrency::agent {

	public:
		typedef ReaderAgent ThisType;

		ReaderAgent(Thread::Queue::Pipe & _sourcePipe):sourcePipe(_sourcePipe),target(nullptr){}
		ReaderAgent(Thread::Queue::Pipe & _sourcePipe,ReaderAgentTarget * & _target):sourcePipe(_sourcePipe),target(_target){}

		void registerTarget(ReaderAgentTarget * const & _target);

	protected:
		void run();

	private:
		Thread::Queue::Pipe & sourcePipe;
		ReaderAgentTarget * target;
		Concurrency::event targetSetEvent;

};

}

}

#endif 