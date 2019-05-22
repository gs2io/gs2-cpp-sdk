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
 * ウォレットの概要
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
        /** ウォレットの概要 のGRN */
        optional<StringHolder> summaryId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** None */
        optional<Int32> slot;
        /** 有償課金通貨所持量 */
        optional<Int32> paid;
        /** 無償課金通貨所持量 */
        optional<Int32> free;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            summaryId(data.summaryId),
            userId(data.userId),
            slot(data.slot),
            paid(data.paid),
            free(data.free),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            summaryId(std::move(data.summaryId)),
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
            if (std::strcmp(name, "summaryId") == 0) {
                if (jsonValue.IsString())
                {
                    this->summaryId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
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
     * ウォレットの概要 のGRNを取得
     *
     * @return ウォレットの概要 のGRN
     */
    const optional<StringHolder>& getSummaryId() const
    {
        return ensureData().summaryId;
    }

    /**
     * ウォレットの概要 のGRNを設定
     *
     * @param summaryId ウォレットの概要 のGRN
     */
    void setSummaryId(const Char* summaryId)
    {
        ensureData().summaryId.emplace(summaryId);
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * Noneを設定
     *
     * @param slot None
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

#endif //GS2_MONEY_MODEL_SUMMARY_HPP_