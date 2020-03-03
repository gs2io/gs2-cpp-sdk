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

#ifndef GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEWITHOUTOVERFLOWPROCESSRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEWITHOUTOVERFLOWPROCESSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/distributor/model/model.hpp>
#include <memory>

namespace gs2 { namespace distributor
{

/**
 * 所持品を配布する(溢れた際の救済処置無し) のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DistributeWithoutOverflowProcessResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 処理した DistributeResource */
        optional<DistributeResource> distributeResource;
        /** レスポンス内容 */
        optional<StringHolder> result;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            result(data.result)
        {
            if (data.distributeResource)
            {
                distributeResource = data.distributeResource->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "distributeResource") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->distributeResource.emplace();
                    detail::json::JsonParser::parse(&this->distributeResource->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "result") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->result.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DistributeWithoutOverflowProcessResult() = default;
    DistributeWithoutOverflowProcessResult(const DistributeWithoutOverflowProcessResult& distributeWithoutOverflowProcessResult) = default;
    DistributeWithoutOverflowProcessResult(DistributeWithoutOverflowProcessResult&& distributeWithoutOverflowProcessResult) = default;
    ~DistributeWithoutOverflowProcessResult() = default;

    DistributeWithoutOverflowProcessResult& operator=(const DistributeWithoutOverflowProcessResult& distributeWithoutOverflowProcessResult) = default;
    DistributeWithoutOverflowProcessResult& operator=(DistributeWithoutOverflowProcessResult&& distributeWithoutOverflowProcessResult) = default;

    DistributeWithoutOverflowProcessResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DistributeWithoutOverflowProcessResult);
    }

    const DistributeWithoutOverflowProcessResult* operator->() const
    {
        return this;
    }

    DistributeWithoutOverflowProcessResult* operator->()
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
    void setDistributeResource(DistributeResource distributeResource)
    {
        ensureData().distributeResource.emplace(std::move(distributeResource));
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
    void setResult(StringHolder result)
    {
        ensureData().result.emplace(std::move(result));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DistributeWithoutOverflowProcessResult> AsyncDistributeWithoutOverflowProcessResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEWITHOUTOVERFLOWPROCESSRESULT_HPP_