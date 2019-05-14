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

#ifndef GS2_STAMINA_CONTROL_DELETEMAXSTAMINATABLEMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_DELETEMAXSTAMINATABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタミナ最大値テーブルを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteMaxStaminaTableMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタミナの種類名 */
        optional<StringHolder> groupName;
        /** 最大スタミナ値テーブル名 */
        optional<StringHolder> maxStaminaTableName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            groupName(data.groupName),
            maxStaminaTableName(data.maxStaminaTableName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            groupName(std::move(data.groupName)),
            maxStaminaTableName(std::move(data.maxStaminaTableName))
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
    DeleteMaxStaminaTableMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteMaxStaminaTableMasterRequest(const DeleteMaxStaminaTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteMaxStaminaTableMasterRequest(DeleteMaxStaminaTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteMaxStaminaTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteMaxStaminaTableMasterRequest& operator=(const DeleteMaxStaminaTableMasterRequest& deleteMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteMaxStaminaTableMasterRequest);
        Gs2Stamina::operator=(deleteMaxStaminaTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteMaxStaminaTableMasterRequest.m_pData);

        return *this;
    }

    DeleteMaxStaminaTableMasterRequest& operator=(DeleteMaxStaminaTableMasterRequest&& deleteMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteMaxStaminaTableMasterRequest));
        Gs2Stamina::operator=(std::move(deleteMaxStaminaTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteMaxStaminaTableMasterRequest.m_pData;
        deleteMaxStaminaTableMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteMaxStaminaTableMasterRequest* operator->() const
    {
        return this;
    }

    DeleteMaxStaminaTableMasterRequest* operator->()
    {
        return this;
    }
    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    void setGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    DeleteMaxStaminaTableMasterRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
        return *this;
    }

    /**
     * 最大スタミナ値テーブル名を取得
     *
     * @return 最大スタミナ値テーブル名
     */
    const optional<StringHolder>& getMaxStaminaTableName() const
    {
        return ensureData().maxStaminaTableName;
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param maxStaminaTableName 最大スタミナ値テーブル名
     */
    void setMaxStaminaTableName(const Char* maxStaminaTableName)
    {
        ensureData().maxStaminaTableName.emplace(maxStaminaTableName);
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param maxStaminaTableName 最大スタミナ値テーブル名
     */
    DeleteMaxStaminaTableMasterRequest& withMaxStaminaTableName(const Char* maxStaminaTableName)
    {
        ensureData().maxStaminaTableName.emplace(maxStaminaTableName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteMaxStaminaTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteMaxStaminaTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteMaxStaminaTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteMaxStaminaTableMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_STAMINA_CONTROL_DELETEMAXSTAMINATABLEMASTERREQUEST_HPP_