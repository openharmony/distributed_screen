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

#include "dscreen_source_proxy.h"

#include "parcel.h"

#include "dscreen_errcode.h"
#include "dscreen_log.h"

namespace OHOS {
namespace DistributedHardware {
int32_t DScreenSourceProxy::InitSource(const std::string &params, const sptr<IDScreenSourceCallback> &callback)
{
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    if (!data.WriteString(params)
        || !data.WriteRemoteObject(callback->AsObject())) {
        DHLOGE("Write param failed.");
        return ERR_DH_SCREEN_SA_WRITEPARAM_FAILED;
    }

    Remote()->SendRequest(INIT_SOURCE, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

int32_t DScreenSourceProxy::ReleaseSource()
{
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    Remote()->SendRequest(RELEASE_SOURCE, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

int32_t DScreenSourceProxy::RegisterDistributedHardware(const std::string &devId,
    const std::string &dhId, const EnableParam &param, const std::string &reqId)
{
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    if (!data.WriteString(devId) || !data.WriteString(dhId)
        || !data.WriteString(param.version) || !data.WriteString(param.attrs)
        || !data.WriteString(reqId)) {
        DHLOGE("Write param failed.");
        return ERR_DH_SCREEN_SA_WRITEPARAM_FAILED;
    }
    Remote()->SendRequest(REGISTER_DISTRIBUTED_HARDWARE, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

int32_t DScreenSourceProxy::UnregisterDistributedHardware(const std::string &devId,
    const std::string &dhId, const std::string &reqId)
{
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    if (!data.WriteString(devId) || !data.WriteString(dhId)
        || !data.WriteString(reqId)) {
        DHLOGE("Write param failed.");
        return ERR_DH_SCREEN_SA_WRITEPARAM_FAILED;
    }
    Remote()->SendRequest(UNREGISTER_DISTRIBUTED_HARDWARE, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

int32_t DScreenSourceProxy::ConfigDistributedHardware(const std::string &devId,
    const std::string &dhId, const std::string &key, const std::string &value)
{
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    if (!data.WriteString(devId) || !data.WriteString(dhId)
        || !data.WriteString(key) || !data.WriteString(value)) {
        DHLOGE("Write param failed.");
        return ERR_DH_SCREEN_SA_WRITEPARAM_FAILED;
    }
    Remote()->SendRequest(CONFIG_DISTRIBUTED_HARDWARE, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

void DScreenSourceProxy::DScreenNotify(const std::string &devId,
    int32_t eventCode, const std::string &eventContent)
{
    DHLOGD("DScreenNotify");
    MessageParcel data;
    MessageParcel reply;
    MessageOption option = { MessageOption::TF_ASYNC };
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return;
    }

    if (!data.WriteString(devId) || !data.WriteInt32(eventCode) || !data.WriteString(eventContent)) {
        DHLOGE("Write param failed.");
        return;
    }

    Remote()->SendRequest(DSCREEN_NOTIFY, data, reply, option);
}
}
}
