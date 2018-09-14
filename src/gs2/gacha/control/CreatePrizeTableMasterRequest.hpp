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

#ifndef GS2_GACHA_CONTROL_CREATEPRIZETABLEMASTERREQUEST_HPP_
#define GS2_GACHA_CONTROL_CREATEPRIZETABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GachaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gacha
{

/**
 * @author Game Server Services, Inc.
 */
class CreatePrizeTableMasterRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "CreatePrizeTableMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前を指定します。 */
        optional<StringHolder> gachaPoolName;
        /** 排出確率テーブル名 */
        optional<StringHolder> name;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gachaPoolName(data.gachaPoolName),
            name(data.name)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            name(std::move(data.name))
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
    CreatePrizeTableMasterRequest() :
        m_pData(nullptr)
    {}

    CreatePrizeTableMasterRequest(const CreatePrizeTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreatePrizeTableMasterRequest(CreatePrizeTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreatePrizeTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreatePrizeTableMasterRequest& operator=(const CreatePrizeTableMasterRequest& createPrizeTableMasterRequest)
    {
        Gs2BasicRequest::operator=(createPrizeTableMasterRequest);
        Gs2Gacha::operator=(createPrizeTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createPrizeTableMasterRequest.m_pData);

        return *this;
    }

    CreatePrizeTableMasterRequest& operator=(CreatePrizeTableMasterRequest&& createPrizeTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createPrizeTableMasterRequest));
        Gs2Gacha::operator=(std::move(createPrizeTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createPrizeTableMasterRequest.m_pData;
        createPrizeTableMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreatePrizeTableMasterRequest* operator->() const
    {
        return this;
    }

    CreatePrizeTableMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ガチャプールの名前を指定します。を取得
     *
     * @return ガチャプールの名前を指定します。
     */
    const optional<StringHolder>& getGachaPoolName() const
    {
        return ensureData().gachaPoolName;
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    void setGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    CreatePrizeTableMasterRequest& withGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
        return *this;
    }

    /**
     * 排出確率テーブル名を取得
     *
     * @return 排出確率テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param name 排出確率テーブル名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param name 排出確率テーブル名
     */
    CreatePrizeTableMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreatePrizeTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreatePrizeTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreatePrizeTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreatePrizeTableMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_CREATEPRIZETABLEMASTERREQUEST_HPP_