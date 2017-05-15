#ifndef TOTORO_BLOCKINGQUEUE_H
#define TOTORO_BLOCKINGQUEUE_H

#include "Condition.h"
#include <queue>

namespace totoro {

template<class T>
class BlockingQueue{
 public:
  BlockingQueue()
    : mutex_(), notEmpty_(mutex_), queue_() {
  }

  void Push(const T& x) {
    MutexLockGuard lock(mutex_);
    queue_.push(x);
    notEmpty_.Notify(); 
  }

  T Pop() {
    MutexLockGuard lock(mutex_);
    while (queue_.empty()) {// use while beacuse spurious wakeup
      notEmpty_.Wait();
    }
    assert(!queue_.empty());
    T front(queue_.front());
    queue_.pop();
    return front;
  }

  size_t Size() const {
    MutexLockGuard lock(mutex_);
    return queue_.size();
  }
  bool Empty() const {
    return Size() == 0;
  }

 private:
  mutable MutexLock mutex_;
  Condition         notEmpty_;
  std::queue<T>     queue_;
}; 

} 

#endif // TOTORO_BLOCKINGQUEUE_H
