#include "rtc_rtp_parameters_impl.h"

#include "base/refcountedobject.h"
namespace libwebrtc {
LIB_WEBRTC_API scoped_refptr<RTCRtpEncodingParameters>
RTCRtpEncodingParameters::Create() {
  return new RefCountedObject<RTCRtpEncodingParametersImpl>();
}

RTCRtpEncodingParametersImpl::RTCRtpEncodingParametersImpl() {}

RTCRtpEncodingParametersImpl::RTCRtpEncodingParametersImpl(
    webrtc::RtpEncodingParameters& rtp_encoding_parameters)
    : rtp_encoding_parameters_(rtp_encoding_parameters) {}

uint32_t RTCRtpEncodingParametersImpl::ssrc() {
  return rtp_encoding_parameters_.ssrc.value();
}

void RTCRtpEncodingParametersImpl::set_ssrc(uint32_t value) {
  rtp_encoding_parameters_.ssrc = value;
}

double RTCRtpEncodingParametersImpl::bitrate_priority() {
  return rtp_encoding_parameters_.bitrate_priority;
}

void RTCRtpEncodingParametersImpl::set_bitrate_priority(double value) {
  rtp_encoding_parameters_.bitrate_priority = value;
}

RTCPriority RTCRtpEncodingParametersImpl::network_priority() {
  return static_cast<RTCPriority>(rtp_encoding_parameters_.network_priority);
}

void RTCRtpEncodingParametersImpl::set_network_priority(RTCPriority value) {
  rtp_encoding_parameters_.network_priority =
      static_cast<webrtc::Priority>(value);
}

int RTCRtpEncodingParametersImpl::max_bitrate_bps() {
  return rtp_encoding_parameters_.max_bitrate_bps.value();
}

void RTCRtpEncodingParametersImpl::set_max_bitrate_bps(int value) {
  rtp_encoding_parameters_.max_bitrate_bps = value;
}

int RTCRtpEncodingParametersImpl::min_bitrate_bps() {
  return rtp_encoding_parameters_.min_bitrate_bps.value();
}

void RTCRtpEncodingParametersImpl::set_min_bitrate_bps(int value) {
  rtp_encoding_parameters_.min_bitrate_bps = value;
}

double RTCRtpEncodingParametersImpl::max_framerate() {
  return rtp_encoding_parameters_.max_framerate.value();
}

void RTCRtpEncodingParametersImpl::set_max_framerate(double value) {
  rtp_encoding_parameters_.max_framerate = value;
}

int RTCRtpEncodingParametersImpl::num_temporal_layers() {
  return rtp_encoding_parameters_.num_temporal_layers.value();
}

void RTCRtpEncodingParametersImpl::set_num_temporal_layers(int value) {
  rtp_encoding_parameters_.num_temporal_layers = value;
}

double RTCRtpEncodingParametersImpl::scale_resolution_down_by() {
  return rtp_encoding_parameters_.scale_resolution_down_by.value();
}

void RTCRtpEncodingParametersImpl::set_scale_resolution_down_by(double value) {
  rtp_encoding_parameters_.scale_resolution_down_by = value;
}

const string RTCRtpEncodingParametersImpl::scalability_mode() {
  auto temp = rtp_encoding_parameters_.scalability_mode.value();
  return temp.c_str();
}

void RTCRtpEncodingParametersImpl::set_scalability_mode(const string mode) {
  rtp_encoding_parameters_.scalability_mode = to_std_string(mode);
}

bool RTCRtpEncodingParametersImpl::active() {
  return rtp_encoding_parameters_.active;
}

void RTCRtpEncodingParametersImpl::set_active(bool value) {
  rtp_encoding_parameters_.active = value;
}

const string RTCRtpEncodingParametersImpl::rid() {
  auto temp = rtp_encoding_parameters_.rid;
  return temp.c_str();
}

void RTCRtpEncodingParametersImpl::set_rid(const string rid) {
  rtp_encoding_parameters_.rid = to_std_string(rid);
}

bool RTCRtpEncodingParametersImpl::adaptive_ptime() {
  return rtp_encoding_parameters_.adaptive_ptime;
}

void RTCRtpEncodingParametersImpl::set_adaptive_ptime(bool value) {
  rtp_encoding_parameters_.adaptive_ptime = value;
}

bool RTCRtpEncodingParametersImpl::operator==(
    scoped_refptr<RTCRtpEncodingParameters> o) const {
  return rtp_encoding_parameters_ ==
         static_cast<RTCRtpEncodingParametersImpl*>(o.get())->rtp_parameters();
}

bool RTCRtpEncodingParametersImpl::operator!=(
    scoped_refptr<RTCRtpEncodingParameters> o) const {
  return rtp_encoding_parameters_ !=
         static_cast<RTCRtpEncodingParametersImpl*>(o.get())->rtp_parameters();
}

webrtc::RtpEncodingParameters RTCRtpEncodingParametersImpl::rtp_parameters() {
  return rtp_encoding_parameters_;
}
RTCRtpParametersImpl::RTCRtpParametersImpl(
    webrtc::RtpParameters rtp_parameters) {}
webrtc::RtpParameters RTCRtpParametersImpl::rtp_parameters() {
  return rtp_parameters_;
}

const string RTCRtpParametersImpl::transaction_id() {
  auto temp = rtp_parameters_.transaction_id;
  return temp.c_str();
}

void RTCRtpParametersImpl::set_transaction_id(const string id) {
  rtp_parameters_.transaction_id = to_std_string(id);
}

const string RTCRtpParametersImpl::mid() {
  auto temp = rtp_parameters_.mid;
  return temp.c_str();
}
void RTCRtpParametersImpl::set_mid(const string mid) {
  rtp_parameters_.mid = to_std_string(mid);
}

const scoped_refptr<RTCCodecs>
RTCRtpParametersImpl::codecs() {
  scoped_refptr<RTCCodecs> vec = RTCCodecs::Create();
  for (auto item : rtp_parameters_.codecs) {
    vec->Add(new RefCountedObject<RTCRtpCodecParametersImpl>(item));
  }
  return vec;
}

void RTCRtpParametersImpl::set_codecs(const scoped_refptr<RTCCodecs> codecs) {
  std::vector<webrtc::RtpCodecParameters> list;
 
  for (int i = 0; i < codecs->Size();i++) {
    auto item = codecs->Get(i);
    auto impl = static_cast<RTCRtpCodecParametersImpl*>(item.get());
    list.push_back(impl->rtp_codec_parameters());
  }
  rtp_parameters_.codecs = list;
}

const scoped_refptr<RTCHeaderExtensions>
RTCRtpParametersImpl::header_extensions() {
  scoped_refptr<RTCHeaderExtensions> vec = RTCHeaderExtensions::Create();
  for (auto item : rtp_parameters_.header_extensions) {
    vec->Add(new RefCountedObject<RTCRtpExtensionImpl>(item));
  }
  return vec;
}

void RTCRtpParametersImpl::set_header_extensions(
    scoped_refptr<RTCHeaderExtensions> header_extensions) {
  std::vector<webrtc::RtpExtension> list;

  for (int i = 0; i < header_extensions->Size(); i++) {
    auto item = header_extensions->Get(i);
    auto impl = static_cast<RTCRtpExtensionImpl*>(item.get());
    list.push_back(impl->rtp_extension());
  }
  rtp_parameters_.header_extensions = list;
}

const scoped_refptr<RTCEncodings>
RTCRtpParametersImpl::encodings() {
  scoped_refptr<RTCEncodings> vec = RTCEncodings::Create();
  for (auto item : rtp_parameters_.encodings) {
    vec->Add(new RefCountedObject<RTCRtpEncodingParametersImpl>(item));
  }
  return vec;
}

void RTCRtpParametersImpl::set_encodings(
    scoped_refptr<RTCEncodings> encodings) {
  std::vector<webrtc::RtpEncodingParameters> list;
  for (int i = 0; i < encodings->Size(); i++) {
    auto item = encodings->Get(i);
    auto impl = static_cast<RTCRtpEncodingParametersImpl*>(item.get());
    list.push_back(impl->rtp_parameters());
  }
  rtp_parameters_.encodings = list;
}

scoped_refptr<RTCRtcpParameters> RTCRtpParametersImpl::rtcp_parameters() {
  return new RefCountedObject<RTCRtcpParametersImpl>(rtp_parameters_.rtcp);
}

void RTCRtpParametersImpl::set_rtcp_parameters(
    scoped_refptr<RTCRtcpParameters> value) {
  rtp_parameters_.rtcp =
      static_cast<RTCRtcpParametersImpl*>(value.get())->rtcp_parameters();
}

bool RTCRtpParametersImpl::operator==(scoped_refptr<RTCRtpParameters> o) const {
  return rtp_parameters_ ==
         static_cast<RTCRtpParametersImpl*>(o.get())->rtp_parameters();
}
bool RTCRtpParametersImpl::operator!=(scoped_refptr<RTCRtpParameters> o) const {
  return rtp_parameters_ !=
         static_cast<RTCRtpParametersImpl*>(o.get())->rtp_parameters();
}

RTCRtcpParametersImpl::RTCRtcpParametersImpl(
    webrtc::RtcpParameters rtcp_parameters)
    : rtcp_parameters_(rtcp_parameters) {}

uint32_t RTCRtcpParametersImpl::ssrc() {
  return rtcp_parameters_.ssrc.value();
}

void RTCRtcpParametersImpl::set_ssrc(uint32_t value) {
  rtcp_parameters_.ssrc = value;
}

const string RTCRtcpParametersImpl::cname() {
  return rtcp_parameters_.cname.c_str();
}
void RTCRtcpParametersImpl::set_cname(const string cname) {
  rtcp_parameters_.cname = to_std_string(cname);
}

bool RTCRtcpParametersImpl::reduced_size() {
  return rtcp_parameters_.reduced_size;
}

void RTCRtcpParametersImpl::set_reduced_size(bool value) {
  rtcp_parameters_.reduced_size = value;
}

bool RTCRtcpParametersImpl::mux() {
  return rtcp_parameters_.mux;
}
void RTCRtcpParametersImpl::set_mux(bool value) {}
bool RTCRtcpParametersImpl::operator==(
    scoped_refptr<RTCRtcpParameters> o) const {
  return rtcp_parameters_ ==
         static_cast<RTCRtcpParametersImpl*>(o.get())->rtcp_parameters();
}
bool RTCRtcpParametersImpl::operator!=(
    scoped_refptr<RTCRtcpParameters> o) const {
  return rtcp_parameters_ !=
         static_cast<RTCRtcpParametersImpl*>(o.get())->rtcp_parameters();
}
webrtc::RtcpParameters RTCRtcpParametersImpl::rtcp_parameters() {
  return rtcp_parameters_;
}

RTCRtpExtensionImpl::RTCRtpExtensionImpl(webrtc::RtpExtension rtp_extension)
    : rtp_extension_(rtp_extension) {}

bool RTCRtpExtensionImpl::operator==(scoped_refptr<RTCRtpExtension> o) const {
  return rtp_extension_ ==
         static_cast<RTCRtpExtensionImpl*>(o.get())->rtp_extension();
}

const string RTCRtpExtensionImpl::uri() {
  return rtp_extension_.uri.c_str();
}

void RTCRtpExtensionImpl::set_uri(const string uri) {
  rtp_extension_.uri = to_std_string(uri);
}

int RTCRtpExtensionImpl::id() {
  return rtp_extension_.id;
}

void RTCRtpExtensionImpl::set_id(int value) {
  rtp_extension_.id = value;
}

bool RTCRtpExtensionImpl::encrypt() {
  return rtp_extension_.encrypt;
}

void RTCRtpExtensionImpl::set_encrypt(bool value) {
  rtp_extension_.encrypt = value;
}

webrtc::RtpExtension RTCRtpExtensionImpl::rtp_extension() {
  return rtp_extension_;
}

const string RTCRtpExtensionImpl::ToString() const {
  auto temp = rtp_extension_.ToString();
  return temp.c_str();
}

RTCRtpCodecParametersImpl::RTCRtpCodecParametersImpl(
    webrtc::RtpCodecParameters rtp_codec_parameters)
    : rtp_codec_parameters_(rtp_codec_parameters) {}

const string RTCRtpCodecParametersImpl::mime_type() const {
  return rtp_codec_parameters_.mime_type().c_str();
}

const string RTCRtpCodecParametersImpl::name() {
  return rtp_codec_parameters_.name.c_str();
}

void RTCRtpCodecParametersImpl::set_name(const string name) {
  rtp_codec_parameters_.name = to_std_string(name);
}

RTCMediaType RTCRtpCodecParametersImpl::kind() {
  return static_cast<RTCMediaType>(rtp_codec_parameters_.kind);
}

void RTCRtpCodecParametersImpl::set_kind(RTCMediaType value) {
  rtp_codec_parameters_.kind = static_cast<cricket::MediaType>(value);
}

int RTCRtpCodecParametersImpl::payload_type() {
  return rtp_codec_parameters_.payload_type;
}

void RTCRtpCodecParametersImpl::set_payload_type(int value) {
  rtp_codec_parameters_.payload_type = value;
}

int RTCRtpCodecParametersImpl::clock_rate() {
  return rtp_codec_parameters_.clock_rate.value();
}

void RTCRtpCodecParametersImpl::set_clock_rate(int value) {
  rtp_codec_parameters_.clock_rate = value;
}

int RTCRtpCodecParametersImpl::num_channels() {
  return rtp_codec_parameters_.num_channels.value();
}

void RTCRtpCodecParametersImpl::set_num_channels(int value) {
  rtp_codec_parameters_.num_channels = value;
}

int RTCRtpCodecParametersImpl::max_ptime() {
  return rtp_codec_parameters_.max_ptime.value();
}

void RTCRtpCodecParametersImpl::set_max_ptime(int value) {
  rtp_codec_parameters_.max_ptime = value;
}

int RTCRtpCodecParametersImpl::ptime() {
  return rtp_codec_parameters_.ptime.value();
}

void RTCRtpCodecParametersImpl::set_ptime(int value) {
  rtp_codec_parameters_.ptime = value;
}

const scoped_refptr<RTCRtcpFeedbacks>
RTCRtpCodecParametersImpl::rtcp_feedback() {
  scoped_refptr<RTCRtcpFeedbacks> vec = RTCRtcpFeedbacks::Create();
  for (auto item : rtp_codec_parameters_.rtcp_feedback) {
    vec->Add(new RefCountedObject<RTCRtcpFeedbackImpl>(item));
  }
  return vec;
}

void RTCRtpCodecParametersImpl::set_rtcp_feedback(
    const scoped_refptr<RTCRtcpFeedbacks> rtcp_feedbacks) {
  std::vector<webrtc::RtcpFeedback> rtcp_feedback;
  for (int i = 0; i < rtcp_feedbacks->Size(); i++) {
    auto item = rtcp_feedbacks->Get(i);
    auto impl = static_cast<RTCRtcpFeedbackImpl*>(item.get());
    rtcp_feedback.push_back(impl->rtcp_feedback());
  }
  rtp_codec_parameters_.rtcp_feedback = rtcp_feedback;
}

const scoped_refptr<RTCParameters> RTCRtpCodecParametersImpl::parameters() {
  scoped_refptr<RTCParameters> els = RTCParameters::Create();
  for (auto item : rtp_codec_parameters_.parameters) {
    els->Set(string(item.first.c_str(), item.first.size()),
             string(item.second.c_str(), item.second.size()));
  }
  return els;
}

void RTCRtpCodecParametersImpl::set_parameters(
    scoped_refptr<RTCParameters> parameters) {
  rtp_codec_parameters_.parameters =
      static_cast<RTCParametersImpl*>(parameters.get())->map();
}

bool RTCRtpCodecParametersImpl::operator==(
    scoped_refptr<RTCRtpCodecParameters> o) {
  RTCRtpCodecParametersImpl* impl =
      static_cast<RTCRtpCodecParametersImpl*>(o.get());
  return rtp_codec_parameters_ == impl->rtp_codec_parameters();
}

bool RTCRtpCodecParametersImpl::operator!=(
    scoped_refptr<RTCRtpCodecParameters> o) {
  RTCRtpCodecParametersImpl* impl =
      static_cast<RTCRtpCodecParametersImpl*>(o.get());
  return rtp_codec_parameters_ != impl->rtp_codec_parameters();
}

webrtc::RtpCodecParameters RTCRtpCodecParametersImpl::rtp_codec_parameters() {
  return rtp_codec_parameters_;
}

RTCRtcpFeedbackImpl::RTCRtcpFeedbackImpl(webrtc::RtcpFeedback rtcp_feedback)
    : rtcp_feedback_(rtcp_feedback) {}

webrtc::RtcpFeedback RTCRtcpFeedbackImpl::rtcp_feedback() {
  return rtcp_feedback_;
}

RTCRtcpFeedbackType RTCRtcpFeedbackImpl::type() {
  return static_cast<RTCRtcpFeedbackType>(rtcp_feedback_.type);
}

void RTCRtcpFeedbackImpl::set_type(RTCRtcpFeedbackType value) {
  rtcp_feedback_.type = static_cast<webrtc::RtcpFeedbackType>(value);
}

RTCRtcpFeedbackMessageType RTCRtcpFeedbackImpl::message_type() {
  return static_cast<RTCRtcpFeedbackMessageType>(
      rtcp_feedback_.message_type.value());
}

void RTCRtcpFeedbackImpl::set_message_type(RTCRtcpFeedbackMessageType value) {
  rtcp_feedback_.message_type =
      static_cast<webrtc::RtcpFeedbackMessageType>(value);
}

bool RTCRtcpFeedbackImpl::operator==(scoped_refptr<RTCRtcpFeedback> o) {
  return rtcp_feedback_ ==
         static_cast<RTCRtcpFeedbackImpl*>(o.get())->rtcp_feedback();
}

bool RTCRtcpFeedbackImpl::operator!=(scoped_refptr<RTCRtcpFeedback> o) {
  return rtcp_feedback_ !=
         static_cast<RTCRtcpFeedbackImpl*>(o.get())->rtcp_feedback();
}

