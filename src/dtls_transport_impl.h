
#ifndef LIB_WEBRTC_DTLS_TRANSPORT_INTERFACE_IMPL_H_
#define LIB_WEBRTC_DTLS_TRANSPORT_INTERFACE_IMPL_H_

#include "dtls_transport.h"
#include "api/dtls_transport_interface.h"
#include "api/scoped_refptr.h"

namespace libwebrtc {


class DtlsTransportInformationImpl : DtlsTransportInformation {
 public:

  virtual DtlsTransportInformation& operator=(
      scoped_refptr<DtlsTransportInformation> c) override;
  virtual DtlsTransportState GetState() const override;
  virtual int GetSslCipherSuite() const override;
  virtual int GetSrtpCipherSuite() const override;


  webrtc::DtlsTransportInformation& dtls_transport_information();

 private:
  webrtc::DtlsTransportInformation dtls_transport_information_;
};


class DtlsTransportImpl : public DtlsTransport
    ,public webrtc::DtlsTransportObserverInterface {
 public:
  DtlsTransportImpl();

  DtlsTransportImpl(
      rtc::scoped_refptr<webrtc::DtlsTransportInterface> dtls_transport);
  
  virtual scoped_refptr<IceTransport> GetIceTransport() override;

  virtual scoped_refptr<DtlsTransportInformation> GetInformation() override;

  virtual void RegisterObserver(DtlsTransportObserver* observer) override ;

  virtual void UnregisterObserver() override;

 public:
  virtual void OnStateChange(webrtc::DtlsTransportInformation info) override;

  virtual void OnError(webrtc::RTCError error) override;


  rtc::scoped_refptr<webrtc::DtlsTransportInterface> dtls_transport();

 private:
  rtc::scoped_refptr<webrtc::DtlsTransportInterface> dtls_transport_;
  DtlsTransportObserver* observer_;
};

}  // namespace webrtc

#endif  // API_DTLS_TRANSPORT_INTERFACE_H_
