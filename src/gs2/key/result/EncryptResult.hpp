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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/key/model/model.hpp>
#include <memory>

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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            data(data.data)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "data") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->data.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EncryptResult() = default;
    EncryptResult(const EncryptResult& encryptResult) = default;
    EncryptResult(EncryptResult&& encryptResult) = default;
    ~EncryptResult() = default;

    EncryptResult& operator=(const EncryptResult& encryptResult) = default;
    EncryptResult& operator=(EncryptResult&& encryptResult) = default;

    EncryptResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EncryptResult);
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
    void setData(StringHolder data)
    {
        ensureData().data.emplace(std::move(data));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<EncryptResult> AsyncEncryptResult;

} }

#endif //GS2_KEY_CONTROL_ENCRYPTRESULT_HPP_