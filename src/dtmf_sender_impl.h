
#ifndef LIB_WEBRTC_DTMF_SENDER_INTERFACE_H_
#define LIB_WEBRTC_DTMF_SENDER_INTERFACE_H_

#include <string>

#include "api/dtmf_sender_interface.h"
#include "api/scoped_refptr.h"
#include "dtmf_sender.h"

namespace libwebrtc {

class DtmfSenderImpl : public DtmfSender,
                       public webrtc::DtmfSenderObserverInterface {
 public:
  DtmfSenderImpl(rtc::scoped_refptr<webrtc::DtmfSenderInterface> dtmf_sender);

  virtual void RegisterObserver(DtmfSenderObserver* observer) override;

  virtual void UnregisterObserver() override;

  virtual bool CanInsertDtmf() override;

  virtual bool InsertDtmf(const std::string& tones,
                          int duration,
                          int inter_tone_gap) override;

  virtual bool InsertDtmf(const std::string& tones,
                          int duration,
                          int inter_tone_gap,
                          int comma_delay) override;

  virtual std::string tones() const override;

  virtual int duration() const override;

  virtual int inter_tone_gap() const override;

 public:
  virtual void OnToneChange(const std::string& tone,
                            const std::string& tone_buffer) override;

  virtual void OnToneChange(const std::string& tone) override;

  virtual int comma_delay() const override;

 protected:
  virtual ~DtmfSenderImpl() = default;

 private:
  rtc::scoped_refptr<webrtc::DtmfSenderInterface> dtmf_sender_;
  DtmfSenderObserver* observer_;
};

}  // namespace libwebrtc

#endif  // API_DTMF_SENDER_INTERFACE_H_
