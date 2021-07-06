#ifndef LIB_WEBRTC_RTC_VIDEO_TIMING_IMPL_H_
#define LIB_WEBRTC_RTC_VIDEO_TIMING_IMPL_H_

#include "api/video/video_timing.h"
#include "rtc_video_timing.h"

namespace libwebrtc {

class VideoSendTimingImpl : public VideoSendTiming {
 public:
  VideoSendTimingImpl();

  virtual uint16_t GetEncodeStartDeltaMs() override;
  virtual void SetEncodeStartDeltaMs(uint16_t value) override;
  virtual uint16_t GetEncodeFinishDeltaMs() override;
  virtual void SetEncodeFinishDeltaMs(uint16_t value) override;
  virtual uint16_t GetPacketizationFinishDeltaMs() override;
  virtual void SetPacketizationFinishDeltaMs(uint16_t value) override;
  virtual uint16_t GetPacerExitDeltaMs() override;
  virtual void GetPacerExitDeltaMs(uint16_t value) override;
  virtual uint16_t GetNetworkTimestampDeltaMs() override;
  virtual void SetNetworkTimestampDeltaMs(uint16_t value) override;
  virtual uint16_t GetNetwork2TimestampDeltaMs() override;
  virtual void setNetwork2TimestampDeltaMs(uint16_t value) override;
  virtual uint8_t GetFlags() override;
  virtual void SetFlags(uint8_t value) override;

  webrtc::VideoSendTiming& video_send_timing();

 private:
  webrtc::VideoSendTiming video_send_timing_;
};

class TimingFrameInfoImpl : public TimingFrameInfo {
 public:
  TimingFrameInfoImpl();
  virtual int64_t EndToEndDelay() const override;
  virtual bool IsLongerThan(
      scoped_refptr<TimingFrameInfo> other) const override;
  virtual bool IsOutlier() const override;
  virtual bool IsTimerTriggered() const override;
  virtual bool IsInvalid() const override;
  virtual std::string ToString() const override;
  virtual bool operator<(scoped_refptr<TimingFrameInfo> other) const override;
  virtual bool operator<=(scoped_refptr<TimingFrameInfo> other) const override;
  virtual uint32_t GetRtpTimestamp() override;
  virtual void SetRtpTimestamp(uint32_t value) override;
  virtual int64_t GetCaptureTimeMs() override;
  virtual void SetCaptureTimeMs(int64_t value) override;
  virtual int64_t GetEncodeStartMs() override;
  virtual void SetEncodeStartMs(int64_t value) override;
  virtual int64_t GetEncodeFinishMs() override;
  virtual void SetEncodeFinishMs(int64_t value) override;
  virtual int64_t GetPacketizationFinishMs() override;
  virtual void SetPacketizationFinishMs(int64_t value) override;
  virtual int64_t GetPacerExitMs() override;
  virtual void SetPacerExitMs(int64_t value) override;
  virtual int64_t GetNetworkTimestampMs() override;
  virtual void SetNetworkTimestampMs(int64_t value) override;
  virtual int64_t GetNetwork2TimestampMs() override;
  virtual void SetNetwork2TimestampMs(int64_t value) override;
  virtual int64_t GetReceiveStartMs() override;
  virtual void SetReceiveStartMs(int64_t value) override;
  virtual int64_t GetReceiveFinishMs() override;
  virtual void SetReceiveFinishMs(int64_t value) override;
  virtual int64_t GetDecodeStartMs() override;
  virtual void SetDecodeStartMs(int64_t value) override;
  virtual int64_t GetDecodeFinishMs() override;
  virtual void SetDecodeFinishMs(int64_t value) override;
  virtual int64_t GetRenderTimeMs() override;
  virtual void SetRenderTimeMs(int64_t value) override;
  virtual uint8_t GetFlags() override;
  virtual void GetFlags(uint8_t value) override;

  webrtc::TimingFrameInfo& timing_frame_info();

 private:
  webrtc::TimingFrameInfo timing_frame_info_;
};

class VideoPlayoutDelayImpl : public VideoPlayoutDelay {
 public:
  VideoPlayoutDelayImpl();
  virtual int GetMinMs() override;
  virtual void SetMaxMs(int value) override;
  virtual int GetMaxMs() override;
  virtual void SeetMaxMs(int value) override;
  virtual bool operator==(scoped_refptr<VideoPlayoutDelay> rhs) const override;

  webrtc::VideoPlayoutDelay& video_playout_delay();

 private:
  webrtc::VideoPlayoutDelay video_playout_delay_;
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_RTC_VIDEO_TIMING_H_
