#include "rtc_rtp_receive_imp.h"

#include "base/refcountedobject.h"
#include "rtc_audio_track_impl.h"
#include "rtc_dtls_transport_impl.h"
#include "rtc_media_stream_impl.h"
#include "rtc_rtp_parameters_impl.h"
#include "rtc_video_track_impl.h"

namespace libwebrtc {
RTCRtpReceiverImpl::RTCRtpReceiverImpl(
    rtc::scoped_refptr<webrtc::RtpReceiverInterface> rtp_receiver)
    : rtp_receiver_(rtp_receiver), observer_(nullptr) {}

rtc::scoped_refptr<webrtc::RtpReceiverInterface>
RTCRtpReceiverImpl::rtp_receiver() {
  return rtp_receiver_;
}

void RTCRtpReceiverImpl::OnFirstPacketReceived(cricket::MediaType media_type) {
  if (nullptr != observer_) {
    observer_->OnFirstPacketReceived(static_cast<RTCMediaType>(media_type));
  }
}

scoped_refptr<RTCMediaTrack> RTCRtpReceiverImpl::track() const {
  rtc::scoped_refptr<webrtc::MediaStreamTrackInterface> track =
      rtp_receiver_->track();
  if (nullptr == track.get()) {
    return scoped_refptr<RTCMediaTrack>();
  }
  if (track->kind() == webrtc::MediaStreamTrackInterface::kVideoKind) {
    return new RefCountedObject<VideoTrackImpl>(
        static_cast<webrtc::VideoTrackInterface*>(track.get()));
  } else if (track->kind() == webrtc::MediaStreamTrackInterface::kAudioKind) {
    return new RefCountedObject<AudioTrackImpl>(
        static_cast<webrtc::AudioTrackInterface*>(track.get()));
  }
  return scoped_refptr<RTCMediaTrack>();
}
scoped_refptr<RTCDtlsTransport> RTCRtpReceiverImpl::dtls_transport() const {
  if (nullptr == rtp_receiver_->dtls_transport().get()) {
    return scoped_refptr<RTCDtlsTransport>();
  }

  return new RefCountedObject<RTCDtlsTransportImpl>(
      rtp_receiver_->dtls_transport());
}

scoped_refptr<RTCStreamIds> RTCRtpReceiverImpl::stream_ids() const {
  return new RefCountedObject<RTCStreamIdsImpl>(rtp_receiver_->stream_ids());
}

scoped_refptr<RTCMediaStreams> RTCRtpReceiverImpl::streams() const {
 std:: vector<scoped_refptr<RTCMediaStream>> streams;
  for (auto item : rtp_receiver_->streams()) {
    streams.push_back(new RefCountedObject<MediaStreamImpl>(item));
  }
  return new RefCountedObject<RTCMediaStreamsImpl>(streams);
}

RTCMediaType RTCRtpReceiverImpl::media_type() const {
  return static_cast<RTCMediaType>(rtp_receiver_->media_type());
}

const string RTCRtpReceiverImpl::id() const {
  return rtp_receiver_->id().c_str();
}
scoped_refptr<RTCRtpParameters> RTCRtpReceiverImpl::parameters() const {
  return new RefCountedObject<RTCRtpParametersImpl>(
      rtp_receiver_->GetParameters());
}
bool RTCRtpReceiverImpl::set_parameters(
    scoped_refptr<RTCRtpParameters> parameters) {
  return rtp_receiver_->SetParameters(
      static_cast<RTCRtpParametersImpl*>(parameters.get())->rtp_parameters());
}
void RTCRtpReceiverImpl::SetObserver(RTCRtpReceiverObserver* observer) {
  observer_ = observer;
  if (nullptr == observer) {
    rtp_receiver_->SetObserver(nullptr);
  } else {
    rtp_receiver_->SetObserver(this);
  }
}

void RTCRtpReceiverImpl::SetJitterBufferMinimumDelay(double delay_seconds) {
  rtp_receiver_->SetJitterBufferMinimumDelay(delay_seconds);
}

scoped_refptr<RTCRtpReceivers> RTCRtpReceivers::Create() {
  return new RefCountedObject<RTCRtpReceiversImpl>();
}

RTCRtpReceiversImpl::RTCRtpReceiversImpl() {}

RTCRtpReceiversImpl::RTCRtpReceiversImpl(
    std::vector<scoped_refptr<RTCRtpReceiver>> list): _list(list) {}

void RTCRtpReceiversImpl::Add(scoped_refptr<RTCRtpReceiver> value) {
  _list.push_back(value);
}

scoped_refptr<RTCRtpReceiver> RTCRtpReceiversImpl::Get(int index) {
  return _list.at(index);
}

int RTCRtpReceiversImpl::Size() {
  return _list.size();
}

void RTCRtpReceiversImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCRtpReceiversImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCRtpReceiver>> RTCRtpReceiversImpl::list() {
  return _list;
}

}  // namespace libwebrtc
