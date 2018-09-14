/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_LEVEL_CONTROL_CHANGELEVELCAPBYUSERIDREQUEST_HPP_
#define GS2_LEVEL_CONTROL_CHANGELEVELCAPBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace level
{

/**
 * @author Game Server Services, Inc.
 */
class ChangeLevelCapByUserIdRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "ChangeLevelCapByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** ステータスID */
        optional<StringHolder> statusId;
        /** ステータス */
        optional<StringHolder> userId;
        /** 新しいレベルキャップ */
        optional<Int32> levelCap;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            statusId(data.statusId),
            userId(data.userId),
            levelCap(data.levelCap)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            statusId(std::move(data.statusId)),
            userId(std::move(data.userId)),
            levelCap(std::move(data.levelCap))
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
    ChangeLevelCapByUserIdRequest() :
        m_pData(nullptr)
    {}

    ChangeLevelCapByUserIdRequest(const ChangeLevelCapByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ChangeLevelCapByUserIdRequest(ChangeLevelCapByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ChangeLevelCapByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ChangeLevelCapByUserIdRequest& operator=(const ChangeLevelCapByUserIdRequest& changeLevelCapByUserIdRequest)
    {
        Gs2BasicRequest::operator=(changeLevelCapByUserIdRequest);
        Gs2Level::operator=(changeLevelCapByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*changeLevelCapByUserIdRequest.m_pData);

        return *this;
    }

    ChangeLevelCapByUserIdRequest& operator=(ChangeLevelCapByUserIdRequest&& changeLevelCapByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(changeLevelCapByUserIdRequest));
        Gs2Level::operator=(std::move(changeLevelCapByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = changeLevelCapByUserIdRequest.m_pData;
        changeLevelCapByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const ChangeLevelCapByUserIdRequest* operator->() const
    {
        return this;
    }

    ChangeLevelCapByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * リソースプールを取得
     *
     * @return リソースプール
     */
    const optional<StringHolder>& getResourcePoolName() const
    {
        return ensureData().resourcePoolName;
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    void setResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    ChangeLevelCapByUserIdRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * ステータスIDを取得
     *
     * @return ステータスID
     */
    const optional<StringHolder>& getStatusId() const
    {
        return ensureData().statusId;
    }

    /**
     * ステータスIDを設定
     *
     * @param statusId ステータスID
     */
    void setStatusId(const Char* statusId)
    {
        ensureData().statusId.emplace(statusId);
    }

    /**
     * ステータスIDを設定
     *
     * @param statusId ステータスID
     */
    ChangeLevelCapByUserIdRequest& withStatusId(const Char* statusId)
    {
        ensureData().statusId.emplace(statusId);
        return *this;
    }

    /**
     * ステータスを取得
     *
     * @return ステータス
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ステータスを設定
     *
     * @param userId ステータス
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ステータスを設定
     *
     * @param userId ステータス
     */
    ChangeLevelCapByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 新しいレベルキャップを取得
     *
     * @return 新しいレベルキャップ
     */
    const optional<Int32>& getLevelCap() const
    {
        return ensureData().levelCap;
    }

    /**
     * 新しいレベルキャップを設定
     *
     * @param levelCap 新しいレベルキャップ
     */
    void setLevelCap(Int32 levelCap)
    {
        ensureData().levelCap.emplace(levelCap);
    }

    /**
     * 新しいレベルキャップを設定
     *
     * @param levelCap 新しいレベルキャップ
     */
    ChangeLevelCapByUserIdRequest& withLevelCap(Int32 levelCap)
    {
        ensureData().levelCap.emplace(levelCap);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    ChangeLevelCapByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ChangeLevelCapByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ChangeLevelCapByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ChangeLevelCapByUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_LEVEL_CONTROL_CHANGELEVELCAPBYUSERIDREQUEST_HPP_