#include "rtp_headers_imp.h"

#include <src/rtc_video_timing_impl.h>

#include "base/refcountedobject.h"
#include <src/color_space_impl.h>

namespace libwebrtc {
LIB_WEBRTC_API scoped_refptr<FeedbackRequest> FeedbackRequest::Create() {
  return new RefCountedObject<FeedbackRequestImpl>();
}

FeedbackRequestImpl::FeedbackRequestImpl() {}

bool FeedbackRequestImpl::GetIncludeTimestamps() {
  return feedback_request_.include_timestamps;
}

void FeedbackRequestImpl::SetIncludeTimestamps(bool value) {
  feedback_request_.include_timestamps = value;
}

int FeedbackRequestImpl::GetSequenceCount() {
  return feedback_request_.sequence_count;
}

void FeedbackRequestImpl::GetSequenceCount(int value) {
  feedback_request_.sequence_count = value;
}

webrtc::FeedbackRequest FeedbackRequestImpl::feedback_request() {
  return feedback_request_;
}

LIB_WEBRTC_API scoped_refptr<AbsoluteCaptureTime>
AbsoluteCaptureTime::Create() {
  return new RefCountedObject<AbsoluteCaptureTimeImpl>();
}

AbsoluteCaptureTimeImpl::AbsoluteCaptureTimeImpl() {}

uint64_t AbsoluteCaptureTimeImpl::GetAbsoluteCaptureTimestamp() {
  return absolute_capture_time_.absolute_capture_timestamp;
}

void AbsoluteCaptureTimeImpl::SetAbsoluteCaptureTimestamp(uint64_t value) {
  absolute_capture_time_.absolute_capture_timestamp = value;
}

int64_t AbsoluteCaptureTimeImpl::GetEstimatedCaptureClockOffset() {
  return absolute_capture_time_.estimated_capture_clock_offset.value();
}

void AbsoluteCaptureTimeImpl::SetEstimatedCaptureClockOffset(int64_t value) {
  absolute_capture_time_.estimated_capture_clock_offset = value;
}

webrtc::AbsoluteCaptureTime AbsoluteCaptureTimeImpl::absolute_capture_time() {
  return absolute_capture_time_;
  ;
}

LIB_WEBRTC_API scoped_refptr<RTPHeader> RTPHeader::Create() {
  return new RefCountedObject<RTPHeaderImpl>();
}

RTPHeaderImpl::RTPHeaderImpl() {}

bool RTPHeaderImpl::GetMarkerBit() {
  return rtp_header_.markerBit;
}

void RTPHeaderImpl::SetMarkerBit(bool value) {
  rtp_header_.markerBit = value;
}

uint8_t RTPHeaderImpl::GetPayloadType() {
  return rtp_header_.payloadType;
}

void RTPHeaderImpl::SetPayloadType(uint8_t value) {
  rtp_header_.payloadType = value;
}

uint16_t RTPHeaderImpl::GetSequenceNumber() {
  return rtp_header_.sequenceNumber;
}

void RTPHeaderImpl::SetSequenceNumber(uint16_t value) {
  rtp_header_.sequenceNumber = value;
}

uint32_t RTPHeaderImpl::GetTimestamp() {
  return rtp_header_.timestamp;
}

void RTPHeaderImpl::SetTimestamp(uint32_t value) {
  rtp_header_.timestamp = value;
}

uint32_t RTPHeaderImpl::GetSsrc() {
  return rtp_header_.ssrc;
}

void RTPHeaderImpl::SetSsrc(uint32_t value) {
  rtp_header_.ssrc = value;
}

uint8_t RTPHeaderImpl::GetNumCSRCs() {
  return rtp_header_.numCSRCs;
}

void RTPHeaderImpl::SetNumCSRCs(uint8_t value) {
  rtp_header_.numCSRCs = value;
}

uint32_t* RTPHeaderImpl::GetArrOfCSRCs() {
  return rtp_header_.arrOfCSRCs;
}

void RTPHeaderImpl::SetArrOfCSRCs(uint32_t* value) {
  std::copy(value, value + kRtpCsrcSize, rtp_header_.arrOfCSRCs);
}

size_t RTPHeaderImpl::GetPaddingLength() {
  return rtp_header_.paddingLength;
}

void RTPHeaderImpl::SetPaddingLength(size_t value) {
  rtp_header_.paddingLength = value;
}

size_t RTPHeaderImpl::GetHeaderLength() {
  return rtp_header_.headerLength;
}

void RTPHeaderImpl::SetHeaderLength(size_t value) {
  rtp_header_.headerLength = value;
}

int RTPHeaderImpl::GetPayloadTypeFrequency() {
  return rtp_header_.payload_type_frequency;
}

void RTPHeaderImpl::SetPayloadTypeFrequency(int value) {
  rtp_header_.payload_type_frequency = value;
}

scoped_refptr<RTPHeaderExtension> RTPHeaderImpl::GetExtension() {
  return new RefCountedObject<RTPHeaderExtensionImpl>(rtp_header_.extension);
}

void RTPHeaderImpl::SetExtension(scoped_refptr<RTPHeaderExtension> value) {
  RTPHeaderExtensionImpl* impl =
      static_cast<RTPHeaderExtensionImpl*>(value.get());
  rtp_header_.extension = impl->rtp_header_extension();
}

webrtc::RTPHeader RTPHeaderImpl::rtp_header() {
  return rtp_header_;
}

LIB_WEBRTC_API scoped_refptr<RTPHeaderExtension> RTPHeaderExtension::Create() {
  new RefCountedObject<RTPHeaderExtensionImpl>();
}

LIB_WEBRTC_API int RTPHeaderExtension::kAbsSendTimeFraction() {
  return webrtc::RTPHeaderExtension::kAbsSendTimeFraction;
}

RTPHeaderExtensionImpl::RTPHeaderExtensionImpl(
    webrtc::RTPHeaderExtension rtp_header_extension)
    : rtp_header_extension_(rtp_header_extension) {}

webrtc::RTPHeaderExtension RTPHeaderExtensionImpl::rtp_header_extension() {
  return rtp_header_extension_;
}

uint64_t RTPHeaderExtensionImpl::GetAbsoluteSendTimestamp() {
  return rtp_header_extension_.GetAbsoluteSendTimestamp().us();
}

uint64_t RTPHeaderExtensionImpl::GetAbsoluteSendTimeDelta(
    uint32_t previous_sendtime) {
  return rtp_header_extension_.GetAbsoluteSendTimeDelta(previous_sendtime).us();
}

bool RTPHeaderExtensionImpl::GetHasTransmissionTimeOffset() {
  return rtp_header_extension_.hasTransmissionTimeOffset;
}

void RTPHeaderExtensionImpl::SetHasTransmissionTimeOffset(bool value) {
  rtp_header_extension_.hasTransmissionTimeOffset = value;
}

int32_t RTPHeaderExtensionImpl::GetTransmissionTimeOffset() {
  return rtp_header_extension_.transmissionTimeOffset;
}

void RTPHeaderExtensionImpl::SetTransmissionTimeOffset(int32_t value) {
  rtp_header_extension_.transmissionTimeOffset = value;
}

bool RTPHeaderExtensionImpl::GetHasAbsoluteSendTime() {
  return rtp_header_extension_.hasAbsoluteSendTime;
}

void RTPHeaderExtensionImpl::SetHasAbsoluteSendTime(bool value) {
  rtp_header_extension_.hasAbsoluteSendTime = value;
}

uint32_t RTPHeaderExtensionImpl::GetAbsoluteSendTime() {
  return rtp_header_extension_.absoluteSendTime;
}

void RTPHeaderExtensionImpl::SetAbsoluteSendTime(uint32_t value) {
  rtp_header_extension_.absoluteSendTime = value;
}

scoped_refptr<AbsoluteCaptureTime>
RTPHeaderExtensionImpl::GetAbsoluteCaptureTime() {
  return new RefCountedObject<AbsoluteCaptureTimeImpl>(
      rtp_header_extension_.absolute_capture_time);
}

void RTPHeaderExtensionImpl::SetAbsoluteCaptureTime(
    scoped_refptr<AbsoluteCaptureTime> value) {
  AbsoluteCaptureTimeImpl* impl =
      static_cast<AbsoluteCaptureTimeImpl*>(value.get());
  rtp_header_extension_.absolute_capture_time = impl->absolute_capture_time();
}

bool RTPHeaderExtensionImpl::GetHasTransportSequenceNumber() {
  return rtp_header_extension_.hasTransportSequenceNumber;
}

void RTPHeaderExtensionImpl::SetHasTransportSequenceNumber(bool value) {
  rtp_header_extension_.hasTransportSequenceNumber = value;
}

uint16_t RTPHeaderExtensionImpl::GetTransportSequenceNumber() {
  return rtp_header_extension_.transportSequenceNumber;
}

void RTPHeaderExtensionImpl::SetTransportSequenceNumber(uint16_t value) {
  rtp_header_extension_.transportSequenceNumber = value;
}

scoped_refptr<FeedbackRequest> RTPHeaderExtensionImpl::GetFeedbackRequest() {
  return new RefCountedObject<FeedbackRequestImpl>(
      rtp_header_extension_.feedback_request);
}

void RTPHeaderExtensionImpl::SetFeedbackRequest(
    scoped_refptr<FeedbackRequest> value) {
  FeedbackRequestImpl* impl = static_cast<FeedbackRequestImpl*>(value.get());
  rtp_header_extension_.feedback_request = impl->feedback_request();
}

bool RTPHeaderExtensionImpl::GetHasAudioLevel() {
  return rtp_header_extension_.hasAudioLevel;
}

void RTPHeaderExtensionImpl::SetHasAudioLevel(bool value) {
  rtp_header_extension_.hasAudioLevel = value;
}

bool RTPHeaderExtensionImpl::GetVoiceActivity() {
  return rtp_header_extension_.voiceActivity;
}

void RTPHeaderExtensionImpl::SetVoiceActivity(bool value) {
  rtp_header_extension_.voiceActivity = value;
}

uint8_t RTPHeaderExtensionImpl::GetAudioLevel() {
  return rtp_header_extension_.audioLevel;
}

void RTPHeaderExtensionImpl::SetAudioLevel(uint8_t value) {
  rtp_header_extension_.audioLevel = value;
}

bool RTPHeaderExtensionImpl::GetHasVideoRotation() {
  return rtp_header_extension_.hasVideoRotation;
}

void RTPHeaderExtensionImpl::SetHasVideoRotation(bool value) {
  rtp_header_extension_.hasVideoRotation = value;
}

VideoRotation RTPHeaderExtensionImpl::GetVideoRotation() {
  return static_cast<VideoRotation>(rtp_header_extension_.videoRotation);
}

void RTPHeaderExtensionImpl::SetVideoRotation(VideoRotation value) {
  rtp_header_extension_.videoRotation =
      static_cast<webrtc::VideoRotation>(value);
}

bool RTPHeaderExtensionImpl::GetHasVideoContentType() {
  return rtp_header_extension_.hasVideoContentType;
}

void RTPHeaderExtensionImpl::SetHasVideoContentType(bool value) {
  rtp_header_extension_.hasVideoContentType = value;
}

VideoContentType RTPHeaderExtensionImpl::GetVideoContentType() {
  return static_cast<VideoContentType>(rtp_header_extension_.videoContentType);
}

void RTPHeaderExtensionImpl::GetVideoContentType(VideoContentType value) {
  rtp_header_extension_.videoContentType =
      static_cast<webrtc::VideoContentType>(value);
}

bool RTPHeaderExtensionImpl::GetHasVideoTiming() {
  return rtp_header_extension_.has_video_timing;
}

void RTPHeaderExtensionImpl::SetHasVideoTiming(bool value) {
  rtp_header_extension_.has_video_timing = value;
}

scoped_refptr<VideoSendTiming> RTPHeaderExtensionImpl::GetVideoTiming() {
  return new RefCountedObject<VideoSendTimingImpl>(
      rtp_header_extension_.video_timing);
}

void RTPHeaderExtensionImpl::SetVideoTiming(
    scoped_refptr<VideoSendTiming> value) {
  VideoSendTimingImpl* impl = static_cast<VideoSendTimingImpl*>(value.get());
  rtp_header_extension_.video_timing = impl->video_send_timing();
}

scoped_refptr<VideoPlayoutDelay> RTPHeaderExtensionImpl::GetPlayoutDelay() {
  return new RefCountedObject<VideoPlayoutDelayImpl>(
      rtp_header_extension_.playout_delay);
}

void RTPHeaderExtensionImpl::SetPlayoutDelay(
    scoped_refptr<VideoPlayoutDelay> value) {
  VideoPlayoutDelayImpl* impl =
      static_cast<VideoPlayoutDelayImpl*>(value.get());
  rtp_header_extension_.playout_delay = impl->video_playout_delay();
}

std::string RTPHeaderExtensionImpl::GetStreamId() {
  return rtp_header_extension_.stream_id;
}

void RTPHeaderExtensionImpl::SetStreamId(std::string value) {
  rtp_header_extension_.stream_id = value;
}

std::string RTPHeaderExtensionImpl::GetRepairedStreamId() {
  return rtp_header_extension_.repaired_stream_id;
}

void RTPHeaderExtensionImpl::SetRepairedStreamId(std::string value) {
  rtp_header_extension_.repaired_stream_id = value;
}

std::string RTPHeaderExtensionImpl::GetMid() {
  return rtp_header_extension_.mid;
}

void RTPHeaderExtensionImpl::SetMid(std::string value) {
  rtp_header_extension_.mid = value;
}

scoped_refptr<ColorSpace> RTPHeaderExtensionImpl::GetColorSpace() {
  return new RefCountedObject<ColorSpaceImpl>(
      rtp_header_extension_.color_space.value());
}

void RTPHeaderExtensionImpl::SetColorSpace(scoped_refptr<ColorSpace> value) {
  ColorSpaceImpl* impl = static_cast<ColorSpaceImpl*>(value.get());
  rtp_header_extension_.color_space = impl->color_space();
}

}  // namespace libwebrtc