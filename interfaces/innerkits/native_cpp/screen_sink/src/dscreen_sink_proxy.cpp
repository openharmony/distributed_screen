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

#include "dscreen_sink_proxy.h"

#include "iremote_object.h"
#include "message_option.h"
#include "message_parcel.h"

#include "dscreen_errcode.h"
#include "dscreen_log.h"

namespace OHOS {
namespace DistributedHardware {
int32_t DScreenSinkProxy::InitSink(const std::string &params)
{
    DHLOGD("InitSink");
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    if (!data.WriteString(params)) {
        DHLOGE("Write param failed.");
        return ERR_DH_SCREEN_SA_WRITEPARAM_FAILED;
    }

    Remote()->SendRequest(INIT_SINK, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

int32_t DScreenSinkProxy::ReleaseSink()
{
    DHLOGD("ReleaseSink");
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    Remote()->SendRequest(RELEASE_SINK, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

int32_t DScreenSinkProxy::SubscribeLocalHardware(const std::string &dhId, const std::string &param)
{
    DHLOGD("SubscribeLocalHardware");
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    if (!data.WriteString(dhId) || !data.WriteString(param)) {
        DHLOGE("Write param failed.");
        return ERR_DH_SCREEN_SA_WRITEPARAM_FAILED;
    }

    Remote()->SendRequest(SUBSCRIBE_DISTRIBUTED_HARDWARE, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

int32_t DScreenSinkProxy::UnsubscribeLocalHardware(const std::string &dhId)
{
    DHLOGD("UnsubscribeLocalHardware");
    MessageParcel data;
    MessageParcel reply;
    MessageOption option;
    if (!data.WriteInterfaceToken(GetDescriptor())) {
        DHLOGE("WriteInterfaceToken failed");
        return ERR_DH_SCREEN_SA_WRITEINTERFACETOKEN_FAILED;
    }

    if (!data.WriteString(dhId)) {
        DHLOGE("Write param failed.");
        return ERR_DH_SCREEN_SA_WRITEPARAM_FAILED;
    }

    Remote()->SendRequest(UNSUBSCRIBE_DISTRIBUTED_HARDWARE, data, reply, option);
    int32_t ret = reply.ReadInt32();
    return ret;
}

void DScreenSinkProxy::DScreenNotify(const std::string &devId, int32_t eventCode, const std::string &eventContent)
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
} // namespace DistributedHardware
} // namespace OHOS