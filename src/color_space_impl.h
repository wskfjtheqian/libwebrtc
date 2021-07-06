#ifndef LIB_WEBRTC_VIDEO_COLOR_SPACE_IMPL_H_
#define LIB_WEBRTC_VIDEO_COLOR_SPACE_IMPL_H_

#include "api/video/color_space.h"
#include "color_space.h"

namespace libwebrtc {

class ColorSpaceImpl : public ColorSpace {
 public:
  ColorSpaceImpl(ColorSpace& other);

  ColorSpaceImpl(PrimaryID primaries,
                 TransferID transfer,
                 MatrixID matrix,
                 RangeID range);

  ColorSpaceImpl(PrimaryID primaries,
                 TransferID transfer,
                 MatrixID matrix,
                 RangeID range,
                 ChromaSiting chroma_siting_horizontal,
                 ChromaSiting chroma_siting_vertical,
                 scoped_refptr<HdrMetadata> hdr_metadata);

  virtual ColorSpaceImpl& operator=(ColorSpace& value) override;

  virtual bool operator==(scoped_refptr<ColorSpace> rhs) override;

  virtual bool operator!=(scoped_refptr<ColorSpace> rhs) override;

  virtual PrimaryID GetPrimaries() const override;

  virtual TransferID GetTransfer() const override;

  virtual MatrixID GetMatrix() const override;

  virtual RangeID GetRange() const override;

  virtual ChromaSiting GetChromaSitingHorizontal() const override;

  virtual ChromaSiting GetChromaSitingVertical() const override;

  virtual scoped_refptr<HdrMetadata> GetHdrMetadata() const override;

  webrtc::ColorSpace& color_space();

 private:
  webrtc::ColorSpace color_space_;
};

}  // namespace libwebrtc
#endif  // API_VIDEO_COLOR_SPACE_H_
