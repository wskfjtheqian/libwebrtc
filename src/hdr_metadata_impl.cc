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
}  // namespace libwebrtc
