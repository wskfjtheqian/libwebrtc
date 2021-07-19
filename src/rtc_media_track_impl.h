
#ifndef LIB_WEBRTC_RTC_MEDIA_TRACK_IMPL_HXX
#define LIB_WEBRTC_RTC_MEDIA_TRACK_IMPL_HXX

#include "include/rtc_media_track.h"


namespace libwebrtc {
class RTCMediaTracksImpl : public RTCMediaTracks {
 public:
  RTCMediaTracksImpl();
  RTCMediaTracksImpl(std::vector<scoped_refptr<RTCMediaTrack>> list);
  virtual void Add(scoped_refptr<RTCMediaTrack> value) override;
  virtual scoped_refptr<RTCMediaTrack> Get(int index) override;
  virtual int Size() override;
  virtual void Remove(int index) override;
  virtual void Clean() override;

    std::vector<scoped_refptr<RTCMediaTrack>> list();

 private:
    std::vector<scoped_refptr<RTCMediaTrack>> _list;
};
}  // namespace libwebrtc

#endif  // LIB_WEBRTC_RTC_MEDIA_TRACK_HXX
