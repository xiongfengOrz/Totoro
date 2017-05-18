#ifndef TOTORO_THREAD_H
#define TOTORO_THREAD_H

#include "Logging.h"

namespace totoro {

class IThread{
 public:
  IThread(): isStarted(false), isJoined(false) {
  }
  virtual ~IThread() {
    if(isStarted && !isJoined) {
      CHECK(!pthread_detach(thread_));
    }
  };

  virtual void Run() = 0;
  void Start() {
    CHECK(!isStarted);
    CHECK(!pthread_create(&thread_, NULL, Worker, this));
    isStarted = true;
  }
  void Join() {
    CHECK(!isJoined);
    CHECK(!pthread_join(thread_, NULL));
    isJoined = true;
  }
 private:
  static void * Worker(void * data) {
    IThread * ptr = (IThread* ) data;
    ptr->Run();
    return NULL;
  }

  pthread_t thread_;
  bool isStarted;
  bool isJoined;
}; 

} 

#endif 
