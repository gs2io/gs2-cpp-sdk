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

#ifndef GS2_GACHA_MODEL_GACHAMASTER_HPP_
#define GS2_GACHA_MODEL_GACHAMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * ガチャ
 *
 * @author Game Server Services, Inc.
 *
 */
class GachaMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ガチャGRN */
        optional<StringHolder> gachaId;
        /** ガチャ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 排出確率名リスト */
        optional<List<StringHolder>> prizeTableNames;
        /** 景品の排出処理に使用する GS2-JobQueue */
        optional<StringHolder> prizeJobQueueName;
        /** 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Script */
        optional<StringHolder> prizeJobQueueScriptName;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gachaId(data.gachaId),
            name(data.name),
            meta(data.meta),
            prizeTableNames(data.prizeTableNames),
            prizeJobQueueName(data.prizeJobQueueName),
            prizeJobQueueScriptName(data.prizeJobQueueScriptName),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gachaId(std::move(data.gachaId)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            prizeTableNames(std::move(data.prizeTableNames)),
            prizeJobQueueName(std::move(data.prizeJobQueueName)),
            prizeJobQueueScriptName(std::move(data.prizeJobQueueScriptName)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gachaId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gachaId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "prizeTableNames") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->prizeTableNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->prizeTableNames += std::move(stringHolder);
                    }
                }
            }
            else if (std::strcmp(name, "prizeJobQueueName") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeJobQueueName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "prizeJobQueueScriptName") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeJobQueueScriptName.emplace(jsonValue.GetString());
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
    GachaMaster() :
        m_pData(nullptr)
    {}

    GachaMaster(const GachaMaster& gachaMaster) :
        Gs2Object(gachaMaster),
        m_pData(gachaMaster.m_pData != nullptr ? new Data(*gachaMaster.m_pData) : nullptr)
    {}

    GachaMaster(GachaMaster&& gachaMaster) :
        Gs2Object(std::move(gachaMaster)),
        m_pData(gachaMaster.m_pData)
    {
        gachaMaster.m_pData = nullptr;
    }

    ~GachaMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GachaMaster& operator=(const GachaMaster& gachaMaster)
    {
        Gs2Object::operator=(gachaMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gachaMaster.m_pData);

        return *this;
    }

    GachaMaster& operator=(GachaMaster&& gachaMaster)
    {
        Gs2Object::operator=(std::move(gachaMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gachaMaster.m_pData;
        gachaMaster.m_pData = nullptr;

        return *this;
    }

    const GachaMaster* operator->() const
    {
        return this;
    }

    GachaMaster* operator->()
    {
        return this;
    }


    /**
     * ガチャGRNを取得
     *
     * @return ガチャGRN
     */
    const optional<StringHolder>& getGachaId() const
    {
        return ensureData().gachaId;
    }

    /**
     * ガチャGRNを設定
     *
     * @param gachaId ガチャGRN
     */
    void setGachaId(const Char* gachaId)
    {
        ensureData().gachaId.emplace(gachaId);
    }

    /**
     * ガチャ名を取得
     *
     * @return ガチャ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ガチャ名を設定
     *
     * @param name ガチャ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 排出確率名リストを取得
     *
     * @return 排出確率名リスト
     */
    const optional<List<StringHolder>>& getPrizeTableNames() const
    {
        return ensureData().prizeTableNames;
    }

    /**
     * 排出確率名リストを設定
     *
     * @param prizeTableNames 排出確率名リスト
     */
    void setPrizeTableNames(const List<StringHolder>& prizeTableNames)
    {
        ensureData().prizeTableNames.emplace(prizeTableNames);
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueueを取得
     *
     * @return 景品の排出処理に使用する GS2-JobQueue
     */
    const optional<StringHolder>& getPrizeJobQueueName() const
    {
        return ensureData().prizeJobQueueName;
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueueを設定
     *
     * @param prizeJobQueueName 景品の排出処理に使用する GS2-JobQueue
     */
    void setPrizeJobQueueName(const Char* prizeJobQueueName)
    {
        ensureData().prizeJobQueueName.emplace(prizeJobQueueName);
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Scriptを取得
     *
     * @return 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Script
     */
    const optional<StringHolder>& getPrizeJobQueueScriptName() const
    {
        return ensureData().prizeJobQueueScriptName;
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Scriptを設定
     *
     * @param prizeJobQueueScriptName 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Script
     */
    void setPrizeJobQueueScriptName(const Char* prizeJobQueueScriptName)
    {
        ensureData().prizeJobQueueScriptName.emplace(prizeJobQueueScriptName);
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

#endif //GS2_GACHA_MODEL_GACHAMASTER_HPP_