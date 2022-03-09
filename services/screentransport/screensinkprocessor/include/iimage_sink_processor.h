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

#ifndef OHOS_IIMAGE_SINK_PROCESSOR_H
#define OHOS_IIMAGE_SINK_PROCESSOR_H

#include <memory>

#include "surface.h"

#include "data_buffer.h"
#include "video_param.h"
#include "iimage_sink_processor_listener.h"

namespace OHOS {
namespace DistributedHardware {
class IImageSinkProcessor {
public:
    virtual ~IImageSinkProcessor() = default;

    virtual int32_t ConfigureImageProcessor(const VideoParam &localParam, const VideoParam &remoteParam,
        const std::shared_ptr<IImageSinkProcessorListener> &listener) = 0;
    virtual int32_t ReleaseImageProcessor() = 0;
    virtual int32_t StartImageProcessor() = 0;
    virtual int32_t StopImageProcessor() = 0;
    virtual int32_t SetImageSurface(sptr<Surface> &surface) = 0;
    virtual int32_t ProcessImage(const std::shared_ptr<DataBuffer> &data) = 0;
};
} // namespace DistributedHardware
} // namespace OHOS
#endif