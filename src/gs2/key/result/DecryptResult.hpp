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

#ifndef GS2_KEY_CONTROL_DECRYPTRESULT_HPP_
#define GS2_KEY_CONTROL_DECRYPTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace key
{

/**
 * データを復号します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DecryptResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 復号済みデータ */
        optional<StringHolder> data;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            data(data.data)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            data(std::move(data.data))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "data") == 0) {
                if (jsonValue.IsString())
                {
                    this->data.emplace(jsonValue.GetString());
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
    DecryptResult() :
        m_pData(nullptr)
    {}

    DecryptResult(const DecryptResult& decryptResult) :
        Gs2Object(decryptResult),
        m_pData(decryptResult.m_pData != nullptr ? new Data(*decryptResult.m_pData) : nullptr)
    {}

    DecryptResult(DecryptResult&& decryptResult) :
        Gs2Object(std::move(decryptResult)),
        m_pData(decryptResult.m_pData)
    {
        decryptResult.m_pData = nullptr;
    }

    ~DecryptResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DecryptResult& operator=(const DecryptResult& decryptResult)
    {
        Gs2Object::operator=(decryptResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*decryptResult.m_pData);

        return *this;
    }

    DecryptResult& operator=(DecryptResult&& decryptResult)
    {
        Gs2Object::operator=(std::move(decryptResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = decryptResult.m_pData;
        decryptResult.m_pData = nullptr;

        return *this;
    }

    const DecryptResult* operator->() const
    {
        return this;
    }

    DecryptResult* operator->()
    {
        return this;
    }
    /**
     * 復号済みデータを取得
     *
     * @return 復号済みデータ
     */
    const optional<StringHolder>& getData() const
    {
        return ensureData().data;
    }

    /**
     * 復号済みデータを設定
     *
     * @param data 復号済みデータ
     */
    void setData(const Char* data)
    {
        ensureData().data.emplace(data);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_KEY_CONTROL_DECRYPTRESULT_HPP_