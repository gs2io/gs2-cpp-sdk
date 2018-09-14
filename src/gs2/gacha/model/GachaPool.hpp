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

#ifndef GS2_GACHA_MODEL_GACHAPOOL_HPP_
#define GS2_GACHA_MODEL_GACHAPOOL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * ガチャプール
 *
 * @author Game Server Services, Inc.
 *
 */
class GachaPool : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ガチャプールGRN */
        optional<StringHolder> gachaPoolId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ガチャプール名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 排出確率を公開するか */
        optional<StringHolder> publicDrawRate;
        /** ガチャ一覧の取得を許すか */
        optional<StringHolder> allowAccessGachaInfo;
        /** 抽選実行を制限するか */
        optional<StringHolder> restrict;
        /** 排出判定時 に実行されるGS2-Script */
        optional<StringHolder> drawPrizeTriggerScript;
        /** 排出判定完了時 に実行されるGS2-Script */
        optional<StringHolder> drawPrizeDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gachaPoolId(data.gachaPoolId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            publicDrawRate(data.publicDrawRate),
            allowAccessGachaInfo(data.allowAccessGachaInfo),
            restrict(data.restrict),
            drawPrizeTriggerScript(data.drawPrizeTriggerScript),
            drawPrizeDoneTriggerScript(data.drawPrizeDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gachaPoolId(std::move(data.gachaPoolId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            publicDrawRate(std::move(data.publicDrawRate)),
            allowAccessGachaInfo(std::move(data.allowAccessGachaInfo)),
            restrict(std::move(data.restrict)),
            drawPrizeTriggerScript(std::move(data.drawPrizeTriggerScript)),
            drawPrizeDoneTriggerScript(std::move(data.drawPrizeDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gachaPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gachaPoolId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "publicDrawRate") == 0) {
                if (jsonValue.IsString())
                {
                    this->publicDrawRate.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "allowAccessGachaInfo") == 0) {
                if (jsonValue.IsString())
                {
                    this->allowAccessGachaInfo.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "restrict") == 0) {
                if (jsonValue.IsString())
                {
                    this->restrict.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "drawPrizeTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->drawPrizeTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "drawPrizeDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->drawPrizeDoneTriggerScript.emplace(jsonValue.GetString());
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
    GachaPool() :
        m_pData(nullptr)
    {}

    GachaPool(const GachaPool& gachaPool) :
        Gs2Object(gachaPool),
        m_pData(gachaPool.m_pData != nullptr ? new Data(*gachaPool.m_pData) : nullptr)
    {}

    GachaPool(GachaPool&& gachaPool) :
        Gs2Object(std::move(gachaPool)),
        m_pData(gachaPool.m_pData)
    {
        gachaPool.m_pData = nullptr;
    }

    ~GachaPool()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GachaPool& operator=(const GachaPool& gachaPool)
    {
        Gs2Object::operator=(gachaPool);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gachaPool.m_pData);

        return *this;
    }

    GachaPool& operator=(GachaPool&& gachaPool)
    {
        Gs2Object::operator=(std::move(gachaPool));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gachaPool.m_pData;
        gachaPool.m_pData = nullptr;

        return *this;
    }

    const GachaPool* operator->() const
    {
        return this;
    }

    GachaPool* operator->()
    {
        return this;
    }


    /**
     * ガチャプールGRNを取得
     *
     * @return ガチャプールGRN
     */
    const optional<StringHolder>& getGachaPoolId() const
    {
        return ensureData().gachaPoolId;
    }

    /**
     * ガチャプールGRNを設定
     *
     * @param gachaPoolId ガチャプールGRN
     */
    void setGachaPoolId(const Char* gachaPoolId)
    {
        ensureData().gachaPoolId.emplace(gachaPoolId);
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
     * ガチャプール名を取得
     *
     * @return ガチャプール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ガチャプール名を設定
     *
     * @param name ガチャプール名
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
     * 排出確率を公開するかを取得
     *
     * @return 排出確率を公開するか
     */
    const optional<StringHolder>& getPublicDrawRate() const
    {
        return ensureData().publicDrawRate;
    }

    /**
     * 排出確率を公開するかを設定
     *
     * @param publicDrawRate 排出確率を公開するか
     */
    void setPublicDrawRate(const Char* publicDrawRate)
    {
        ensureData().publicDrawRate.emplace(publicDrawRate);
    }

    /**
     * ガチャ一覧の取得を許すかを取得
     *
     * @return ガチャ一覧の取得を許すか
     */
    const optional<StringHolder>& getAllowAccessGachaInfo() const
    {
        return ensureData().allowAccessGachaInfo;
    }

    /**
     * ガチャ一覧の取得を許すかを設定
     *
     * @param allowAccessGachaInfo ガチャ一覧の取得を許すか
     */
    void setAllowAccessGachaInfo(const Char* allowAccessGachaInfo)
    {
        ensureData().allowAccessGachaInfo.emplace(allowAccessGachaInfo);
    }

    /**
     * 抽選実行を制限するかを取得
     *
     * @return 抽選実行を制限するか
     */
    const optional<StringHolder>& getRestrict() const
    {
        return ensureData().restrict;
    }

    /**
     * 抽選実行を制限するかを設定
     *
     * @param restrict 抽選実行を制限するか
     */
    void setRestrict(const Char* restrict)
    {
        ensureData().restrict.emplace(restrict);
    }

    /**
     * 排出判定時 に実行されるGS2-Scriptを取得
     *
     * @return 排出判定時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDrawPrizeTriggerScript() const
    {
        return ensureData().drawPrizeTriggerScript;
    }

    /**
     * 排出判定時 に実行されるGS2-Scriptを設定
     *
     * @param drawPrizeTriggerScript 排出判定時 に実行されるGS2-Script
     */
    void setDrawPrizeTriggerScript(const Char* drawPrizeTriggerScript)
    {
        ensureData().drawPrizeTriggerScript.emplace(drawPrizeTriggerScript);
    }

    /**
     * 排出判定完了時 に実行されるGS2-Scriptを取得
     *
     * @return 排出判定完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDrawPrizeDoneTriggerScript() const
    {
        return ensureData().drawPrizeDoneTriggerScript;
    }

    /**
     * 排出判定完了時 に実行されるGS2-Scriptを設定
     *
     * @param drawPrizeDoneTriggerScript 排出判定完了時 に実行されるGS2-Script
     */
    void setDrawPrizeDoneTriggerScript(const Char* drawPrizeDoneTriggerScript)
    {
        ensureData().drawPrizeDoneTriggerScript.emplace(drawPrizeDoneTriggerScript);
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

#endif //GS2_GACHA_MODEL_GACHAPOOL_HPP_