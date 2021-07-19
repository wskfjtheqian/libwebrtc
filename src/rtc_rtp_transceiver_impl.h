#ifndef LIB_WEBRTC_RTC_RTP_TRANSCEIVER_IMPL_HXX
#define LIB_WEBRTC_RTC_RTP_TRANSCEIVER_IMPL_HXX

#include "api/rtp_transceiver_interface.h"
#include "api/scoped_refptr.h"
#include "rtc_rtp_transceiver.h"

namespace libwebrtc {
class RTCRtpTransceiverInitImpl : public RTCRtpTransceiverInit {
 public:
  RTCRtpTransceiverInitImpl();

  virtual RTCRtpTransceiverDirection direction() override;
  virtual void set_direction(RTCRtpTransceiverDirection value) override;
  virtual const scoped_refptr<RTCStreamIds> stream_ids() override;
  virtual void set_stream_ids(const scoped_refptr<RTCStreamIds> ids) override;
  virtual const scoped_refptr<RTCEncodings> send_encodings()
      override;
  virtual void set_send_encodings(
      const scoped_refptr<RTCEncodings> send_encodings)
      override;

  webrtc::RtpTransceiverInit rtp_transceiver_init() {
    return rtp_transceiver_init_;
  }

 private:
  webrtc::RtpTransceiverInit rtp_transceiver_init_;
};

class RTCRtpTransceiverImpl : public RTCRtpTransceiver {
 public:
  RTCRtpTransceiverImpl(
      rtc::scoped_refptr<webrtc::RtpTransceiverInterface> rtp_transceiver);

  virtual RTCMediaType media_type() const override;
  virtual const string mid() const override;
  virtual scoped_refptr<RTCRtpSender> sender() const override;
  virtual scoped_refptr<RTCRtpReceiver> receiver() const override;
  virtual bool Stopped() const override;
  virtual bool Stopping() const override;
  virtual RTCRtpTransceiverDirection direction() const override;
  virtual const string SetDirectionWithError(
      RTCRtpTransceiverDirection new_direction) override;
  virtual RTCRtpTransceiverDirection current_direction() const override;
  virtual RTCRtpTransceiverDirection fired_direction() const override;
  virtual const string StopStandard() override;
  virtual void StopInternal() override;

  rtc::scoped_refptr<webrtc::RtpTransceiverInterface> rtp_transceiver();

 private:
  rtc::scoped_refptr<webrtc::RtpTransceiverInterface> rtp_transceiver_;
};

class RTCRtpTransceiversImpl : public RTCRtpTransceivers {
 public:
  RTCRtpTransceiversImpl(std::vector<scoped_refptr<RTCRtpTransceiver>> list);
  virtual void Add(scoped_refptr<RTCRtpTransceiver> value) override;
  virtual scoped_refptr<RTCRtpTransceiver> Get(int index) override;
  virtual int Size() override;
  virtual void Remove(int index) override;
  virtual void Clean() override;

  std::vector<scoped_refptr<RTCRtpTransceiver>> list();

 private:
  std::vector<scoped_refptr<RTCRtpTransceiver>> _list;
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_RTC_TYPES_HXX
