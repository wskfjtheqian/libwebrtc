
#ifndef LIB_WEBRTC_DTLS_TRANSPORT_INTERFACE_IMPL_H_
#define LIB_WEBRTC_DTLS_TRANSPORT_INTERFACE_IMPL_H_

#include "dtls_transport.h"
#include "api/dtls_transport_interface.h"
#include "api/scoped_refptr.h"

namespace libwebrtc {


class DtlsTransportInformationImpl : DtlsTransportInformation {

};


class DtlsTransportImpl : public DtlsTransport
    ,public webrtc::DtlsTransportObserverInterface {
 public:
  DtlsTransportImpl(
      rtc::scoped_refptr<webrtc::DtlsTransportInterface> dtls_transport);
  
  virtual rtc::scoped_refptr<IceTransport> ice_transport() override;

  virtual DtlsTransportInformation Information() override;

  virtual void RegisterObserver(DtlsTransportObserver* observer) override ;

  virtual void UnregisterObserver() override;

 public:
  virtual void OnStateChange(webrtc::DtlsTransportInformation info) override;

  virtual void OnError(webrtc::RTCError error) override;

 protected:
  virtual  ~DtlsTransportImpl();

 private:
  rtc::scoped_refptr<webrtc::DtlsTransportInterface> dtls_transport_;
  DtlsTransportObserver* observer_;
};

}  // namespace webrtc

#endif  // API_DTLS_TRANSPORT_INTERFACE_H_
