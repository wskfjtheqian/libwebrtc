#ifndef LIB_WEBRTC_RTP_RECEIVER_IMPL_H_
#define LIB_WEBRTC_RTP_RECEIVER_IMPL_H_

#include "rtp_receiver.h"
#include "api/rtp_receiver_interface.h"

namespace libwebrtc {
class RtpReceiverImpl : public RtpReceiver {

private:
  rtc::scoped_refptr<webrtc::RtpReceiverInterface> rtp_receiver_;
};  // namespace libwebrtc

}  // namespace libwebrtc

#endif  // !LIB_WEBRTC_RTP_RECEIV