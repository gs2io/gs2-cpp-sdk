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

#ifndef GS2_DATASTORE_CONTROL_RESTOREDATAOBJECTBYUSERIDANDDATAOBJECTNAMERESULT_HPP_
#define GS2_DATASTORE_CONTROL_RESTOREDATAOBJECTBYUSERIDANDDATAOBJECTNAMERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/datastore/model/model.hpp>
#include <memory>

namespace gs2 { namespace datastore
{

/**
 * ユーザIDを指定してデータオブジェクトの管理情報を修復する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RestoreDataObjectByUserIdAndDataObjectNameResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** データオブジェクト */
        optional<DataObject> item;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RestoreDataObjectByUserIdAndDataObjectNameResult() = default;
    RestoreDataObjectByUserIdAndDataObjectNameResult(const RestoreDataObjectByUserIdAndDataObjectNameResult& restoreDataObjectByUserIdAndDataObjectNameResult) = default;
    RestoreDataObjectByUserIdAndDataObjectNameResult(RestoreDataObjectByUserIdAndDataObjectNameResult&& restoreDataObjectByUserIdAndDataObjectNameResult) = default;
    ~RestoreDataObjectByUserIdAndDataObjectNameResult() = default;

    RestoreDataObjectByUserIdAndDataObjectNameResult& operator=(const RestoreDataObjectByUserIdAndDataObjectNameResult& restoreDataObjectByUserIdAndDataObjectNameResult) = default;
    RestoreDataObjectByUserIdAndDataObjectNameResult& operator=(RestoreDataObjectByUserIdAndDataObjectNameResult&& restoreDataObjectByUserIdAndDataObjectNameResult) = default;

    RestoreDataObjectByUserIdAndDataObjectNameResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RestoreDataObjectByUserIdAndDataObjectNameResult);
    }

    const RestoreDataObjectByUserIdAndDataObjectNameResult* operator->() const
    {
        return this;
    }

    RestoreDataObjectByUserIdAndDataObjectNameResult* operator->()
    {
        return this;
    }
    /**
     * データオブジェクトを取得
     *
     * @return データオブジェクト
     */
    const optional<DataObject>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * データオブジェクトを設定
     *
     * @param item データオブジェクト
     */
    void setItem(DataObject item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<RestoreDataObjectByUserIdAndDataObjectNameResult> AsyncRestoreDataObjectByUserIdAndDataObjectNameResult;

} }

#endif //GS2_DATASTORE_CONTROL_RESTOREDATAOBJECTBYUSERIDANDDATAOBJECTNAMERESULT_HPP_