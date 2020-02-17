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

#ifndef GS2_INVENTORY_CONTROL_GETITEMWITHSIGNATUREBYUSERIDRESULT_HPP_
#define GS2_INVENTORY_CONTROL_GETITEMWITHSIGNATUREBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inventory/model/model.hpp>
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * 有効期限ごとのアイテム所持数量を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetItemWithSignatureByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 有効期限毎の{model_name} */
        optional<List<ItemSet>> items;
        /** アイテムモデル */
        optional<ItemModel> itemModel;
        /** インベントリ */
        optional<Inventory> inventory;
        /** 署名対象のアイテムセット情報 */
        optional<StringHolder> body;
        /** 署名 */
        optional<StringHolder> signature;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            body(data.body),
            signature(data.signature)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
            if (data.itemModel)
            {
                itemModel = data.itemModel->deepCopy();
            }
            if (data.inventory)
            {
                inventory = data.inventory->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ItemSet item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "itemModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->itemModel.emplace();
                    detail::json::JsonParser::parse(&this->itemModel->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "inventory") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->inventory.emplace();
                    detail::json::JsonParser::parse(&this->inventory->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "body") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetItemWithSignatureByUserIdResult() = default;
    GetItemWithSignatureByUserIdResult(const GetItemWithSignatureByUserIdResult& getItemWithSignatureByUserIdResult) = default;
    GetItemWithSignatureByUserIdResult(GetItemWithSignatureByUserIdResult&& getItemWithSignatureByUserIdResult) = default;
    ~GetItemWithSignatureByUserIdResult() = default;

    GetItemWithSignatureByUserIdResult& operator=(const GetItemWithSignatureByUserIdResult& getItemWithSignatureByUserIdResult) = default;
    GetItemWithSignatureByUserIdResult& operator=(GetItemWithSignatureByUserIdResult&& getItemWithSignatureByUserIdResult) = default;

    GetItemWithSignatureByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetItemWithSignatureByUserIdResult);
    }

    const GetItemWithSignatureByUserIdResult* operator->() const
    {
        return this;
    }

    GetItemWithSignatureByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 有効期限毎の{model_name}を取得
     *
     * @return 有効期限毎の{model_name}
     */
    const optional<List<ItemSet>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 有効期限毎の{model_name}を設定
     *
     * @param items 有効期限毎の{model_name}
     */
    void setItems(List<ItemSet> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * アイテムモデルを取得
     *
     * @return アイテムモデル
     */
    const optional<ItemModel>& getItemModel() const
    {
        return ensureData().itemModel;
    }

    /**
     * アイテムモデルを設定
     *
     * @param itemModel アイテムモデル
     */
    void setItemModel(ItemModel itemModel)
    {
        ensureData().itemModel.emplace(std::move(itemModel));
    }

    /**
     * インベントリを取得
     *
     * @return インベントリ
     */
    const optional<Inventory>& getInventory() const
    {
        return ensureData().inventory;
    }

    /**
     * インベントリを設定
     *
     * @param inventory インベントリ
     */
    void setInventory(Inventory inventory)
    {
        ensureData().inventory.emplace(std::move(inventory));
    }

    /**
     * 署名対象のアイテムセット情報を取得
     *
     * @return 署名対象のアイテムセット情報
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 署名対象のアイテムセット情報を設定
     *
     * @param body 署名対象のアイテムセット情報
     */
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
    }

    /**
     * 署名を取得
     *
     * @return 署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetItemWithSignatureByUserIdResult> AsyncGetItemWithSignatureByUserIdResult;

} }

#endif //GS2_INVENTORY_CONTROL_GETITEMWITHSIGNATUREBYUSERIDRESULT_HPP_