 LIB_WEBRTC_API scoped_refptr<RTCEncodings> RTCEncodings::Create() {
  return new RefCountedObject<RTCEncodingsImpl>();
 }

void RTCEncodingsImpl::Add(scoped_refptr<RTCRtpEncodingParameters> value) {
  _list.push_back(value);
}

scoped_refptr<RTCRtpEncodingParameters> RTCEncodingsImpl::Get(int index) {
  return _list.at(index);
}

int RTCEncodingsImpl::Size() {
  return _list.size();
}

void RTCEncodingsImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCEncodingsImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCRtpEncodingParameters>> RTCEncodingsImpl::list() {
  return _list;
}


LIB_WEBRTC_API scoped_refptr<RTCHeaderExtensions> RTCHeaderExtensions::Create() {
  return new RefCountedObject<RTCHeaderExtensionsImpl>();
}

void RTCHeaderExtensionsImpl::Add(scoped_refptr<RTCRtpExtension> value) {
  _list.push_back(value);
}

scoped_refptr<RTCRtpExtension> RTCHeaderExtensionsImpl::Get(int index) {
  return _list.at(index);
}

int RTCHeaderExtensionsImpl::Size() {
  return _list.size();
}

void RTCHeaderExtensionsImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCHeaderExtensionsImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCRtpExtension>> RTCHeaderExtensionsImpl::list() {
  return _list;
}

LIB_WEBRTC_API scoped_refptr<RTCCodecs> RTCCodecs::Create() {
  return new RefCountedObject<RTCCodecsImpl>();
}

void RTCCodecsImpl::Add(scoped_refptr<RTCRtpCodecParameters> value) {
  _list.push_back(value);
}

scoped_refptr<RTCRtpCodecParameters> RTCCodecsImpl::Get(int index) {
  return scoped_refptr<RTCRtpCodecParameters>();
}

int RTCCodecsImpl::Size() {
  return _list.size();
}

void RTCCodecsImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCCodecsImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCRtpCodecParameters>> RTCCodecsImpl::list() {
  return _list;
}

scoped_refptr<RTCParameters> RTCParameters::Create() {
  return new RefCountedObject<RTCParametersImpl>();
}

void RTCParametersImpl::Set(string key, string value) {
  _map[std::string(key.data(), key.size())] =
      std::string(value.data(), value.size());
}

string RTCParametersImpl::Get(string key) {
    std::string ret = _map.at(std::string(key.data(),key.size()));
  return string(ret.c_str(),ret.size());
}

int RTCParametersImpl::Size() {
  return _map.size();
}

void RTCParametersImpl::Remove(string key) {
  _map.erase(std::string(key.data(), key.size()));
}

void RTCParametersImpl::Clean() {
  _map.clear();
}

void RTCParametersImpl::ForEcoh(OnRTCParameters on) {
  for (auto item : _map) {
    on(string(item.first.c_str(), item.first.size()),
       string(item.second.c_str(), item.second.size()));
  }
}

std::map<std::string, std::string> RTCParametersImpl::map() {
  return _map;
}


LIB_WEBRTC_API scoped_refptr<RTCRtcpFeedbacks> RTCRtcpFeedbacks::Create() {
  return new RefCountedObject<RTCRtcpFeedbacksImpl>();
}

void RTCRtcpFeedbacksImpl::Add(scoped_refptr<RTCRtcpFeedback> value) {
  _list.push_back(value);
}

scoped_refptr<RTCRtcpFeedback> RTCRtcpFeedbacksImpl::Get(int index) {
  return _list.at(index);
}

int RTCRtcpFeedbacksImpl::Size() {
  return _list.size();
}

void RTCRtcpFeedbacksImpl::Remove(int index) {
  auto it = _list.begin() + index;
  if (it != _list.end()) {
    _list.erase(it);
  }
}

void RTCRtcpFeedbacksImpl::Clean() {
  _list.clear();
}

std::vector<scoped_refptr<RTCRtcpFeedback>> RTCRtcpFeedbacksImpl::list() {
  return _list;
}

}  // namespace libwebrtc