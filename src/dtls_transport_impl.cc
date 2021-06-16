#include "dtls_transport_impl.h"
#include "rtc_ice_transport_impl.h"


namespace libwebrtc {

DtlsTransportInformation& DtlsTransportInformationImpl::operator=(
    scoped_refptr<DtlsTransportInformation> c) {
  DtlsTransportInformationImpl* impl= static_cast<DtlsTransportInformationImpl*>(c.get());
  dtls_transport_information_ = impl->dtls_transport_information();
}

DtlsTransportInformation::DtlsTransportState
DtlsTransportInformationImpl::GetState() const {
  return static_cast<DtlsTransportState>(dtls_transport_information_.state());
}

int DtlsTransportInformationImpl::GetSslCipherSuite() const {
  return dtls_transport_information_.ssl_cipher_suite().value();
}

int DtlsTransportInformationImpl::GetSrtpCipherSuite() const {
  return dtls_transport_information_.srtp_cipher_suite().value();
}

webrtc::DtlsTransportInformation&
DtlsTransportInformationImpl::dtls_transport_information() {
  return dtls_transport_information_;
}


DtlsTransportImpl::DtlsTransportImpl() {}

DtlsTransportImpl::DtlsTransportImpl(
    rtc::scoped_refptr<webrtc::DtlsTransportInterface> dtls_transport)
    : dtls_transport_(dtls_transport), observer_(nullptr) {}

scoped_refptr<IceTransport> DtlsTransportImpl::GetIceTransport() {
  return new RefCountedObject<IceTransportImpl>(dtls_transport_->ice_transport().get());
}

DtlsTransportInformation DtlsTransportImpl::GetInformation() {
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