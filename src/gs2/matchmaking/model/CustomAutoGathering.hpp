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

#ifndef GS2_MATCHMAKING_MODEL_CUSTOMAUTOGATHERING_HPP_
#define GS2_MATCHMAKING_MODEL_CUSTOMAUTOGATHERING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * CustomAutoマッチメイキング ギャザリング
 *
 * @author Game Server Services, Inc.
 *
 */
class CustomAutoGathering : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ギャザリングID */
        optional<StringHolder> gatheringId;
        /** 属性値1 */
        optional<Int32> attribute1;
        /** 属性値2 */
        optional<Int32> attribute2;
        /** 属性値3 */
        optional<Int32> attribute3;
        /** 属性値4 */
        optional<Int32> attribute4;
        /** 属性値5 */
        optional<Int32> attribute5;
        /** 参加プレイヤー数 */
        optional<Int32> joinPlayer;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gatheringId(data.gatheringId),
            attribute1(data.attribute1),
            attribute2(data.attribute2),
            attribute3(data.attribute3),
            attribute4(data.attribute4),
            attribute5(data.attribute5),
            joinPlayer(data.joinPlayer),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gatheringId(std::move(data.gatheringId)),
            attribute1(std::move(data.attribute1)),
            attribute2(std::move(data.attribute2)),
            attribute3(std::move(data.attribute3)),
            attribute4(std::move(data.attribute4)),
            attribute5(std::move(data.attribute5)),
            joinPlayer(std::move(data.joinPlayer)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gatheringId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "attribute1") == 0) {
                if (jsonValue.IsInt())
                {
                    this->attribute1 = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "attribute2") == 0) {
                if (jsonValue.IsInt())
                {
                    this->attribute2 = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "attribute3") == 0) {
                if (jsonValue.IsInt())
                {
                    this->attribute3 = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "attribute4") == 0) {
                if (jsonValue.IsInt())
                {
                    this->attribute4 = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "attribute5") == 0) {
                if (jsonValue.IsInt())
                {
                    this->attribute5 = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "joinPlayer") == 0) {
                if (jsonValue.IsInt())
                {
                    this->joinPlayer = jsonValue.GetInt();
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
    CustomAutoGathering() :
        m_pData(nullptr)
    {}

    CustomAutoGathering(const CustomAutoGathering& customAutoGathering) :
        Gs2Object(customAutoGathering),
        m_pData(customAutoGathering.m_pData != nullptr ? new Data(*customAutoGathering.m_pData) : nullptr)
    {}

    CustomAutoGathering(CustomAutoGathering&& customAutoGathering) :
        Gs2Object(std::move(customAutoGathering)),
        m_pData(customAutoGathering.m_pData)
    {
        customAutoGathering.m_pData = nullptr;
    }

    ~CustomAutoGathering()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CustomAutoGathering& operator=(const CustomAutoGathering& customAutoGathering)
    {
        Gs2Object::operator=(customAutoGathering);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*customAutoGathering.m_pData);

        return *this;
    }

    CustomAutoGathering& operator=(CustomAutoGathering&& customAutoGathering)
    {
        Gs2Object::operator=(std::move(customAutoGathering));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = customAutoGathering.m_pData;
        customAutoGathering.m_pData = nullptr;

        return *this;
    }

    const CustomAutoGathering* operator->() const
    {
        return this;
    }

    CustomAutoGathering* operator->()
    {
        return this;
    }


    /**
     * ギャザリングIDを取得
     *
     * @return ギャザリングID
     */
    const optional<StringHolder>& getGatheringId() const
    {
        return ensureData().gatheringId;
    }

    /**
     * ギャザリングIDを設定
     *
     * @param gatheringId ギャザリングID
     */
    void setGatheringId(const Char* gatheringId)
    {
        ensureData().gatheringId.emplace(gatheringId);
    }

    /**
     * 属性値1を取得
     *
     * @return 属性値1
     */
    const optional<Int32>& getAttribute1() const
    {
        return ensureData().attribute1;
    }

    /**
     * 属性値1を設定
     *
     * @param attribute1 属性値1
     */
    void setAttribute1(Int32 attribute1)
    {
        ensureData().attribute1.emplace(attribute1);
    }

    /**
     * 属性値2を取得
     *
     * @return 属性値2
     */
    const optional<Int32>& getAttribute2() const
    {
        return ensureData().attribute2;
    }

    /**
     * 属性値2を設定
     *
     * @param attribute2 属性値2
     */
    void setAttribute2(Int32 attribute2)
    {
        ensureData().attribute2.emplace(attribute2);
    }

    /**
     * 属性値3を取得
     *
     * @return 属性値3
     */
    const optional<Int32>& getAttribute3() const
    {
        return ensureData().attribute3;
    }

    /**
     * 属性値3を設定
     *
     * @param attribute3 属性値3
     */
    void setAttribute3(Int32 attribute3)
    {
        ensureData().attribute3.emplace(attribute3);
    }

    /**
     * 属性値4を取得
     *
     * @return 属性値4
     */
    const optional<Int32>& getAttribute4() const
    {
        return ensureData().attribute4;
    }

    /**
     * 属性値4を設定
     *
     * @param attribute4 属性値4
     */
    void setAttribute4(Int32 attribute4)
    {
        ensureData().attribute4.emplace(attribute4);
    }

    /**
     * 属性値5を取得
     *
     * @return 属性値5
     */
    const optional<Int32>& getAttribute5() const
    {
        return ensureData().attribute5;
    }

    /**
     * 属性値5を設定
     *
     * @param attribute5 属性値5
     */
    void setAttribute5(Int32 attribute5)
    {
        ensureData().attribute5.emplace(attribute5);
    }

    /**
     * 参加プレイヤー数を取得
     *
     * @return 参加プレイヤー数
     */
    const optional<Int32>& getJoinPlayer() const
    {
        return ensureData().joinPlayer;
    }

    /**
     * 参加プレイヤー数を設定
     *
     * @param joinPlayer 参加プレイヤー数
     */
    void setJoinPlayer(Int32 joinPlayer)
    {
        ensureData().joinPlayer.emplace(joinPlayer);
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
     * 更新日時(エポック秒)を取得
     *
     * @return 更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 更新日時(エポック秒)を設定
     *
     * @param updateAt 更新日時(エポック秒)
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

#endif //GS2_MATCHMAKING_MODEL_CUSTOMAUTOGATHERING_HPP_