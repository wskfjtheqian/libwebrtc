#include "rtc_audio_track_impl.h"

namespace libwebrtc {

AudioTrackImpl::AudioTrackImpl(
    rtc::scoped_refptr<webrtc::AudioTrackInterface> audio_track)
    : rtc_track_(audio_track) {
  RTC_LOG(INFO) << __FUNCTION__ << ": ctor ";
  id_ = rtc_track_->id().c_str();
  kind_ = rtc_track_->kind().c_str();
}

AudioTrackImpl::~AudioTrackImpl() {
  RTC_LOG(INFO) << __FUNCTION__ << ": dtor ";
}

LIB_WEBRTC_API scoped_refptr<RTCAudioTracks> RTCAudioTracks::Create() {
  return new RefCountedObject<RTCAudioTracksImpl>();
}

RTCAudioTracksImpl::RTCAudioTracksImpl() {}

RTCAudioTracksImpl::RTCAudioTracksImpl(
    std::vector<scoped_refptr<RTCAudioTrack>> list):_list(list) {}

void RTCAudioTracksImpl::Add(scoped_refptr<RTCAudioTrack> value) {
  _list.push_back(value);
}

scoped_refptr<RTCAudioTrack> RTCAudioTracksImpl::Get(int index) {
  return _list.at(index);
}

int RTCAudioTracksImpl::Size() {
  return _list.size();
}

void RTCAudioTracksImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCAudioTracksImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCAudioTrack>> RTCAudioTracksImpl::list() {
  return _list;
}

}  // namespace libwebrtc
