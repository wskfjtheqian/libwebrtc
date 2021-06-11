#include "rtp_transceiver_interface_impl.h"
#include "base/refcountedobject.h"
#include <src/rtp_parameters_impl.h>

namespace libwebrtc {
scoped_refptr<RtpTransceiverInit> RtpTransceiverInit::Create() {
  return new RefCountedObject<RtpTransceiverInitImpl>();
}
RtpTransceiverInitImpl::RtpTransceiverInitImpl()
    : rtp_transceiver_init_(new RefCountedObject<webrtc::RtpTransceiverInit>()) {}

RtpTransceiverInitImpl::RtpTransceiverInitImpl(const RtpTransceiverInit& param)
    : rtp_transceiver_init_(new RefCountedObject<webrtc::RtpTransceiverInit>(param)) {}

RtpTransceiverInitImpl::~RtpTransceiverInitImpl() {
}

RtpTransceiverDirection RtpTransceiverInitImpl::GetDirection() {
  int direction = static_cast<int>(rtp_transceiver_init_->direction);
  return static_cast<RtpTransceiverDirection>(direction);
}

void RtpTransceiverInitImpl::SetDirection(RtpTransceiverDirection value) {
  int direction = static_cast<int>(value);
  rtp_transceiver_init_->direction =
      static_cast<webrtc::RtpTransceiverDirection>(direction);
}

std::vector<std::string> RtpTransceiverInitImpl::GetStreamIds() {
  return rtp_transceiver_init_->stream_ids;
}

void RtpTransceiverInitImpl::GetStreamIds(std::vector<std::string> value) {
  rtp_transceiver_init_->stream_ids = value;
}

std::vector<scoped_refptr<RtpEncodingParameters>>
RtpTransceiverInitImpl::GetSendEncodings() {
  return std::vector<scoped_refptr<RtpEncodingParameters>>();
}

void RtpTransceiverInitImpl::SetSendEncodings(
    std::vector<scoped_refptr<RtpEncodingParameters>> value) {
  std::vector<webrtc::RtpEncodingParameters> list;
  for (auto item : value) {
    RtpEncodingParametersImpl* impl =
        static_cast<RtpEncodingParametersImpl*>(item.get());
    list.push_back(*impl->rtp_parameters());
  }
  rtp_transceiver_init_->send_encodings = list;
}

scoped_refptr<webrtc::RtpTransceiverInit> RtpTransceiverInitImpl::rtc_init() {
  return rtp_transceiver_init_;
}



MediaType RtpTransceiverInterfaceImpl::GetMediaType() const {
  int ret = static_cast<int>( rtp_transceiver_interface_->media_type());
  return static_cast<MediaType>(ret);
}

std::string RtpTransceiverInterfaceImpl::GetMid() const {
  return rtp_transceiver_interface_->mid().value();
}

scoped_refptr<RtpSenderInterface> RtpTransceiverInterfaceImpl::Sender() const {
  return rtp_transceiver_interface_->sender();
}

bool RtpTransceiverInterfaceImpl::Stopped() const {
  return rtp_transceiver_interface_->stopped();
 }


void RtpTransceiverInterfaceImpl::SetRtpTransceiverInterface(
     rtc::scoped_refptr<webrtc::RtpTransceiverInterface> rti) {
   rtp_transceiver_interface_ = rti;
 }

 rtc::scoped_refptr<webrtc::RtpTransceiverInterface>
 RtpTransceiverInterfaceImpl::GetRtpTransceiverInterface() {
   return rtp_transceiver_interface_;
 }