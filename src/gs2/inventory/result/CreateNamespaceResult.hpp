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

#ifndef GS2_INVENTORY_CONTROL_CREATENAMESPACERESULT_HPP_
#define GS2_INVENTORY_CONTROL_CREATENAMESPACERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inventory/model/model.hpp>
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * ネームスペースを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateNamespaceResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したネームスペース */
        optional<Namespace> item;

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
    CreateNamespaceResult() = default;
    CreateNamespaceResult(const CreateNamespaceResult& createNamespaceResult) = default;
    CreateNamespaceResult(CreateNamespaceResult&& createNamespaceResult) = default;
    ~CreateNamespaceResult() = default;

    CreateNamespaceResult& operator=(const CreateNamespaceResult& createNamespaceResult) = default;
    CreateNamespaceResult& operator=(CreateNamespaceResult&& createNamespaceResult) = default;

    CreateNamespaceResult deepCopy() const;

    const CreateNamespaceResult* operator->() const
    {
        return this;
    }

    CreateNamespaceResult* operator->()
    {
        return this;
    }
    /**
     * 作成したネームスペースを取得
     *
     * @return 作成したネームスペース
     */
    const optional<Namespace>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したネームスペースを設定
     *
     * @param item 作成したネームスペース
     */
    void setItem(Namespace item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;

} }

#endif //GS2_INVENTORY_CONTROL_CREATENAMESPACERESULT_HPP_