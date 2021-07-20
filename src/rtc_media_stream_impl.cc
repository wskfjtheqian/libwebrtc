#include "rtc_media_stream_impl.h"

#include <algorithm>

#include "rtc_audio_track_impl.h"
#include "rtc_peerconnection.h"
#include "rtc_video_track_impl.h"

namespace libwebrtc {

MediaStreamImpl::MediaStreamImpl(
    rtc::scoped_refptr<webrtc::MediaStreamInterface> rtc_media_stream)
    : rtc_media_stream_(rtc_media_stream) {
  rtc_media_stream_->RegisterObserver(this);

  for (auto track : rtc_media_stream->GetAudioTracks()) {
    scoped_refptr<AudioTrackImpl> audio_track = scoped_refptr<AudioTrackImpl>(
        new RefCountedObject<AudioTrackImpl>(track));
    audio_tracks_.push_back(audio_track);
  }

  for (auto track : rtc_media_stream->GetVideoTracks()) {
    scoped_refptr<VideoTrackImpl> video_track = scoped_refptr<VideoTrackImpl>(
        new RefCountedObject<VideoTrackImpl>(track));
    video_tracks_.push_back(video_track);
  }
  id_ = rtc_media_stream_->id().c_str();
  label_ = rtc_media_stream_->id().c_str();
}

MediaStreamImpl::~MediaStreamImpl() {
  RTC_LOG(INFO) << __FUNCTION__ << ": dtor ";
  rtc_media_stream_->UnregisterObserver(this);
  audio_tracks_.clear();
  video_tracks_.clear();
}

bool MediaStreamImpl::AddTrack(scoped_refptr<RTCAudioTrack> track) {
  AudioTrackImpl* track_impl = static_cast<AudioTrackImpl*>(track.get());
  if (rtc_media_stream_->AddTrack(track_impl->rtc_track())) {
    audio_tracks_.push_back(track);
    return true;
  }
  return false;
}

bool MediaStreamImpl::AddTrack(scoped_refptr<RTCVideoTrack> track) {
  VideoTrackImpl* track_impl = static_cast<VideoTrackImpl*>(track.get());
  if (rtc_media_stream_->AddTrack(track_impl->rtc_track())) {
    video_tracks_.push_back(track);
    return true;
  }
  return false;
}

bool MediaStreamImpl::RemoveTrack(scoped_refptr<RTCAudioTrack> track) {
  AudioTrackImpl* track_impl = static_cast<AudioTrackImpl*>(track.get());
  if (rtc_media_stream_->RemoveTrack(track_impl->rtc_track())) {
    auto it = std::find(audio_tracks_.begin(), audio_tracks_.end(), track);
    if (it != audio_tracks_.end())
      audio_tracks_.erase(it);
    return true;
  }
  return false;
}

bool MediaStreamImpl::RemoveTrack(scoped_refptr<RTCVideoTrack> track) {
  VideoTrackImpl* track_impl = static_cast<VideoTrackImpl*>(track.get());
  if (rtc_media_stream_->RemoveTrack(track_impl->rtc_track())) {

    auto it = std::find(video_tracks_.begin(), video_tracks_.end(), track);
    if (it != video_tracks_.end())
      video_tracks_.erase(it);
    return true;
  }
  return false;
}

scoped_refptr<RTCAudioTracks> MediaStreamImpl::audio_tracks() {
  return new RefCountedObject<RTCAudioTracksImpl>(audio_tracks_);
}

scoped_refptr<RTCVideoTracks> MediaStreamImpl::video_tracks() {
  return new RefCountedObject<RTCVideoTracksImpl>(video_tracks_);
}

