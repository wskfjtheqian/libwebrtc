#ifndef LIB_WEBRTC_TRANSCEIVER_DIRECTION_H_
#define LIB_WEBRTC_TRANSCEIVER_DIRECTION_H_

namespace libwebrtc {

enum class RtpTransceiverDirection {
  kSendRecv,
  kSendOnly,
  kRecvOnly,
  kInactive,
  kStopped,
};

}  // namespace libwebrtc

#endif  // API_RTP_TRANSCEIVER_DIRECTION_H_
