/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "data_buffer.h"

#include <new>

namespace OHOS {
namespace DistributedHardware {
DataBuffer::DataBuffer(size_t capacity)
{
    if (capacity != 0) {
        data_ = new (std::nothrow) uint8_t[capacity] {0};
        if (data_ != nullptr) {
            capacity_ = capacity;
        }
    }
}

DataBuffer::~DataBuffer()
{
    if (data_ != nullptr) {
        delete []data_;
        data_ = nullptr;
    }

    capacity_ = 0;
}

size_t DataBuffer::Capacity() const
{
    return capacity_;
}

uint8_t *DataBuffer::Data() const
{
    return data_;
}
} // namespace DistributedHardware
} // namespcae OHOS