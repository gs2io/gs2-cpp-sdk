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

#ifndef GS2_DISTRIBUTOR_CONTROL_DISTRIBUTERESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DISTRIBUTERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * 所持品を配布する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DistributeResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 処理した DistributeResource */
        optional<DistributeResource> distributeResource;
        /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
        optional<StringHolder> inboxNamespaceId;
        /** レスポンス内容 */
        optional<StringHolder> result;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            distributeResource(data.distributeResource),
            inboxNamespaceId(data.inboxNamespaceId),
            result(data.result)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            distributeResource(std::move(data.distributeResource)),
            inboxNamespaceId(std::move(data.inboxNamespaceId)),
            result(std::move(data.result))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "distributeResource") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->distributeResource.emplace();
                    detail::json::JsonParser::parse(&this->distributeResource->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "inboxNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inboxNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "result") == 0) {
                if (jsonValue.IsString())
                {
                    this->result.emplace(jsonValue.GetString());
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
    DistributeResult() :
        m_pData(nullptr)
    {}

    DistributeResult(const DistributeResult& distributeResult) :
        Gs2Object(distributeResult),
        m_pData(distributeResult.m_pData != nullptr ? new Data(*distributeResult.m_pData) : nullptr)
    {}

    DistributeResult(DistributeResult&& distributeResult) :
        Gs2Object(std::move(distributeResult)),
        m_pData(distributeResult.m_pData)
    {
        distributeResult.m_pData = nullptr;
    }

    ~DistributeResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DistributeResult& operator=(const DistributeResult& distributeResult)
    {
        Gs2Object::operator=(distributeResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*distributeResult.m_pData);

        return *this;
    }

    DistributeResult& operator=(DistributeResult&& distributeResult)
    {
        Gs2Object::operator=(std::move(distributeResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = distributeResult.m_pData;
        distributeResult.m_pData = nullptr;

        return *this;
    }

    const DistributeResult* operator->() const
    {
        return this;
    }

    DistributeResult* operator->()
    {
        return this;
    }
    /**
     * 処理した DistributeResourceを取得
     *
     * @return 処理した DistributeResource
     */
    const optional<DistributeResource>& getDistributeResource() const
    {
        return ensureData().distributeResource;
    }

    /**
     * 処理した DistributeResourceを設定
     *
     * @param distributeResource 処理した DistributeResource
     */
    void setDistributeResource(const DistributeResource& distributeResource)
    {
        ensureData().distributeResource.emplace(distributeResource);
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを取得
     *
     * @return 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    const optional<StringHolder>& getInboxNamespaceId() const
    {
        return ensureData().inboxNamespaceId;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    void setInboxNamespaceId(const Char* inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(inboxNamespaceId);
    }

    /**
     * レスポンス内容を取得
     *
     * @return レスポンス内容
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * レスポンス内容を設定
     *
     * @param result レスポンス内容
     */
    void setResult(const Char* result)
    {
        ensureData().result.emplace(result);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_DISTRIBUTERESULT_HPP_