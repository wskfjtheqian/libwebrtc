#include "rtp_parameters_impl.h"
#include "base/refcountedobject.h"

namespace libwebrtc {

scoped_refptr<RtpEncodingParameters> RtpEncodingParameters::Create() {
  return new RefCountedObject<RtpEncodingParametersImpl>();
}

RtpEncodingParametersImpl::RtpEncodingParametersImpl()
    : rtp_encoding_parameters_(
          new RefCountedObject<webrtc::RtpEncodingParameters>()) {}

RtpEncodingParametersImpl::RtpEncodingParametersImpl(
    const RtpEncodingParameters& param)
    : rtp_encoding_parameters_(
          new RefCountedObject<webrtc::RtpEncodingParameters>(param)) {}

RtpEncodingParametersImpl::~RtpEncodingParametersImpl(){};

uint32_t RtpEncodingParametersImpl::GetSsrc() {
  return rtp_encoding_parameters_->ssrc.value();
}

void RtpEncodingParametersImpl::SetSsrc(uint32_t value) {
  rtp_encoding_parameters_->ssrc = value;
}

double RtpEncodingParametersImpl::GetBitratePriority() {
  return rtp_encoding_parameters_->bitrate_priority;
}

void RtpEncodingParametersImpl::SetBitratePriority(double value) {
  rtp_encoding_parameters_->bitrate_priority = value;
}

Priority RtpEncodingParametersImpl::GetNetworkPriority() {
  switch (rtp_encoding_parameters_->network_priority) {
    case webrtc::Priority ::kHigh:
      return Priority ::kHigh;
    case webrtc::Priority ::kLow:
      return Priority ::kHigh;
    case webrtc::Priority ::kMedium:
      return Priority ::kMedium;
    case webrtc::Priority ::kVeryLow:
      return Priority ::kVeryLow;
  }
  return Priority::kLow;
}

void RtpEncodingParametersImpl::SetNetworkPriority(Priority value) {
  switch (value) {
    case Priority ::kHigh:
      rtp_encoding_parameters_->network_priority = webrtc::Priority ::kHigh;
      return;
    case Priority ::kLow:
      rtp_encoding_parameters_->network_priority = webrtc::Priority ::kHigh;
      return;
    case Priority ::kMedium:
      rtp_encoding_parameters_->network_priority = webrtc::Priority ::kMedium;
      return;
    case Priority ::kVeryLow:
      rtp_encoding_parameters_->network_priority = webrtc::Priority ::kVeryLow;
      return;
  }
  rtp_encoding_parameters_->network_priority = webrtc::Priority::kLow;
}

int RtpEncodingParametersImpl::GetMaxBitrateBps() {
  return rtp_encoding_parameters_->max_bitrate_bps.value();
}

void RtpEncodingParametersImpl::SetMaxBitrateBps(int value) {
  rtp_encoding_parameters_->max_bitrate_bps = value;
}

int RtpEncodingParametersImpl::GetMinBitrateBps() {
  return rtp_encoding_parameters_->min_bitrate_bps.value();
}

void RtpEncodingParametersImpl::SetMinBitrateBps(int value) {
  rtp_encoding_parameters_->min_bitrate_bps = value;
}

double RtpEncodingParametersImpl::GetMaxFramerate() {
  return rtp_encoding_parameters_->max_framerate.value();
}

void RtpEncodingParametersImpl::SetMaxFramerate(double value) {
  rtp_encoding_parameters_->max_framerate = value;
}

int RtpEncodingParametersImpl::GetNumTemporalLayers() {
  return rtp_encoding_parameters_->num_temporal_layers.value();
}

void RtpEncodingParametersImpl::SetNumTemporalLayers(int value) {
  rtp_encoding_parameters_->num_temporal_layers = value;
}

double RtpEncodingParametersImpl::GetScaleResolutionDownBy() {
  return rtp_encoding_parameters_->scale_resolution_down_by.value();
}

void RtpEncodingParametersImpl::SetScaleResolutionDownBy(double value) {
  rtp_encoding_parameters_->scale_resolution_down_by = value;
}

std::string RtpEncodingParametersImpl::GetScalabilityMode() {
  return rtp_encoding_parameters_->scalability_mode.value();
}

void RtpEncodingParametersImpl::SetScalabilityMode(std::string value) {
  rtp_encoding_parameters_->scalability_mode = value;
}

bool RtpEncodingParametersImpl::GetActive() {
  return rtp_encoding_parameters_->active;
}

void RtpEncodingParametersImpl::SetActive(bool value) {
  rtp_encoding_parameters_->active = value;
}

std::string RtpEncodingParametersImpl::GetRid() {
  return rtp_encoding_parameters_->rid;
}

void RtpEncodingParametersImpl::SetRid(std::string value) {
  rtp_encoding_parameters_->rid = value;
}

bool RtpEncodingParametersImpl::GetAdaptivePtime() {
  return rtp_encoding_parameters_->adaptive_ptime;
}

void RtpEncodingParametersImpl::SetAdaptivePtime(bool value) {
  rtp_encoding_parameters_->adaptive_ptime;
}

bool RtpEncodingParametersImpl::operator==(
    const RtpEncodingParameters& o) const {
  return rtp_encoding_parameters_ ==
         ((RtpEncodingParametersImpl*)&o)->rtp_encoding_parameters_;
}

bool RtpEncodingParametersImpl::operator!=(
    const RtpEncodingParameters& o) const {
  return rtp_encoding_parameters_ !=
         ((RtpEncodingParametersImpl*)&o)->rtp_encoding_parameters_;
}

scoped_refptr<webrtc::RtpEncodingParameters>
RtpEncodingParametersImpl::rtp_parameters() {
  return rtp_encoding_parameters_;
}

}  // namespace libwebrtc
