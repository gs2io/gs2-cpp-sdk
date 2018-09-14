/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_REALTIME_MODEL_GATHERINGPOOL_HPP_
#define GS2_REALTIME_MODEL_GATHERINGPOOL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace realtime {

/**
 * ギャザリングプール
 *
 * @author Game Server Services, Inc.
 *
 */
class GatheringPool : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ギャザリングプールGRN */
        optional<StringHolder> gatheringPoolId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ギャザリングプール名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gatheringPoolId(data.gatheringPoolId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gatheringPoolId(std::move(data.gatheringPoolId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gatheringPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringPoolId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    GatheringPool() :
        m_pData(nullptr)
    {}

    GatheringPool(const GatheringPool& gatheringPool) :
        Gs2Object(gatheringPool),
        m_pData(gatheringPool.m_pData != nullptr ? new Data(*gatheringPool.m_pData) : nullptr)
    {}

    GatheringPool(GatheringPool&& gatheringPool) :
        Gs2Object(std::move(gatheringPool)),
        m_pData(gatheringPool.m_pData)
    {
        gatheringPool.m_pData = nullptr;
    }

    ~GatheringPool()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GatheringPool& operator=(const GatheringPool& gatheringPool)
    {
        Gs2Object::operator=(gatheringPool);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gatheringPool.m_pData);

        return *this;
    }

    GatheringPool& operator=(GatheringPool&& gatheringPool)
    {
        Gs2Object::operator=(std::move(gatheringPool));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gatheringPool.m_pData;
        gatheringPool.m_pData = nullptr;

        return *this;
    }

    const GatheringPool* operator->() const
    {
        return this;
    }

    GatheringPool* operator->()
    {
        return this;
    }


    /**
     * ギャザリングプールGRNを取得
     *
     * @return ギャザリングプールGRN
     */
    const optional<StringHolder>& getGatheringPoolId() const
    {
        return ensureData().gatheringPoolId;
    }

    /**
     * ギャザリングプールGRNを設定
     *
     * @param gatheringPoolId ギャザリングプールGRN
     */
    void setGatheringPoolId(const Char* gatheringPoolId)
    {
        ensureData().gatheringPoolId.emplace(gatheringPoolId);
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
     * ギャザリングプール名を取得
     *
     * @return ギャザリングプール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ギャザリングプール名を設定
     *
     * @param name ギャザリングプール名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_REALTIME_MODEL_GATHERINGPOOL_HPP_