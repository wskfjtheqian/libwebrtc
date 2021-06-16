#ifndef LIB_WEBRTC_FRAME_DECRYPTOR_H_
#define LIB_WEBRTC_FRAME_DECRYPTOR_H_

#include "base/refcount.h"
#include "rtc_media_types.h"
#include <vector>

namespace libwebrtc {

class FrameDecryptor : public RefCountInterface {
 public:
  enum class Status { kOk, kRecoverable, kFailedToDecrypt, kUnknown };

  struct Result {
    Result(Status status, size_t bytes_written)
        : status(status), bytes_written(bytes_written) {}

    bool IsOk() const { return status == Status::kOk; }

    const Status status;
    const size_t bytes_written;
  };

  ~FrameDecryptor() override {}

  virtual Result Decrypt(MediaType media_type,
                         const std::vector<uint32_t>& csrcs,
                         rtc::ArrayView<const uint8_t> additional_data,
                         rtc::ArrayView<const uint8_t> encrypted_frame,
                         rtc::ArrayView<uint8_t> frame) = 0;

  virtual size_t GetMaxPlaintextByteSize(MediaType media_type,
                                         size_t encrypted_frame_size) = 0;
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_FRAME_DECRYPTOR_H_
