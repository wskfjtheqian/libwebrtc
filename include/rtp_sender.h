#ifndef LIB_WEBRTC_SENDER_H_
#define LIB_WEBRTC_SENDER_H_

#include <api/rtp_parameters.h>

#include "base/refcount.h"
#include "dtls_transport.h"
#include "rtc_media_track.h"
#include "rtc_media_types.h"
#include "rtc_types.h"
#include "rtp_parameters.h"
#include "dtmf_sender.h"

namespace libwebrtc {

class RtpSender : public RefCountInterface {
 public:
  virtual bool SetTrack(RTCMediaTrack* track) = 0;

  virtual scoped_refptr<RTCMediaTrack> GetTrack() const = 0;

  virtual scoped_refptr<DtlsTransport> GetDtlsTransport() const = 0;

  virtual uint32_t GetSsrc() const = 0;

  virtual MediaType GetMediaType() const = 0;

  virtual std::string Id() const = 0;

  virtual std::vector<std::string> GetStreamIds() const = 0;

  virtual void SetStreams(const std::vector<std::string>& stream_ids) {}

  virtual std::vector<scoped_refptr<RtpEncodingParameters>> InitSendEncodings()
      const = 0;

  virtual scoped_refptr<RtpParameters> GetParameters() const = 0;

  virtual const char* SetParameters(
      const scoped_refptr<RtpParameters> parameters) = 0;

  virtual scoped_refptr<DtmfSender> GetDtmfSender() const = 0;
};

}  // namespace libwebrtc

#endif  // !LIB_WEBRTC_SENDER_H_