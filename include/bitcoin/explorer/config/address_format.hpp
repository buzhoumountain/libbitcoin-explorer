/**
 * Copyright (c) 2011-2019 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BX_ADDRESS_FORMAT_HPP
#define BX_ADDRESS_FORMAT_HPP

#include <iostream>
#include <string>
#include <bitcoin/system.hpp>
#include <bitcoin/explorer/define.hpp>

namespace libbitcoin {
namespace explorer {
namespace config {

/**
 * Serialization helper to convert between address_format and string.
 */
class BCX_API address_format
{
public:

    /**
     * Default constructor.
     */
    address_format();

    /**
     * Initialization constructor.
     * @param[in]  token  The value to initialize with.
     */
    address_format(const std::string& token);

    /**
     * Initialization constructor.
     * @param[in]  address_formats  The value to initialize with.
     */
    address_format(system::wallet::witness_address::address_format address_format);

    /**
     * Copy constructor.
     * @param[in]  other  The object to copy into self on construct.
     */
    address_format(const address_format& other);

    /**
     * Overload cast to internal type.
     * @return  This object's value cast to internal type.
     */
    operator system::wallet::witness_address::address_format() const;

    /**
     * Overload stream in. Throws if input is invalid.
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    friend std::istream& operator>>(std::istream& input,
        address_format& argument);

    /**
     * Overload stream out.
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& output,
        const address_format& argument);

private:

    /**
     * The state of this object.
     */
    system::wallet::witness_address::address_format value_;
};

} // namespace config
} // namespace explorer
} // namespace libbitcoin

#endif
