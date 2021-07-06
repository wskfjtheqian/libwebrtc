#include "api/scoped_refptr.h"
#include "base/refcountedobject.h"
#include "dtls_transport_impl.h"
#include "rtc_audio_track_impl.h"
#include "rtc_video_track_impl.h"
#include "rtp_parameters_impl.h"
#include "rtp_sender_impl.h"
#include "dtls_transport_impl.h"
#include "dtmf_sender_impl.h"

namespace libwebrtc {
RtpSenderImpl::RtpSenderImpl(rtc::scoped_refptr<webrtc::RtpSenderInterface> rsi)
    : rtp_sender_(rsi) {}

RtpSenderImpl::~RtpSenderImpl() {}

bool RtpSenderImpl::SetTrack(RTCMediaTrack* track) {
  if (track->kind() == webrtc::MediaStreamTrackInterface::kVideoKind) {
    VideoTrackImpl* impl = static_cast<VideoTrackImpl*>(track);
    return rtp_sender_->SetTrack(impl->rtc_track());

  } else if (track->kind() == webrtc::MediaStreamTrackInterface::kAudioKind) {
    AudioTrackImpl* impl = static_cast<AudioTrackImpl*>(track);
    return rtp_sender_->SetTrack(impl->rtc_track());
  }
}

scoped_refptr<RTCMediaTrack> RtpSenderImpl::GetTrack() const {
  rtc::scoped_refptr<webrtc::MediaStreamTrackInterface> track =
      rtp_sender_->track();

  if (track->kind() == webrtc::MediaStreamTrackInterface::kVideoKind) {
    return new RefCountedObject<VideoTrackImpl>(track);
  } else if (track->kind() == webrtc::MediaStreamTrackInterface::kAudioKind) {
    return new RefCountedObject<AudioTrackImpl>(track);
  }
}

scoped_refptr<DtlsTransport> RtpSenderImpl::GetDtlsTransport() const {
  return new RefCountedObject<DtlsTransportImpl>(rtp_sender_->dtls_transport());
}

uint32_t RtpSenderImpl::GetSsrc() const {
  return rtp_sender_->ssrc();
}

MediaType RtpSenderImpl::GetMediaType() const {
  int type = static_cast<int>(rtp_sender_->media_type());
  return static_cast<MediaType>(type);
}

std::string RtpSenderImpl::Id() const {
  return rtp_sender_->id();
}

std::vector<std::string> RtpSenderImpl::GetStreamIds() const {
  return rtp_sender_->stream_ids();
}

void RtpSenderImpl::SetStreams(const std::vector<std::string>& stream_ids) {
  rtp_sender_->SetStreams(stream_ids);
}

std::vector<scoped_refptr<RtpEncodingParameters>>
RtpSenderImpl::InitSendEncodings() const {
  std::vector<scoped_refptr<RtpEncodingParameters>> ret;
  for (webrtc::RtpEncodingParameters item :
       rtp_sender_->init_send_encodings()) {
    ret.push_back(new RefCountedObject<RtpEncodingParametersImpl>(item));
  }
  return ret;
}

scoped_refptr<RtpParameters> RtpSenderImpl::GetParameters() const {
  return new RefCountedObject<RtpParametersImpl>(rtp_sender_->GetParameters());
}

const char* RtpSenderImpl::SetParameters(
    const scoped_refptr<RtpParameters> parameters) {
  RtpParametersImpl* impl = static_cast<RtpParametersImpl*>(parameters.get());
  rtp_sender_->SetParameters(impl->rtp_parameters()).message();
}

scoped_refptr<DtmfSender> RtpSenderImpl::GetDtmfSender() const {
  return new RefCountedObject<DtmfSenderImpl>(rtp_sender_->GetDtmfSender());
}

rtc::scoped_refptr<webrtc::RtpSenderInterface> RtpSenderImpl::rtp_sender() {
  return rtp_sender_;
}



}  // namespace libwebrtc
