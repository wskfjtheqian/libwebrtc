#include "rtc_video_track_impl.h"
#include "rtc_media_stream_impl.h"

#include "rtc_base/logging.h"

namespace libwebrtc {

VideoTrackImpl::VideoTrackImpl(
    rtc::scoped_refptr<webrtc::VideoTrackInterface> rtc_track)
    : rtc_track_(rtc_track),
      video_sink_(new RefCountedObject<VideoSinkAdapter>(rtc_track)) {
  RTC_LOG(INFO) << __FUNCTION__ << ": ctor ";
  id_ = rtc_track_->id().c_str();
  kind_ = rtc_track_->kind().c_str();
}

VideoTrackImpl::~VideoTrackImpl() {
  RTC_LOG(INFO) << __FUNCTION__ << ": dtor ";
}

void VideoTrackImpl::AddRenderer(
    RTCVideoRenderer<scoped_refptr<RTCVideoFrame>>* renderer) {
  return video_sink_->AddRenderer(renderer);
}

void VideoTrackImpl::RemoveRenderer(
    RTCVideoRenderer<scoped_refptr<RTCVideoFrame>>* renderer) {
  return video_sink_->RemoveRenderer(renderer);
}



LIB_WEBRTC_API scoped_refptr<RTCVideoTracks> RTCVideoTracks::Create() {
  return new RefCountedObject<RTCVideoTracksImpl>();
}

RTCVideoTracksImpl::RTCVideoTracksImpl() {}

RTCVideoTracksImpl::RTCVideoTracksImpl(
    std::vector<scoped_refptr<RTCVideoTrack>> list):_list(list) {}

void RTCVideoTracksImpl::Add(scoped_refptr<RTCVideoTrack> value) {
  _list.push_back(value);
}

scoped_refptr<RTCVideoTrack> RTCVideoTracksImpl::Get(int index) {
  return _list.at(index);
}

int RTCVideoTracksImpl::Size() {
  return _list.size();
}

void RTCVideoTracksImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCVideoTracksImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCVideoTrack>> RTCVideoTracksImpl::list() {
  return _list;
}


}  // namespace libwebrtc
