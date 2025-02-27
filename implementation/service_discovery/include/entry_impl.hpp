// Copyright (C) 2014-2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_SD_ENTRY_IMPL_HPP
#define VSOMEIP_SD_ENTRY_IMPL_HPP

#include <memory>
#include <vector>

#include <vsomeip/primitive_types.hpp>
#include <vsomeip/serializable.hpp>

#include "enumeration_types.hpp"
#include "message_element_impl.hpp"

#define VSOMEIP_MAX_OPTION_RUN	2

namespace vsomeip {

class deserializer;

namespace sd {

class option_impl;
class message_impl;

class entry_impl: public message_element_impl {
public:
    virtual ~entry_impl();

    // public interface
    entry_type_e get_type() const;

    service_t get_service() const;
    void set_service(service_t _service);

    instance_t get_instance() const;
    void set_instance(instance_t _instance);

    major_version_t get_major_version() const;
    void set_major_version(major_version_t _version);

    ttl_t get_ttl() const;
    void set_ttl(ttl_t _ttl);

    const std::vector<uint8_t> & get_options(uint8_t _run) const;
    void assign_option(const std::shared_ptr<option_impl> &_option,
            uint8_t _run);

    bool is_service_entry() const;
    bool is_eventgroup_entry() const;

    void set_type(entry_type_e _type);

    virtual bool serialize(vsomeip::serializer *_to) const;
    virtual bool deserialize(vsomeip::deserializer *_from);

protected:
    entry_type_e type_;
    service_t service_;
    instance_t instance_;
    major_version_t major_version_;
    ttl_t ttl_;

    std::vector<uint8_t> options_[VSOMEIP_MAX_OPTION_RUN];

    entry_impl();
    entry_impl(const entry_impl &entry_);
};

} // namespace sd
} // namespace vsomeip

#endif // VSOMEIP_SD_ENTRY_IMPL_HPP
