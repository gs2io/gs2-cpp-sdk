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

#ifndef GS2_EZ_DICTIONARY_EZGETENTRYWITHSIGNATURERESULT_HPP_
#define GS2_EZ_DICTIONARY_EZGETENTRYWITHSIGNATURERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/dictionary/result/GetEntryWithSignatureResult.hpp>


namespace gs2 { namespace ez { namespace dictionary {

class EzGetEntryWithSignatureResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** エントリー */
        EzEntry item;
        /** 署名対象のエントリー情報 */
        StringHolder body;
        /** 署名 */
        StringHolder signature;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            body(data.body),
            signature(data.signature)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::dictionary::GetEntryWithSignatureResult& getEntryWithSignatureResult) :
            item(*getEntryWithSignatureResult.getItem()),
            body(*getEntryWithSignatureResult.getBody()),
            signature(*getEntryWithSignatureResult.getSignature())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetEntryWithSignatureResult() = default;
    EzGetEntryWithSignatureResult(const EzGetEntryWithSignatureResult& result) = default;
    EzGetEntryWithSignatureResult(EzGetEntryWithSignatureResult&& result) = default;
    ~EzGetEntryWithSignatureResult() = default;

    EzGetEntryWithSignatureResult(gs2::dictionary::GetEntryWithSignatureResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetEntryWithSignatureResult& operator=(const EzGetEntryWithSignatureResult& result) = default;
    EzGetEntryWithSignatureResult& operator=(EzGetEntryWithSignatureResult&& result) = default;

    EzGetEntryWithSignatureResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetEntryWithSignatureResult);
    }

    static bool isConvertible(const gs2::dictionary::GetEntryWithSignatureResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getBody().has_value() &&
            result.getSignature().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzEntry& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getBody() const
    {
        return ensureData().body;
    }

    const StringHolder& getSignature() const
    {
        return ensureData().signature;
    }
};

typedef gs2::AsyncResult<EzGetEntryWithSignatureResult> AsyncEzGetEntryWithSignatureResult;

}}}

#endif //GS2_EZ_DICTIONARY_EZGETENTRYWITHSIGNATURERESULT_HPP_