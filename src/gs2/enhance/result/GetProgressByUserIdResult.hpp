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

#ifndef GS2_ENHANCE_CONTROL_GETPROGRESSBYUSERIDRESULT_HPP_
#define GS2_ENHANCE_CONTROL_GETPROGRESSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/enhance/model/model.hpp>
#include <memory>

namespace gs2 { namespace enhance
{

/**
 * ユーザIDを指定して強化実行を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetProgressByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 強化実行 */
        optional<Progress> item;
        /** 強化レートモデル */
        optional<RateModel> rateModel;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
            if (data.rateModel)
            {
                rateModel = data.rateModel->deepCopy();
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
            else if (std::strcmp(name_, "rateModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->rateModel.emplace();
                    detail::json::JsonParser::parse(&this->rateModel->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetProgressByUserIdResult() = default;
    GetProgressByUserIdResult(const GetProgressByUserIdResult& getProgressByUserIdResult) = default;
    GetProgressByUserIdResult(GetProgressByUserIdResult&& getProgressByUserIdResult) = default;
    ~GetProgressByUserIdResult() = default;

    GetProgressByUserIdResult& operator=(const GetProgressByUserIdResult& getProgressByUserIdResult) = default;
    GetProgressByUserIdResult& operator=(GetProgressByUserIdResult&& getProgressByUserIdResult) = default;

    GetProgressByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetProgressByUserIdResult);
    }

    const GetProgressByUserIdResult* operator->() const
    {
        return this;
    }

    GetProgressByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 強化実行を取得
     *
     * @return 強化実行
     */
    const optional<Progress>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 強化実行を設定
     *
     * @param item 強化実行
     */
    void setItem(Progress item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 強化レートモデルを取得
     *
     * @return 強化レートモデル
     */
    const optional<RateModel>& getRateModel() const
    {
        return ensureData().rateModel;
    }

    /**
     * 強化レートモデルを設定
     *
     * @param rateModel 強化レートモデル
     */
    void setRateModel(RateModel rateModel)
    {
        ensureData().rateModel.emplace(std::move(rateModel));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetProgressByUserIdResult> AsyncGetProgressByUserIdResult;

} }

#endif //GS2_ENHANCE_CONTROL_GETPROGRESSBYUSERIDRESULT_HPP_