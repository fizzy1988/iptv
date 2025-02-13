/*  Copyright (C) 2014-2019 FastoGT. All right reserved.
    This file is part of iptv_cloud.
    iptv_cloud is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    iptv_cloud is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with iptv_cloud.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stream/streams/configs/encode_config.h"

#include <string>

#include "base/constants.h"
#include "base/gst_constants.h"

#include "stream/gst_types.h"

#define DEFAULT_VIDEO_ENCODER X264_ENC
#define DEFAULT_AUDIO_ENCODER FAAC

namespace iptv_cloud {
namespace stream {
namespace streams {

EncodeConfig::EncodeConfig(const base_class& config)
    : base_class(config),
      deinterlace_(),
      frame_rate_(),
      volume_(),
      video_encoder_(DEFAULT_VIDEO_ENCODER),
      audio_encoder_(DEFAULT_AUDIO_ENCODER),
      audio_channels_count_(),
      video_encoder_args_(),
      video_encoder_str_args_(),
      size_(),
      video_bit_rate_(),
      audio_bit_rate_(),
      logo_(),
      decklink_video_mode_(DEFAULT_DECKLINK_VIDEO_MODE),
      aspect_ratio_(),
      relay_video_(false),
      relay_audio_(false) {}

bool EncodeConfig::GetRelayVideo() const {
  return relay_video_;
}

void EncodeConfig::SetRelayVideo(bool rv) {
  relay_video_ = rv;
}

bool EncodeConfig::GetRelayAudio() const {
  return relay_audio_;
}

void EncodeConfig::SetRelayAudio(bool ra) {
  relay_audio_ = ra;
}

void EncodeConfig::SetVolume(volume_t volume) {
  volume_ = volume;
}

volume_t EncodeConfig::GetVolume() const {
  return volume_;
}

frame_rate_t EncodeConfig::GetFramerate() const {
  return frame_rate_;
}

void EncodeConfig::SetFrameRate(frame_rate_t rate) {
  frame_rate_ = rate;
}

deinterlace_t EncodeConfig::GetDeinterlace() const {
  return deinterlace_;
}

void EncodeConfig::SetDeinterlace(deinterlace_t deinterlace) {
  deinterlace_ = deinterlace;
}

std::string EncodeConfig::GetVideoEncoder() const {
  return video_encoder_;
}

void EncodeConfig::SetVideoEncoder(const std::string& enc) {
  video_encoder_ = enc;
}

std::string EncodeConfig::GetAudioEncoder() const {
  return audio_encoder_;
}

void EncodeConfig::SetAudioEncoder(const std::string& enc) {
  audio_encoder_ = enc;
}

bool EncodeConfig::IsGpu() const {
  const std::string video_enc = GetVideoEncoder();
  EncoderType enc;
  if (GetEncoderType(video_enc, &enc)) {
    return enc == GPU_MFX || enc == GPU_VAAPI;
  }

  return false;
}

bool EncodeConfig::IsMfxGpu() const {
  const std::string video_enc = GetVideoEncoder();
  EncoderType enc;
  if (GetEncoderType(video_enc, &enc)) {
    return enc == GPU_MFX;
  }

  return false;
}

audio_channels_count_t EncodeConfig::GetAudioChannelsCount() const {
  return audio_channels_count_;
}

void EncodeConfig::SetAudioChannelsCount(audio_channels_count_t channels) {
  audio_channels_count_ = channels;
}

common::draw::Size EncodeConfig::GetSize() const {
  return size_;
}

void EncodeConfig::SetSize(common::draw::Size size) {
  size_ = size;
}

bit_rate_t EncodeConfig::GetVideoBitrate() const {
  return video_bit_rate_;
}

void EncodeConfig::SetVideoBitrate(bit_rate_t bitr) {
  video_bit_rate_ = bitr;
}

bit_rate_t EncodeConfig::GetAudioBitrate() const {
  return audio_bit_rate_;
}

void EncodeConfig::SetAudioBitrate(bit_rate_t bitr) {
  audio_bit_rate_ = bitr;
}

video_encoders_args_t EncodeConfig::GetVideoEncoderArgs() const {
  return video_encoder_args_;
}

void EncodeConfig::SetVideoEncoderArgs(const video_encoders_args_t& args) {
  video_encoder_args_ = args;
}

video_encoders_str_args_t EncodeConfig::GetVideoEncoderStrArgs() const {
  return video_encoder_str_args_;
}

void EncodeConfig::SetVideoEncoderStrArgs(const video_encoders_str_args_t& args) {
  video_encoder_str_args_ = args;
}

void EncodeConfig::SetLogo(const Logo& logo) {
  logo_ = logo;
}

Logo EncodeConfig::GetLogo() const {
  return logo_;
}

rational_t EncodeConfig::GetAspectRatio() const {
  return aspect_ratio_;
}

void EncodeConfig::SetAspectRatio(rational_t rat) {
  aspect_ratio_ = rat;
}

decklink_video_mode_t EncodeConfig::GetDecklinkMode() const {
  return decklink_video_mode_;
}

void EncodeConfig::SetDecklinkMode(decklink_video_mode_t decl) {
  decklink_video_mode_ = decl;
}

VodEncodeConfig::VodEncodeConfig(const base_class& config) : base_class(config), cleanup_ts_(false) {}

bool VodEncodeConfig::GetCleanupTS() const {
  return cleanup_ts_;
}

void VodEncodeConfig::SetCleanupTS(bool cleanup) {
  cleanup_ts_ = cleanup;
}

}  // namespace streams
}  // namespace stream
}  // namespace iptv_cloud
