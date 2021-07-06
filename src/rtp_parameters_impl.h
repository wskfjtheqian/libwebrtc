
#ifndef WINDOWS_RTP_PARAMETERS_IMPL_H
#define WINDOWS_RTP_PARAMETERS_IMPL_H

#include "rtp_parameters.h"
#include "api/rtp_parameters.h"
#include "api/scoped_refptr.h"

namespace libwebrtc {

class RtpParametersImpl : public RtpParameters {
 public:
  RtpParametersImpl(webrtc::RtpParameters rtp_parameters);
  ~RtpParametersImpl();


  virtual std::string GetTransactionId() override;
  virtual void SetTransactionId(std::string value) override;

  virtual std::string GetMid() override;
  virtual void SetMid(std::string value) override;

  virtual std::vector<RtpCodecParameters> GetCodecs() override;
  virtual void SetCodecs(std::vector<RtpCodecParameters> value) override;

  virtual std::vector<RtpExtension> GetHeaderExtensions() override;
  virtual void SetHeaderExtensions(std::vector<RtpExtension> value) override;

  virtual std::vector<RtpEncodingParameters> GetEncodings() override;
  virtual void SetEncodings(std::vector<RtpEncodingParameters> value) override;

  virtual RtcpParameters GetRtcp() override;
  virtual void SetRtcp(RtcpParameters value) override;

  virtual DegradationPreference GetDegradationPreference() override;
  virtual void SetDegradationPreference(DegradationPreference value) override;

  virtual bool operator==(const RtpParameters& o) const override;
  virtual bool operator!=(const RtpParameters& o) const override;

  webrtc::RtpParameters rtp_parameters();
 private:
  webrtc::RtpParameters rtp_parameters_;
};


class RtpEncodingParametersImpl : public RtpEncodingParameters {
 public:
  RtpEncodingParametersImpl();
  RtpEncodingParametersImpl(const RtpEncodingParameters&);
  ~RtpEncodingParametersImpl();

  virtual uint32_t GetSsrc() override;
  virtual void SetSsrc(uint32_t value) override;

  virtual double GetBitratePriority() override;
  virtual void SetBitratePriority(double value) override;

  virtual Priority GetNetworkPriority() override;
  virtual void SetNetworkPriority(Priority value) override;

  virtual int GetMaxBitrateBps() override;
  virtual void SetMaxBitrateBps(int value) override;

  virtual int GetMinBitrateBps() override;
  virtual void SetMinBitrateBps(int value) override;

  virtual double GetMaxFramerate() override;
  virtual void SetMaxFramerate(double value) override;

  virtual int GetNumTemporalLayers() override;
  virtual void SetNumTemporalLayers(int value) override;

  virtual double GetScaleResolutionDownBy() override;
  virtual void SetScaleResolutionDownBy(double value) override;

  virtual std::string GetScalabilityMode() override;
  virtual void SetScalabilityMode(std::string value) override;

  virtual bool GetActive() override;
  virtual void SetActive(bool value) override;

  virtual std::string GetRid() override;
  virtual void SetRid(std::string value) override;

  virtual bool GetAdaptivePtime() override;
  virtual void SetAdaptivePtime(bool value) override;

  virtual bool operator==(const RtpEncodingParameters& o) const override;
  virtual bool operator!=(const RtpEncodingParameters& o) const override;

  scoped_refptr<webrtc::RtpEncodingParameters> rtp_parameters(); 
 private:
  scoped_refptr<webrtc::RtpEncodingParameters> rtp_encoding_parameters_;
};

}  // namespace libwebrtc
#endif  // WINDOWS_RTP_PARAMETERS_IMPL_H
