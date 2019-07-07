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

#include "server/daemon/commands.h"

namespace iptv_cloud {
namespace server {

fastotv::protocol::response_t StopServiceResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::response_t StopServiceResponceFail(fastotv::protocol::sequance_id_t id,
                                                      const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::response_t GetLogServiceResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::response_t GetLogServiceResponceFail(fastotv::protocol::sequance_id_t id,
                                                        const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::request_t StopServiceRequest(fastotv::protocol::sequance_id_t id,
                                                fastotv::protocol::serializet_params_t params) {
  fastotv::protocol::request_t req;
  req.id = id;
  req.method = DAEMON_STOP_SERVICE;
  req.params = params;
  return req;
}

fastotv::protocol::response_t ActivateResponce(fastotv::protocol::sequance_id_t id, const std::string& result) {
  return fastotv::protocol::response_t::MakeMessage(
      id, common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage(result));
}

fastotv::protocol::response_t ActivateResponceFail(fastotv::protocol::sequance_id_t id, const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::response_t StateServiceResponce(fastotv::protocol::sequance_id_t id, const std::string& result) {
  return fastotv::protocol::response_t::MakeMessage(
      id, common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage(result));
}

fastotv::protocol::response_t SyncServiceResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::response_t StartStreamResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::response_t StartStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                      const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::response_t StopStreamResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::response_t StopStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                     const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::response_t RestartStreamResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::response_t RestartStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                        const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::response_t GetLogStreamResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::response_t GetLogStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                       const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::request_t PingDaemonRequest(fastotv::protocol::sequance_id_t id,
                                               fastotv::protocol::serializet_params_t params) {
  fastotv::protocol::request_t req;
  req.id = id;
  req.method = DAEMON_SERVER_PING;
  req.params = params;
  return req;
}

fastotv::protocol::response_t PingServiceResponce(fastotv::protocol::sequance_id_t id, const std::string& result) {
  return fastotv::protocol::response_t::MakeMessage(
      id, common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage(result));
}

fastotv::protocol::response_t PingServiceResponceFail(fastotv::protocol::sequance_id_t id,
                                                      const std::string& error_text) {
  return fastotv::protocol::response_t::MakeError(
      id, common::protocols::json_rpc::JsonRPCError::MakeServerErrorFromText(error_text));
}

fastotv::protocol::request_t ChangedSourcesStreamBroadcast(fastotv::protocol::serializet_params_t params) {
  return fastotv::protocol::request_t::MakeNotification(STREAM_CHANGED_SOURCES_STREAM, params);
}

fastotv::protocol::request_t StatisitcStreamBroadcast(fastotv::protocol::serializet_params_t params) {
  return fastotv::protocol::request_t::MakeNotification(STREAM_STATISTIC_STREAM, params);
}

fastotv::protocol::request_t StatisitcServiceBroadcast(fastotv::protocol::serializet_params_t params) {
  return fastotv::protocol::request_t::MakeNotification(STREAM_STATISTIC_SERVICE, params);
}

fastotv::protocol::request_t QuitStatusStreamBroadcast(fastotv::protocol::serializet_params_t params) {
  return fastotv::protocol::request_t::MakeNotification(STREAM_QUIT_STATUS_STREAM, params);
}

}  // namespace server
}  // namespace iptv_cloud
