/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_MISSION_CONTROL_GETMISSIONTASKMODELREQUEST_HPP_
#define GS2_MISSION_CONTROL_GETMISSIONTASKMODELREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/mission/Gs2MissionConst.hpp>
#include <gs2/mission/model/model.hpp>
#include <memory>

namespace gs2 { namespace mission
{

/**
 * ミッションタスクを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMissionTaskModelRequest : public Gs2BasicRequest, public Gs2Mission
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** グループ名 */
        optional<StringHolder> missionGroupName;
        /** タスク名 */
        optional<StringHolder> missionTaskName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            missionGroupName(data.missionGroupName),
            missionTaskName(data.missionTaskName)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    GetMissionTaskModelRequest() = default;
    GetMissionTaskModelRequest(const GetMissionTaskModelRequest& getMissionTaskModelRequest) = default;
    GetMissionTaskModelRequest(GetMissionTaskModelRequest&& getMissionTaskModelRequest) = default;
    ~GetMissionTaskModelRequest() GS2_OVERRIDE = default;

    GetMissionTaskModelRequest& operator=(const GetMissionTaskModelRequest& getMissionTaskModelRequest) = default;
    GetMissionTaskModelRequest& operator=(GetMissionTaskModelRequest&& getMissionTaskModelRequest) = default;

    GetMissionTaskModelRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetMissionTaskModelRequest);
    }

    const GetMissionTaskModelRequest* operator->() const
    {
        return this;
    }

    GetMissionTaskModelRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    GetMissionTaskModelRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getMissionGroupName() const
    {
        return ensureData().missionGroupName;
    }

    /**
     * グループ名を設定
     *
     * @param missionGroupName グループ名
     */
    void setMissionGroupName(StringHolder missionGroupName)
    {
        ensureData().missionGroupName.emplace(std::move(missionGroupName));
    }

    /**
     * グループ名を設定
     *
     * @param missionGroupName グループ名
     */
    GetMissionTaskModelRequest& withMissionGroupName(StringHolder missionGroupName)
    {
        ensureData().missionGroupName.emplace(std::move(missionGroupName));
        return *this;
    }

    /**
     * タスク名を取得
     *
     * @return タスク名
     */
    const optional<StringHolder>& getMissionTaskName() const
    {
        return ensureData().missionTaskName;
    }

    /**
     * タスク名を設定
     *
     * @param missionTaskName タスク名
     */
    void setMissionTaskName(StringHolder missionTaskName)
    {
        ensureData().missionTaskName.emplace(std::move(missionTaskName));
    }

    /**
     * タスク名を設定
     *
     * @param missionTaskName タスク名
     */
    GetMissionTaskModelRequest& withMissionTaskName(StringHolder missionTaskName)
    {
        ensureData().missionTaskName.emplace(std::move(missionTaskName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetMissionTaskModelRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetMissionTaskModelRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MISSION_CONTROL_GETMISSIONTASKMODELREQUEST_HPP_