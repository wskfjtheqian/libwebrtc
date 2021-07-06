
#ifndef LIB_WEBRTC_DTMF_SENDER__H_
#define LIB_WEBRTC_DTMF_SENDER__H_

#include <string>

#include "base/refcount.h"

namespace libwebrtc {

class DtmfSenderObserver {
 public:
  virtual void OnToneChange(const std::string& tone,
                            const std::string& tone_buffer) {}

  virtual void OnToneChange(const std::string& tone) {}

 protected:
  virtual ~DtmfSenderObserver() = default;
};

class DtmfSender : public RefCountInterface {
 public:
  static const int kDtmfDefaultCommaDelayMs = 2000;

  virtual void RegisterObserver(DtmfSenderObserver* observer) = 0;

  virtual void UnregisterObserver() = 0;

  virtual bool CanInsertDtmf() = 0;

  virtual bool InsertDtmf(const std::string& tones,
                          int duration,
                          int inter_tone_gap) = 0;
 

  virtual bool InsertDtmf(const std::string& tones,
                          int duration,
                          int inter_tone_gap,
                          int comma_delay) = 0;

  virtual std::string tones() const = 0;

  virtual int duration() const = 0;

  virtual int inter_tone_gap() const = 0;

  virtual int comma_delay() const = 0;
};

}  // namespace libwebrtc

#endif  // API_DTMF_SENDER__H_
