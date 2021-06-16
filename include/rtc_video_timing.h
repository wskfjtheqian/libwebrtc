#ifndef LIB_WEBRTC_RTC_VIDEO_TIMING_H_
#define LIB_WEBRTC_RTC_VIDEO_TIMING_H_

#include <stdint.h>

#include <limits>
#include <string>

#include "base/refcount.h"
#include "base/scoped_ref_ptr.h"
#include "rtc_types.h"

namespace libwebrtc {

class VideoSendTiming : public RefCountInterface {
 public:
  enum TimingFrameFlags : uint8_t {
    kNotTriggered = 0,  // Timing info valid, but not to be transmitted.
                        // Used on send-side only.
    kTriggeredByTimer = 1 << 0,  // Frame marked for tracing by periodic timer.
    kTriggeredBySize = 1 << 1,   // Frame marked for tracing due to size.
    kInvalid = std::numeric_limits<uint8_t>::max()  // Invalid, ignore!
  };

  LIB_WEBRTC_API static scoped_refptr<VideoSendTiming> Create();

  LIB_WEBRTC_API static uint16_t GetDeltaCappedMs(int64_t base_ms,
                                                  int64_t time_ms);

  virtual uint16_t GetEncodeStartDeltaMs() = 0;
  virtual void SetEncodeStartDeltaMs(uint16_t value) = 0;

  virtual uint16_t GetEncodeFinishDeltaMs() = 0;
  virtual void SetEncodeFinishDeltaMs(uint16_t value) = 0;

  virtual uint16_t GetPacketizationFinishDeltaMs() = 0;
  virtual void SetPacketizationFinishDeltaMs(uint16_t value) = 0;

  virtual uint16_t GetPacerExitDeltaMs() = 0;
  virtual void GetPacerExitDeltaMs(uint16_t value) = 0;

  virtual uint16_t GetNetworkTimestampDeltaMs() = 0;
  virtual void SetNetworkTimestampDeltaMs(uint16_t value) = 0;

  virtual uint16_t GetNetwork2TimestampDeltaMs() = 0;
  virtual void setNetwork2TimestampDeltaMs(uint16_t value) = 0;

  virtual uint8_t GetFlags() = 0;
  virtual void SetFlags(uint8_t vlaue) = 0;
};

class TimingFrameInfo : public RefCountInterface {
 public:
  LIB_WEBRTC_API static scoped_refptr<TimingFrameInfo> Create();

  virtual int64_t EndToEndDelay() const = 0;

  virtual bool IsLongerThan(scoped_refptr<TimingFrameInfo> other) const = 0;

  virtual bool IsOutlier() const = 0;

  virtual bool IsTimerTriggered() const = 0;

  virtual bool IsInvalid() const = 0;

  virtual std::string ToString() const = 0;

  virtual bool operator<(scoped_refptr<TimingFrameInfo> other) const = 0;
  virtual bool operator<=(scoped_refptr<TimingFrameInfo> other) const = 0;

  virtual uint32_t GetRtpTimestamp() = 0;
  virtual void SetRtpTimestamp(uint32_t value) = 0;

  virtual int64_t GetCaptureTimeMs() = 0;
  virtual void SetCaptureTimeMs(int64_t value) = 0;

  virtual int64_t GetEncodeStartMs() = 0;
  virtual void SetEncodeStartMs(int64_t value) = 0;

  virtual int64_t GetEncodeFinishMs() = 0;
  virtual void SetEncodeFinishMs(int64_t value) = 0;

  virtual int64_t GetPacketizationFinishMs() = 0;
  virtual void SetPacketizationFinishMs(int64_t value) = 0;

  virtual int64_t GetPacerExitMs() = 0;
  virtual void SetPacerExitMs(int64_t value) = 0;

  virtual int64_t GetNetworkTimestampMs() = 0;
  virtual void SetNetworkTimestampMs(int64_t value) = 0;

  virtual int64_t GetNetwork2TimestampMs() = 0;
  virtual void SetNetwork2TimestampMs(int64_t value) = 0;

  virtual int64_t GetReceiveStartMs() = 0;
  virtual void SetReceiveStartMs(int64_t value) = 0;

  virtual int64_t GetReceiveFinishMs() = 0;
  virtual void SetReceiveFinishMs(int64_t value) = 0;

  virtual int64_t GetDecodeStartMs() = 0;
  virtual void SetDecodeStartMs(int64_t value) = 0;

  virtual int64_t GetDecodeFinishMs() = 0;
  virtual void SetDecodeFinishMs(int64_t value) = 0;

  virtual int64_t GetRenderTimeMs() = 0;
  virtual void SetRenderTimeMs(int64_t value) = 0;

  virtual uint8_t GetFlags() = 0;
  virtual void GetFlags(uint8_t value) = 0;
};

class VideoPlayoutDelay : public RefCountInterface {
 public:
  LIB_WEBRTC_API static scoped_refptr<VideoPlayoutDelay> Create();

  virtual int GetMinMs() = 0;
  virtual void SetMaxMs(int value) = 0;

  virtual int GetMaxMs() = 0;
  virtual void SeetMaxMs(int value) = 0;

  virtual bool operator==(scoped_refptr<VideoPlayoutDelay> rhs) const = 0;
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_RTC_VIDEO_TIMING_H_
