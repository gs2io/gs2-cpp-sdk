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

#ifndef GS2_DICTIONARY_CONTROL_DELETEENTRYMODELMASTERREQUEST_HPP_
#define GS2_DICTIONARY_CONTROL_DELETEENTRYMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/dictionary/Gs2DictionaryConst.hpp>
#include <gs2/dictionary/model/model.hpp>
#include <memory>

namespace gs2 { namespace dictionary
{

/**
 * エントリーモデルマスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteEntryModelMasterRequest : public Gs2BasicRequest, public Gs2Dictionary
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** エントリーモデル名 */
        optional<StringHolder> entryName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            entryName(data.entryName)
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
    DeleteEntryModelMasterRequest() = default;
    DeleteEntryModelMasterRequest(const DeleteEntryModelMasterRequest& deleteEntryModelMasterRequest) = default;
    DeleteEntryModelMasterRequest(DeleteEntryModelMasterRequest&& deleteEntryModelMasterRequest) = default;
    ~DeleteEntryModelMasterRequest() GS2_OVERRIDE = default;

    DeleteEntryModelMasterRequest& operator=(const DeleteEntryModelMasterRequest& deleteEntryModelMasterRequest) = default;
    DeleteEntryModelMasterRequest& operator=(DeleteEntryModelMasterRequest&& deleteEntryModelMasterRequest) = default;

    DeleteEntryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteEntryModelMasterRequest);
    }

    const DeleteEntryModelMasterRequest* operator->() const
    {
        return this;
    }

    DeleteEntryModelMasterRequest* operator->()
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
    DeleteEntryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * エントリーモデル名を取得
     *
     * @return エントリーモデル名
     */
    const optional<StringHolder>& getEntryName() const
    {
        return ensureData().entryName;
    }

    /**
     * エントリーモデル名を設定
     *
     * @param entryName エントリーモデル名
     */
    void setEntryName(StringHolder entryName)
    {
        ensureData().entryName.emplace(std::move(entryName));
    }

    /**
     * エントリーモデル名を設定
     *
     * @param entryName エントリーモデル名
     */
    DeleteEntryModelMasterRequest& withEntryName(StringHolder entryName)
    {
        ensureData().entryName.emplace(std::move(entryName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteEntryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteEntryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DICTIONARY_CONTROL_DELETEENTRYMODELMASTERREQUEST_HPP_