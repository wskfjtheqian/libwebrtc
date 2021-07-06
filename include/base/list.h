#ifndef LIBWEBRTC_LIST_H
#define LIBWEBRTC_LIST_H

#include "base/refcount.h"
#include "base/scoped_ref_ptr.h"
#include "rtc_types.h"

namespace libwebrtc {

template<class T>
class List : public RefCountInterface{
 public:
  LIB_WEBRTC_API static scoped_refptr<List> Create();

  virtual void Add(scoped_refptr<T> item) = 0;

  

};
}  // namespace libwebrtc
#endif //LIBWEBRTC_LIST_H
