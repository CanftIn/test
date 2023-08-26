#ifndef MSG_QUEUE_H
#define MSG_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

namespace Sun {
	class Task;

	enum class TaskState {
		FINISH = 0,
	};
	struct Msg {
		Task* task = nullptr;
		TaskState taskState = TaskState::FINISH;
	};

	class MsgQueue {
	public:
		void push(const Msg& task);
		Msg pop();
		Msg front();
		bool empty();
		void wait();
		void stop_wait();
	private:
		std::condition_variable condition_;
		std::mutex mtx_;
		std::queue<Msg> queue_;
		bool stop_ = false;
	};
}

#endif 