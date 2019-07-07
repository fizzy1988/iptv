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

#include "base/stream_commands.h"

namespace iptv_cloud {

fastotv::protocol::request_t RestartStreamRequest(fastotv::protocol::sequance_id_t id) {
  fastotv::protocol::request_t req;
  req.id = id;
  req.method = RESTART_STREAM;
  return req;
}

fastotv::protocol::response_t RestartStreamResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::request_t StopStreamRequest(fastotv::protocol::sequance_id_t id) {
  fastotv::protocol::request_t req;
  req.id = id;
  req.method = STOP_STREAM;
  return req;
}

fastotv::protocol::response_t StopStreamResponceSuccess(fastotv::protocol::sequance_id_t id) {
  return fastotv::protocol::response_t::MakeMessage(id,
                                                    common::protocols::json_rpc::JsonRPCMessage::MakeSuccessMessage());
}

fastotv::protocol::request_t ChangedSourcesStreamBroadcast(fastotv::protocol::serializet_params_t params) {
  return fastotv::protocol::request_t::MakeNotification(CHANGED_SOURCES_STREAM, params);
}

fastotv::protocol::request_t StatisticStreamBroadcast(fastotv::protocol::serializet_params_t params) {
  return fastotv::protocol::request_t::MakeNotification(STATISTIC_STREAM, params);
}

}  // namespace iptv_cloud
