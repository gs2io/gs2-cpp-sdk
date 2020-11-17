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

#ifndef GS2_EZ_DATASTORE_EZRESTOREDATAOBJECTBYUSERIDANDDATAOBJECTNAMERESULT_HPP_
#define GS2_EZ_DATASTORE_EZRESTOREDATAOBJECTBYUSERIDANDDATAOBJECTNAMERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/datastore/result/RestoreDataObjectByUserIdAndDataObjectNameResult.hpp>


namespace gs2 { namespace ez { namespace datastore {

class EzRestoreDataObjectByUserIdAndDataObjectNameResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** データオブジェクト */
        EzDataObject item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::datastore::RestoreDataObjectByUserIdAndDataObjectNameResult& restoreDataObjectByUserIdAndDataObjectNameResult) :
            item(*restoreDataObjectByUserIdAndDataObjectNameResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRestoreDataObjectByUserIdAndDataObjectNameResult() = default;
    EzRestoreDataObjectByUserIdAndDataObjectNameResult(const EzRestoreDataObjectByUserIdAndDataObjectNameResult& result) = default;
    EzRestoreDataObjectByUserIdAndDataObjectNameResult(EzRestoreDataObjectByUserIdAndDataObjectNameResult&& result) = default;
    ~EzRestoreDataObjectByUserIdAndDataObjectNameResult() = default;

    EzRestoreDataObjectByUserIdAndDataObjectNameResult(gs2::datastore::RestoreDataObjectByUserIdAndDataObjectNameResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzRestoreDataObjectByUserIdAndDataObjectNameResult& operator=(const EzRestoreDataObjectByUserIdAndDataObjectNameResult& result) = default;
    EzRestoreDataObjectByUserIdAndDataObjectNameResult& operator=(EzRestoreDataObjectByUserIdAndDataObjectNameResult&& result) = default;

    EzRestoreDataObjectByUserIdAndDataObjectNameResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRestoreDataObjectByUserIdAndDataObjectNameResult);
    }

    static bool isConvertible(const gs2::datastore::RestoreDataObjectByUserIdAndDataObjectNameResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzDataObject& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzRestoreDataObjectByUserIdAndDataObjectNameResult> AsyncEzRestoreDataObjectByUserIdAndDataObjectNameResult;

}}}

#endif //GS2_EZ_DATASTORE_EZRESTOREDATAOBJECTBYUSERIDANDDATAOBJECTNAMERESULT_HPP_