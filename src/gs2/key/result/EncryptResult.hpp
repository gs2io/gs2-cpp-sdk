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

#ifndef GS2_KEY_CONTROL_ENCRYPTRESULT_HPP_
#define GS2_KEY_CONTROL_ENCRYPTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace key
{

/**
 * データを暗号化します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class EncryptResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 暗号化済みデータ */
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

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "data") == 0) {
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
    EncryptResult() :
        m_pData(nullptr)
    {}

    EncryptResult(const EncryptResult& encryptResult) :
        Gs2Object(encryptResult),
        m_pData(encryptResult.m_pData != nullptr ? new Data(*encryptResult.m_pData) : nullptr)
    {}

    EncryptResult(EncryptResult&& encryptResult) :
        Gs2Object(std::move(encryptResult)),
        m_pData(encryptResult.m_pData)
    {
        encryptResult.m_pData = nullptr;
    }

    ~EncryptResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    EncryptResult& operator=(const EncryptResult& encryptResult)
    {
        Gs2Object::operator=(encryptResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*encryptResult.m_pData);

        return *this;
    }

    EncryptResult& operator=(EncryptResult&& encryptResult)
    {
        Gs2Object::operator=(std::move(encryptResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = encryptResult.m_pData;
        encryptResult.m_pData = nullptr;

        return *this;
    }

    const EncryptResult* operator->() const
    {
        return this;
    }

    EncryptResult* operator->()
    {
        return this;
    }
    /**
     * 暗号化済みデータを取得
     *
     * @return 暗号化済みデータ
     */
    const optional<StringHolder>& getData() const
    {
        return ensureData().data;
    }

    /**
     * 暗号化済みデータを設定
     *
     * @param data 暗号化済みデータ
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

typedef AsyncResult<EncryptResult> AsyncEncryptResult;

} }

#endif //GS2_KEY_CONTROL_ENCRYPTRESULT_HPP_