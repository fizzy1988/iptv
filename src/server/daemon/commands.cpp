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

common::Error ChangedSourcesStreamBroadcast(const ChangedSouresInfo& params, fastotv::protocol::request_t* req) {
  if (!req) {
    return common::make_error_inval();
  }

  std::string changed_json;
  common::Error err_ser = params.SerializeToString(&changed_json);
  if (err_ser) {
    return err_ser;
  }

  *req = fastotv::protocol::request_t::MakeNotification(STREAM_CHANGED_SOURCES_STREAM, changed_json);
  return common::Error();
}

common::Error StatisitcStreamBroadcast(const StatisticInfo& params, fastotv::protocol::request_t* req) {
  if (!req) {
    return common::make_error_inval();
  }

  std::string stat_json;
  common::Error err_ser = params.SerializeToString(&stat_json);
  if (err_ser) {
    return err_ser;
  }

  *req = fastotv::protocol::request_t::MakeNotification(STREAM_STATISTIC_STREAM, stat_json);
  return common::Error();
}

common::Error StatisitcServiceBroadcast(fastotv::protocol::serializet_params_t params,
                                        fastotv::protocol::request_t* req) {
  if (!req) {
    return common::make_error_inval();
  }

  *req = fastotv::protocol::request_t::MakeNotification(STREAM_STATISTIC_SERVICE, params);
  return common::Error();
}

common::Error QuitStatusStreamBroadcast(const stream::QuitStatusInfo& params, fastotv::protocol::request_t* req) {
  if (!req) {
    return common::make_error_inval();
  }

  std::string quit_json;
  common::Error err_ser = params.SerializeToString(&quit_json);
  if (err_ser) {
    return err_ser;
  }

  *req = fastotv::protocol::request_t::MakeNotification(STREAM_QUIT_STATUS_STREAM, quit_json);
  return common::Error();
}

}  // namespace server
}  // namespace iptv_cloud
