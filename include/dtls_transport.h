#ifndef LIB_WEBRTC_DTLS_TRANSPORT_H_
#define LIB_WEBRTC_DTLS_TRANSPORT_H_

#include "base/refcount.h"
#include "rtc_ice_transport.h"
#include "rtc_types.h"

namespace libwebrtc {

class DtlsTransportInformation : public RefCountInterface {
 public:
  enum class DtlsTransportState {
    kNew,         // Has not started negotiating yet.
    kConnecting,  // In the process of negotiating a secure connection.
    kConnected,   // Completed negotiation and verified fingerprints.
    kClosed,      // Intentionally closed.
    kFailed,      // Failure due to an error or failing to verify a remote
                  // fingerprint.
    kNumValues
  };

  LIB_WEBRTC_API static scoped_refptr<DtlsTransportInformation> Create();

  LIB_WEBRTC_API static scoped_refptr<DtlsTransportInformation> Create(
      DtlsTransportState state);

  LIB_WEBRTC_API static scoped_refptr<DtlsTransportInformation> Create(
      DtlsTransportState state,
      int tls_version,
      int ssl_cipher_suite,
      int srtp_cipher_suite,
      std::string remote_ssl_certificates);

  LIB_WEBRTC_API static scoped_refptr<DtlsTransportInformation> Create(
      scoped_refptr<DtlsTransportInformation> c);

  virtual DtlsTransportInformation& operator=(
      scoped_refptr<DtlsTransportInformation> c) = 0;

  virtual DtlsTransportState GetState() const = 0;
  virtual int GetSslCipherSuite() const = 0;
  virtual int GetSrtpCipherSuite() const = 0;
};

class DtlsTransportObserver {
 public:
  virtual void OnStateChange(DtlsTransportInformation info) = 0;

  virtual void OnError(const int type, const char* message) = 0;

 protected:
  virtual ~DtlsTransportObserver() = default;
};

class DtlsTransport : public RefCountInterface {
  LIB_WEBRTC_API static scoped_refptr<DtlsTransport> Create();

 public:
  virtual rtc::scoped_refptr<IceTransport> GetIceTransport() = 0;

  virtual DtlsTransportInformation GetInformation() = 0;

  virtual void RegisterObserver(DtlsTransportObserver* observer) = 0;

  virtual void UnregisterObserver() = 0;
};

}  // namespace libwebrtc

#endif  // API_DTLS_TRANSPORT_INTERFACE_H_
