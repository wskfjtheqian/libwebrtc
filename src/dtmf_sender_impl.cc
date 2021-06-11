#include "dtmf_sender_impl.h"

namespace libwebrtc {

DtmfSenderImpl::DtmfSenderImpl(
    rtc::scoped_refptr<webrtc::DtmfSenderInterface> dtmf_sender)
    : dtmf_sender_(dtmf_sender), observer_(nullptr) {}


void DtmfSenderImpl::RegisterObserver(DtmfSenderObserver* observer) {
  observer_ = observer;
  dtmf_sender_->RegisterObserver(this);
}


void DtmfSenderImpl::UnregisterObserver() {
  dtmf_sender_->UnregisterObserver();
  observer_ = nullptr;
}


bool DtmfSenderImpl::CanInsertDtmf() {
  return dtmf_sender_->CanInsertDtmf();
}


bool DtmfSenderImpl::InsertDtmf(const std::string& tones,
                                int duration,
                                int inter_tone_gap) {
  return dtmf_sender_->InsertDtmf(tones, duration, inter_tone_gap);
}


bool DtmfSenderImpl::InsertDtmf(const std::string& tones,
                                int duration,
                                int inter_tone_gap,
                                int comma_delay) {
  return dtmf_sender_->InsertDtmf(tones, duration, inter_tone_gap, comma_delay);
}


std::string DtmfSenderImpl::tones() const {
  return dtmf_sender_->tones();
}


int DtmfSenderImpl::duration() const {
  return dtmf_sender_->duration();
}


int DtmfSenderImpl::inter_tone_gap() const {
  return dtmf_sender_->inter_tone_gap();
}


void DtmfSenderImpl::OnToneChange(const std::string& tone,
                                  const std::string& tone_buffer) {
  if (observer_) {
    observer_->OnToneChange(tone, tone_buffer);
  }
}


void DtmfSenderImpl::OnToneChange(const std::string& tone) {
  if (observer_) {
    observer_->OnToneChange(tone);
  }
}


int DtmfSenderImpl::comma_delay() const {
  return dtmf_sender_->comma_delay();
}
}  // namespace libwebrtc