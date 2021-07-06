

#ifndef LIB_WEBRTC_RTP_HEADERS_IMPL_H_
#define LIB_WEBRTC_RTP_HEADERS_IMPL_H_

#include "api/rtp_headers.h"
#include "rtp_headers.h"

namespace libwebrtc {

class FeedbackRequestImpl : public FeedbackRequest {
 public:
  FeedbackRequestImpl();
  virtual bool GetIncludeTimestamps() override;
  virtual void SetIncludeTimestamps(bool value) override;

  virtual int GetSequenceCount() override;
  virtual void GetSequenceCount(int value) override;

  webrtc::FeedbackRequest feedback_request();

 private:
  webrtc::FeedbackRequest feedback_request_;
};

class AbsoluteCaptureTimeImpl : public AbsoluteCaptureTime {
 public:
  AbsoluteCaptureTimeImpl();

  virtual uint64_t GetAbsoluteCaptureTimestamp() override;
  virtual void SetAbsoluteCaptureTimestamp(uint64_t value) override;

  virtual int64_t GetEstimatedCaptureClockOffset() override;
  virtual void SetEstimatedCaptureClockOffset(int64_t value) override;


  webrtc::AbsoluteCaptureTime absolute_capture_time();

 private:
  webrtc::AbsoluteCaptureTime absolute_capture_time_;
};

class RTPHeaderExtensionImpl : public RTPHeaderExtension {
 public:
  RTPHeaderExtensionImpl(webrtc::RTPHeaderExtension rtp_header_extension);

  virtual uint64_t GetAbsoluteSendTimestamp() override;
  virtual uint64_t GetAbsoluteSendTimeDelta(
      uint32_t previous_sendtime) override;
  virtual bool GetHasTransmissionTimeOffset() override;
  virtual void SetHasTransmissionTimeOffset(bool value) override;
  virtual int32_t GetTransmissionTimeOffset() override;
  virtual void SetTransmissionTimeOffset(int32_t value) override;
  virtual bool GetHasAbsoluteSendTime() override;
  virtual void SetHasAbsoluteSendTime(bool value) override;
  virtual uint32_t GetAbsoluteSendTime() override;
  virtual void SetAbsoluteSendTime(uint32_t value) override;
  virtual scoped_refptr<AbsoluteCaptureTime> GetAbsoluteCaptureTime() override;
  virtual void SetAbsoluteCaptureTime(
      scoped_refptr<AbsoluteCaptureTime> value) override;
  virtual bool GetHasTransportSequenceNumber() override;
  virtual void SetHasTransportSequenceNumber(bool value) override;
  virtual uint16_t GetTransportSequenceNumber() override;
  virtual void SetTransportSequenceNumber(uint16_t value) override;
  virtual scoped_refptr<FeedbackRequest> GetFeedbackRequest() override;
  virtual void SetFeedbackRequest(
      scoped_refptr<FeedbackRequest> value) override;
  virtual bool GetHasAudioLevel() override;
  virtual void SetHasAudioLevel(bool value) override;
  virtual bool GetVoiceActivity() override;
  virtual void SetVoiceActivity(bool value) override;
  virtual uint8_t GetAudioLevel() override;
  virtual void SetAudioLevel(uint8_t value) override;
  virtual bool GetHasVideoRotation() override;
  virtual void SetHasVideoRotation(bool value) override;
  virtual VideoRotation GetVideoRotation() override;
  virtual void SetVideoRotation(VideoRotation value) override;
  virtual bool GetHasVideoContentType() override;
  virtual void SetHasVideoContentType(bool value) override;
  virtual VideoContentType GetVideoContentType() override;
  virtual void GetVideoContentType(VideoContentType value) override;
  virtual bool GetHasVideoTiming() override;
  virtual void SetHasVideoTiming(bool value) override;
  virtual scoped_refptr<VideoSendTiming> GetVideoTiming() override;
  virtual void SetVideoTiming(scoped_refptr<VideoSendTiming> value) override;
  virtual scoped_refptr<VideoPlayoutDelay> GetPlayoutDelay() override;
  virtual void SetPlayoutDelay(scoped_refptr<VideoPlayoutDelay> value) override;
  virtual std::string GetStreamId() override;
  virtual void SetStreamId(std::string value) override;
  virtual std::string GetRepairedStreamId() override;
  virtual void SetRepairedStreamId(std::string value) override;
  virtual std::string GetMid() override;
  virtual void SetMid(std::string value) override;
  virtual scoped_refptr<ColorSpace> GetColorSpace() override;
  virtual void SetColorSpace(scoped_refptr<ColorSpace> value) override;

  webrtc::RTPHeaderExtension rtp_header_extension();

 private:
  webrtc::RTPHeaderExtension rtp_header_extension_;

};

class RTPHeaderImpl : public RTPHeader {
 public:
  RTPHeaderImpl();

  virtual bool GetMarkerBit() override;
  virtual void SetMarkerBit(bool value) override;

  virtual uint8_t GetPayloadType() override;
  virtual void SetPayloadType(uint8_t value) override;

  virtual uint16_t GetSequenceNumber() override;
  virtual void SetSequenceNumber(uint16_t value) override;

  virtual uint32_t GetTimestamp() override;
  virtual void SetTimestamp(uint32_t value) override;

  virtual uint32_t GetSsrc() override;
  virtual void SetSsrc(uint32_t value) override;

  virtual uint8_t GetNumCSRCs() override;
  virtual void SetNumCSRCs(uint8_t value) override;

  virtual uint32_t* GetArrOfCSRCs() override;
  virtual void SetArrOfCSRCs(uint32_t* value) override;

  virtual size_t GetPaddingLength() override;
  virtual void SetPaddingLength(size_t value) override;

  virtual size_t GetHeaderLength() override;
  virtual void SetHeaderLength(size_t value) override;

  virtual int GetPayloadTypeFrequency() override;
  virtual void SetPayloadTypeFrequency(int value) override;

  virtual scoped_refptr<RTPHeaderExtension> GetExtension() override;
  virtual void SetExtension(scoped_refptr<RTPHeaderExtension> value) override;


  webrtc::RTPHeader rtp_header();

 private:
  webrtc::RTPHeader rtp_header_;
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_RTP_HEADERS_H_
