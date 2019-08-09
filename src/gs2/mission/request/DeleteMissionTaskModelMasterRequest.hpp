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

#ifndef GS2_MISSION_CONTROL_DELETEMISSIONTASKMODELMASTERREQUEST_HPP_
#define GS2_MISSION_CONTROL_DELETEMISSIONTASKMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MissionConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace mission
{

/**
 * ミッションタスクマスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteMissionTaskModelMasterRequest : public Gs2BasicRequest, public Gs2Mission
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ミッショングループ名 */
        optional<StringHolder> missionGroupName;
        /** タスク名 */
        optional<StringHolder> missionTaskName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            missionGroupName(data.missionGroupName),
            missionTaskName(data.missionTaskName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            missionGroupName(std::move(data.missionGroupName)),
            missionTaskName(std::move(data.missionTaskName))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    DeleteMissionTaskModelMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteMissionTaskModelMasterRequest(const DeleteMissionTaskModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Mission(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteMissionTaskModelMasterRequest(DeleteMissionTaskModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Mission(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteMissionTaskModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteMissionTaskModelMasterRequest& operator=(const DeleteMissionTaskModelMasterRequest& deleteMissionTaskModelMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteMissionTaskModelMasterRequest);
        Gs2Mission::operator=(deleteMissionTaskModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteMissionTaskModelMasterRequest.m_pData);

        return *this;
    }

    DeleteMissionTaskModelMasterRequest& operator=(DeleteMissionTaskModelMasterRequest&& deleteMissionTaskModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteMissionTaskModelMasterRequest));
        Gs2Mission::operator=(std::move(deleteMissionTaskModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteMissionTaskModelMasterRequest.m_pData;
        deleteMissionTaskModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteMissionTaskModelMasterRequest* operator->() const
    {
        return this;
    }

    DeleteMissionTaskModelMasterRequest* operator->()
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    DeleteMissionTaskModelMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * ミッショングループ名を取得
     *
     * @return ミッショングループ名
     */
    const optional<StringHolder>& getMissionGroupName() const
    {
        return ensureData().missionGroupName;
    }

    /**
     * ミッショングループ名を設定
     *
     * @param missionGroupName ミッショングループ名
     */
    void setMissionGroupName(const Char* missionGroupName)
    {
        ensureData().missionGroupName.emplace(missionGroupName);
    }

    /**
     * ミッショングループ名を設定
     *
     * @param missionGroupName ミッショングループ名
     */
    DeleteMissionTaskModelMasterRequest& withMissionGroupName(const Char* missionGroupName)
    {
        ensureData().missionGroupName.emplace(missionGroupName);
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
    void setMissionTaskName(const Char* missionTaskName)
    {
        ensureData().missionTaskName.emplace(missionTaskName);
    }

    /**
     * タスク名を設定
     *
     * @param missionTaskName タスク名
     */
    DeleteMissionTaskModelMasterRequest& withMissionTaskName(const Char* missionTaskName)
    {
        ensureData().missionTaskName.emplace(missionTaskName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteMissionTaskModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    DeleteMissionTaskModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    DeleteMissionTaskModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteMissionTaskModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_MISSION_CONTROL_DELETEMISSIONTASKMODELMASTERREQUEST_HPP_