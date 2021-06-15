#ifndef LIB_WEBRTC_VIDEO_HDR_METADATA_IMPL_H_
#define LIB_WEBRTC_VIDEO_HDR_METADATA_IMPL_H_

#include "api/video/hdr_metadata.h"
#include "hdr_metadata.h"

namespace libwebrtc {

class ChromaticityImpl : public Chromaticity {
 public:
  ChromaticityImpl();

  virtual bool operator==(const scoped_refptr<Chromaticity> rhs) const override;
  virtual bool Validate() const override ;

  virtual float GetX() override ;
  virtual void SetX(float value) override;

  virtual float GetY() override ;
  virtual void SetY(float value) override;

  webrtc::HdrMasteringMetadata::Chromaticity chromaticity();

 private:
  webrtc::HdrMasteringMetadata::Chromaticity chromaticity_;
};

struct HdrMasteringMetadataImpl : public HdrMasteringMetadata {
 public:
  HdrMasteringMetadataImpl();

  static scoped_refptr<HdrMasteringMetadata> Create();

  virtual bool operator==(const scoped_refptr<HdrMasteringMetadata> rhs) const;

  virtual bool Validate() const;

  virtual scoped_refptr<Chromaticity> GetPrimaryR() override ;
  virtual void SetPrimaryR(scoped_refptr<Chromaticity> value) override ;

  virtual scoped_refptr<Chromaticity> GetPrimaryG() override ;
  virtual void SetPrimaryG(scoped_refptr<Chromaticity> value) override ;

  virtual scoped_refptr<Chromaticity> GetPrimaryB() override ;
  virtual void SetPrimaryB(scoped_refptr<Chromaticity> value) override ;

  virtual scoped_refptr<Chromaticity> GetWhitePoint() override ;
  virtual void SetWhitePoint(scoped_refptr<Chromaticity> value) override ;

  virtual float GetLuminanceMax() override ;
  virtual void SetLuminanceMax(float value) override ;

  virtual float GetLuminanceMin() override ;
  virtual void SetLuminanceMin(float value) override ;

 private:
  webrtc::HdrMasteringMetadata hdr_mastering_metadata_;
};

struct HdrMetadataImpl : public HdrMetadata {
 public:
  HdrMetadataImpl();

  static scoped_refptr<HdrMetadata> Create();

  virtual bool operator==(const scoped_refptr<HdrMetadata> rhs) const override;

  virtual bool Validate() const override ;

  virtual scoped_refptr<HdrMasteringMetadata> GetMasteringMetadata() override ;
  virtual void SetMasteringMetadata(
      scoped_refptr<HdrMasteringMetadata> value) override ;

  virtual int GetMaxContentLightLevel() override ;
  virtual void SetMaxContentLightLevel(int value) override ;

  virtual int GetMaxFrameAverageLightLevel() override ;
  virtual void SetMaxFrameAverageLightLevel(int value) override ;
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_VIDEO_HDR_METADATA_IMPL_H_
