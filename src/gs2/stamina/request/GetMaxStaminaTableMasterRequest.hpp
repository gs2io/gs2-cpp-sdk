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

#ifndef GS2_STAMINA_CONTROL_GETMAXSTAMINATABLEMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_GETMAXSTAMINATABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタミナの最大値テーブルマスターを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMaxStaminaTableMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 最大スタミナ値テーブル名 */
        optional<StringHolder> maxStaminaTableName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            maxStaminaTableName(data.maxStaminaTableName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
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
    GetMaxStaminaTableMasterRequest() :
        m_pData(nullptr)
    {}

    GetMaxStaminaTableMasterRequest(const GetMaxStaminaTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetMaxStaminaTableMasterRequest(GetMaxStaminaTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetMaxStaminaTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMaxStaminaTableMasterRequest& operator=(const GetMaxStaminaTableMasterRequest& getMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(getMaxStaminaTableMasterRequest);
        Gs2Stamina::operator=(getMaxStaminaTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMaxStaminaTableMasterRequest.m_pData);

        return *this;
    }

    GetMaxStaminaTableMasterRequest& operator=(GetMaxStaminaTableMasterRequest&& getMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(getMaxStaminaTableMasterRequest));
        Gs2Stamina::operator=(std::move(getMaxStaminaTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMaxStaminaTableMasterRequest.m_pData;
        getMaxStaminaTableMasterRequest.m_pData = nullptr;

        return *this;
    }

    const GetMaxStaminaTableMasterRequest* operator->() const
    {
        return this;
    }

    GetMaxStaminaTableMasterRequest* operator->()
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
    GetMaxStaminaTableMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    GetMaxStaminaTableMasterRequest& withMaxStaminaTableName(const Char* maxStaminaTableName)
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
    GetMaxStaminaTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetMaxStaminaTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetMaxStaminaTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetMaxStaminaTableMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_GETMAXSTAMINATABLEMASTERREQUEST_HPP_