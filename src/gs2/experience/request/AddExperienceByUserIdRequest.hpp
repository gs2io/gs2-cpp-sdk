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

#ifndef GS2_EXPERIENCE_CONTROL_ADDEXPERIENCEBYUSERIDREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_ADDEXPERIENCEBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/experience/Gs2ExperienceConst.hpp>
#include <gs2/experience/model/model.hpp>
#include <memory>

namespace gs2 { namespace experience
{

/**
 * 経験値を加算 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AddExperienceByUserIdRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 経験値の種類の名前 */
        optional<StringHolder> experienceName;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** 加算する経験値量 */
        optional<Int64> experienceValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            experienceName(data.experienceName),
            propertyId(data.propertyId),
            experienceValue(data.experienceValue),
            duplicationAvoider(data.duplicationAvoider)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    AddExperienceByUserIdRequest() = default;
    AddExperienceByUserIdRequest(const AddExperienceByUserIdRequest& addExperienceByUserIdRequest) = default;
    AddExperienceByUserIdRequest(AddExperienceByUserIdRequest&& addExperienceByUserIdRequest) = default;
    ~AddExperienceByUserIdRequest() GS2_OVERRIDE = default;

    AddExperienceByUserIdRequest& operator=(const AddExperienceByUserIdRequest& addExperienceByUserIdRequest) = default;
    AddExperienceByUserIdRequest& operator=(AddExperienceByUserIdRequest&& addExperienceByUserIdRequest) = default;

    AddExperienceByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AddExperienceByUserIdRequest);
    }

    const AddExperienceByUserIdRequest* operator->() const
    {
        return this;
    }

    AddExperienceByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    AddExperienceByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    AddExperienceByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * 経験値の種類の名前を取得
     *
     * @return 経験値の種類の名前
     */
    const optional<StringHolder>& getExperienceName() const
    {
        return ensureData().experienceName;
    }

    /**
     * 経験値の種類の名前を設定
     *
     * @param experienceName 経験値の種類の名前
     */
    void setExperienceName(StringHolder experienceName)
    {
        ensureData().experienceName.emplace(std::move(experienceName));
    }

    /**
     * 経験値の種類の名前を設定
     *
     * @param experienceName 経験値の種類の名前
     */
    AddExperienceByUserIdRequest& withExperienceName(StringHolder experienceName)
    {
        ensureData().experienceName.emplace(std::move(experienceName));
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
    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    AddExperienceByUserIdRequest& withPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
        return *this;
    }

    /**
     * 加算する経験値量を取得
     *
     * @return 加算する経験値量
     */
    const optional<Int64>& getExperienceValue() const
    {
        return ensureData().experienceValue;
    }

    /**
     * 加算する経験値量を設定
     *
     * @param experienceValue 加算する経験値量
     */
    void setExperienceValue(Int64 experienceValue)
    {
        ensureData().experienceValue.emplace(experienceValue);
    }

    /**
     * 加算する経験値量を設定
     *
     * @param experienceValue 加算する経験値量
     */
    AddExperienceByUserIdRequest& withExperienceValue(Int64 experienceValue)
    {
        ensureData().experienceValue.emplace(experienceValue);
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
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    AddExperienceByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    AddExperienceByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AddExperienceByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_ADDEXPERIENCEBYUSERIDREQUEST_HPP_