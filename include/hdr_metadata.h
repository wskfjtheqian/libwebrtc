#ifndef LIB_WEBRTC_VIDEO_HDR_METADATA_H_
#define LIB_WEBRTC_VIDEO_HDR_METADATA_H_

#include "base/refcount.h"
#include "base/scoped_ref_ptr.h"

namespace libwebrtc {

class Chromaticity : public RefCountInterface {
 public:
  static scoped_refptr<Chromaticity> Create();

  virtual bool operator==(const scoped_refptr<Chromaticity> rhs) const = 0;
  virtual bool Validate() const = 0;

  virtual float GetX() = 0;
  virtual void SetX(float value) = 0;

  virtual float GetY() = 0;
  virtual void SetY(float value) = 0;
};

struct HdrMasteringMetadata : public RefCountInterface {
 public:
  static scoped_refptr<HdrMasteringMetadata> Create();

  virtual bool operator==(
      const scoped_refptr<HdrMasteringMetadata> rhs) const = 0;

  virtual bool Validate() const = 0;

  virtual scoped_refptr<Chromaticity> GetPrimaryR() = 0;
  virtual void SetPrimaryR(scoped_refptr<Chromaticity> value) = 0;

  virtual scoped_refptr<Chromaticity> GetPrimaryG() = 0;
  virtual void SetPrimaryG(scoped_refptr<Chromaticity> value) = 0;

  virtual scoped_refptr<Chromaticity> GetPrimaryB() = 0;
  virtual void SetPrimaryB(scoped_refptr<Chromaticity> value) = 0;

  virtual scoped_refptr<Chromaticity> GetWhitePoint() = 0;
  virtual void SetWhitePoint(scoped_refptr<Chromaticity> value) = 0;

  virtual float GetLuminanceMax() = 0;
  virtual void SetLuminanceMax(float value) = 0;

  virtual float GetLuminanceMin() = 0;
  virtual void SetLuminanceMin(float value) = 0;
};

struct HdrMetadata : public RefCountInterface {
 public:
  static scoped_refptr<HdrMetadata> Create();

  virtual bool operator==(const scoped_refptr<HdrMetadata> rhs) const = 0;

  virtual bool Validate() const = 0;

  virtual scoped_refptr<HdrMasteringMetadata> GetMasteringMetadata() = 0;
  virtual void SetMasteringMetadata(
      scoped_refptr<HdrMasteringMetadata> value) = 0;

  virtual int GetMaxContentLightLevel() = 0;
  virtual void SetMaxContentLightLevel(int value) = 0;

  virtual int GetMaxFrameAverageLightLevel() = 0;
  virtual void SetMaxFrameAverageLightLevel(int value) = 0;
};

}  // namespace libwebrtc

#endif  // API_VIDEO_HDR_METADATA_H_
