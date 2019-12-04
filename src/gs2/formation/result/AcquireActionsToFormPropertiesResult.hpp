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

#ifndef GS2_FORMATION_CONTROL_ACQUIREACTIONSTOFORMPROPERTIESRESULT_HPP_
#define GS2_FORMATION_CONTROL_ACQUIREACTIONSTOFORMPROPERTIESRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * 署名付きスロットを使ってフォームを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class AcquireActionsToFormPropertiesResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** フォーム */
        optional<Form> item;
        /** 保存したフォーム */
        optional<Mold> mold;
        /** スタンプシート */
        optional<StringHolder> stampSheet;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
            if (data.mold)
            {
                mold = data.mold->deepCopy();
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
            else if (std::strcmp(name_, "mold") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->mold.emplace();
                    detail::json::JsonParser::parse(&this->mold->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "stampSheet") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AcquireActionsToFormPropertiesResult() = default;
    AcquireActionsToFormPropertiesResult(const AcquireActionsToFormPropertiesResult& acquireActionsToFormPropertiesResult) = default;
    AcquireActionsToFormPropertiesResult(AcquireActionsToFormPropertiesResult&& acquireActionsToFormPropertiesResult) = default;
    ~AcquireActionsToFormPropertiesResult() = default;

    AcquireActionsToFormPropertiesResult& operator=(const AcquireActionsToFormPropertiesResult& acquireActionsToFormPropertiesResult) = default;
    AcquireActionsToFormPropertiesResult& operator=(AcquireActionsToFormPropertiesResult&& acquireActionsToFormPropertiesResult) = default;

    AcquireActionsToFormPropertiesResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcquireActionsToFormPropertiesResult);
    }

    const AcquireActionsToFormPropertiesResult* operator->() const
    {
        return this;
    }

    AcquireActionsToFormPropertiesResult* operator->()
    {
        return this;
    }
    /**
     * フォームを取得
     *
     * @return フォーム
     */
    const optional<Form>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * フォームを設定
     *
     * @param item フォーム
     */
    void setItem(Form item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 保存したフォームを取得
     *
     * @return 保存したフォーム
     */
    const optional<Mold>& getMold() const
    {
        return ensureData().mold;
    }

    /**
     * 保存したフォームを設定
     *
     * @param mold 保存したフォーム
     */
    void setMold(Mold mold)
    {
        ensureData().mold.emplace(std::move(mold));
    }

    /**
     * スタンプシートを取得
     *
     * @return スタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * スタンプシートを設定
     *
     * @param stampSheet スタンプシート
     */
    void setStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<AcquireActionsToFormPropertiesResult> AsyncAcquireActionsToFormPropertiesResult;

} }

#endif //GS2_FORMATION_CONTROL_ACQUIREACTIONSTOFORMPROPERTIESRESULT_HPP_