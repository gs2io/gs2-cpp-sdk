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

#ifndef GS2_GOLD_CONTROL_WITHDRAWFROMWALLETBYUSERIDREQUEST_HPP_
#define GS2_GOLD_CONTROL_WITHDRAWFROMWALLETBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GoldConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gold
{

/**
 * @author Game Server Services, Inc.
 */
class WithdrawFromWalletByUserIdRequest : public Gs2BasicRequest, public Gs2Gold
{
public:
    constexpr static const Char* const FUNCTION = "WithdrawFromWalletByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゴールドプールの名前 */
        optional<StringHolder> goldPoolName;
        /** ゴールドの名前 */
        optional<StringHolder> goldName;
        /** ウォレット所有者のユーザID */
        optional<StringHolder> userId;
        /** 減算量 */
        optional<Int64> value;
        /** コンテキスト */
        optional<StringHolder> context;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            goldPoolName(data.goldPoolName),
            goldName(data.goldName),
            userId(data.userId),
            value(data.value),
            context(data.context)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            goldPoolName(std::move(data.goldPoolName)),
            goldName(std::move(data.goldName)),
            userId(std::move(data.userId)),
            value(std::move(data.value)),
            context(std::move(data.context))
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
    WithdrawFromWalletByUserIdRequest() :
        m_pData(nullptr)
    {}

    WithdrawFromWalletByUserIdRequest(const WithdrawFromWalletByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gold(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    WithdrawFromWalletByUserIdRequest(WithdrawFromWalletByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gold(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~WithdrawFromWalletByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WithdrawFromWalletByUserIdRequest& operator=(const WithdrawFromWalletByUserIdRequest& withdrawFromWalletByUserIdRequest)
    {
        Gs2BasicRequest::operator=(withdrawFromWalletByUserIdRequest);
        Gs2Gold::operator=(withdrawFromWalletByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*withdrawFromWalletByUserIdRequest.m_pData);

        return *this;
    }

    WithdrawFromWalletByUserIdRequest& operator=(WithdrawFromWalletByUserIdRequest&& withdrawFromWalletByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(withdrawFromWalletByUserIdRequest));
        Gs2Gold::operator=(std::move(withdrawFromWalletByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = withdrawFromWalletByUserIdRequest.m_pData;
        withdrawFromWalletByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const WithdrawFromWalletByUserIdRequest* operator->() const
    {
        return this;
    }

    WithdrawFromWalletByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ゴールドプールの名前を取得
     *
     * @return ゴールドプールの名前
     */
    const optional<StringHolder>& getGoldPoolName() const
    {
        return ensureData().goldPoolName;
    }

    /**
     * ゴールドプールの名前を設定
     *
     * @param goldPoolName ゴールドプールの名前
     */
    void setGoldPoolName(const Char* goldPoolName)
    {
        ensureData().goldPoolName.emplace(goldPoolName);
    }

    /**
     * ゴールドプールの名前を設定
     *
     * @param goldPoolName ゴールドプールの名前
     */
    WithdrawFromWalletByUserIdRequest& withGoldPoolName(const Char* goldPoolName)
    {
        ensureData().goldPoolName.emplace(goldPoolName);
        return *this;
    }

    /**
     * ゴールドの名前を取得
     *
     * @return ゴールドの名前
     */
    const optional<StringHolder>& getGoldName() const
    {
        return ensureData().goldName;
    }

    /**
     * ゴールドの名前を設定
     *
     * @param goldName ゴールドの名前
     */
    void setGoldName(const Char* goldName)
    {
        ensureData().goldName.emplace(goldName);
    }

    /**
     * ゴールドの名前を設定
     *
     * @param goldName ゴールドの名前
     */
    WithdrawFromWalletByUserIdRequest& withGoldName(const Char* goldName)
    {
        ensureData().goldName.emplace(goldName);
        return *this;
    }

    /**
     * ウォレット所有者のユーザIDを取得
     *
     * @return ウォレット所有者のユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ウォレット所有者のユーザIDを設定
     *
     * @param userId ウォレット所有者のユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ウォレット所有者のユーザIDを設定
     *
     * @param userId ウォレット所有者のユーザID
     */
    WithdrawFromWalletByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 減算量を取得
     *
     * @return 減算量
     */
    const optional<Int64>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 減算量を設定
     *
     * @param value 減算量
     */
    void setValue(Int64 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 減算量を設定
     *
     * @param value 減算量
     */
    WithdrawFromWalletByUserIdRequest& withValue(Int64 value)
    {
        ensureData().value.emplace(value);
        return *this;
    }

    /**
     * コンテキストを取得
     *
     * @return コンテキスト
     */
    const optional<StringHolder>& getContext() const
    {
        return ensureData().context;
    }

    /**
     * コンテキストを設定
     *
     * @param context コンテキスト
     */
    void setContext(const Char* context)
    {
        ensureData().context.emplace(context);
    }

    /**
     * コンテキストを設定
     *
     * @param context コンテキスト
     */
    WithdrawFromWalletByUserIdRequest& withContext(const Char* context)
    {
        ensureData().context.emplace(context);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    WithdrawFromWalletByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    WithdrawFromWalletByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    WithdrawFromWalletByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    WithdrawFromWalletByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GOLD_CONTROL_WITHDRAWFROMWALLETBYUSERIDREQUEST_HPP_