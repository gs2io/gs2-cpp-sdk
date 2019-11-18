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

#ifndef GS2_GATEWAY_MODEL_RESPONSECACHE_HPP_
#define GS2_GATEWAY_MODEL_RESPONSECACHE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace gateway {

/**
 * レスポンスキャッシュ
 *
 * @author Game Server Services, Inc.
 *
 */
class ResponseCache : public Gs2Object
{
    friend bool operator!=(const ResponseCache& lhs, const ResponseCache& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** None */
        optional<StringHolder> region;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** レスポンスキャッシュ のGRN */
        optional<StringHolder> responseCacheId;
        /** None */
        optional<StringHolder> requestHash;
        /** APIの応答内容 */
        optional<StringHolder> result;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            region(data.region),
            ownerId(data.ownerId),
            responseCacheId(data.responseCacheId),
            requestHash(data.requestHash),
            result(data.result)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "region") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->region.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "responseCacheId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->responseCacheId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "requestHash") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->requestHash.emplace(jsonValue.GetString());
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
    ResponseCache() = default;
    ResponseCache(const ResponseCache& responseCache) = default;
    ResponseCache(ResponseCache&& responseCache) = default;
    ~ResponseCache() = default;

    ResponseCache& operator=(const ResponseCache& responseCache) = default;
    ResponseCache& operator=(ResponseCache&& responseCache) = default;

    ResponseCache deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ResponseCache);
    }

    const ResponseCache* operator->() const
    {
        return this;
    }

    ResponseCache* operator->()
    {
        return this;
    }
    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getRegion() const
    {
        return ensureData().region;
    }

    /**
     * Noneを設定
     *
     * @param region None
     */
    void setRegion(StringHolder region)
    {
        ensureData().region.emplace(std::move(region));
    }

    /**
     * Noneを設定
     *
     * @param region None
     */
    ResponseCache& withRegion(StringHolder region)
    {
        setRegion(std::move(region));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    ResponseCache& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * レスポンスキャッシュ のGRNを取得
     *
     * @return レスポンスキャッシュ のGRN
     */
    const optional<StringHolder>& getResponseCacheId() const
    {
        return ensureData().responseCacheId;
    }

    /**
     * レスポンスキャッシュ のGRNを設定
     *
     * @param responseCacheId レスポンスキャッシュ のGRN
     */
    void setResponseCacheId(StringHolder responseCacheId)
    {
        ensureData().responseCacheId.emplace(std::move(responseCacheId));
    }

    /**
     * レスポンスキャッシュ のGRNを設定
     *
     * @param responseCacheId レスポンスキャッシュ のGRN
     */
    ResponseCache& withResponseCacheId(StringHolder responseCacheId)
    {
        setResponseCacheId(std::move(responseCacheId));
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getRequestHash() const
    {
        return ensureData().requestHash;
    }

    /**
     * Noneを設定
     *
     * @param requestHash None
     */
    void setRequestHash(StringHolder requestHash)
    {
        ensureData().requestHash.emplace(std::move(requestHash));
    }

    /**
     * Noneを設定
     *
     * @param requestHash None
     */
    ResponseCache& withRequestHash(StringHolder requestHash)
    {
        setRequestHash(std::move(requestHash));
        return *this;
    }

    /**
     * APIの応答内容を取得
     *
     * @return APIの応答内容
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * APIの応答内容を設定
     *
     * @param result APIの応答内容
     */
    void setResult(StringHolder result)
    {
        ensureData().result.emplace(std::move(result));
    }

    /**
     * APIの応答内容を設定
     *
     * @param result APIの応答内容
     */
    ResponseCache& withResult(StringHolder result)
    {
        setResult(std::move(result));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ResponseCache& lhs, const ResponseCache& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->region != lhr.m_pData->region)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->responseCacheId != lhr.m_pData->responseCacheId)
        {
            return true;
        }
        if (lhs.m_pData->requestHash != lhr.m_pData->requestHash)
        {
            return true;
        }
        if (lhs.m_pData->result != lhr.m_pData->result)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const ResponseCache& lhs, const ResponseCache& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_GATEWAY_MODEL_RESPONSECACHE_HPP_