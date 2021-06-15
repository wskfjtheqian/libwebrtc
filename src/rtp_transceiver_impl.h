#ifndef LIB_WEBRTC_RTP_TRANSCEIVER_IMPL_H_
#define LIB_WEBRTC_RTP_TRANSCEIVER_IMPL_H_

#include <pc/rtp_transceiver.h>

#include "rtp_transceiver.h"

namespace libwebrtc {
class RtpTransceiverInitImpl : public RtpTransceiverInit {
 public:
  RtpTransceiverInitImpl();
  RtpTransceiverInitImpl(const RtpTransceiverInit&);
  ~RtpTransceiverInitImpl();

  RtpTransceiverDirection GetDirection() override;
  void SetDirection(RtpTransceiverDirection value) override;

  std::vector<std::string> GetStreamIds();
  void GetStreamIds(std::vector<std::string> value) override;

  std::vector<scoped_refptr<RtpEncodingParameters>> GetSendEncodings() override;
  void SetSendEncodings(
      std::vector<scoped_refptr<RtpEncodingParameters>> value) override;

 public:
  scoped_refptr<webrtc::RtpTransceiverInit> rtc_init();

 private:
  scoped_refptr<webrtc::RtpTransceiverInit> rtp_transceiver_init_;
};

class RtpTransceiverImpl : public RtpTransceiver {
 public:
  MediaType GetMediaType() const;

  std::string GetMid() const;

 scoped_refptr<RtpSender> Sender() const;

 scoped_refptr<RtpReceiver> Receiver() const;

  bool Stopped() const;

  bool Stopping() const;

  RtpTransceiverDirection direction() const;

  RTCError SetDirectionWithError(RtpTransceiverDirection new_direction);

  RtpTransceiverDirection current_direction() const;

  RtpTransceiverDirection fired_direction() const;

  RTCError StopStandard();

  void StopInternal();

  RTCError SetCodecPreferences(rtc::ArrayView<RtpCodecCapability> codecs);

  std::vector<RtpCodecCapability> codec_preferences() const;

  std::vector<RtpHeaderExtensionCapability> HeaderExtensionsToOffer() const;

  std::vector<RtpHeaderExtensionCapability> HeaderExtensionsNegotiated() const;

  webrtc::RTCError SetOfferedRtpHeaderExtensions(
      rtc::ArrayView<const RtpHeaderExtensionCapability>
          header_extensions_to_offer);


  void SetRtpTransceiverInterface(rtc::scoped_refptr<webrtc::RtpTransceiverInterface> rti);

  rtc::scoped_refptr<webrtc::RtpTransceiverInterface> GetRtpTransceiverInterface();

 protected:
  ~RtpTransceiverImpl() override = default;

 private:
  rtc::scoped_refptr<webrtc::RtpTransceiverInterface>
      rtp_transceiver_;
};

}  // namespace libwebrtc

#endif  // API_RTP_TRANSCEIVER_H_
