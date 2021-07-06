#ifndef LIB_WEBRTC_RTC_VIDEO_ROTATION_H_
#define LIB_WEBRTC_RTC_VIDEO_ROTATION_H_

namespace libwebrtc {

// enum for clockwise rotation.
enum VideoRotation {
  kVideoRotation_0 = 0,
  kVideoRotation_90 = 90,
  kVideoRotation_180 = 180,
  kVideoRotation_270 = 270
};

enum class VideoContentType : uint8_t {
  UNSPECIFIED = 0,
  SCREENSHARE = 1,
};

}  // namespace webrtc

#endif  // LIB_WEBRTC_RTC_VIDEO_ROTATION_H_
