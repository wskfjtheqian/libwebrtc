#include "rtp_headers_imp.h"

#include "base/refcountedobject.h"

namespace libwebrtc {
scoped_refptr<FeedbackRequest> FeedbackRequest::Create() {
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

scoped_refptr<AbsoluteCaptureTime> AbsoluteCaptureTime::Create() {
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

uint16_t RTPHeaderImpl::GetSequenceNumber( ) {
  return rtp_header_.sequenceNumber;
}

void RTPHeaderImpl::SetSequenceNumber(uint16_t value) {
  rtp_header_.sequenceNumber = value;
}

uint32_t RTPHeaderImpl::GetTimestamp( ) {
  return rtp_header_.timestamp ;
}

void RTPHeaderImpl::SetTimestamp(uint32_t value) {
  rtp_header_.timestamp=value;
}

uint32_t RTPHeaderImpl::GetSsrc( ) {
  return rtp_header_.ssrc;
}

void RTPHeaderImpl::SetSsrc(uint32_t value) {
  rtp_header_.ssrc = value;
}

uint8_t RTPHeaderImpl::GetNumCSRCs( ) {
  return rtp_header_.numCSRCs;
}

void RTPHeaderImpl::SetNumCSRCs(uint8_t value) {
  rtp_header_.numCSRCs = value;
}

uint32_t* RTPHeaderImpl::GetArrOfCSRCs( ) {
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
	
RTPHeaderExtensionImpl::RTPHeaderExtensionImpl(
    webrtc::RTPHeaderExtension rtp_header_extension)
    : rtp_header_extension_(rtp_header_extension) {}

webrtc::RTPHeaderExtension RTPHeaderExtensionImpl::rtp_header_extension() {
  return rtp_header_extension_;
}

}  // namespace libwebrtc