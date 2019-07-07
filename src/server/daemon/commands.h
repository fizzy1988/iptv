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

#pragma once

#include <string>

#include <fastotv/protocol/types.h>

// daemon
// client commands

#define DAEMON_START_STREAM "start_stream"  // {"config": {...}, "command_line": {...} }
#define DAEMON_STOP_STREAM "stop_stream"
#define DAEMON_RESTART_STREAM "restart_stream"
#define DAEMON_GET_LOG_STREAM "get_log_stream"
#define DAEMON_GET_PIPELINE_STREAM "get_pipeline_stream"

#define DAEMON_ACTIVATE "activate_request"  // {"key": "XXXXXXXXXXXXXXXXXX"}
#define DAEMON_STOP_SERVICE "stop_service"  // {"delay": 0 }
#define DAEMON_PREPARE_SERVICE \
  "prepare_service"  // { "feedback_directory": "", "timeshifts_directory": "", "hls_directory": "",
                     // "playlists_directory": "", "dvb_directory": "", "capture_card_directory": "" }
#define DAEMON_SYNC_SERVICE "sync_service"
#define DAEMON_PING_SERVICE "ping_service"
#define DAEMON_GET_LOG_SERVICE "get_log_service"  // {"path":"http://localhost/service/id"}

#define DAEMON_SERVER_PING "ping_client"

// Broadcast
#define STREAM_CHANGED_SOURCES_STREAM "changed_source_stream"
#define STREAM_STATISTIC_STREAM "statistic_stream"
#define STREAM_QUIT_STATUS_STREAM "quit_status_stream"
#define STREAM_STATISTIC_SERVICE "statistic_service"

namespace iptv_cloud {
namespace server {

// requests
fastotv::protocol::request_t StopServiceRequest(fastotv::protocol::sequance_id_t id,
                                                fastotv::protocol::serializet_params_t params);  // StopInfo
fastotv::protocol::request_t PingDaemonRequest(fastotv::protocol::sequance_id_t id,
                                               fastotv::protocol::serializet_params_t params);  // ServerPingInfo

// responces service
fastotv::protocol::response_t StopServiceResponceSuccess(fastotv::protocol::sequance_id_t id);
fastotv::protocol::response_t StopServiceResponceFail(fastotv::protocol::sequance_id_t id,
                                                      const std::string& error_text);

fastotv::protocol::response_t GetLogServiceResponceSuccess(fastotv::protocol::sequance_id_t id);
fastotv::protocol::response_t GetLogServiceResponceFail(fastotv::protocol::sequance_id_t id,
                                                        const std::string& error_text);

fastotv::protocol::response_t ActivateResponce(fastotv::protocol::sequance_id_t id,
                                               const std::string& result);  // ServerInfo
fastotv::protocol::response_t ActivateResponceFail(fastotv::protocol::sequance_id_t id, const std::string& error_text);

fastotv::protocol::response_t StateServiceResponce(fastotv::protocol::sequance_id_t id,
                                                   const std::string& result);  // Directories

fastotv::protocol::response_t SyncServiceResponceSuccess(fastotv::protocol::sequance_id_t id);

fastotv::protocol::response_t PingServiceResponce(fastotv::protocol::sequance_id_t id,
                                                  const std::string& result);  // ServerPingInfo
fastotv::protocol::response_t PingServiceResponceFail(fastotv::protocol::sequance_id_t id,
                                                      const std::string& error_text);

// responces streams
fastotv::protocol::response_t StartStreamResponceSuccess(fastotv::protocol::sequance_id_t id);
fastotv::protocol::response_t StartStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                      const std::string& error_text);

fastotv::protocol::response_t StopStreamResponceSuccess(fastotv::protocol::sequance_id_t id);
fastotv::protocol::response_t StopStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                     const std::string& error_text);

fastotv::protocol::response_t RestartStreamResponceSuccess(fastotv::protocol::sequance_id_t id);
fastotv::protocol::response_t RestartStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                        const std::string& error_text);

fastotv::protocol::response_t GetLogStreamResponceSuccess(fastotv::protocol::sequance_id_t id);
fastotv::protocol::response_t GetLogStreamResponceFail(fastotv::protocol::sequance_id_t id,
                                                       const std::string& error_text);

// Broadcast
fastotv::protocol::request_t ChangedSourcesStreamBroadcast(
    fastotv::protocol::serializet_params_t params);  // ChangedSouresInfo
fastotv::protocol::request_t StatisitcStreamBroadcast(fastotv::protocol::serializet_params_t params);   // StatisticInfo
fastotv::protocol::request_t StatisitcServiceBroadcast(fastotv::protocol::serializet_params_t params);  // ServerInfo
fastotv::protocol::request_t QuitStatusStreamBroadcast(fastotv::protocol::serializet_params_t params);  // StatusInfo

}  // namespace server
}  // namespace iptv_cloud
