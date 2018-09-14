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

#ifndef GS2_GACHA_CONTROL_DETAILPROBABILITYRESULT_HPP_
#define GS2_GACHA_CONTROL_DETAILPROBABILITYRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gacha
{

/**
 * @author Game Server Services, Inc.
 */
class DetailProbabilityResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** リソース毎の排出率 */
        optional<List<ProbabilityDetail>> items;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ProbabilityDetail item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
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
    DetailProbabilityResult() :
        m_pData(nullptr)
    {}

    DetailProbabilityResult(const DetailProbabilityResult& detailProbabilityResult) :
        Gs2Object(detailProbabilityResult),
        m_pData(detailProbabilityResult.m_pData != nullptr ? new Data(*detailProbabilityResult.m_pData) : nullptr)
    {}

    DetailProbabilityResult(DetailProbabilityResult&& detailProbabilityResult) :
        Gs2Object(std::move(detailProbabilityResult)),
        m_pData(detailProbabilityResult.m_pData)
    {
        detailProbabilityResult.m_pData = nullptr;
    }

    ~DetailProbabilityResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DetailProbabilityResult& operator=(const DetailProbabilityResult& detailProbabilityResult)
    {
        Gs2Object::operator=(detailProbabilityResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*detailProbabilityResult.m_pData);

        return *this;
    }

    DetailProbabilityResult& operator=(DetailProbabilityResult&& detailProbabilityResult)
    {
        Gs2Object::operator=(std::move(detailProbabilityResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = detailProbabilityResult.m_pData;
        detailProbabilityResult.m_pData = nullptr;

        return *this;
    }

    const DetailProbabilityResult* operator->() const
    {
        return this;
    }

    DetailProbabilityResult* operator->()
    {
        return this;
    }


    /**
     * リソース毎の排出率を取得
     *
     * @return リソース毎の排出率
     */
    const optional<List<ProbabilityDetail>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * リソース毎の排出率を設定
     *
     * @param items リソース毎の排出率
     */
    void setItems(const List<ProbabilityDetail>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_CONTROL_DETAILPROBABILITYRESULT_HPP_