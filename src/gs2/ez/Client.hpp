/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#ifndef GS2_EZ_CLIENT_HPP_
#define GS2_EZ_CLIENT_HPP_

#include "../core/Gs2Object.hpp"
#include "account/Client.hpp"
#include "auth/Client.hpp"
#include "chat/Client.hpp"
#include "datastore/Client.hpp"
#include "distributor/Client.hpp"
#include "exchange/Client.hpp"
#include "experience/Client.hpp"
#include "formation/Client.hpp"
#include "friend/Client.hpp"
#include "gateway/Client.hpp"
#include "inbox/Client.hpp"
#include "inventory/Client.hpp"
#include "jobQueue/Client.hpp"
#include "limit/Client.hpp"
#include "lock/Client.hpp"
#include "lottery/Client.hpp"
#include "matchmaking/Client.hpp"
#include "mission/Client.hpp"
#include "money/Client.hpp"
#include "news/Client.hpp"
#include "quest/Client.hpp"
#include "ranking/Client.hpp"
#include "realtime/Client.hpp"
#include "schedule/Client.hpp"
#include "showcase/Client.hpp"
#include "stamina/Client.hpp"
#include "version/Client.hpp"

namespace gs2 { namespace ez {

class Client : public gs2::Gs2Object
{
public:
    account::Client account;
    auth::Client auth;
    chat::Client chat;
    datastore::Client datastore;
    distributor::Client distributor;
    exchange::Client exchange;
    experience::Client experience;
    formation::Client formation;
    friend_::Client friend_;
    gateway::Client gateway;
    inbox::Client inbox;
    inventory::Client inventory;
    jobQueue::Client jobQueue;
    limit::Client limit;
    lock::Client lock;
    lottery::Client lottery;
    matchmaking::Client matchmaking;
    mission::Client mission;
    money::Client money;
    news::Client news;
    quest::Client quest;
    ranking::Client ranking;
    realtime::Client realtime;
    schedule::Client schedule;
    showcase::Client showcase;
    stamina::Client stamina;
    version::Client version;

public:
    Client(Profile& profile) :
        account(profile),
        auth(profile),
        chat(profile),
        datastore(profile),
        distributor(profile),
        exchange(profile),
        experience(profile),
        formation(profile),
        friend_(profile),
        gateway(profile),
        inbox(profile),
        inventory(profile),
        jobQueue(profile),
        limit(profile),
        lock(profile),
        lottery(profile),
        matchmaking(profile),
        mission(profile),
        money(profile),
        news(profile),
        quest(profile),
        ranking(profile),
        realtime(profile),
        schedule(profile),
        showcase(profile),
        stamina(profile),
        version(profile)
    {}
};

}}

#endif //GS2_EZ_CLIENT_HPP_
