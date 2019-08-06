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

#ifndef GS2_LOTTERY_MODEL_RESPONSECACHE_HPP_
#define GS2_LOTTERY_MODEL_RESPONSECACHE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            region(data.region),
            ownerId(data.ownerId),
            responseCacheId(data.responseCacheId),
            requestHash(data.requestHash),
            result(data.result)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            region(std::move(data.region)),
            ownerId(std::move(data.ownerId)),
            responseCacheId(std::move(data.responseCacheId)),
            requestHash(std::move(data.requestHash)),
            result(std::move(data.result))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "region") == 0) {
                if (jsonValue.IsString())
                {
                    this->region.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "responseCacheId") == 0) {
                if (jsonValue.IsString())
                {
                    this->responseCacheId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "requestHash") == 0) {
                if (jsonValue.IsString())
                {
                    this->requestHash.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "result") == 0) {
                if (jsonValue.IsString())
                {
                    this->result.emplace(jsonValue.GetString());
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
    ResponseCache() :
        m_pData(nullptr)
    {}

    ResponseCache(const ResponseCache& responseCache) :
        Gs2Object(responseCache),
        m_pData(responseCache.m_pData != nullptr ? new Data(*responseCache.m_pData) : nullptr)
    {}

    ResponseCache(ResponseCache&& responseCache) :
        Gs2Object(std::move(responseCache)),
        m_pData(responseCache.m_pData)
    {
        responseCache.m_pData = nullptr;
    }

    ~ResponseCache()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ResponseCache& operator=(const ResponseCache& responseCache)
    {
        Gs2Object::operator=(responseCache);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*responseCache.m_pData);

        return *this;
    }

    ResponseCache& operator=(ResponseCache&& responseCache)
    {
        Gs2Object::operator=(std::move(responseCache));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = responseCache.m_pData;
        responseCache.m_pData = nullptr;

        return *this;
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
    void setRegion(const Char* region)
    {
        ensureData().region.emplace(region);
    }

    /**
     * Noneを設定
     *
     * @param region None
     */
    ResponseCache& withRegion(const Char* region)
    {
        setRegion(region);
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
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    ResponseCache& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
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
    void setResponseCacheId(const Char* responseCacheId)
    {
        ensureData().responseCacheId.emplace(responseCacheId);
    }

    /**
     * レスポンスキャッシュ のGRNを設定
     *
     * @param responseCacheId レスポンスキャッシュ のGRN
     */
    ResponseCache& withResponseCacheId(const Char* responseCacheId)
    {
        setResponseCacheId(responseCacheId);
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
    void setRequestHash(const Char* requestHash)
    {
        ensureData().requestHash.emplace(requestHash);
    }

    /**
     * Noneを設定
     *
     * @param requestHash None
     */
    ResponseCache& withRequestHash(const Char* requestHash)
    {
        setRequestHash(requestHash);
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
    void setResult(const Char* result)
    {
        ensureData().result.emplace(result);
    }

    /**
     * APIの応答内容を設定
     *
     * @param result APIの応答内容
     */
    ResponseCache& withResult(const Char* result)
    {
        setResult(result);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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

#endif //GS2_LOTTERY_MODEL_RESPONSECACHE_HPP_