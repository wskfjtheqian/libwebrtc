

#ifndef LIB_WEBRTC_RTP_HEADERS_H_
#define LIB_WEBRTC_RTP_HEADERS_H_

#include <include/color_space.h>
#include <include/rtc_video_timing.h>
#include <src/rtc_video_rotation.h>
#include <stddef.h>
#include <stdint.h>

#include <string>

#include "base/refcount.h"
#include "base/scoped_ref_ptr.h"
#include "rtc_types.h"
namespace libwebrtc {

class FeedbackRequest : public RefCountInterface {
 public:
  LIB_WEBRTC_API static scoped_refptr<FeedbackRequest> Create();

  virtual bool GetIncludeTimestamps() = 0;
  virtual void SetIncludeTimestamps(bool value) = 0;

  virtual int GetSequenceCount() = 0;
  virtual void GetSequenceCount(int value) = 0;
};

class AbsoluteCaptureTime : public RefCountInterface {
 public:
  LIB_WEBRTC_API static scoped_refptr<AbsoluteCaptureTime> Create();

  virtual uint64_t GetAbsoluteCaptureTimestamp() = 0;
  virtual void SetAbsoluteCaptureTimestamp(uint64_t value) = 0;

  virtual int64_t GetEstimatedCaptureClockOffset() = 0;
  virtual void SetEstimatedCaptureClockOffset(int64_t value) = 0;
};

class RTPHeaderExtension : public RefCountInterface {
 public:
  LIB_WEBRTC_API static scoped_refptr<RTPHeaderExtension> Create();

  LIB_WEBRTC_API static int kAbsSendTimeFraction();

  virtual uint64_t GetAbsoluteSendTimestamp() = 0;
  virtual uint64_t GetAbsoluteSendTimeDelta(uint32_t previous_sendtime) = 0;

  virtual bool GetHasTransmissionTimeOffset() = 0;
  virtual void SetHasTransmissionTimeOffset(bool value) = 0;

  virtual int32_t GetTransmissionTimeOffset() = 0;
  virtual void SetTransmissionTimeOffset(int32_t value) = 0;

  virtual bool GetHasAbsoluteSendTime() = 0;
  virtual void SetHasAbsoluteSendTime(bool value) = 0;

  virtual uint32_t GetAbsoluteSendTime() = 0;
  virtual void SetAbsoluteSendTime(uint32_t value) = 0;

  virtual scoped_refptr<AbsoluteCaptureTime> GetAbsoluteCaptureTime() = 0;
  virtual void SetAbsoluteCaptureTime(
      scoped_refptr<AbsoluteCaptureTime> value) = 0;

  virtual bool GetHasTransportSequenceNumber() = 0;
  virtual void SetHasTransportSequenceNumber(bool value) = 0;

  virtual uint16_t GetTransportSequenceNumber() = 0;
  virtual void SetTransportSequenceNumber(uint16_t value) = 0;

  virtual scoped_refptr<FeedbackRequest> GetFeedbackRequest() = 0;
  virtual void SetFeedbackRequest(scoped_refptr<FeedbackRequest> value) = 0;

  virtual bool GetHasAudioLevel() = 0;
  virtual void SetHasAudioLevel(bool value) = 0;

  virtual bool GetVoiceActivity() = 0;
  virtual void SetVoiceActivity(bool value) = 0;

  virtual uint8_t GetAudioLevel() = 0;
  virtual void SetAudioLevel(uint8_t value) = 0;

  virtual bool GetHasVideoRotation() = 0;
  virtual void SetHasVideoRotation(bool value) = 0;

  virtual VideoRotation GetVideoRotation() = 0;
  virtual void SetVideoRotation(VideoRotation value) = 0;

  virtual bool GetHasVideoContentType() = 0;
  virtual void SetHasVideoContentType(bool value) = 0;

  virtual VideoContentType GetVideoContentType() = 0;
  virtual void GetVideoContentType(VideoContentType value) = 0;

  virtual bool GetHasVideoTiming() = 0;
  virtual void SetHasVideoTiming(bool value) = 0;

  virtual scoped_refptr<VideoSendTiming> GetVideoTiming() = 0;
  virtual void SetVideoTiming(scoped_refptr<VideoSendTiming> value) = 0;

  virtual scoped_refptr<VideoPlayoutDelay> GetPlayoutDelay() = 0;
  virtual void SetPlayoutDelay(scoped_refptr<VideoPlayoutDelay> value) = 0;

  virtual std::string GetStreamId() = 0;
  virtual void SetStreamId(std::string value) = 0;

  virtual std::string GetRepairedStreamId() = 0;
  virtual void SetRepairedStreamId(std::string value) = 0;

  virtual std::string GetMid() = 0;
  virtual void SetMid(std::string value) = 0;

  virtual scoped_refptr<ColorSpace> GetColorSpace() = 0;
  virtual void SetColorSpace(scoped_refptr<ColorSpace> value) = 0;
};

enum { kRtpCsrcSize = 15 };  // RFC 3550 page 13

class RTPHeader : public RefCountInterface {
 public:
  LIB_WEBRTC_API static scoped_refptr<RTPHeader> Create();

  virtual bool GetMarkerBit() = 0;
  virtual void SetMarkerBit(bool value) = 0;

  virtual uint8_t GetPayloadType() = 0;
  virtual void SetPayloadType(uint8_t value) = 0;

  virtual uint16_t GetSequenceNumber() = 0;
  virtual void SetSequenceNumber(uint16_t value) = 0;

  virtual uint32_t GetTimestamp() = 0;
  virtual void SetTimestamp(uint32_t value) = 0;

  virtual uint32_t GetSsrc() = 0;
  virtual void SetSsrc(uint32_t value) = 0;

  virtual uint8_t GetNumCSRCs() = 0;
  virtual void SetNumCSRCs(uint8_t value) = 0;

  virtual uint32_t* GetArrOfCSRCs() = 0;
  virtual void SetArrOfCSRCs(uint32_t* value) = 0;

  virtual size_t GetPaddingLength() = 0;
  virtual void SetPaddingLength(size_t) = 0;

  virtual size_t GetHeaderLength() = 0;
  virtual void SetHeaderLength(size_t value) = 0;

  virtual int GetPayloadTypeFrequency() = 0;
  virtual void SetPayloadTypeFrequency(int value) = 0;

  virtual scoped_refptr<RTPHeaderExtension> GetExtension() = 0;
  virtual void SetExtension(scoped_refptr<RTPHeaderExtension> value) = 0;
};

enum class RtcpMode { kOff, kCompound, kReducedSize };

enum NetworkState {
  kNetworkUp,
  kNetworkDown,
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_RTP_HEADERS_H_

