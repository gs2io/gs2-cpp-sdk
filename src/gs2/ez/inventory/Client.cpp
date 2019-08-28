/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0(the "License").
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

#include "Client.hpp"
#include "../Profile.hpp"
#include "../GameSession.hpp"


namespace gs2 { namespace ez { namespace inventory {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_Client(profile.getGs2Session())
{
}

void Client::ListInventoryModels(
    std::function<void(AsyncEzListInventoryModelsResult&)> callback,
    const Char* namespaceName
)
{
    gs2::inventory::DescribeInventoryModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeInventoryModels(
        request,
        [callback](gs2::inventory::AsyncDescribeInventoryModelsResult& r)
        {
            if (r.getError())
            {
                EzListInventoryModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListInventoryModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListInventoryModelsResult::isConvertible(*r.getResult()))
                {
                    EzListInventoryModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListInventoryModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListInventoryModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListInventoryModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetInventoryModel(
    std::function<void(AsyncEzGetInventoryModelResult&)> callback,
    const Char* namespaceName,
    const Char* inventoryName
)
{
    gs2::inventory::GetInventoryModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    m_Client.getInventoryModel(
        request,
        [callback](gs2::inventory::AsyncGetInventoryModelResult& r)
        {
            if (r.getError())
            {
                EzGetInventoryModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetInventoryModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetInventoryModelResult::isConvertible(*r.getResult()))
                {
                    EzGetInventoryModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetInventoryModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetInventoryModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetInventoryModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListItemModels(
    std::function<void(AsyncEzListItemModelsResult&)> callback,
    const Char* namespaceName,
    const Char* inventoryName
)
{
    gs2::inventory::DescribeItemModelsRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    m_Client.describeItemModels(
        request,
        [callback](gs2::inventory::AsyncDescribeItemModelsResult& r)
        {
            if (r.getError())
            {
                EzListItemModelsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListItemModelsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListItemModelsResult::isConvertible(*r.getResult()))
                {
                    EzListItemModelsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListItemModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListItemModelsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListItemModelsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetItemModel(
    std::function<void(AsyncEzGetItemModelResult&)> callback,
    const Char* namespaceName,
    const Char* inventoryName,
    const Char* itemName
)
{
    gs2::inventory::GetItemModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    request.setItemName(itemName);
    m_Client.getItemModel(
        request,
        [callback](gs2::inventory::AsyncGetItemModelResult& r)
        {
            if (r.getError())
            {
                EzGetItemModelResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetItemModelResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetItemModelResult::isConvertible(*r.getResult()))
                {
                    EzGetItemModelResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetItemModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetItemModelResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetItemModelResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListInventories(
    std::function<void(AsyncEzListInventoriesResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::inventory::DescribeInventoriesRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(pageToken);
    }
    if (limit)
    {
        request.setLimit(*limit);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeInventories(
        request,
        [callback](gs2::inventory::AsyncDescribeInventoriesResult& r)
        {
            if (r.getError())
            {
                EzListInventoriesResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListInventoriesResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListInventoriesResult::isConvertible(*r.getResult()))
                {
                    EzListInventoriesResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListInventoriesResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListInventoriesResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListInventoriesResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetInventory(
    std::function<void(AsyncEzGetInventoryResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* inventoryName
)
{
    gs2::inventory::GetInventoryRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getInventory(
        request,
        [callback](gs2::inventory::AsyncGetInventoryResult& r)
        {
            if (r.getError())
            {
                EzGetInventoryResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetInventoryResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetInventoryResult::isConvertible(*r.getResult()))
                {
                    EzGetInventoryResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetInventoryResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetInventoryResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetInventoryResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::ListItems(
    std::function<void(AsyncEzListItemsResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* inventoryName,
    const Char* pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::inventory::DescribeItemSetsRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    if (pageToken)
    {
        request.setPageToken(pageToken);
    }
    if (limit)
    {
        request.setLimit(*limit);
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeItemSets(
        request,
        [callback](gs2::inventory::AsyncDescribeItemSetsResult& r)
        {
            if (r.getError())
            {
                EzListItemsResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzListItemsResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzListItemsResult::isConvertible(*r.getResult()))
                {
                    EzListItemsResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzListItemsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzListItemsResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzListItemsResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::GetItem(
    std::function<void(AsyncEzGetItemResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* inventoryName,
    const Char* itemName
)
{
    gs2::inventory::GetItemSetRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    request.setItemName(itemName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getItemSet(
        request,
        [callback](gs2::inventory::AsyncGetItemSetResult& r)
        {
            if (r.getError())
            {
                EzGetItemResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzGetItemResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzGetItemResult::isConvertible(*r.getResult()))
                {
                    EzGetItemResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzGetItemResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzGetItemResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzGetItemResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

void Client::Consume(
    std::function<void(AsyncEzConsumeResult&)> callback,
    GameSession& session,
    const Char* namespaceName,
    const Char* inventoryName,
    const Char* itemName,
    Int64 consumeCount
)
{
    gs2::inventory::ConsumeItemSetRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    request.setItemName(itemName);
    request.setConsumeCount(consumeCount);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.consumeItemSet(
        request,
        [callback](gs2::inventory::AsyncConsumeItemSetResult& r)
        {
            if (r.getError())
            {
                EzConsumeResult ezResult(*r.getResult());
                auto gs2ClientException = r.getError();
                gs2::AsyncResult<EzConsumeResult> asyncResult(ezResult, gs2ClientException);
                callback(asyncResult);
            }
            else
            {
                optional<Gs2ClientException> gs2ClientException;
                if (r.getResult() && EzConsumeResult::isConvertible(*r.getResult()))
                {
                    EzConsumeResult ezResult(*r.getResult());
                    gs2::AsyncResult<EzConsumeResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
                else
                {
                    EzConsumeResult ezResult(*r.getResult());
                    gs2ClientException.emplace();
                    gs2ClientException->setType(Gs2ClientException::UnknownException);
                    gs2::AsyncResult<EzConsumeResult> asyncResult(ezResult, gs2ClientException);
                    callback(asyncResult);
                }
            }
        }
    );
}

}}}