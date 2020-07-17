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
#include <gs2/formation/Gs2FormationWebSocketClient.hpp>


namespace gs2 { namespace ez { namespace formation {

Client::Client(gs2::ez::Profile& profile) :
    m_Profile(profile),
    m_pClient(new gs2::formation::Gs2FormationWebSocketClient(profile.getGs2Session()))
{
}

Client::~Client()
{
    delete m_pClient;
}

void Client::listMoldModels(
    std::function<void(AsyncEzListMoldModelsResult)> callback,
    StringHolder namespaceName
)
{
    gs2::formation::DescribeMoldModelsRequest request;
    request.setNamespaceName(namespaceName);
    m_pClient->describeMoldModels(
        request,
        [callback](gs2::formation::AsyncDescribeMoldModelsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMoldModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListMoldModelsResult::isConvertible(*r.getResult()))
            {
                EzListMoldModelsResult ezResult(*r.getResult());
                AsyncEzListMoldModelsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListMoldModelsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getMoldModel(
    std::function<void(AsyncEzGetMoldModelResult)> callback,
    StringHolder namespaceName,
    StringHolder moldName
)
{
    gs2::formation::GetMoldModelRequest request;
    request.setNamespaceName(namespaceName);
    request.setMoldName(moldName);
    m_pClient->getMoldModel(
        request,
        [callback](gs2::formation::AsyncGetMoldModelResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetMoldModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetMoldModelResult::isConvertible(*r.getResult()))
            {
                EzGetMoldModelResult ezResult(*r.getResult());
                AsyncEzGetMoldModelResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetMoldModelResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listMolds(
    std::function<void(AsyncEzListMoldsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::formation::DescribeMoldsRequest request;
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
    m_pClient->describeMolds(
        request,
        [callback](gs2::formation::AsyncDescribeMoldsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListMoldsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListMoldsResult::isConvertible(*r.getResult()))
            {
                EzListMoldsResult ezResult(*r.getResult());
                AsyncEzListMoldsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListMoldsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getMold(
    std::function<void(AsyncEzGetMoldResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder moldName
)
{
    gs2::formation::GetMoldRequest request;
    request.setNamespaceName(namespaceName);
    request.setMoldName(moldName);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getMold(
        request,
        [callback](gs2::formation::AsyncGetMoldResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetMoldResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetMoldResult::isConvertible(*r.getResult()))
            {
                EzGetMoldResult ezResult(*r.getResult());
                AsyncEzGetMoldResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetMoldResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::listForms(
    std::function<void(AsyncEzListFormsResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    gs2::optional<StringHolder> moldName,
    gs2::optional<StringHolder> pageToken,
    gs2::optional<Int64> limit
)
{
    gs2::formation::DescribeFormsRequest request;
    request.setNamespaceName(namespaceName);
    if (moldName)
    {
        request.setMoldName(std::move(*moldName));
    }
    if (pageToken)
    {
        request.setPageToken(std::move(*pageToken));
    }
    if (limit)
    {
        request.setLimit(std::move(*limit));
    }
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->describeForms(
        request,
        [callback](gs2::formation::AsyncDescribeFormsResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzListFormsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzListFormsResult::isConvertible(*r.getResult()))
            {
                EzListFormsResult ezResult(*r.getResult());
                AsyncEzListFormsResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzListFormsResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getForm(
    std::function<void(AsyncEzGetFormResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder moldName,
    Int32 index
)
{
    gs2::formation::GetFormRequest request;
    request.setNamespaceName(namespaceName);
    request.setMoldName(moldName);
    request.setIndex(index);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getForm(
        request,
        [callback](gs2::formation::AsyncGetFormResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetFormResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetFormResult::isConvertible(*r.getResult()))
            {
                EzGetFormResult ezResult(*r.getResult());
                AsyncEzGetFormResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetFormResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::getFormWithSignature(
    std::function<void(AsyncEzGetFormWithSignatureResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder moldName,
    Int32 index,
    StringHolder keyId
)
{
    gs2::formation::GetFormWithSignatureRequest request;
    request.setNamespaceName(namespaceName);
    request.setMoldName(moldName);
    request.setIndex(index);
    request.setKeyId(keyId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->getFormWithSignature(
        request,
        [callback](gs2::formation::AsyncGetFormWithSignatureResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzGetFormWithSignatureResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzGetFormWithSignatureResult::isConvertible(*r.getResult()))
            {
                EzGetFormWithSignatureResult ezResult(*r.getResult());
                AsyncEzGetFormWithSignatureResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzGetFormWithSignatureResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

void Client::setForm(
    std::function<void(AsyncEzSetFormResult)> callback,
    GameSession& session,
    StringHolder namespaceName,
    StringHolder moldName,
    Int32 index,
    List<EzSlotWithSignature> slots,
    StringHolder keyId
)
{
    gs2::formation::SetFormWithSignatureRequest request;
    request.setNamespaceName(namespaceName);
    request.setMoldName(moldName);
    request.setIndex(index);
    {
        gs2::List<gs2::formation::SlotWithSignature> list;
        for (int i = 0; i < slots.getCount(); ++i)
        {
            list += slots[i].ToModel();
        }
        request.setSlots(list);
    }
    request.setKeyId(keyId);
    request.setAccessToken(*session.getAccessToken()->getToken());
    m_pClient->setFormWithSignature(
        request,
        [callback](gs2::formation::AsyncSetFormWithSignatureResult r)
        {
            if (r.getError())
            {
                auto gs2ClientException = *r.getError();
                AsyncEzSetFormResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
            else if (r.getResult() && EzSetFormResult::isConvertible(*r.getResult()))
            {
                EzSetFormResult ezResult(*r.getResult());
                AsyncEzSetFormResult asyncResult(std::move(ezResult));
                callback(asyncResult);
            }
            else
            {
                Gs2ClientException gs2ClientException;
                gs2ClientException.setType(Gs2ClientException::UnknownException);
                AsyncEzSetFormResult asyncResult(std::move(gs2ClientException));
                callback(asyncResult);
            }
        }
    );
}

}}}