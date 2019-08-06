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

#ifndef GS2_EXPERIENCE_CONTROL_GETSTATUSWITHSIGNATURERESULT_HPP_
#define GS2_EXPERIENCE_CONTROL_GETSTATUSWITHSIGNATURERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ステータスを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetStatusWithSignatureResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ステータス */
        optional<Status> item;
        /** 検証対象のオブジェクト */
        optional<StringHolder> body;
        /** 署名 */
        optional<StringHolder> signature;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            body(data.body),
            signature(data.signature)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            body(std::move(data.body)),
            signature(std::move(data.signature))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "body") == 0) {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0) {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
        }
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
    GetStatusWithSignatureResult() :
        m_pData(nullptr)
    {}

    GetStatusWithSignatureResult(const GetStatusWithSignatureResult& getStatusWithSignatureResult) :
        Gs2Object(getStatusWithSignatureResult),
        m_pData(getStatusWithSignatureResult.m_pData != nullptr ? new Data(*getStatusWithSignatureResult.m_pData) : nullptr)
    {}

    GetStatusWithSignatureResult(GetStatusWithSignatureResult&& getStatusWithSignatureResult) :
        Gs2Object(std::move(getStatusWithSignatureResult)),
        m_pData(getStatusWithSignatureResult.m_pData)
    {
        getStatusWithSignatureResult.m_pData = nullptr;
    }

    ~GetStatusWithSignatureResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetStatusWithSignatureResult& operator=(const GetStatusWithSignatureResult& getStatusWithSignatureResult)
    {
        Gs2Object::operator=(getStatusWithSignatureResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getStatusWithSignatureResult.m_pData);

        return *this;
    }

    GetStatusWithSignatureResult& operator=(GetStatusWithSignatureResult&& getStatusWithSignatureResult)
    {
        Gs2Object::operator=(std::move(getStatusWithSignatureResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getStatusWithSignatureResult.m_pData;
        getStatusWithSignatureResult.m_pData = nullptr;

        return *this;
    }

    const GetStatusWithSignatureResult* operator->() const
    {
        return this;
    }

    GetStatusWithSignatureResult* operator->()
    {
        return this;
    }
    /**
     * ステータスを取得
     *
     * @return ステータス
     */
    const optional<Status>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ステータスを設定
     *
     * @param item ステータス
     */
    void setItem(const Status& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * 検証対象のオブジェクトを取得
     *
     * @return 検証対象のオブジェクト
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 検証対象のオブジェクトを設定
     *
     * @param body 検証対象のオブジェクト
     */
    void setBody(const Char* body)
    {
        ensureData().body.emplace(body);
    }

    /**
     * 署名を取得
     *
     * @return 署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    void setSignature(const Char* signature)
    {
        ensureData().signature.emplace(signature);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_GETSTATUSWITHSIGNATURERESULT_HPP_