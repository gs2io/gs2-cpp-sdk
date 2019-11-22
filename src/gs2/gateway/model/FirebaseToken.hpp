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

#ifndef GS2_GATEWAY_MODEL_FIREBASETOKEN_HPP_
#define GS2_GATEWAY_MODEL_FIREBASETOKEN_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace gateway {

/**
 * Firebaseデバイストークン
 *
 * @author Game Server Services, Inc.
 *
 */
class FirebaseToken : public Gs2Object
{
    friend bool operator!=(const FirebaseToken& lhs, const FirebaseToken& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** Firebaseデバイストークン のGRN */
        optional<StringHolder> firebaseTokenId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** Firebase Cloud Messaging のデバイストークン */
        optional<StringHolder> token;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    FirebaseToken() = default;
    FirebaseToken(const FirebaseToken& firebaseToken) = default;
    FirebaseToken(FirebaseToken&& firebaseToken) = default;
    ~FirebaseToken() = default;

    FirebaseToken& operator=(const FirebaseToken& firebaseToken) = default;
    FirebaseToken& operator=(FirebaseToken&& firebaseToken) = default;

    FirebaseToken deepCopy() const;

    const FirebaseToken* operator->() const
    {
        return this;
    }

    FirebaseToken* operator->()
    {
        return this;
    }
    /**
     * Firebaseデバイストークン のGRNを取得
     *
     * @return Firebaseデバイストークン のGRN
     */
    const optional<StringHolder>& getFirebaseTokenId() const
    {
        return ensureData().firebaseTokenId;
    }

    /**
     * Firebaseデバイストークン のGRNを設定
     *
     * @param firebaseTokenId Firebaseデバイストークン のGRN
     */
    void setFirebaseTokenId(StringHolder firebaseTokenId)
    {
        ensureData().firebaseTokenId.emplace(std::move(firebaseTokenId));
    }

    /**
     * Firebaseデバイストークン のGRNを設定
     *
     * @param firebaseTokenId Firebaseデバイストークン のGRN
     */
    FirebaseToken& withFirebaseTokenId(StringHolder firebaseTokenId)
    {
        setFirebaseTokenId(std::move(firebaseTokenId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    FirebaseToken& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
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
    FirebaseToken& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * Firebase Cloud Messaging のデバイストークンを取得
     *
     * @return Firebase Cloud Messaging のデバイストークン
     */
    const optional<StringHolder>& getToken() const
    {
        return ensureData().token;
    }

    /**
     * Firebase Cloud Messaging のデバイストークンを設定
     *
     * @param token Firebase Cloud Messaging のデバイストークン
     */
    void setToken(StringHolder token)
    {
        ensureData().token.emplace(std::move(token));
    }

    /**
     * Firebase Cloud Messaging のデバイストークンを設定
     *
     * @param token Firebase Cloud Messaging のデバイストークン
     */
    FirebaseToken& withToken(StringHolder token)
    {
        setToken(std::move(token));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    FirebaseToken& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    FirebaseToken& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const FirebaseToken& lhs, const FirebaseToken& lhr);

inline bool operator==(const FirebaseToken& lhs, const FirebaseToken& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_GATEWAY_MODEL_FIREBASETOKEN_HPP_