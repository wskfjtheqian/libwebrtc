#ifndef LIB_WEBRTC_RTC_RTP_RECEIVER_IMPL_HXX
#define LIB_WEBRTC_RTC_RTP_RECEIVER_IMPL_HXX

#include "api/rtp_receiver_interface.h"
#include "rtc_rtp_receiver.h"

namespace libwebrtc {
class RTCRtpReceiverImpl : public RTCRtpReceiver,
                           webrtc::RtpReceiverObserverInterface {
 public:
  RTCRtpReceiverImpl(
      rtc::scoped_refptr<webrtc::RtpReceiverInterface> rtp_receiver);

  virtual scoped_refptr<RTCMediaTrack> track() const override;
  virtual scoped_refptr<RTCDtlsTransport> dtls_transport() const override;
  virtual scoped_refptr<RTCStreamIds> stream_ids() const override;
  virtual scoped_refptr<RTCMediaStreams> streams() const override;
  virtual RTCMediaType media_type() const override;
  virtual const string id() const override;
  virtual scoped_refptr<RTCRtpParameters> parameters() const override;
  virtual bool set_parameters(
      scoped_refptr<RTCRtpParameters> parameters) override;
  virtual void SetObserver(RTCRtpReceiverObserver* observer) override;
  virtual void SetJitterBufferMinimumDelay(double delay_seconds) override;
  rtc::scoped_refptr<webrtc::RtpReceiverInterface> rtp_receiver();

 private:
  rtc::scoped_refptr<webrtc::RtpReceiverInterface> rtp_receiver_;
  RTCRtpReceiverObserver* observer_;

  virtual void OnFirstPacketReceived(cricket::MediaType media_type) override;

};  // namespace libwebrtc

class RTCRtpReceiversImpl : public RTCRtpReceivers {
 public:
  RTCRtpReceiversImpl();
  RTCRtpReceiversImpl(std::vector<scoped_refptr<RTCRtpReceiver>> list);
  virtual void Add(scoped_refptr<RTCRtpReceiver> value) override;
  virtual scoped_refptr<RTCRtpReceiver> Get(int index) override;
  virtual int Size() override;
  virtual void Remove(int index) override;
  virtual void Clean() override;

  std::vector<scoped_refptr<RTCRtpReceiver>> list();

 private:
  std::vector<scoped_refptr<RTCRtpReceiver>> _list;
};

}  // namespace libwebrtc

#endif  // !LIB_WEBRTC_RTP_RECEIV