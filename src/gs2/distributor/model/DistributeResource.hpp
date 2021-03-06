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

#ifndef GS2_DISTRIBUTOR_MODEL_DISTRIBUTERESOURCE_HPP_
#define GS2_DISTRIBUTOR_MODEL_DISTRIBUTERESOURCE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace distributor {

/**
 * 加算するリソース
 *
 * @author Game Server Services, Inc.
 *
 */
class DistributeResource : public Gs2Object
{
    friend bool operator!=(const DistributeResource& lhs, const DistributeResource& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプシートで実行するアクションの種類 */
        optional<StringHolder> action;
        /** 加算リクエストのJSON */
        optional<StringHolder> request;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            action(data.action),
            request(data.request)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "action") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->action.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "request") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->request.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DistributeResource() = default;
    DistributeResource(const DistributeResource& distributeResource) = default;
    DistributeResource(DistributeResource&& distributeResource) = default;
    ~DistributeResource() = default;

    DistributeResource& operator=(const DistributeResource& distributeResource) = default;
    DistributeResource& operator=(DistributeResource&& distributeResource) = default;

    DistributeResource deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DistributeResource);
    }

    const DistributeResource* operator->() const
    {
        return this;
    }

    DistributeResource* operator->()
    {
        return this;
    }
    /**
     * スタンプシートで実行するアクションの種類を取得
     *
     * @return スタンプシートで実行するアクションの種類
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * スタンプシートで実行するアクションの種類を設定
     *
     * @param action スタンプシートで実行するアクションの種類
     */
    void setAction(StringHolder action)
    {
        ensureData().action.emplace(std::move(action));
    }

    /**
     * スタンプシートで実行するアクションの種類を設定
     *
     * @param action スタンプシートで実行するアクションの種類
     */
    DistributeResource& withAction(StringHolder action)
    {
        setAction(std::move(action));
        return *this;
    }

    /**
     * 加算リクエストのJSONを取得
     *
     * @return 加算リクエストのJSON
     */
    const optional<StringHolder>& getRequest() const
    {
        return ensureData().request;
    }

    /**
     * 加算リクエストのJSONを設定
     *
     * @param request 加算リクエストのJSON
     */
    void setRequest(StringHolder request)
    {
        ensureData().request.emplace(std::move(request));
    }

    /**
     * 加算リクエストのJSONを設定
     *
     * @param request 加算リクエストのJSON
     */
    DistributeResource& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DistributeResource& lhs, const DistributeResource& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->action != lhr.m_pData->action)
        {
            return true;
        }
        if (lhs.m_pData->request != lhr.m_pData->request)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const DistributeResource& lhs, const DistributeResource& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DISTRIBUTOR_MODEL_DISTRIBUTERESOURCE_HPP_