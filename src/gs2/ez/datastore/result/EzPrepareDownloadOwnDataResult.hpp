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

#ifndef GS2_EZ_DATASTORE_EZPREPAREDOWNLOADOWNDATARESULT_HPP_
#define GS2_EZ_DATASTORE_EZPREPAREDOWNLOADOWNDATARESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/datastore/result/PrepareDownloadOwnDataResult.hpp>


namespace gs2 { namespace ez { namespace datastore {

class EzPrepareDownloadOwnDataResult : public gs2::Gs2Object
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

        Data(const gs2::datastore::PrepareDownloadOwnDataResult& prepareDownloadOwnDataResult) :
            item(*prepareDownloadOwnDataResult.getItem()),
            fileUrl(*prepareDownloadOwnDataResult.getFileUrl()),
            contentLength(*prepareDownloadOwnDataResult.getContentLength())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzPrepareDownloadOwnDataResult() = default;
    EzPrepareDownloadOwnDataResult(const EzPrepareDownloadOwnDataResult& result) = default;
    EzPrepareDownloadOwnDataResult(EzPrepareDownloadOwnDataResult&& result) = default;
    ~EzPrepareDownloadOwnDataResult() = default;

    EzPrepareDownloadOwnDataResult(gs2::datastore::PrepareDownloadOwnDataResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzPrepareDownloadOwnDataResult& operator=(const EzPrepareDownloadOwnDataResult& result) = default;
    EzPrepareDownloadOwnDataResult& operator=(EzPrepareDownloadOwnDataResult&& result) = default;

    EzPrepareDownloadOwnDataResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzPrepareDownloadOwnDataResult);
    }

    static bool isConvertible(const gs2::datastore::PrepareDownloadOwnDataResult& result)
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

typedef gs2::AsyncResult<EzPrepareDownloadOwnDataResult> AsyncEzPrepareDownloadOwnDataResult;

}}}

#endif //GS2_EZ_DATASTORE_EZPREPAREDOWNLOADOWNDATARESULT_HPP_