 scoped_refptr<RTCMediaTracks> MediaStreamImpl::tracks() {
  scoped_refptr<RTCMediaTracks> tracks = RTCMediaTracks::Create();
  for (auto track : audio_tracks_) {
    tracks->Add(track);
  }
  for (auto track : video_tracks_) {
    tracks->Add(track);
  }
  return tracks;
}

scoped_refptr<RTCAudioTrack> MediaStreamImpl::FindAudioTrack(
    const string track_id) {
  for (auto track : audio_tracks_) {
    if (track->id() == track_id)
      return track;
  }

  return scoped_refptr<RTCAudioTrack>();
}

scoped_refptr<RTCVideoTrack> MediaStreamImpl::FindVideoTrack(
    const string track_id) {
  for (auto track : video_tracks_) {
    if (track->id() == track_id)
      return track;
  }

  return scoped_refptr<RTCVideoTrack>();
}

void MediaStreamImpl::OnChanged() {
  std::vector<scoped_refptr<RTCAudioTrack>> audio_tracks;
  for (auto track : rtc_media_stream_->GetAudioTracks()) {
    scoped_refptr<AudioTrackImpl> audio_track = scoped_refptr<AudioTrackImpl>(
        new RefCountedObject<AudioTrackImpl>(track));
    audio_tracks.push_back(audio_track);
  }

  audio_tracks_ = audio_tracks;

  std::vector<scoped_refptr<RTCVideoTrack>> video_tracks;
  for (auto track : rtc_media_stream_->GetVideoTracks()) {
    scoped_refptr<VideoTrackImpl> video_track = scoped_refptr<VideoTrackImpl>(
        new RefCountedObject<VideoTrackImpl>(track));
    video_tracks.push_back(video_track);
  }

  std::vector<scoped_refptr<RTCVideoTrack>> removed_video_tracks;

  for (auto track : video_tracks_) {
    if (std::find(video_tracks.begin(), video_tracks.end(), track) ==
        video_tracks.end()) {
      removed_video_tracks.push_back(track);
    }
  }

  for (auto track : removed_video_tracks) {
    /*  if (observer_) {
        observer_->OnRemoveTrack([&](OnRTCMediaStream on) { on(this); }, track);
      }*/
  }

  std::vector<scoped_refptr<RTCVideoTrack>> new_video_tracks;
  for (auto track : video_tracks) {
    if (std::find(video_tracks_.begin(), video_tracks_.end(), track) ==
        video_tracks_.end()) {
      new_video_tracks.push_back(track);
    }
  }

  // for (auto track : new_video_tracks) {
  //  if (observer_)
  //    observer_->OnAddTrack([&](OnRTCMediaStream on) { on(this); }, track);
  //}

  video_tracks_ = video_tracks;
}

LIB_WEBRTC_API scoped_refptr<RTCMediaStreams> RTCMediaStreams::Create() {
  return new  RefCountedObject<RTCMediaStreamsImpl>();
}

RTCMediaStreamsImpl::RTCMediaStreamsImpl() {}

RTCMediaStreamsImpl::RTCMediaStreamsImpl(
    std::vector<scoped_refptr<RTCMediaStream>> list):_list(list) {}

void RTCMediaStreamsImpl::Add(scoped_refptr<RTCMediaStream> value) {
  _list.push_back(value);
}

scoped_refptr<RTCMediaStream> RTCMediaStreamsImpl::Get(int index) {
  return _list.at(index);
}

int RTCMediaStreamsImpl::Size() {
  return _list.size();
}

void RTCMediaStreamsImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCMediaStreamsImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCMediaStream>> RTCMediaStreamsImpl::list() {
  return _list;
}


LIB_WEBRTC_API scoped_refptr<RTCStreamIds> RTCStreamIds::Create() {
  return new RefCountedObject<RTCStreamIdsImpl>();
}

RTCStreamIdsImpl::RTCStreamIdsImpl() {}

RTCStreamIdsImpl::RTCStreamIdsImpl(std::vector<std::string> list)
    : _list(list) {}

void RTCStreamIdsImpl::Add(string value) {
  _list.push_back(std::string(value.data(), value.size()));
}

string RTCStreamIdsImpl::Get(int index) {
  std::string ret = _list.at(index);

  return string(ret.data(), ret.size());
}

int RTCStreamIdsImpl::Size() {
  return _list.size();
}

void RTCStreamIdsImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCStreamIdsImpl::Clean() {
  _list.clear();
}

std::vector<std::string> RTCStreamIdsImpl::list() {
  return _list;
}


}  // namespace libwebrtc
