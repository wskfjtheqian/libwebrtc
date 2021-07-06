#ifndef LIB_WEBRTC_RTP_SENDER_IMPL_H_
#define LIB_WEBRTC_RTP_SENDER_IMPL_H_

#include "api/rtp_sender_interface.h"
#include "api/scoped_refptr.h"
#include "rtp_sender.h"

namespace libwebrtc {

class RtpSenderImpl : public RtpSender {
 public:
  RtpSenderImpl(rtc::scoped_refptr<webrtc::RtpSenderInterface> rsi);

  virtual ~RtpSenderImpl();

  virtual bool SetTrack(RTCMediaTrack* track) override;

  virtual scoped_refptr<RTCMediaTrack> GetTrack() const override;

  virtual scoped_refptr<DtlsTransport> GetDtlsTransport() const override;

  virtual uint32_t GetSsrc() const override;

  virtual MediaType GetMediaType() const override;

  virtual std::string Id() const override;
  virtual std::vector<std::string> GetStreamIds() const override;

  virtual void SetStreams(const std::vector<std::string>& stream_ids) override;

  virtual std::vector<scoped_refptr<RtpEncodingParameters>> InitSendEncodings()
      const override;

  virtual scoped_refptr<RtpParameters> GetParameters() const override;

  virtual const char* SetParameters(
      const scoped_refptr<RtpParameters> parameters) override;

  virtual scoped_refptr<DtmfSender> GetDtmfSender() const override;

  rtc::scoped_refptr<webrtc::RtpSenderInterface> rtp_sender();
 private:
  rtc::scoped_refptr<webrtc::RtpSenderInterface> rtp_sender_;
};
}  // namespace libwebrtc

#endif  // !LIB_WEBRTC_RTP_SENDER_IMPL_H_