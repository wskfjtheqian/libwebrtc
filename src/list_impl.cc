#include "list_impl.h"
#include "base/refcountedobject.h"

namespace libwebrtc {
template <class T>
LIB_WEBRTC_API  scoped_refptr<List<T>> List<T>::Create() {
  return new RefCountedObject<ListImpl<T>>();
}

template <class T>
inline void ListImpl<T>::Add(scoped_refptr<T> item) {
  _vector.push_back(item);
}
}
