#ifndef TOTORO_CONDITION_H
#define TOTORO_CONDITION_H

#include "MutexLock.h"

namespace totoro {

class Condition{
 public:
  explicit Condition(MutexLock& mutex)
    : mutex_(mutex) {
    CHECK(!pthread_cond_init(&pcond_, NULL));
  }

  ~Condition() {
    CHECK(!pthread_cond_destroy(&pcond_));
  }

  void Wait() {
    CHECK(!pthread_cond_wait(&pcond_, mutex_.GetPthreadMutex()));
  }

  void Notify() {
    CHECK(!pthread_cond_signal(&pcond_));
  }

  void NotifyAll() {
    CHECK(!pthread_cond_broadcast(&pcond_));
  }

 private:
  MutexLock& mutex_;
  pthread_cond_t pcond_;
}; 

} 

#endif // TOTORO_CONDITION_H
