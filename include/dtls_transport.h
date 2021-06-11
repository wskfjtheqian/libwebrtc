
#ifndef LIB_WEBRTC_DTLS_TRANSPORT_H_
#define LIB_WEBRTC_DTLS_TRANSPORT_H_

#include "base/refcount.h"


namespace libwebrtc {

enum class DtlsTransportState {
  kNew,         // Has not started negotiating yet.
  kConnecting,  // In the process of negotiating a secure connection.
  kConnected,   // Completed negotiation and verified fingerprints.
  kClosed,      // Intentionally closed.
  kFailed,      // Failure due to an error or failing to verify a remote
                // fingerprint.
  kNumValues
};

class  DtlsTransportInformation {
 public:
  DtlsTransportInformation();
  explicit DtlsTransportInformation(DtlsTransportState state);
  DtlsTransportInformation(DtlsTransportState state,
                           int tls_version,
                           int ssl_cipher_suite,
                           int srtp_cipher_suite,
                           std::string remote_ssl_certificates)
      : state_(state),
        tls_version_(tls_version),
        ssl_cipher_suite_(ssl_cipher_suite),
        srtp_cipher_suite_(srtp_cipher_suite),
        remote_ssl_certificates_(remote_ssl_certificates)
  {};

  DtlsTransportInformation(const DtlsTransportInformation& c);
  DtlsTransportInformation& operator=(const DtlsTransportInformation& c);
  DtlsTransportInformation(DtlsTransportInformation&& other) = default;
  DtlsTransportInformation& operator=(DtlsTransportInformation&& other) =
      default;

  DtlsTransportState state() const { return state_; }
  int tls_version() const { return tls_version_; }
  int ssl_cipher_suite() const { return ssl_cipher_suite_; }
  int srtp_cipher_suite() const { return srtp_cipher_suite_; }
  const std::string remote_ssl_certificates() const {
    return remote_ssl_certificates_;
  }

 private:
  DtlsTransportState state_;
  int tls_version_;
  int ssl_cipher_suite_;
  int srtp_cipher_suite_;
  std::string remote_ssl_certificates_;
};



class DtlsTransportObserver {
 public:

  virtual void OnStateChange(DtlsTransportInformation info) = 0;

  virtual void OnError(const int type, const char* message) = 0;

 protected:
  virtual ~DtlsTransportObserver() = default;
};


class DtlsTransport : public RefCountInterface {
 public:
  
  virtual rtc::scoped_refptr<IceTransport> ice_transport() = 0;

  virtual DtlsTransportInformation Information() = 0;

  virtual void RegisterObserver(DtlsTransportObserver* observer) = 0;

  virtual void UnregisterObserver() = 0;


};

}  // namespace webrtc

#endif  // API_DTLS_TRANSPORT_INTERFACE_H_
