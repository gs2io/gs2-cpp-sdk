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
#include <gs2/core/external/optional/optional.hpp>
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
        /** アクション */
        optional<StringHolder> action;
        /** 加算リクエストのJSON */
        optional<StringHolder> request;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            action(data.action),
            request(data.request)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            action(std::move(data.action)),
            request(std::move(data.request))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "action") == 0) {
                if (jsonValue.IsString())
                {
                    this->action.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "request") == 0) {
                if (jsonValue.IsString())
                {
                    this->request.emplace(jsonValue.GetString());
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
    DistributeResource() :
        m_pData(nullptr)
    {}

    DistributeResource(const DistributeResource& distributeResource) :
        Gs2Object(distributeResource),
        m_pData(distributeResource.m_pData != nullptr ? new Data(*distributeResource.m_pData) : nullptr)
    {}

    DistributeResource(DistributeResource&& distributeResource) :
        Gs2Object(std::move(distributeResource)),
        m_pData(distributeResource.m_pData)
    {
        distributeResource.m_pData = nullptr;
    }

    ~DistributeResource()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DistributeResource& operator=(const DistributeResource& distributeResource)
    {
        Gs2Object::operator=(distributeResource);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*distributeResource.m_pData);

        return *this;
    }

    DistributeResource& operator=(DistributeResource&& distributeResource)
    {
        Gs2Object::operator=(std::move(distributeResource));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = distributeResource.m_pData;
        distributeResource.m_pData = nullptr;

        return *this;
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
     * アクションを取得
     *
     * @return アクション
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * アクションを設定
     *
     * @param action アクション
     */
    void setAction(const Char* action)
    {
        ensureData().action.emplace(action);
    }

    /**
     * アクションを設定
     *
     * @param action アクション
     */
    DistributeResource& withAction(const Char* action)
    {
        setAction(action);
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
    void setRequest(const Char* request)
    {
        ensureData().request.emplace(request);
    }

    /**
     * 加算リクエストのJSONを設定
     *
     * @param request 加算リクエストのJSON
     */
    DistributeResource& withRequest(const Char* request)
    {
        setRequest(request);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const DistributeResource& lhs, const DistributeResource& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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

bool operator==(const DistributeResource& lhs, const DistributeResource& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DISTRIBUTOR_MODEL_DISTRIBUTERESOURCE_HPP_