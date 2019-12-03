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

#ifndef GS2_FORMATION_CONTROL_SETFORMWITHSIGNATUREREQUEST_HPP_
#define GS2_FORMATION_CONTROL_SETFORMWITHSIGNATUREREQUEST_HPP_

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
 * 署名付きスロットを使ってフォームを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SetFormWithSignatureRequest : public Gs2BasicRequest, public Gs2Formation
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** フォームの保存領域の名前 */
        optional<StringHolder> moldName;
        /** 保存領域のインデックス */
        optional<Int32> index;
        /** 編成するスロットのリスト */
        optional<List<SlotWithSignature>> slots;
        /** 署名の発行に使用した GS2-Key の暗号鍵GRN */
        optional<StringHolder> keyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            moldName(data.moldName),
            index(data.index),
            keyId(data.keyId),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.slots)
            {
                slots = data.slots->deepCopy();
            }
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
    SetFormWithSignatureRequest() = default;
    SetFormWithSignatureRequest(const SetFormWithSignatureRequest& setFormWithSignatureRequest) = default;
    SetFormWithSignatureRequest(SetFormWithSignatureRequest&& setFormWithSignatureRequest) = default;
    ~SetFormWithSignatureRequest() GS2_OVERRIDE = default;

    SetFormWithSignatureRequest& operator=(const SetFormWithSignatureRequest& setFormWithSignatureRequest) = default;
    SetFormWithSignatureRequest& operator=(SetFormWithSignatureRequest&& setFormWithSignatureRequest) = default;

    SetFormWithSignatureRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SetFormWithSignatureRequest);
    }

    const SetFormWithSignatureRequest* operator->() const
    {
        return this;
    }

    SetFormWithSignatureRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    SetFormWithSignatureRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    SetFormWithSignatureRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    SetFormWithSignatureRequest& withMoldName(StringHolder moldName)
    {
        ensureData().moldName.emplace(std::move(moldName));
        return *this;
    }

    /**
     * 保存領域のインデックスを取得
     *
     * @return 保存領域のインデックス
     */
    const optional<Int32>& getIndex() const
    {
        return ensureData().index;
    }

    /**
     * 保存領域のインデックスを設定
     *
     * @param index 保存領域のインデックス
     */
    void setIndex(Int32 index)
    {
        ensureData().index.emplace(index);
    }

    /**
     * 保存領域のインデックスを設定
     *
     * @param index 保存領域のインデックス
     */
    SetFormWithSignatureRequest& withIndex(Int32 index)
    {
        ensureData().index.emplace(index);
        return *this;
    }

    /**
     * 編成するスロットのリストを取得
     *
     * @return 編成するスロットのリスト
     */
    const optional<List<SlotWithSignature>>& getSlots() const
    {
        return ensureData().slots;
    }

    /**
     * 編成するスロットのリストを設定
     *
     * @param slots 編成するスロットのリスト
     */
    void setSlots(List<SlotWithSignature> slots)
    {
        ensureData().slots.emplace(std::move(slots));
    }

    /**
     * 編成するスロットのリストを設定
     *
     * @param slots 編成するスロットのリスト
     */
    SetFormWithSignatureRequest& withSlots(List<SlotWithSignature> slots)
    {
        ensureData().slots.emplace(std::move(slots));
        return *this;
    }

    /**
     * 署名の発行に使用した GS2-Key の暗号鍵GRNを取得
     *
     * @return 署名の発行に使用した GS2-Key の暗号鍵GRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 署名の発行に使用した GS2-Key の暗号鍵GRNを設定
     *
     * @param keyId 署名の発行に使用した GS2-Key の暗号鍵GRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 署名の発行に使用した GS2-Key の暗号鍵GRNを設定
     *
     * @param keyId 署名の発行に使用した GS2-Key の暗号鍵GRN
     */
    SetFormWithSignatureRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
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
    SetFormWithSignatureRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    SetFormWithSignatureRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetFormWithSignatureRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FORMATION_CONTROL_SETFORMWITHSIGNATUREREQUEST_HPP_