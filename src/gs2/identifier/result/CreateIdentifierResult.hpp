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

#ifndef GS2_IDENTIFIER_CONTROL_CREATEIDENTIFIERRESULT_HPP_
#define GS2_IDENTIFIER_CONTROL_CREATEIDENTIFIERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/identifier/model/model.hpp>
#include <memory>

namespace gs2 { namespace identifier
{

/**
 * クレデンシャルを新規作成します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateIdentifierResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したクレデンシャル */
        optional<Identifier> item;
        /** クライアントシークレット */
        optional<StringHolder> clientSecret;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            clientSecret(data.clientSecret)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "clientSecret") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->clientSecret.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CreateIdentifierResult() = default;
    CreateIdentifierResult(const CreateIdentifierResult& createIdentifierResult) = default;
    CreateIdentifierResult(CreateIdentifierResult&& createIdentifierResult) = default;
    ~CreateIdentifierResult() = default;

    CreateIdentifierResult& operator=(const CreateIdentifierResult& createIdentifierResult) = default;
    CreateIdentifierResult& operator=(CreateIdentifierResult&& createIdentifierResult) = default;

    CreateIdentifierResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateIdentifierResult);
    }

    const CreateIdentifierResult* operator->() const
    {
        return this;
    }

    CreateIdentifierResult* operator->()
    {
        return this;
    }
    /**
     * 作成したクレデンシャルを取得
     *
     * @return 作成したクレデンシャル
     */
    const optional<Identifier>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したクレデンシャルを設定
     *
     * @param item 作成したクレデンシャル
     */
    void setItem(Identifier item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * クライアントシークレットを取得
     *
     * @return クライアントシークレット
     */
    const optional<StringHolder>& getClientSecret() const
    {
        return ensureData().clientSecret;
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    void setClientSecret(StringHolder clientSecret)
    {
        ensureData().clientSecret.emplace(std::move(clientSecret));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CreateIdentifierResult> AsyncCreateIdentifierResult;

} }

#endif //GS2_IDENTIFIER_CONTROL_CREATEIDENTIFIERRESULT_HPP_