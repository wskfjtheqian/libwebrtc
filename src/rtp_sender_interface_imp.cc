#ifndef RTP_SENDER_INTERFACE_H_
#define RTP_SENDER_INTERFACE_H_

#include "base/refcount.h"
#include "rtc_media_types.h"
#include "rtc_types.h"

namespace libwebrtc {

class  RtpSender : public RefCountInterface {
 public:
  virtual bool SetTrack(MediaStreamTrackInterface* track) = 0;

  virtual scoped_refptr<MediaStreamTrackInterface> track() const = 0;


  virtual scoped_refptr<DtlsTransportInterface> GetDtlsTransport() const;

  virtual uint32_t GetSsrc() const = 0;


  virtual MediaType GetMediaType() const = 0;

  virtual std::string Id() const = 0;

  virtual std::vector<std::string> GetStreamIds() const = 0;


  virtual void SetStreams(const std::vector<std::string>& stream_ids) {}

  virtual std::vector<RtpEncodingParameters> initSendEncodings() const;

  virtual RtpParameters GetParameters() const = 0;

  virtual RTCError SetParameters(const RtpParameters& parameters) = 0;

  virtual scoped_refptr<DtmfSenderInterface> GetDtmfSender() const = 0;

  virtual void SetFrameEncryptor(
      scoped_refptr<FrameEncryptorInterface> frame_encryptor);

  virtual scoped_refptr<FrameEncryptorInterface> GetFrameEncryptor() const;

  virtual void SetEncoderToPacketizerFrameTransformer(
      scoped_refptr<FrameTransformerInterface> frame_transformer);

 protected:
  ~RtpSenderInterface() override = default;


}  // namespace libwebrtc

#endif  // !RTP_SENDER_INTERFACE_H_