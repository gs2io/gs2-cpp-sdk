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

#ifndef GS2_MONEY_MODEL_SUMMARY_HPP_
#define GS2_MONEY_MODEL_SUMMARY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ウォレット
 *
 * @author Game Server Services, Inc.
 *
 */
class Summary : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> slot;
        /** 有償課金通貨所持量 */
        optional<Int32> paid;
        /** 無償課金通貨所持量 */
        optional<Int32> free;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            slot(data.slot),
            paid(data.paid),
            free(data.free),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            paid(std::move(data.paid)),
            free(std::move(data.free)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "slot") == 0) {
                if (jsonValue.IsInt())
                {
                    this->slot = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "paid") == 0) {
                if (jsonValue.IsInt())
                {
                    this->paid = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "free") == 0) {
                if (jsonValue.IsInt())
                {
                    this->free = jsonValue.GetInt();
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
    Summary() :
        m_pData(nullptr)
    {}

    Summary(const Summary& summary) :
        Gs2Object(summary),
        m_pData(summary.m_pData != nullptr ? new Data(*summary.m_pData) : nullptr)
    {}

    Summary(Summary&& summary) :
        Gs2Object(std::move(summary)),
        m_pData(summary.m_pData)
    {
        summary.m_pData = nullptr;
    }

    ~Summary()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Summary& operator=(const Summary& summary)
    {
        Gs2Object::operator=(summary);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*summary.m_pData);

        return *this;
    }

    Summary& operator=(Summary&& summary)
    {
        Gs2Object::operator=(std::move(summary));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = summary.m_pData;
        summary.m_pData = nullptr;

        return *this;
    }

    const Summary* operator->() const
    {
        return this;
    }

    Summary* operator->()
    {
        return this;
    }


    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * 有償課金通貨所持量を取得
     *
     * @return 有償課金通貨所持量
     */
    const optional<Int32>& getPaid() const
    {
        return ensureData().paid;
    }

    /**
     * 有償課金通貨所持量を設定
     *
     * @param paid 有償課金通貨所持量
     */
    void setPaid(Int32 paid)
    {
        ensureData().paid.emplace(paid);
    }

    /**
     * 無償課金通貨所持量を取得
     *
     * @return 無償課金通貨所持量
     */
    const optional<Int32>& getFree() const
    {
        return ensureData().free;
    }

    /**
     * 無償課金通貨所持量を設定
     *
     * @param free 無償課金通貨所持量
     */
    void setFree(Int32 free)
    {
        ensureData().free.emplace(free);
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

#endif //GS2_MONEY_MODEL_SUMMARY_HPP_