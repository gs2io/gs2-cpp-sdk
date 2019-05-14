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

#ifndef GS2_EXPERIENCE_CONTROL_ADDRANKCAPBYUSERIDREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_ADDRANKCAPBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ランクキャップを加算 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AddRankCapByUserIdRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 経験値名 */
        optional<StringHolder> experienceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 経験値の種類名 */
        optional<StringHolder> experienceModelName;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** 累計獲得経験値 */
        optional<Int64> rankCapValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            experienceName(data.experienceName),
            userId(data.userId),
            experienceModelName(data.experienceModelName),
            propertyId(data.propertyId),
            rankCapValue(data.rankCapValue),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            experienceName(std::move(data.experienceName)),
            userId(std::move(data.userId)),
            experienceModelName(std::move(data.experienceModelName)),
            propertyId(std::move(data.propertyId)),
            rankCapValue(std::move(data.rankCapValue)),
            duplicationAvoider(std::move(data.duplicationAvoider))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    AddRankCapByUserIdRequest() :
        m_pData(nullptr)
    {}

    AddRankCapByUserIdRequest(const AddRankCapByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    AddRankCapByUserIdRequest(AddRankCapByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~AddRankCapByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AddRankCapByUserIdRequest& operator=(const AddRankCapByUserIdRequest& addRankCapByUserIdRequest)
    {
        Gs2BasicRequest::operator=(addRankCapByUserIdRequest);
        Gs2Experience::operator=(addRankCapByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*addRankCapByUserIdRequest.m_pData);

        return *this;
    }

    AddRankCapByUserIdRequest& operator=(AddRankCapByUserIdRequest&& addRankCapByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(addRankCapByUserIdRequest));
        Gs2Experience::operator=(std::move(addRankCapByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = addRankCapByUserIdRequest.m_pData;
        addRankCapByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const AddRankCapByUserIdRequest* operator->() const
    {
        return this;
    }

    AddRankCapByUserIdRequest* operator->()
    {
        return this;
    }
    /**
     * 経験値名を取得
     *
     * @return 経験値名
     */
    const optional<StringHolder>& getExperienceName() const
    {
        return ensureData().experienceName;
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    void setExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    AddRankCapByUserIdRequest& withExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
        return *this;
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
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    AddRankCapByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getExperienceModelName() const
    {
        return ensureData().experienceModelName;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    void setExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    AddRankCapByUserIdRequest& withExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
        return *this;
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    AddRankCapByUserIdRequest& withPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
        return *this;
    }

    /**
     * 累計獲得経験値を取得
     *
     * @return 累計獲得経験値
     */
    const optional<Int64>& getRankCapValue() const
    {
        return ensureData().rankCapValue;
    }

    /**
     * 累計獲得経験値を設定
     *
     * @param rankCapValue 累計獲得経験値
     */
    void setRankCapValue(Int64 rankCapValue)
    {
        ensureData().rankCapValue.emplace(rankCapValue);
    }

    /**
     * 累計獲得経験値を設定
     *
     * @param rankCapValue 累計獲得経験値
     */
    AddRankCapByUserIdRequest& withRankCapValue(Int64 rankCapValue)
    {
        ensureData().rankCapValue.emplace(rankCapValue);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    AddRankCapByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    AddRankCapByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    AddRankCapByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    AddRankCapByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AddRankCapByUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_ADDRANKCAPBYUSERIDREQUEST_HPP_