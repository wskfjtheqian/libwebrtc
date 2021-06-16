#ifndef LIB_WEBRTC_VIDEO_COLOR_SPACE_H_
#define LIB_WEBRTC_VIDEO_COLOR_SPACE_H_

#include <include/hdr_metadata.h>
#include <stdint.h>
#include "rtc_types.h"
#include "base/refcount.h"
#include "base/scoped_ref_ptr.h"

namespace libwebrtc {

class ColorSpace : public RefCountInterface {
 public:
  enum class PrimaryID : uint8_t {
    kBT709 = 1,
    kUnspecified = 2,
    kBT470M = 4,
    kBT470BG = 5,
    kSMPTE170M = 6,  // Identical to BT601
    kSMPTE240M = 7,
    kFILM = 8,
    kBT2020 = 9,
    kSMPTEST428 = 10,
    kSMPTEST431 = 11,
    kSMPTEST432 = 12,
    kJEDECP22 = 22,  // Identical to EBU3213-E
  };

  enum class TransferID : uint8_t {
    kBT709 = 1,
    kUnspecified = 2,
    kGAMMA22 = 4,
    kGAMMA28 = 5,
    kSMPTE170M = 6,
    kSMPTE240M = 7,
    kLINEAR = 8,
    kLOG = 9,
    kLOG_SQRT = 10,
    kIEC61966_2_4 = 11,
    kBT1361_ECG = 12,
    kIEC61966_2_1 = 13,
    kBT2020_10 = 14,
    kBT2020_12 = 15,
    kSMPTEST2084 = 16,
    kSMPTEST428 = 17,
    kARIB_STD_B67 = 18,
  };

  enum class MatrixID : uint8_t {
    kRGB = 0,
    kBT709 = 1,
    kUnspecified = 2,
    kFCC = 4,
    kBT470BG = 5,
    kSMPTE170M = 6,
    kSMPTE240M = 7,
    kYCOCG = 8,
    kBT2020_NCL = 9,
    kBT2020_CL = 10,
    kSMPTE2085 = 11,
    kCDNCLS = 12,
    kCDCLS = 13,
    kBT2100_ICTCP = 14,
  };

  enum class RangeID {
    kInvalid = 0,
    kLimited = 1,
    kFull = 2,
    kDerived = 3,
  };

  enum class ChromaSiting {
    kUnspecified = 0,
    kCollocated = 1,
    kHalf = 2,
  };

  LIB_WEBRTC_API static scoped_refptr<ColorSpace> Create(
      scoped_refptr<ColorSpace> other);

  LIB_WEBRTC_API static scoped_refptr<ColorSpace> Create(PrimaryID primaries,
                                          TransferID transfer,
                                          MatrixID matrix,
                                          RangeID range);

  LIB_WEBRTC_API static scoped_refptr<ColorSpace> Create(
      PrimaryID primaries,
      TransferID transfer,
      MatrixID matrix,
      RangeID range,
      ChromaSiting chroma_siting_horizontal,
      ChromaSiting chroma_siting_vertical,
      scoped_refptr<HdrMetadata> hdr_metadata);

  virtual ColorSpace& operator=(ColorSpace& value) = 0;

  virtual bool operator==(scoped_refptr<ColorSpace> rhs) = 0;

  virtual bool operator!=(scoped_refptr<ColorSpace> rhs) = 0;

  virtual PrimaryID GetPrimaries() const = 0;

  virtual TransferID GetTransfer() const = 0;

  virtual MatrixID GetMatrix() const = 0;

  virtual RangeID GetRange() const = 0;

  virtual ChromaSiting GetChromaSitingHorizontal() const = 0;

  virtual ChromaSiting GetChromaSitingVertical() const = 0;

  virtual scoped_refptr<HdrMetadata> GetHdrMetadata() const = 0;
};

}  // namespace libwebrtc
#endif  // API_VIDEO_COLOR_SPACE_H_
