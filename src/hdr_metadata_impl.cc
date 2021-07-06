#include "hdr_metadata_impl.h"

#include "base/refcountedobject.h"
namespace libwebrtc {

scoped_refptr<Chromaticity> Chromaticity::Create() {
  return new RefCountedObject<ChromaticityImpl>();
}

ChromaticityImpl::ChromaticityImpl() {}

bool ChromaticityImpl::operator==(const scoped_refptr<Chromaticity> rhs) const {
  ChromaticityImpl* impl = static_cast<ChromaticityImpl*>(rhs.get());
  return chromaticity_ == impl->chromaticity();
}
bool ChromaticityImpl::Validate() const {
  return chromaticity_.Validate();
}
float ChromaticityImpl::GetX() {
  return chromaticity_.x;
}
void ChromaticityImpl::SetX(float value) {
  chromaticity_.x = value;
}
float ChromaticityImpl::GetY() {
  return chromaticity_.y;
}
void ChromaticityImpl::SetY(float value) {
  chromaticity_.y = value;
}

webrtc::HdrMasteringMetadata::Chromaticity ChromaticityImpl::chromaticity() {
  return chromaticity_;
}

scoped_refptr<HdrMasteringMetadata> HdrMasteringMetadata::Create() {
  return new RefCountedObject<HdrMasteringMetadataImpl>();
}

HdrMasteringMetadataImpl::HdrMasteringMetadataImpl(
    webrtc::HdrMasteringMetadata hdr_mastering_metadata)
    : hdr_mastering_metadata_(hdr_mastering_metadata) {}

bool HdrMasteringMetadataImpl::operator==(
    const scoped_refptr<HdrMasteringMetadata> rhs) const {
  HdrMasteringMetadataImpl* impl =
      static_cast<HdrMasteringMetadataImpl*>(rhs.get());
  return hdr_mastering_metadata_ == impl->hdr_mastering_metadata();
}

bool HdrMasteringMetadataImpl::Validate() const {
  return hdr_mastering_metadata_.Validate();
}

scoped_refptr<Chromaticity> HdrMasteringMetadataImpl::GetPrimaryR() {
  return new RefCountedObject<ChromaticityImpl>(
      hdr_mastering_metadata_.primary_r);
}

void HdrMasteringMetadataImpl::SetPrimaryR(scoped_refptr<Chromaticity> value) {
  ChromaticityImpl* impl = static_cast<ChromaticityImpl*>(value.get());
  hdr_mastering_metadata_.primary_r = impl->chromaticity();
}

scoped_refptr<Chromaticity> HdrMasteringMetadataImpl::GetPrimaryG() {
  return new RefCountedObject<ChromaticityImpl>(
      hdr_mastering_metadata_.primary_g);
}

void HdrMasteringMetadataImpl::SetPrimaryG(scoped_refptr<Chromaticity> value) {
  ChromaticityImpl* impl = static_cast<ChromaticityImpl*>(value.get());
  hdr_mastering_metadata_.primary_g = impl->chromaticity();
}

scoped_refptr<Chromaticity> HdrMasteringMetadataImpl::GetPrimaryB() {
  return new RefCountedObject<ChromaticityImpl>(
      hdr_mastering_metadata_.primary_b);
}

void HdrMasteringMetadataImpl::SetPrimaryB(scoped_refptr<Chromaticity> value) {
  ChromaticityImpl* impl = static_cast<ChromaticityImpl*>(value.get());
  hdr_mastering_metadata_.primary_b = impl->chromaticity();
}

scoped_refptr<Chromaticity> HdrMasteringMetadataImpl::GetWhitePoint() {
  return new RefCountedObject<ChromaticityImpl>(
      hdr_mastering_metadata_.white_point);
}

void HdrMasteringMetadataImpl::SetWhitePoint(
    scoped_refptr<Chromaticity> value) {
  ChromaticityImpl* impl = static_cast<ChromaticityImpl*>(value.get());
  hdr_mastering_metadata_.white_point = impl->chromaticity();
}

float HdrMasteringMetadataImpl::GetLuminanceMax() {
  return hdr_mastering_metadata_.luminance_max;
}

void HdrMasteringMetadataImpl::SetLuminanceMax(float value) {
  hdr_mastering_metadata_.luminance_max = value;
}

float HdrMasteringMetadataImpl::GetLuminanceMin() {
  return hdr_mastering_metadata_.luminance_min;
}

void HdrMasteringMetadataImpl::SetLuminanceMin(float value) {
  hdr_mastering_metadata_.luminance_min = value;
}

webrtc::HdrMasteringMetadata
HdrMasteringMetadataImpl::hdr_mastering_metadata() {
  return hdr_mastering_metadata_;
}

HdrMetadataImpl::HdrMetadataImpl() {}

HdrMetadataImpl::HdrMetadataImpl(webrtc::HdrMetadata& hdr_metadata)
    : hdr_metadata_(hdr_metadata) {}

HdrMetadataImpl::HdrMetadataImpl(webrtc::HdrMetadata* hdr_metadata)
    : hdr_metadata_(*hdr_metadata) {}

scoped_refptr<HdrMetadata> HdrMetadata::Create() {
  return new RefCountedObject<HdrMetadataImpl>();
}

bool HdrMetadataImpl::operator==(const scoped_refptr<HdrMetadata> rhs) const {
  HdrMetadataImpl* impl = static_cast<HdrMetadataImpl*>(rhs.get());
  return hdr_metadata_ == impl->hdr_metadata();
}

bool HdrMetadataImpl::Validate() const {
  return hdr_metadata_.Validate();
}

scoped_refptr<HdrMasteringMetadata> HdrMetadataImpl::GetMasteringMetadata() {
  return new RefCountedObject<HdrMasteringMetadataImpl>(
      hdr_metadata_.mastering_metadata);
}

void HdrMetadataImpl::SetMasteringMetadata(
    scoped_refptr<HdrMasteringMetadata> value) {
  HdrMasteringMetadataImpl* impl =
      static_cast<HdrMasteringMetadataImpl*>(value.get());
  hdr_metadata_.mastering_metadata = impl->hdr_mastering_metadata();
}

int HdrMetadataImpl::GetMaxContentLightLevel() {
  return hdr_metadata_.max_content_light_level;
}

void HdrMetadataImpl::SetMaxContentLightLevel(int value) {
  hdr_metadata_.max_content_light_level = value;
}

int HdrMetadataImpl::GetMaxFrameAverageLightLevel() {
  return hdr_metadata_.max_frame_average_light_level;
}

void HdrMetadataImpl::SetMaxFrameAverageLightLevel(int value) {
  hdr_metadata_.max_content_light_level = value;
}

webrtc::HdrMetadata& HdrMetadataImpl::hdr_metadata() {
  return hdr_metadata_;
}

}  // namespace libwebrtc
