#ifndef LAN_4GATELIBRARYCPP_FIELDRANGECHECKER_H
#define LAN_4GATELIBRARYCPP_FIELDRANGECHECKER_H

#include <string>
#include <cstdint>

#include "Lanter/Message/OperationCode.h"

namespace Lanter {
    namespace Utils {
        bool checkEcrNumberRange(int16_t ecrNumber);
        bool checkEcrMerchantNumberRange(int16_t ecrMerchantNumber);
        bool checkOperationCodeRange(int32_t operationCode);
        bool checkAmountRange(int64_t amount);
        bool checkCurrencyCodeRange(const std::string &currencyCode);
        bool checkRRNRange(const std::string & RRN);
        bool checkAuthCodeRange(const std::string & authCode);
        bool checkReceiptReferenceRange(const std::string & receiptReference);
        bool checkTransactionIDRange(const std::string & transactionID);
        bool checkCardDataEncRange(const std::string & cardDataEnc);
        bool checkOpenTagsRange(const std::string & openTags);
        bool checkEncTagsRange(const std::string & encTags);
        bool checkHashCardTrack2(const std::string &hashCardTrack2);
        bool checkProviderCodeRange(const std::string & providerCode);
        bool checkAdditionalInfoRange(const std::string & additionalInfo);
        bool checkAdditionalChoiceRange(const std::string & additionalChoice);
        bool checkStatusRange(int32_t status);
        bool checkTransDateTimeRange(const std::string & dateTime);
        bool checkTerminalDateTimeRange(const std::string & dateTime);
        bool checkCardPANRange(const std::string & cardPAN);
        bool checkExpireDateRange(const std::string & expireDate);
        bool checkCardholderNameRange(const std::string & cardholderName);
        bool checkCardholderAuthMethodRange(int32_t cardholderAuthMethod);
        bool checkResponseCodeRange(const std::string & responseCode);
        bool checkResponseTextRange(const std::string & responseText);
        bool checkSTANRange(const std::string & STAN);
        bool checkTerminalIDRange(const std::string & terminalID);
        bool checkCardEmvAidRange(const std::string & emvAID);
        bool checkCardAppNameRange(const std::string & cardAppName);
        bool checkCardInputMethodRange(int32_t cardInputMethod);
        bool checkIssuerNameRange(const std::string & issuerName);
        bool checkCardDataRange(const std::string & cardData);
        bool checkMerchantIDRange(const std::string & merchantID);
        bool checkTVRRange(const std::string & TVR);
        bool checkTSIRange(const std::string & TSI);
        bool checkTCRange(const std::string & TC);
        bool checkCIDRange(const std::string & CID);
        bool checkKVRRange(const std::string & KVR);
        bool checkCDAResultRange(const std::string & CDAResult);
        bool checkSalesCountRange(int32_t salesCount);
        bool checkVoidCountRange(int32_t voidCount);
        bool checkRefundCountRange(int32_t refundCount);

        bool checkNotificationsRange(int32_t notification);

        bool checkInteractionsRange(int32_t interaction);
    }
}


#endif //LAN_4GATELIBRARYCPP_FIELDRANGECHECKER_H
