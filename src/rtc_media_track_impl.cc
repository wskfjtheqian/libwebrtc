#include "include/rtc_media_track.h"
#include "rtc_media_track_impl.h"

namespace libwebrtc {

scoped_refptr<RTCMediaTracks> RTCMediaTracks::Create() {
  return new RefCountedObject<RTCMediaTracksImpl>();
}

RTCMediaTracksImpl::RTCMediaTracksImpl() {}

RTCMediaTracksImpl::RTCMediaTracksImpl(
    std::vector<scoped_refptr<RTCMediaTrack>> list)
    : _list(list) {}
void RTCMediaTracksImpl::Add(scoped_refptr<RTCMediaTrack> value) {
  _list.push_back(value);
}

scoped_refptr<RTCMediaTrack> RTCMediaTracksImpl::Get(int index) {
  return _list.at(index);
}

int RTCMediaTracksImpl::Size() {
  return _list.size();
}

void RTCMediaTracksImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCMediaTracksImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCMediaTrack>> RTCMediaTracksImpl::list() {
  return _list;
}
  
}  // namespace libwebrtc