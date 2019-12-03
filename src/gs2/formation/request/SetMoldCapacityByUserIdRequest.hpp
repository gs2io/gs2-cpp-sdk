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

#ifndef GS2_FORMATION_CONTROL_SETMOLDCAPACITYBYUSERIDREQUEST_HPP_
#define GS2_FORMATION_CONTROL_SETMOLDCAPACITYBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/Gs2FormationConst.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * ユーザIDを指定して保存したフォームのキャパシティを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SetMoldCapacityByUserIdRequest : public Gs2BasicRequest, public Gs2Formation
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
        /** フォームの保存領域の名前 */
        optional<StringHolder> moldName;
        /** 現在のキャパシティ */
        optional<Int32> capacity;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            moldName(data.moldName),
            capacity(data.capacity),
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
    SetMoldCapacityByUserIdRequest() = default;
    SetMoldCapacityByUserIdRequest(const SetMoldCapacityByUserIdRequest& setMoldCapacityByUserIdRequest) = default;
    SetMoldCapacityByUserIdRequest(SetMoldCapacityByUserIdRequest&& setMoldCapacityByUserIdRequest) = default;
    ~SetMoldCapacityByUserIdRequest() GS2_OVERRIDE = default;

    SetMoldCapacityByUserIdRequest& operator=(const SetMoldCapacityByUserIdRequest& setMoldCapacityByUserIdRequest) = default;
    SetMoldCapacityByUserIdRequest& operator=(SetMoldCapacityByUserIdRequest&& setMoldCapacityByUserIdRequest) = default;

    SetMoldCapacityByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SetMoldCapacityByUserIdRequest);
    }

    const SetMoldCapacityByUserIdRequest* operator->() const
    {
        return this;
    }

    SetMoldCapacityByUserIdRequest* operator->()
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
    SetMoldCapacityByUserIdRequest& withNamespaceName(StringHolder namespaceName)
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
    SetMoldCapacityByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * フォームの保存領域の名前を取得
     *
     * @return フォームの保存領域の名前
     */
    const optional<StringHolder>& getMoldName() const
    {
        return ensureData().moldName;
    }

    /**
     * フォームの保存領域の名前を設定
     *
     * @param moldName フォームの保存領域の名前
     */
    void setMoldName(StringHolder moldName)
    {
        ensureData().moldName.emplace(std::move(moldName));
    }

    /**
     * フォームの保存領域の名前を設定
     *
     * @param moldName フォームの保存領域の名前
     */
    SetMoldCapacityByUserIdRequest& withMoldName(StringHolder moldName)
    {
        ensureData().moldName.emplace(std::move(moldName));
        return *this;
    }

    /**
     * 現在のキャパシティを取得
     *
     * @return 現在のキャパシティ
     */
    const optional<Int32>& getCapacity() const
    {
        return ensureData().capacity;
    }

    /**
     * 現在のキャパシティを設定
     *
     * @param capacity 現在のキャパシティ
     */
    void setCapacity(Int32 capacity)
    {
        ensureData().capacity.emplace(capacity);
    }

    /**
     * 現在のキャパシティを設定
     *
     * @param capacity 現在のキャパシティ
     */
    SetMoldCapacityByUserIdRequest& withCapacity(Int32 capacity)
    {
        ensureData().capacity.emplace(capacity);
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
    SetMoldCapacityByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    SetMoldCapacityByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetMoldCapacityByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FORMATION_CONTROL_SETMOLDCAPACITYBYUSERIDREQUEST_HPP_