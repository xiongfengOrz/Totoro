#ifndef TOTORO_MUTEX_LOCK_H
#define TOTORO_MUTEX_LOCK_H

#include <pthread.h>
#include "Logging.h"

namespace totoro {

class MutexLock{
 public:
  MutexLock() {
    CHECK(!pthread_mutex_init(&mutex_, NULL));
  }
  ~MutexLock() {
    CHECK(!pthread_mutex_destroy(&mutex_));
  }
  pthread_mutex_t* GetPthreadMutex() {
    return &mutex_;
  }

 private:
  void Lock() {
    CHECK(!pthread_mutex_lock(&mutex_));
  }
  void Unlock() {
    CHECK(!pthread_mutex_unlock(&mutex_));
  }
  friend class MutexLockGuard;

  pthread_mutex_t mutex_;
}; 

class MutexLockGuard{
 public:
  explicit MutexLockGuard(MutexLock & mutex)
    : mutex_(mutex) {
    mutex_.Lock();
  }
  ~MutexLockGuard() {
    mutex_.Unlock();
  }
 private:
  MutexLock & mutex_;
}; 

#define MutexLockGuard(x) CHECK(false);

} 

#endif // TOTORO_MUTEX_LOCK_
