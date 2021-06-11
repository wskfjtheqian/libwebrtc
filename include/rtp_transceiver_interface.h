#ifndef LIB_WEBRTC_RTP_TRANSCEIVER_H_
#define LIB_WEBRTC_RTP_TRANSCEIVER_H_
#include "base/refcount.h"
#include "rtp_sender_interface.h"
#include "rtp_receiver_interface.h"
#include "rtp_parameters.h"
#include "rtp_transceiver_direction.h"
#include "rtc_media_types.h"
#include <include/rtc_error.h>

namespace libwebrtc {

class RtpTransceiverInit : public RefCountInterface {
 public:
  RtpTransceiverInit();
  RtpTransceiverInit(const RtpTransceiverInit&);
  ~RtpTransceiverInit();
  static scoped_refptr<RtpTransceiverInit> Create() {}

  virtual RtpTransceiverDirection GetDirection() = 0;
  virtual void SetDirection(RtpTransceiverDirection value) = 0;

  virtual std::vector<std::string> GetStreamIds() = 0;
  virtual void GetStreamIds(std::vector<std::string> value) = 0;

  virtual std::vector <
      scoped_refptr<RtpEncodingParameters>> GetSendEncodings() = 0;
  virtual void SetSendEncodings(std::vector <
 scoped_refptr<RtpEncodingParameters>> value) = 0;
};


class RtpTransceiverInterface : public RefCountInterface {
 public:
  virtual MediaType GetMediaType() const = 0;

  virtual std::string GetMid() const = 0;

  virtual scoped_refptr<RtpSender> Sender() const = 0;

  virtual scoped_refptr<RtpReceiver> Receiver() const = 0;

  virtual bool Stopped() const = 0;

  virtual bool Stopping() const;

  virtual RtpTransceiverDirection direction() const = 0;

  virtual RTCError SetDirectionWithError(RtpTransceiverDirection new_direction);


  virtual absl::optional<RtpTransceiverDirection> current_direction() const = 0;


  virtual absl::optional<RtpTransceiverDirection> fired_direction() const;


  virtual RTCError StopStandard();


  virtual void StopInternal();

  virtual RTCError SetCodecPreferences(
      rtc::ArrayView<RtpCodecCapability> codecs);

  virtual std::vector<RtpCodecCapability> codec_preferences() const;

  virtual std::vector<RtpHeaderExtensionCapability> HeaderExtensionsToOffer()
      const;


  virtual std::vector<RtpHeaderExtensionCapability> HeaderExtensionsNegotiated()
      const;

  virtual webrtc::RTCError SetOfferedRtpHeaderExtensions(
      rtc::ArrayView<const RtpHeaderExtensionCapability>
          header_extensions_to_offer);

 protected:
  ~RtpTransceiver() override = default;
};

}  // namespace libwebrtc

#endif  // API_RTP_TRANSCEIVER_H_
