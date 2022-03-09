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

#include "dscreen_maprelation.h"

#include "dscreen_constants.h"
#include "dscreen_errcode.h"

using json = nlohmann::json;

namespace OHOS {
namespace DistributedHardware {
void DScreenMapRelation::SetDisplayId(uint64_t displayId)
{
    displayId_ = displayId;
}

uint64_t DScreenMapRelation::GetDisplayId() const
{
    return displayId_;
}

void DScreenMapRelation::SetScreenId(uint64_t screenId)
{
    screenId_ = screenId;
}

uint64_t DScreenMapRelation::GetScreenId() const
{
    return screenId_;
}

void DScreenMapRelation::SetDisplayRect(const DisplayRect &displayRect)
{
    displayRect_ = displayRect;
}

DisplayRect& DScreenMapRelation::GetDisplayRect()
{
    return displayRect_;
}

void DScreenMapRelation::SetScreenRect(const ScreenRect &screenRect)
{
    screenRect_ = screenRect;
}

ScreenRect& DScreenMapRelation::GetScreenRect()
{
    return screenRect_;
}

void to_json(json &j, const DScreenMapRelation &dScreenMapRelation)
{
    json displayRectJson;
    json screenRectJson;
    to_json(displayRectJson, dScreenMapRelation.displayRect_);
    to_json(screenRectJson, dScreenMapRelation.screenRect_);
    j = json {
        {KEY_DISPLAY_ID, dScreenMapRelation.displayId_},
        {KEY_SCREEN_ID, dScreenMapRelation.screenId_},
        {KEY_DISPLAY_RECT, displayRectJson},
        {KEY_SCREEN_RECT, screenRectJson}
    };
}

void from_json(const json &j, DScreenMapRelation &dScreenMapRelation)
{
    j.at(KEY_DISPLAY_ID).get_to(dScreenMapRelation.displayId_);
    j.at(KEY_SCREEN_ID).get_to(dScreenMapRelation.screenId_);
    from_json(j.at(KEY_DISPLAY_RECT), dScreenMapRelation.displayRect_);
    from_json(j.at(KEY_SCREEN_RECT), dScreenMapRelation.screenRect_);
}

void to_json(json &j, const DisplayRect &rect)
{
    j = json {
        {KEY_POINT_START_X, rect.startX},
        {KEY_POINT_START_Y, rect.startY},
        {KEY_WIDTH, rect.width},
        {KEY_HEIGHT, rect.height}
    };
}

void from_json(const json &j, DisplayRect &rect)
{
    j.at(KEY_POINT_START_X).get_to(rect.startX);
    j.at(KEY_POINT_START_Y).get_to(rect.startY);
    j.at(KEY_WIDTH).get_to(rect.width);
    j.at(KEY_HEIGHT).get_to(rect.height);
}

void to_json(json &j, const ScreenRect &rect)
{
    j = json {
        {KEY_POINT_START_X, rect.startX},
        {KEY_POINT_START_Y, rect.startY},
        {KEY_WIDTH, rect.width},
        {KEY_HEIGHT, rect.height}
    };
}

void from_json(const json &j, ScreenRect &rect)
{
    j.at(KEY_POINT_START_X).get_to(rect.startX);
    j.at(KEY_POINT_START_Y).get_to(rect.startY);
    j.at(KEY_WIDTH).get_to(rect.width);
    j.at(KEY_HEIGHT).get_to(rect.height);
}
} // namespace DistributedHardware
} // namespace OHOS