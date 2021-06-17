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

#ifndef GS2_DICTIONARY_CONTROL_GETENTRYWITHSIGNATURERESULT_HPP_
#define GS2_DICTIONARY_CONTROL_GETENTRYWITHSIGNATURERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/dictionary/model/model.hpp>
#include <memory>

namespace gs2 { namespace dictionary
{

/**
 * エントリーを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetEntryWithSignatureResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** エントリー */
        optional<Entry> item;
        /** 署名対象のエントリー情報 */
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
    GetEntryWithSignatureResult() = default;
    GetEntryWithSignatureResult(const GetEntryWithSignatureResult& getEntryWithSignatureResult) = default;
    GetEntryWithSignatureResult(GetEntryWithSignatureResult&& getEntryWithSignatureResult) = default;
    ~GetEntryWithSignatureResult() = default;

    GetEntryWithSignatureResult& operator=(const GetEntryWithSignatureResult& getEntryWithSignatureResult) = default;
    GetEntryWithSignatureResult& operator=(GetEntryWithSignatureResult&& getEntryWithSignatureResult) = default;

    GetEntryWithSignatureResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetEntryWithSignatureResult);
    }

    const GetEntryWithSignatureResult* operator->() const
    {
        return this;
    }

    GetEntryWithSignatureResult* operator->()
    {
        return this;
    }
    /**
     * エントリーを取得
     *
     * @return エントリー
     */
    const optional<Entry>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * エントリーを設定
     *
     * @param item エントリー
     */
    void setItem(Entry item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 署名対象のエントリー情報を取得
     *
     * @return 署名対象のエントリー情報
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 署名対象のエントリー情報を設定
     *
     * @param body 署名対象のエントリー情報
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

typedef AsyncResult<GetEntryWithSignatureResult> AsyncGetEntryWithSignatureResult;

} }

#endif //GS2_DICTIONARY_CONTROL_GETENTRYWITHSIGNATURERESULT_HPP_