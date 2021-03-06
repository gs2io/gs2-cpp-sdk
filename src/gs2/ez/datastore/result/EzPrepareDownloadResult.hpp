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

#ifndef GS2_EZ_DATASTORE_EZPREPAREDOWNLOADRESULT_HPP_
#define GS2_EZ_DATASTORE_EZPREPAREDOWNLOADRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/datastore/result/PrepareDownloadResult.hpp>


namespace gs2 { namespace ez { namespace datastore {

class EzPrepareDownloadResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** データオブジェクト */
        EzDataObject item;
        /** ファイルをダウンロードするためのURL */
        StringHolder fileUrl;
        /** ファイルの容量 */
        Int64 contentLength;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            fileUrl(data.fileUrl),
            contentLength(data.contentLength)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::datastore::PrepareDownloadResult& prepareDownloadResult) :
            item(*prepareDownloadResult.getItem()),
            fileUrl(*prepareDownloadResult.getFileUrl()),
            contentLength(*prepareDownloadResult.getContentLength())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzPrepareDownloadResult() = default;
    EzPrepareDownloadResult(const EzPrepareDownloadResult& result) = default;
    EzPrepareDownloadResult(EzPrepareDownloadResult&& result) = default;
    ~EzPrepareDownloadResult() = default;

    EzPrepareDownloadResult(gs2::datastore::PrepareDownloadResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzPrepareDownloadResult& operator=(const EzPrepareDownloadResult& result) = default;
    EzPrepareDownloadResult& operator=(EzPrepareDownloadResult&& result) = default;

    EzPrepareDownloadResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzPrepareDownloadResult);
    }

    static bool isConvertible(const gs2::datastore::PrepareDownloadResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getFileUrl().has_value() &&
            result.getContentLength().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzDataObject& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getFileUrl() const
    {
        return ensureData().fileUrl;
    }

    Int64 getContentLength() const
    {
        return ensureData().contentLength;
    }
};

typedef gs2::AsyncResult<EzPrepareDownloadResult> AsyncEzPrepareDownloadResult;

}}}

#endif //GS2_EZ_DATASTORE_EZPREPAREDOWNLOADRESULT_HPP_