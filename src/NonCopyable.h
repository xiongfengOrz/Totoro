#ifndef TOTORO_NONCOPYABLE_H
#define TOTORO_NONCOPYABLE_H

namespace totoro {

class NonCopyable {
 protected:
  NonCopyable() {
  }
  ~NonCopyable() {
  }
 private:
  NonCopyable(const NonCopyable& );
  const NonCopyable& operator=(const NonCopyable& );
}; 

} 

#endif 
