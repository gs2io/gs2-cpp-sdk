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

void Client::listInventoryModels(
    std::function<void(AsyncEzListInventoryModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::inventory::DescribeInventoryModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_Client.describeInventoryModels(
        request,
        [callback](gs2::inventory::AsyncDescribeInventoryModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListInventoryModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListInventoryModelsResult::isConvertible(*r.getResult()))
            {
                EzListInventoryModelsResult ezResult(*r.getResult());
                AsyncEzListInventoryModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListInventoryModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getInventoryModel(
    std::function<void(AsyncEzGetInventoryModelResult)> callback,
    StringHolder namespaceName,
    StringHolder inventoryName
)
{
    gs2::inventory::GetInventoryModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    m_Client.getInventoryModel(
        request,
        [callback](gs2::inventory::AsyncGetInventoryModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetInventoryModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetInventoryModelResult::isConvertible(*r.getResult()))
            {
                EzGetInventoryModelResult ezResult(*r.getResult());
                AsyncEzGetInventoryModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetInventoryModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listItemModels(
    std::function<void(AsyncEzListItemModelsResult)> callback,
    StringHolder namespaceName,
    StringHolder inventoryName
)
{
    gs2::inventory::DescribeItemModelsRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    m_Client.describeItemModels(
        request,
        [callback](gs2::inventory::AsyncDescribeItemModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListItemModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListItemModelsResult::isConvertible(*r.getResult()))
            {
                EzListItemModelsResult ezResult(*r.getResult());
                AsyncEzListItemModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListItemModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getItemModel(
    std::function<void(AsyncEzGetItemModelResult)> callback,
    StringHolder namespaceName,
    StringHolder inventoryName,
    StringHolder itemName
)
{
    gs2::inventory::GetItemModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    request.setItemName(itemName);
    m_Client.getItemModel(
        request,
        [callback](gs2::inventory::AsyncGetItemModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetItemModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetItemModelResult::isConvertible(*r.getResult()))
            {
                EzGetItemModelResult ezResult(*r.getResult());
                AsyncEzGetItemModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetItemModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listInventories(
    std::function<void(AsyncEzListInventoriesResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::inventory::DescribeInventoriesRequest request;
    request.setNamespaceName(namespaceName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeInventories(
        request,
        [callback](gs2::inventory::AsyncDescribeInventoriesResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListInventoriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListInventoriesResult::isConvertible(*r.getResult()))
            {
                EzListInventoriesResult ezResult(*r.getResult());
                AsyncEzListInventoriesResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListInventoriesResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getInventory(
    std::function<void(AsyncEzGetInventoryResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder inventoryName
)
{
    gs2::inventory::GetInventoryRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getInventory(
        request,
        [callback](gs2::inventory::AsyncGetInventoryResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetInventoryResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetInventoryResult::isConvertible(*r.getResult()))
            {
                EzGetInventoryResult ezResult(*r.getResult());
                AsyncEzGetInventoryResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetInventoryResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listItems(
    std::function<void(AsyncEzListItemsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder inventoryName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::inventory::DescribeItemSetsRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.describeItemSets(
        request,
        [callback](gs2::inventory::AsyncDescribeItemSetsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListItemsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListItemsResult::isConvertible(*r.getResult()))
            {
                EzListItemsResult ezResult(*r.getResult());
                AsyncEzListItemsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListItemsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getItem(
    std::function<void(AsyncEzGetItemResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder inventoryName,
    StringHolder itemName
)
{
    gs2::inventory::GetItemSetRequest request;
    request.setNamespaceName(namespaceName);
    request.setInventoryName(inventoryName);
    request.setItemName(itemName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_Client.getItemSet(
        request,
        [callback](gs2::inventory::AsyncGetItemSetResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetItemResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetItemResult::isConvertible(*r.getResult()))
            {
                EzGetItemResult ezResult(*r.getResult());
                AsyncEzGetItemResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetItemResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::consume(
    std::function<void(AsyncEzConsumeResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder inventoryName,
    StringHolder itemName,
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
        [callback](gs2::inventory::AsyncConsumeItemSetResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzConsumeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzConsumeResult::isConvertible(*r.getResult()))
            {
                EzConsumeResult ezResult(*r.getResult());
                AsyncEzConsumeResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzConsumeResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}