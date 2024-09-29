// Copyright (C) 2014-2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_ROUTING_TYPES_HPP
#define VSOMEIP_ROUTING_TYPES_HPP

#include <map>
#include <memory>

#include <vsomeip/primitive_types.hpp>

namespace vsomeip {

class serviceinfo;

// 根据serviceId与instanceId定位，serviceinfo描述一个服务实例，一个服务可以有多个实例
typedef std::map<service_t,
                 std::map<instance_t,
                          std::shared_ptr<serviceinfo> > > services_t;

class eventgroupinfo;
// 根据service id 与 instance id 唯一定位一个服务实例，但服务实例可以在不同的事件组中存在
// 因此需要再增加一个eventgroup id 来唯一标识
typedef std::map<service_t,
                 std::map<instance_t,
                          std::map<eventgroup_t,
                                   std::shared_ptr<
                                       eventgroupinfo> > > > eventgroups_t;

}
// namespace vsomeip

#endif // VSOMEIP_ROUTING_TYPES_HPP
