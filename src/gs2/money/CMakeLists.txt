# Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
# Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License").
# You may not use this file except in compliance with the License.
# A copy of the License is located at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# or in the "license" file accompanying this file. This file is distributed
# on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied. See the License for the specific language governing
# permissions and limitations under the License.

cmake_minimum_required(VERSION 3.2)
project(gs2-cpp-sdk-money)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Money.hpp
        Gs2MoneyConst.hpp
        Gs2MoneyRestClient.hpp
        Gs2MoneyWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Wallet.hpp
        model/WalletDetail.hpp
        model/Receipt.hpp
        model/ResponseCache.hpp
        model/ScriptSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeWalletsRequest.hpp
        request/DescribeWalletsByUserIdRequest.hpp
        request/QueryWalletsRequest.hpp
        request/GetWalletRequest.hpp
        request/GetWalletByUserIdRequest.hpp
        request/DepositByUserIdRequest.hpp
        request/WithdrawRequest.hpp
        request/WithdrawByUserIdRequest.hpp
        request/DepositByStampSheetRequest.hpp
        request/WithdrawByStampTaskRequest.hpp
        request/DescribeWalletDetailsByUserIdRequest.hpp
        request/DescribeReceiptsRequest.hpp
        request/GetByUserIdAndTransactionIdRequest.hpp
        request/RecordReceiptRequest.hpp
        request/RecordReceiptByStampTaskRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeWalletsResult.hpp
        result/DescribeWalletsByUserIdResult.hpp
        result/QueryWalletsResult.hpp
        result/GetWalletResult.hpp
        result/GetWalletByUserIdResult.hpp
        result/DepositByUserIdResult.hpp
        result/WithdrawResult.hpp
        result/WithdrawByUserIdResult.hpp
        result/DepositByStampSheetResult.hpp
        result/WithdrawByStampTaskResult.hpp
        result/DescribeWalletDetailsByUserIdResult.hpp
        result/DescribeReceiptsResult.hpp
        result/GetByUserIdAndTransactionIdResult.hpp
        result/RecordReceiptResult.hpp
        result/RecordReceiptByStampTaskResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2MoneyRestClient.cpp
        Gs2MoneyWebSocketClient.cpp
        model/Namespace.cpp
        model/Wallet.cpp
        model/WalletDetail.cpp
        model/Receipt.cpp
        model/ResponseCache.cpp
        model/ScriptSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeWalletsResult.cpp
        result/DescribeWalletsByUserIdResult.cpp
        result/QueryWalletsResult.cpp
        result/GetWalletResult.cpp
        result/GetWalletByUserIdResult.cpp
        result/DepositByUserIdResult.cpp
        result/WithdrawResult.cpp
        result/WithdrawByUserIdResult.cpp
        result/DepositByStampSheetResult.cpp
        result/WithdrawByStampTaskResult.cpp
        result/DescribeWalletDetailsByUserIdResult.cpp
        result/DescribeReceiptsResult.cpp
        result/GetByUserIdAndTransactionIdResult.cpp
        result/RecordReceiptResult.cpp
        result/RecordReceiptByStampTaskResult.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-core)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )