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

#ifndef GS2_DISTRIBUTOR_MODEL_DISTRIBUTOR_HPP_
#define GS2_DISTRIBUTOR_MODEL_DISTRIBUTOR_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * ディストリビュータ
 *
 * @author Game Server Services, Inc.
 *
 */
class Distributor : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ディストリビュータ のGRN */
        optional<StringHolder> distributorId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ディストリビュータ名 */
        optional<StringHolder> name;
        /** ディストリビュータの説明 */
        optional<StringHolder> description;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            distributorId(data.distributorId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            distributorId(std::move(data.distributorId)),
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
            if (std::strcmp(name, "distributorId") == 0) {
                if (jsonValue.IsString())
                {
                    this->distributorId.emplace(jsonValue.GetString());
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
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
    Distributor() :
        m_pData(nullptr)
    {}

    Distributor(const Distributor& distributor) :
        Gs2Object(distributor),
        m_pData(distributor.m_pData != nullptr ? new Data(*distributor.m_pData) : nullptr)
    {}

    Distributor(Distributor&& distributor) :
        Gs2Object(std::move(distributor)),
        m_pData(distributor.m_pData)
    {
        distributor.m_pData = nullptr;
    }

    ~Distributor()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Distributor& operator=(const Distributor& distributor)
    {
        Gs2Object::operator=(distributor);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*distributor.m_pData);

        return *this;
    }

    Distributor& operator=(Distributor&& distributor)
    {
        Gs2Object::operator=(std::move(distributor));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = distributor.m_pData;
        distributor.m_pData = nullptr;

        return *this;
    }

    const Distributor* operator->() const
    {
        return this;
    }

    Distributor* operator->()
    {
        return this;
    }
    /**
     * ディストリビュータ のGRNを取得
     *
     * @return ディストリビュータ のGRN
     */
    const optional<StringHolder>& getDistributorId() const
    {
        return ensureData().distributorId;
    }

    /**
     * ディストリビュータ のGRNを設定
     *
     * @param distributorId ディストリビュータ のGRN
     */
    void setDistributorId(const Char* distributorId)
    {
        ensureData().distributorId.emplace(distributorId);
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
     * ディストリビュータ名を取得
     *
     * @return ディストリビュータ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param name ディストリビュータ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ディストリビュータの説明を取得
     *
     * @return ディストリビュータの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ディストリビュータの説明を設定
     *
     * @param description ディストリビュータの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_DISTRIBUTOR_MODEL_DISTRIBUTOR_HPP_