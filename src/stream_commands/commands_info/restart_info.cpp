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

#include "stream_commands/commands_info/restart_info.h"

namespace iptv_cloud {

RestartInfo::RestartInfo() : base_class() {}

common::Error RestartInfo::SerializeFields(json_object* out) const {
  UNUSED(out);
  return common::Error();
}

common::Error RestartInfo::DoDeSerialize(json_object* serialized) {
  UNUSED(serialized);
  RestartInfo inf;
  *this = inf;
  return common::Error();
}

}  // namespace iptv_cloud
