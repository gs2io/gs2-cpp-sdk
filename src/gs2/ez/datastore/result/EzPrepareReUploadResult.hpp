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

#ifndef GS2_EZ_DATASTORE_EZPREPAREREUPLOADRESULT_HPP_
#define GS2_EZ_DATASTORE_EZPREPAREREUPLOADRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/datastore/result/PrepareReUploadResult.hpp>


namespace gs2 { namespace ez { namespace datastore {

class EzPrepareReUploadResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** データオブジェクト */
        EzDataObject item;
        /** アップロード処理の実行に使用するURL */
        StringHolder uploadUrl;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            uploadUrl(data.uploadUrl)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::datastore::PrepareReUploadResult& prepareReUploadResult) :
            item(*prepareReUploadResult.getItem()),
            uploadUrl(*prepareReUploadResult.getUploadUrl())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzPrepareReUploadResult() = default;
    EzPrepareReUploadResult(const EzPrepareReUploadResult& result) = default;
    EzPrepareReUploadResult(EzPrepareReUploadResult&& result) = default;
    ~EzPrepareReUploadResult() = default;

    EzPrepareReUploadResult(gs2::datastore::PrepareReUploadResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzPrepareReUploadResult& operator=(const EzPrepareReUploadResult& result) = default;
    EzPrepareReUploadResult& operator=(EzPrepareReUploadResult&& result) = default;

    EzPrepareReUploadResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzPrepareReUploadResult);
    }

    static bool isConvertible(const gs2::datastore::PrepareReUploadResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getUploadUrl().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzDataObject& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getUploadUrl() const
    {
        return ensureData().uploadUrl;
    }
};

typedef gs2::AsyncResult<EzPrepareReUploadResult> AsyncEzPrepareReUploadResult;

}}}

#endif //GS2_EZ_DATASTORE_EZPREPAREREUPLOADRESULT_HPP_