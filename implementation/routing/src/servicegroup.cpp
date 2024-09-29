// Copyright (C) 2014-2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "../include/servicegroup.hpp"
#include "../include/serviceinfo.hpp"

namespace vsomeip {

servicegroup::servicegroup(const std::string &_name, bool _is_local)
	: name_(_name), is_local_(_is_local) {
}

servicegroup::~servicegroup() {
}

std::string servicegroup::get_name() const {
	return name_;
}

bool servicegroup::is_local() const {
    return is_local_;
}

bool servicegroup::add_service(
		service_t _service, instance_t _instance,
		std::shared_ptr< serviceinfo > _info) {
	bool its_result(true);
	auto find_service = services_.find(_service);
	// 如果services里有service
	if (find_service != services_.end()) {
		auto find_instance = find_service->second.find(_instance);
		// 如果有service的instance，则不添加，否则添加上
		if (find_instance != find_service->second.end()) {
			its_result = false;
		} else {
			find_service->second[_instance] = _info;
		}
	} else {
		services_[_service][_instance] = _info;
	}

	_info->set_group(this);

	return its_result;
}

bool servicegroup::remove_service(service_t _service, instance_t _instance) {
	bool its_result(false);
	auto find_service = services_.find(_service);
	if (find_service != services_.end()) {
		auto find_instance = find_service->second.find(_instance);
		if (find_instance != find_service->second.end()) {
			find_service->second.erase(_instance);
			if (0 == find_service->second.size()) {
				services_.erase(_service);
			}
			its_result = true;
		}
	}
	return its_result;
}

services_t servicegroup::get_services() const {
	return services_;
}

} // namespace vsomeip



