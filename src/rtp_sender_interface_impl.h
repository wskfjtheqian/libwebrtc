#ifndef LIB_WEBRTC_RTP_SENDER_IMPL_H_
#define LIB_WEBRTC_RTP_SENDER_IMPL_H_

#include "rtp_sender.h"


namespace libwebrtc {

class RtpSenderImpl : public RtpSender {
 public:
   bool SetTrack(RTCMediaStream* track);

   scoped_refptr<RTCMediaStream> track() const;


   scoped_refptr<DtlsTransportInterface> GetDtlsTransport() const;

   uint32_t GetSsrc() const;

   MediaType GetMediaType() const;

   std::string Id() const;


   std::vector<std::string> GetStreamIds() const;


   void SetStreams(const std::vector<std::string>& stream_ids) {}

   std::vector<RtpEncodingParameters> initSendEncodings() const;

   RtpParameters GetParameters() const;

   RTCError SetParameters(const RtpParameters& parameters);

   scoped_refptr<DtmfSenderInterface> GetDtmfSender() const;

   void SetFrameEncryptor(
      scoped_refptr<FrameEncryptorInterface> frame_encryptor);

   scoped_refptr<FrameEncryptorInterface> GetFrameEncryptor() const;

   void SetEncoderToPacketizerFrameTransformer(
      scoped_refptr<FrameTransformerInterface> frame_transformer);

 protected:
  ~RtpSenderInterface() override = default;


}  // namespace libwebrtc

#endif  // !RTP_SENDER_INTERFACE_H_