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

#ifndef GS2_DICTIONARY_CONTROL_GETNAMESPACESTATUSRESULT_HPP_
#define GS2_DICTIONARY_CONTROL_GETNAMESPACESTATUSRESULT_HPP_

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
 * ネームスペースを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetNamespaceStatusResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** None */
        optional<StringHolder> status;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            status(data.status)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "status") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetNamespaceStatusResult() = default;
    GetNamespaceStatusResult(const GetNamespaceStatusResult& getNamespaceStatusResult) = default;
    GetNamespaceStatusResult(GetNamespaceStatusResult&& getNamespaceStatusResult) = default;
    ~GetNamespaceStatusResult() = default;

    GetNamespaceStatusResult& operator=(const GetNamespaceStatusResult& getNamespaceStatusResult) = default;
    GetNamespaceStatusResult& operator=(GetNamespaceStatusResult&& getNamespaceStatusResult) = default;

    GetNamespaceStatusResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetNamespaceStatusResult);
    }

    const GetNamespaceStatusResult* operator->() const
    {
        return this;
    }

    GetNamespaceStatusResult* operator->()
    {
        return this;
    }
    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * Noneを設定
     *
     * @param status None
     */
    void setStatus(StringHolder status)
    {
        ensureData().status.emplace(std::move(status));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;

} }

#endif //GS2_DICTIONARY_CONTROL_GETNAMESPACESTATUSRESULT_HPP_