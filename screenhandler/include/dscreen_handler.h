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

#ifndef OHOS_DSCREEN_HANDLER_H
#define OHOS_DSCREEN_HANDLER_H

#include "screen_manager.h"

#include "ihardware_handler.h"
#include "single_instance.h"

namespace OHOS {
namespace DistributedHardware {
class DScreenHandler : public IHardwareHandler, public Rosen::ScreenManager::IScreenListener {
DECLARE_SINGLE_INSTANCE_BASE(DScreenHandler);
public:
    void OnConnect(uint64_t screenId) override;
    void OnDisconnect(uint64_t screenId) override;
    void OnChange(uint64_t screenId) override {};
    int32_t Initialize() override;
    std::vector<DHItem> Query() override;
    std::map<std::string, std::string> QueryExtraInfo() override;
    bool IsSupportPlugin() override;
    void RegisterPluginListener(std::shared_ptr<PluginListener> listener) override;

private:
    DScreenHandler();
    ~DScreenHandler();
    std::string QueryCodecInfo();

    std::shared_ptr<PluginListener> listener_ = nullptr;
    std::string codecInfoStr_;
};

#ifdef __cplusplus
extern "C" {
#endif
__attribute__((visibility("default"))) IHardwareHandler* GetHardwareHandler();
#ifdef __cplusplus
}
#endif
} // namespace DistributedHardware
} // namespace OHOS
#endif