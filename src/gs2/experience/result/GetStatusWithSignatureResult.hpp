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
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/experience/model/model.hpp>
#include <memory>

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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            body(data.body),
            signature(data.signature)
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
            else if (std::strcmp(name_, "body") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetStatusWithSignatureResult() = default;
    GetStatusWithSignatureResult(const GetStatusWithSignatureResult& getStatusWithSignatureResult) = default;
    GetStatusWithSignatureResult(GetStatusWithSignatureResult&& getStatusWithSignatureResult) = default;
    ~GetStatusWithSignatureResult() = default;

    GetStatusWithSignatureResult& operator=(const GetStatusWithSignatureResult& getStatusWithSignatureResult) = default;
    GetStatusWithSignatureResult& operator=(GetStatusWithSignatureResult&& getStatusWithSignatureResult) = default;

    GetStatusWithSignatureResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetStatusWithSignatureResult);
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
    void setItem(Status item)
    {
        ensureData().item.emplace(std::move(item));
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
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
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
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetStatusWithSignatureResult> AsyncGetStatusWithSignatureResult;

} }

#endif //GS2_EXPERIENCE_CONTROL_GETSTATUSWITHSIGNATURERESULT_HPP_