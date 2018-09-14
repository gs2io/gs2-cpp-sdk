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

#ifndef GS2_GACHA_MODEL_PROBABILITYDETAIL_HPP_
#define GS2_GACHA_MODEL_PROBABILITYDETAIL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * リソース毎の排出率
 *
 * @author Game Server Services, Inc.
 *
 */
class ProbabilityDetail : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レアリティ名 */
        optional<StringHolder> rarityName;
        /** リソースID */
        optional<StringHolder> resourceId;
        /** 排出率 */
        optional<Float> rate;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            rarityName(data.rarityName),
            resourceId(data.resourceId),
            rate(data.rate)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            rarityName(std::move(data.rarityName)),
            resourceId(std::move(data.resourceId)),
            rate(std::move(data.rate))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "rarityName") == 0) {
                if (jsonValue.IsString())
                {
                    this->rarityName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resourceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "rate") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->rate = jsonValue.GetFloat();
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
    ProbabilityDetail() :
        m_pData(nullptr)
    {}

    ProbabilityDetail(const ProbabilityDetail& probabilityDetail) :
        Gs2Object(probabilityDetail),
        m_pData(probabilityDetail.m_pData != nullptr ? new Data(*probabilityDetail.m_pData) : nullptr)
    {}

    ProbabilityDetail(ProbabilityDetail&& probabilityDetail) :
        Gs2Object(std::move(probabilityDetail)),
        m_pData(probabilityDetail.m_pData)
    {
        probabilityDetail.m_pData = nullptr;
    }

    ~ProbabilityDetail()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ProbabilityDetail& operator=(const ProbabilityDetail& probabilityDetail)
    {
        Gs2Object::operator=(probabilityDetail);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*probabilityDetail.m_pData);

        return *this;
    }

    ProbabilityDetail& operator=(ProbabilityDetail&& probabilityDetail)
    {
        Gs2Object::operator=(std::move(probabilityDetail));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = probabilityDetail.m_pData;
        probabilityDetail.m_pData = nullptr;

        return *this;
    }

    const ProbabilityDetail* operator->() const
    {
        return this;
    }

    ProbabilityDetail* operator->()
    {
        return this;
    }


    /**
     * レアリティ名を取得
     *
     * @return レアリティ名
     */
    const optional<StringHolder>& getRarityName() const
    {
        return ensureData().rarityName;
    }

    /**
     * レアリティ名を設定
     *
     * @param rarityName レアリティ名
     */
    void setRarityName(const Char* rarityName)
    {
        ensureData().rarityName.emplace(rarityName);
    }

    /**
     * リソースIDを取得
     *
     * @return リソースID
     */
    const optional<StringHolder>& getResourceId() const
    {
        return ensureData().resourceId;
    }

    /**
     * リソースIDを設定
     *
     * @param resourceId リソースID
     */
    void setResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
    }

    /**
     * 排出率を取得
     *
     * @return 排出率
     */
    const optional<Float>& getRate() const
    {
        return ensureData().rate;
    }

    /**
     * 排出率を設定
     *
     * @param rate 排出率
     */
    void setRate(Float rate)
    {
        ensureData().rate.emplace(rate);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_MODEL_PROBABILITYDETAIL_HPP_