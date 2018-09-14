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

#ifndef GS2_LEVEL_CONTROL_DELETELEVELTABLEMASTERREQUEST_HPP_
#define GS2_LEVEL_CONTROL_DELETELEVELTABLEMASTERREQUEST_HPP_

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
class DeleteLevelTableMasterRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "DeleteLevelTableMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** レベルテーブル */
        optional<StringHolder> levelTableName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            levelTableName(data.levelTableName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            levelTableName(std::move(data.levelTableName))
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
    DeleteLevelTableMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteLevelTableMasterRequest(const DeleteLevelTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteLevelTableMasterRequest(DeleteLevelTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteLevelTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteLevelTableMasterRequest& operator=(const DeleteLevelTableMasterRequest& deleteLevelTableMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteLevelTableMasterRequest);
        Gs2Level::operator=(deleteLevelTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteLevelTableMasterRequest.m_pData);

        return *this;
    }

    DeleteLevelTableMasterRequest& operator=(DeleteLevelTableMasterRequest&& deleteLevelTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteLevelTableMasterRequest));
        Gs2Level::operator=(std::move(deleteLevelTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteLevelTableMasterRequest.m_pData;
        deleteLevelTableMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteLevelTableMasterRequest* operator->() const
    {
        return this;
    }

    DeleteLevelTableMasterRequest* operator->()
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
    DeleteLevelTableMasterRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * レベルテーブルを取得
     *
     * @return レベルテーブル
     */
    const optional<StringHolder>& getLevelTableName() const
    {
        return ensureData().levelTableName;
    }

    /**
     * レベルテーブルを設定
     *
     * @param levelTableName レベルテーブル
     */
    void setLevelTableName(const Char* levelTableName)
    {
        ensureData().levelTableName.emplace(levelTableName);
    }

    /**
     * レベルテーブルを設定
     *
     * @param levelTableName レベルテーブル
     */
    DeleteLevelTableMasterRequest& withLevelTableName(const Char* levelTableName)
    {
        ensureData().levelTableName.emplace(levelTableName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteLevelTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteLevelTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteLevelTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteLevelTableMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_DELETELEVELTABLEMASTERREQUEST_HPP_