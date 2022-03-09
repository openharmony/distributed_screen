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

#define private public
#include "video_param_test.h"
#undef private

using json = nlohmann::json;

using namespace testing::ext;

namespace OHOS {
namespace DistributedHardware {
void VideoParamTest::SetUpTestCase(void) {}

void VideoParamTest::TearDownTestCase(void) {}

void VideoParamTest::SetUp()
{
    videoParam_ = std::make_shared<VideoParam>();
}

void VideoParamTest::TearDown() {}

/**
 * @tc.name: GetScreenWidth_001
 * @tc.desc: Verify the GetScreenWidth function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(VideoParamTest, GetScreenWidth_001, TestSize.Level1)
{
    uint32_t screenWidth = 1;
    videoParam_->SetScreenWidth(screenWidth);
    uint32_t actual = videoParam_->GetScreenWidth();
    EXPECT_EQ(screenWidth, actual);
}

/**
 * @tc.name: GetScreenHeight_001
 * @tc.desc: Verify the GetScreenHeight function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(VideoParamTest, GetScreenHeight_001, TestSize.Level1)
{
    uint32_t screenHeight = 1;
    videoParam_->SetScreenHeight(screenHeight);
    uint32_t actual = videoParam_->GetScreenHeight();
    EXPECT_EQ(screenHeight, actual);
}

/**
 * @tc.name: GetVideoWidth_001
 * @tc.desc: Verify the GetVideoWidth function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(VideoParamTest, GetVideoWidth_001, TestSize.Level1)
{
    uint32_t videoWidth = 1;
    videoParam_->SetVideoWidth(videoWidth);
    uint32_t actual = videoParam_->GetVideoWidth();
    EXPECT_EQ(videoWidth, actual);
}

/**
 * @tc.name: GetVideoHeight_001
 * @tc.desc: Verify the GetVideoHeight function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(VideoParamTest, GetVideoHeight_001, TestSize.Level1)
{
    uint32_t videoHeight = 1;
    videoParam_->SetVideoHeight(videoHeight);
    uint32_t actual = videoParam_->GetVideoHeight();
    EXPECT_EQ(videoHeight, actual);
}

/**
 * @tc.name: GetFps_001
 * @tc.desc: Verify the GetFps function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(VideoParamTest, GetFps_001, TestSize.Level1)
{
    uint32_t fps = 1;
    videoParam_->SetFps(fps);
    uint32_t actual = videoParam_->GetFps();
    EXPECT_EQ(fps, actual);
}

/**
 * @tc.name: GetCodecType_001
 * @tc.desc: Verify the GetCodecType function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(VideoParamTest, GetCodecType_001, TestSize.Level1)
{
    uint8_t codecType = 1;
    videoParam_->SetCodecType(codecType);
    uint8_t actual = videoParam_->GetCodecType();
    EXPECT_EQ(codecType, actual);
}

/**
 * @tc.name: GetVideoFormat_001
 * @tc.desc: Verify the GetVideoFormat function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(VideoParamTest, GetVideoFormat_001, TestSize.Level1)
{
    uint8_t videoFormat = 1;
    videoParam_->SetVideoFormat(videoFormat);
    uint8_t actual = videoParam_->GetVideoFormat();
    EXPECT_EQ(videoFormat, actual);
}
}
}