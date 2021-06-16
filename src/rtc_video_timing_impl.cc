#include "rtc_video_timing_impl.h"

#include "base/refcountedobject.h"
namespace libwebrtc {
LIB_WEBRTC_API scoped_refptr<VideoSendTiming> VideoSendTiming::Create() {
  return new RefCountedObject<VideoSendTimingImpl>();
}

LIB_WEBRTC_API uint16_t VideoSendTiming::GetDeltaCappedMs(int64_t base_ms,
                                                          int64_t time_ms) {
  return webrtc::VideoSendTiming::GetDeltaCappedMs(base_ms, time_ms);
}

VideoSendTimingImpl::VideoSendTimingImpl() {}

uint16_t VideoSendTimingImpl::GetEncodeStartDeltaMs() {
  return video_send_timing_.encode_start_delta_ms;
}

void VideoSendTimingImpl::SetEncodeStartDeltaMs(uint16_t value) {
  video_send_timing_.encode_start_delta_ms = value;
}

uint16_t VideoSendTimingImpl::GetEncodeFinishDeltaMs() {
  return video_send_timing_.encode_finish_delta_ms;
}

void VideoSendTimingImpl::SetEncodeFinishDeltaMs(uint16_t value) {
  video_send_timing_.encode_finish_delta_ms = value;
}

uint16_t VideoSendTimingImpl::GetPacketizationFinishDeltaMs() {
  return video_send_timing_.packetization_finish_delta_ms;
}

void VideoSendTimingImpl::SetPacketizationFinishDeltaMs(uint16_t value) {
  video_send_timing_.packetization_finish_delta_ms = value;
}

uint16_t VideoSendTimingImpl::GetPacerExitDeltaMs() {
  return video_send_timing_.pacer_exit_delta_ms;
}

void VideoSendTimingImpl::GetPacerExitDeltaMs(uint16_t value) {
  video_send_timing_.pacer_exit_delta_ms = value;
}

uint16_t VideoSendTimingImpl::GetNetworkTimestampDeltaMs() {
  return video_send_timing_.network_timestamp_delta_ms;
}

void VideoSendTimingImpl::SetNetworkTimestampDeltaMs(uint16_t value) {
  video_send_timing_.network_timestamp_delta_ms = value;
}

uint16_t VideoSendTimingImpl::GetNetwork2TimestampDeltaMs() {
  return video_send_timing_.network2_timestamp_delta_ms;
}

void VideoSendTimingImpl::setNetwork2TimestampDeltaMs(uint16_t value) {
  video_send_timing_.network2_timestamp_delta_ms = value;
}

uint8_t VideoSendTimingImpl::GetFlags() {
  return video_send_timing_.flags;
}

void VideoSendTimingImpl::SetFlags(uint8_t value) {
  video_send_timing_.flags = value;
}

webrtc::VideoSendTiming& VideoSendTimingImpl::video_send_timing() {
  return video_send_timing_;
}

LIB_WEBRTC_API scoped_refptr<TimingFrameInfo> TimingFrameInfo::Create() {
  return new RefCountedObject<TimingFrameInfoImpl>();
}

TimingFrameInfoImpl::TimingFrameInfoImpl() {}

int64_t TimingFrameInfoImpl::EndToEndDelay() const {
  return timing_frame_info_.EndToEndDelay();
}

bool TimingFrameInfoImpl::IsLongerThan(
    scoped_refptr<TimingFrameInfo> other) const {
  TimingFrameInfoImpl* impl = static_cast<TimingFrameInfoImpl*>(other.get());
  return timing_frame_info_.IsLongerThan(impl->timing_frame_info());
}

bool TimingFrameInfoImpl::IsOutlier() const {
  return timing_frame_info_.IsOutlier();
}

bool TimingFrameInfoImpl::IsTimerTriggered() const {
  return timing_frame_info_.IsTimerTriggered();
}

bool TimingFrameInfoImpl::IsInvalid() const {
  return timing_frame_info_.IsInvalid();
}

std::string TimingFrameInfoImpl::ToString() const {
  return timing_frame_info_.ToString();
}

bool TimingFrameInfoImpl::operator<(
    scoped_refptr<TimingFrameInfo> other) const {
  TimingFrameInfoImpl* impl = static_cast<TimingFrameInfoImpl*>(other.get());
  return timing_frame_info_<impl->timing_frame_info();
}

bool TimingFrameInfoImpl::operator<=(
    scoped_refptr<TimingFrameInfo> other) const {
  TimingFrameInfoImpl* impl = static_cast<TimingFrameInfoImpl*>(other.get());
  return timing_frame_info_ <= impl->timing_frame_info();
}

uint32_t TimingFrameInfoImpl::GetRtpTimestamp() {
  return timing_frame_info_.rtp_timestamp;
}

void TimingFrameInfoImpl::SetRtpTimestamp(uint32_t value) {
  timing_frame_info_.rtp_timestamp = value;
}

int64_t TimingFrameInfoImpl::GetCaptureTimeMs() {
  return timing_frame_info_.capture_time_ms;
}

void TimingFrameInfoImpl::SetCaptureTimeMs(int64_t value) {
  timing_frame_info_.capture_time_ms = value;
}

int64_t TimingFrameInfoImpl::GetEncodeStartMs() {
  return timing_frame_info_.encode_start_ms;
}

void TimingFrameInfoImpl::SetEncodeStartMs(int64_t value) {
  timing_frame_info_.encode_start_ms = value;
}

int64_t TimingFrameInfoImpl::GetEncodeFinishMs() {
  return timing_frame_info_.encode_finish_ms;
}

void TimingFrameInfoImpl::SetEncodeFinishMs(int64_t value) {
  timing_frame_info_.encode_finish_ms = value;
}

int64_t TimingFrameInfoImpl::GetPacketizationFinishMs() {
  return timing_frame_info_.packetization_finish_ms;
}

void TimingFrameInfoImpl::SetPacketizationFinishMs(int64_t value) {
  timing_frame_info_.packetization_finish_ms = value;
}

int64_t TimingFrameInfoImpl::GetPacerExitMs() {
  return timing_frame_info_.pacer_exit_ms;
}

void TimingFrameInfoImpl::SetPacerExitMs(int64_t value) {
  timing_frame_info_.pacer_exit_ms = value;
}

int64_t TimingFrameInfoImpl::GetNetworkTimestampMs() {
  return timing_frame_info_.network_timestamp_ms;
}

void TimingFrameInfoImpl::SetNetworkTimestampMs(int64_t value) {
  timing_frame_info_.network_timestamp_ms = value;
}

int64_t TimingFrameInfoImpl::GetNetwork2TimestampMs() {
  return timing_frame_info_.network2_timestamp_ms;
}

void TimingFrameInfoImpl::SetNetwork2TimestampMs(int64_t value) {
  timing_frame_info_.network2_timestamp_ms = value;
}

int64_t TimingFrameInfoImpl::GetReceiveStartMs() {
  return timing_frame_info_.receive_start_ms;
}

void TimingFrameInfoImpl::SetReceiveStartMs(int64_t value) {
  timing_frame_info_.receive_finish_ms = value;
}

int64_t TimingFrameInfoImpl::GetReceiveFinishMs() {
  return timing_frame_info_.receive_finish_ms;
}

void TimingFrameInfoImpl::SetReceiveFinishMs(int64_t value) {
  timing_frame_info_.receive_finish_ms = value;
}

int64_t TimingFrameInfoImpl::GetDecodeStartMs() {
  return timing_frame_info_.decode_start_ms;
}

void TimingFrameInfoImpl::SetDecodeStartMs(int64_t value) {
  timing_frame_info_.decode_start_ms = value;
}

int64_t TimingFrameInfoImpl::GetDecodeFinishMs() {
  return timing_frame_info_.decode_finish_ms;
}

void TimingFrameInfoImpl::SetDecodeFinishMs(int64_t value) {
  timing_frame_info_.decode_finish_ms = value;
}

int64_t TimingFrameInfoImpl::GetRenderTimeMs() {
  return timing_frame_info_.render_time_ms ;
}

void TimingFrameInfoImpl::SetRenderTimeMs(int64_t value) {
  timing_frame_info_.render_time_ms = value;
}

uint8_t TimingFrameInfoImpl::GetFlags() {
  return timing_frame_info_.flags;
}

void TimingFrameInfoImpl::GetFlags(uint8_t value) {
  timing_frame_info_.flags = value;
}

webrtc::TimingFrameInfo& TimingFrameInfoImpl::timing_frame_info() {
  return timing_frame_info_;
}

  LIB_WEBRTC_API scoped_refptr<VideoPlayoutDelay> VideoPlayoutDelay::Create() {
  new RefCountedObject<VideoPlayoutDelayImpl>();
  }

VideoPlayoutDelayImpl::VideoPlayoutDelayImpl() {}

int VideoPlayoutDelayImpl::GetMinMs() {
  return video_playout_delay_.min_ms;
}

void VideoPlayoutDelayImpl::SetMaxMs(int value) {
  video_playout_delay_.min_ms = value;
}

int VideoPlayoutDelayImpl::GetMaxMs() {
  return video_playout_delay_.max_ms;
}

void VideoPlayoutDelayImpl::SeetMaxMs(int value) {
  video_playout_delay_.max_ms = value;
}

bool VideoPlayoutDelayImpl::operator==(
    scoped_refptr<VideoPlayoutDelay> rhs) const {
  VideoPlayoutDelayImpl* impl = static_cast<VideoPlayoutDelayImpl*>(rhs.get());
  return video_playout_delay_ == impl->video_playout_delay();
}

webrtc::VideoPlayoutDelay& VideoPlayoutDelayImpl::video_playout_delay() {
  return video_playout_delay_;
}

}  // namespace libwebrtc