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

#ifndef GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEBYUSERIDRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEBYUSERIDRESULT_HPP_

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
 * ユーザーIDを指定して所持品を配布する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DistributeByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 処理した DistributeResource */
        optional<DistributeResource> distributeResource;
        /** 溢れたときに転送する プレゼントボックス のGRN */
        optional<StringHolder> inboxId;
        /** レスポンス内容 */
        optional<StringHolder> result;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            distributeResource(data.distributeResource),
            inboxId(data.inboxId),
            result(data.result)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            distributeResource(std::move(data.distributeResource)),
            inboxId(std::move(data.inboxId)),
            result(std::move(data.result))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "distributeResource") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->distributeResource.emplace();
                    detail::json::JsonParser::parse(&this->distributeResource->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "inboxId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inboxId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "result") == 0) {
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
    DistributeByUserIdResult() :
        m_pData(nullptr)
    {}

    DistributeByUserIdResult(const DistributeByUserIdResult& distributeByUserIdResult) :
        Gs2Object(distributeByUserIdResult),
        m_pData(distributeByUserIdResult.m_pData != nullptr ? new Data(*distributeByUserIdResult.m_pData) : nullptr)
    {}

    DistributeByUserIdResult(DistributeByUserIdResult&& distributeByUserIdResult) :
        Gs2Object(std::move(distributeByUserIdResult)),
        m_pData(distributeByUserIdResult.m_pData)
    {
        distributeByUserIdResult.m_pData = nullptr;
    }

    ~DistributeByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DistributeByUserIdResult& operator=(const DistributeByUserIdResult& distributeByUserIdResult)
    {
        Gs2Object::operator=(distributeByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*distributeByUserIdResult.m_pData);

        return *this;
    }

    DistributeByUserIdResult& operator=(DistributeByUserIdResult&& distributeByUserIdResult)
    {
        Gs2Object::operator=(std::move(distributeByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = distributeByUserIdResult.m_pData;
        distributeByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const DistributeByUserIdResult* operator->() const
    {
        return this;
    }

    DistributeByUserIdResult* operator->()
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
     * 溢れたときに転送する プレゼントボックス のGRNを取得
     *
     * @return 溢れたときに転送する プレゼントボックス のGRN
     */
    const optional<StringHolder>& getInboxId() const
    {
        return ensureData().inboxId;
    }

    /**
     * 溢れたときに転送する プレゼントボックス のGRNを設定
     *
     * @param inboxId 溢れたときに転送する プレゼントボックス のGRN
     */
    void setInboxId(const Char* inboxId)
    {
        ensureData().inboxId.emplace(inboxId);
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

#endif //GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEBYUSERIDRESULT_HPP_