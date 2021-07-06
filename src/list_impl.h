//
// Created by Administrator on 2021/7/6.
//

#ifndef LIBWEBRTC_LIST_IMPL_H
#define LIBWEBRTC_LIST_IMPL_H

#include "base/list.h"
#include "vector"

namespace libwebrtc {

template <class T>
class ListImpl : public libwebrtc::List<T> {
 public:
  virtual void Add(scoped_refptr<T> item) override;

 private:
  std::vector<scoped_refptr<T>> _vector;
};

}  // namespace libwebrtc

#endif  // LIBWEBRTC_LIST_IMPL_H
