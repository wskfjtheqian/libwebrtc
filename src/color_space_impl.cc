#include "color_space_impl.h"

#include "hdr_metadata_impl.h"
#include "rtc_base/ref_counted_object.h"
namespace libwebrtc {

scoped_refptr<ColorSpace> ColorSpace::Create(scoped_refptr<ColorSpace> other) {
  return new RefCountedObject<ColorSpaceImpl>(other.get());
}

scoped_refptr<ColorSpace> ColorSpace::Create(PrimaryID primaries,
                                             TransferID transfer,
                                             MatrixID matrix,
                                             RangeID range) {
  return new RefCountedObject<ColorSpaceImpl>(primaries, transfer, matrix,
                                              range);
}

scoped_refptr<ColorSpace> ColorSpace::Create(
    PrimaryID primaries,
    TransferID transfer,
    MatrixID matrix,
    RangeID range,
    ChromaSiting chroma_siting_horizontal,
    ChromaSiting chroma_siting_vertical,
    scoped_refptr<HdrMetadata> hdr_metadata) {
  return new RefCountedObject<ColorSpaceImpl>(
      primaries, transfer, matrix, range, chroma_siting_horizontal,
      chroma_siting_vertical, hdr_metadata);
}

ColorSpaceImpl::ColorSpaceImpl(ColorSpace& other) {}

ColorSpaceImpl::ColorSpaceImpl(PrimaryID primaries,
                               TransferID transfer,
                               MatrixID matrix,
                               RangeID range)
    : color_space_(static_cast<webrtc::ColorSpace::PrimaryID>(primaries),
                   static_cast<webrtc::ColorSpace::TransferID>(transfer),
                   static_cast<webrtc::ColorSpace::MatrixID>(matrix),
                   static_cast<webrtc::ColorSpace::RangeID>(range)) {}

ColorSpaceImpl::ColorSpaceImpl(PrimaryID primaries,
                               TransferID transfer,
                               MatrixID matrix,
                               RangeID range,
                               ChromaSiting chroma_siting_horizontal,
                               ChromaSiting chroma_siting_vertical,
                               scoped_refptr<HdrMetadata> hdr_metadata)
    : color_space_(
          static_cast<webrtc::ColorSpace::PrimaryID>(primaries),
          static_cast<webrtc::ColorSpace::TransferID>(transfer),
          static_cast<webrtc::ColorSpace::MatrixID>(matrix),
          static_cast<webrtc::ColorSpace::RangeID>(range),
          static_cast<webrtc::ColorSpace::ChromaSiting>(
              chroma_siting_horizontal),
          static_cast<webrtc::ColorSpace::ChromaSiting>(chroma_siting_vertical),
          &static_cast<HdrMetadataImpl*>(hdr_metadata.get())->hdr_metadata()) {}

ColorSpaceImpl& ColorSpaceImpl::operator=(ColorSpace& rhs) {
  ColorSpaceImpl* impl = static_cast<ColorSpaceImpl*>(&rhs);
  color_space_ = impl->color_space();
  return *this;
}

bool ColorSpaceImpl::operator==(scoped_refptr<ColorSpace> rhs) {
  ColorSpaceImpl* impl = static_cast<ColorSpaceImpl*>(rhs.get());
  return color_space_ == impl->color_space();
  ;
}

bool ColorSpaceImpl::operator!=(scoped_refptr<ColorSpace> rhs) {
  ColorSpaceImpl* impl = static_cast<ColorSpaceImpl*>(rhs.get());
  return color_space_ != impl->color_space();
  ;
}

ColorSpace::PrimaryID ColorSpaceImpl::GetPrimaries() const {
  return static_cast<PrimaryID>(color_space_.primaries());
}

ColorSpace::TransferID ColorSpaceImpl::GetTransfer() const {
  return static_cast<TransferID>(color_space_.transfer());
}

ColorSpace::MatrixID ColorSpaceImpl::GetMatrix() const {
  return static_cast<MatrixID>(color_space_.matrix());
}

ColorSpace::RangeID ColorSpaceImpl::GetRange() const {
  return static_cast<RangeID>(color_space_.range());
}

ColorSpace::ChromaSiting ColorSpaceImpl::GetChromaSitingHorizontal() const {
  return static_cast<ChromaSiting>(color_space_.chroma_siting_horizontal());
}

ColorSpace::ChromaSiting ColorSpaceImpl::GetChromaSitingVertical() const {
  return static_cast<ChromaSiting>(color_space_.chroma_siting_vertical());
}

scoped_refptr<HdrMetadata> ColorSpaceImpl::GetHdrMetadata() const {
  return new RefCountedObject<HdrMetadataImpl>(color_space_.hdr_metadata());
}

webrtc::ColorSpace& ColorSpaceImpl::color_space() {
  return color_space_;
}
}  // namespace libwebrtc
