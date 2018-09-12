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

#include "Gs2Constant.hpp"

GS2_START_OF_NAMESPACE

const Int32 Gs2Constant::REQUEST_VALID_TIME_RANGE = 60 * 5;

const Int32 Gs2Constant::RETRY_NUM = 3;

const Int32 Gs2Constant::RETRY_WAIT = 1000;

const Char* Gs2Constant::ENDPOINT_HOST = "https://{service}.{region}.gs2io.com";

GS2_END_OF_NAMESPACE