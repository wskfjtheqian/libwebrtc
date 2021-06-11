#include "dtls_transport_impl.h"

namespace libwebrtc {



DtlsTransportImpl::DtlsTransportImpl(
    rtc::scoped_refptr<webrtc::DtlsTransportInterface> dtls_transport)
    : dtls_transport_(dtls_transport), observer_(nullptr) {}

rtc::scoped_refptr<IceTransport> DtlsTransportImpl::ice_transport() {
  return rtc::scoped_refptr<IceTransport>();
}

DtlsTransportInformation DtlsTransportImpl::Information() {
  return DtlsTransportInformation();
}

void DtlsTransportImpl::RegisterObserver(DtlsTransportObserver* observer) {
  observer_ = observer;
  dtls_transport_->RegisterObserver(this);
}

void DtlsTransportImpl::UnregisterObserver() {
  dtls_transport_->UnregisterObserver();
  observer_ = nullptr;
}

void DtlsTransportImpl::OnStateChange(webrtc::DtlsTransportInformation info) {}

void DtlsTransportImpl::OnError(webrtc::RTCError error) {
  if (observer_) {
    observer_->OnError(static_cast<int>(error.type()), error.message());
  }
}

DtlsTransportImpl::~DtlsTransportImpl() {}

}  // namespace libwebrtc