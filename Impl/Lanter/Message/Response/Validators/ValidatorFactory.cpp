#include "ValidatorFactory.h"

#include "Lanter/Message/Response/Validators/Operations/BasicValidator.h"

#include "Lanter/Message/Response/Validators/Operations/Refund/QuickPaymentRefund.h"
#include "Lanter/Message/Response/Validators/Operations/Refund/QuickPaymentRefundStatus.h"
#include "Lanter/Message/Response/Validators/Operations/Refund/Refund.h"
#include "Lanter/Message/Response/Validators/Operations/Refund/RefundWithoutRRN.h"

#include "Lanter/Message/Response/Validators/Operations/Sale/AliPay.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/Payment.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/FastTrack.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/MOTO.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/PreAuth.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/QuickPayment.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/QuickPaymentStatus.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/Sale.h"
#include "Lanter/Message/Response/Validators/Operations/Sale/SalesCompletion.h"

#include "Lanter/Message/Response/Validators/Operations/Service/DisplayQR.h"
#include "Lanter/Message/Response/Validators/Operations/Service/FinalizeTransaction.h"
#include "Lanter/Message/Response/Validators/Operations/Service/GetCurrentPrinter.h"
#include "Lanter/Message/Response/Validators/Operations/Service/GetLastOperation.h"
#include "Lanter/Message/Response/Validators/Operations/Service/GetOperationCopy.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Initialization.h"
#include "Lanter/Message/Response/Validators/Operations/Service/KeyDowload.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintCommsInfo.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintDetailReport.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintLastReceipt.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintReceiptCopy.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintSoftInfo.h"
#include "Lanter/Message/Response/Validators/Operations/Service/PrintSummaryReport.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Registration.h"
#include "Lanter/Message/Response/Validators/Operations/Service/SelfTest.h"
#include "Lanter/Message/Response/Validators/Operations/Service/SetCurrentPrinter.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Settlement.h"
#include "Lanter/Message/Response/Validators/Operations/Service/Test.h"
#include "Lanter/Message/Response/Validators/Operations/Service/TestCommunication.h"
#include "Lanter/Message/Response/Validators/Operations/Service/UpdateSW.h"
#include "Lanter/Message/Response/Validators/Operations/Service/SendLogs.h"
#include "Lanter/Message/Response/Validators/Operations/Service/SetLogLevel.h"
#include "Lanter/Message/Response/Validators/Operations/Service/LicenseActivationFile.h"
#include "Lanter/Message/Response/Validators/Operations/Service/LicenseActivationServer.h"
#include "Lanter/Message/Response/Validators/Operations/Service/ClearReversal.h"
#include "Lanter/Message/Response/Validators/Operations/Service/ClearAllJournals.h"
#include "Lanter/Message/Response/Validators/Operations/Service/TakeLockCard.h"
#include "Lanter/Message/Response/Validators/Operations/Service/EjectCard.h"
#include "Lanter/Message/Response/Validators/Operations/Service/EjectWaitCard.h"
#include "Lanter/Message/Response/Validators/Operations/Service/IsCardPresent.h"
#include "Lanter/Message/Response/Validators/Operations/Service/UploadPending.h"
#include "Lanter/Message/Response/Validators/Operations/Service/BonusBalance.h"
#include "Lanter/Message/Response/Validators/Operations/Service/GrabEjectCard.h"

#include "Lanter/Message/Response/Validators/Operations/Void/Void.h"
#include "Lanter/Message/Response/Validators/Operations/Void/VoidPartialSale.h"
#include "Lanter/Message/Response/Validators/Operations/Void/VoidPreAuth.h"

#include "Lanter/Message/Response/Validators/Operations/InternalServiceOperations/ArrayElement.h"

// TODO Добавить QuickPaymentRefund
namespace Lanter {
    namespace Message {
        namespace Response {

            std::shared_ptr<IValidator> ValidatorFactory::getValidator(OperationCode operationCode) {
                std::shared_ptr<BasicValidator> validator;
                switch (operationCode) {
                    case OperationCode::Sale:
                        validator = std::make_shared<Sale>();
                        break;
                    case OperationCode::MOTO:
                        validator = std::make_shared<MOTO>();
                        break;
                    case OperationCode::QuickPayment:
                        validator = std::make_shared<QuickPayment>();
                        break;
                    case OperationCode::AliPay:
                        validator = std::make_shared<AliPay>();
                        break;
                    case OperationCode::Payment:
                        validator = std::make_shared<Payment>();
                        break;
                    case OperationCode::PreAuth:
                        validator = std::make_shared<PreAuth>();
                        break;
                    case OperationCode::SalesCompletion:
                        validator = std::make_shared<SalesCompletion>();
                        break;
                    case OperationCode::QuickPaymentStatus:
                        validator = std::make_shared<QuickPaymentStatus>();
                        break;
                    case OperationCode::FastTrack:
                        validator = std::make_shared<FastTrack>();
                        break;
                    case OperationCode::Void:
                        validator = std::make_shared<Void>();
                        break;
                    case OperationCode::VoidPartialSale:
                        validator = std::make_shared<VoidPartialSale>();
                        break;
                    case OperationCode::VoidPreAuth:
                        validator = std::make_shared<VoidPreAuth>();
                        break;
                    case OperationCode::Refund:
                        validator = std::make_shared<Refund>();
                        break;
                    case OperationCode::RefundWithoutRRN:
                        validator = std::make_shared<RefundWithoutRRN>();
                        break;
                    case OperationCode::QuickPaymentRefund:
                        validator = std::make_shared<QuickPaymentRefund>();
                        break;
                    case OperationCode::QuickPaymentRefundStatus:
                        validator = std::make_shared<QuickPaymentRefundStatus>();
                        break;
                    case OperationCode::Registration:
                        validator = std::make_shared<Registration>();
                        break;
                    case OperationCode::TestCommunication:
                        validator = std::make_shared<TestCommunication>();
                        break;
                    case OperationCode::Test:
                        validator = std::make_shared<Test>();
                        break;
                    case OperationCode::PrintLastReceipt:
                        validator = std::make_shared<PrintLastReceipt>();
                        break;
                    case OperationCode::GetLastOperation:
                        validator = std::make_shared<GetLastOperation>();
                        break;
                    case OperationCode::PrintReceiptCopy:
                        validator = std::make_shared<PrintReceiptCopy>();
                        break;
                    case OperationCode::PrintDetailReport:
                        validator = std::make_shared<PrintDetailReport>();
                        break;
                    case OperationCode::PrintSummaryReport:
                        validator = std::make_shared<PrintSummaryReport>();
                        break;
                    case OperationCode::Settlement:
                        validator = std::make_shared<Settlement>();
                        break;
                    case OperationCode::KeyDownload:
                        validator = std::make_shared<KeyDownload>();
                        break;
                    case OperationCode::Initialization:
                        validator = std::make_shared<Initialization>();
                        break;
                    case OperationCode::UpdateSW:
                        validator = std::make_shared<UpdateSW>();
                        break;
                    case OperationCode::PrintCommsInfo:
                        validator = std::make_shared<PrintCommsInfo>();
                        break;
                    case OperationCode::PrintSoftInfo:
                        validator = std::make_shared<PrintSoftInfo>();
                        break;
                    case OperationCode::FinalizeTransaction:
                        validator = std::make_shared<FinalizeTransaction>();
                        break;
                    case OperationCode::GetCurrentPrinter:
                        validator = std::make_shared<GetCurrentPrinter>();
                        break;
                    case OperationCode::SetCurrentPrinter:
                        validator = std::make_shared<SetCurrentPrinter>();
                        break;
                    case OperationCode::SelfTest:
                        validator = std::make_shared<SelfTest>();
                        break;
                    case OperationCode::GetOperationCopy:
                        validator = std::make_shared<GetOperationCopy>();
                        break;
                    case OperationCode::DisplayQR:
                        validator = std::make_shared<DisplayQR>();
                        break;
                    case OperationCode::ArrayElement:
                        validator = std::make_shared<ArrayElement>();
                        break;
                    case OperationCode::SendLogs:
                        validator = std::make_shared<SendLogs>();
                        break;
                    case OperationCode::SetLogLevel:
                        validator = std::make_shared<SetLogLevel>();
                        break;
                    case OperationCode::LicenseActivationFile:
                        validator = std::make_shared<LicenseActivationFile>();
                        break;
                    case OperationCode::LicenseActivationServer:
                        validator = std::make_shared<LicenseActivationServer>();
                        break;
                    case OperationCode::ClearReversal:
                        validator = std::make_shared<ClearReversal>();
                        break;
                    case OperationCode::ClearAllJournals:
                        validator = std::make_shared<ClearAllJournals>();
                        break;
                    case OperationCode::TakeLockCard:
                        validator = std::make_shared<TakeLockCard>();
                        break;
                    case OperationCode::EjectCard:
                        validator = std::make_shared<EjectCard>();
                        break;
                    case OperationCode::EjectWaitCard:
                        validator = std::make_shared<EjectWaitCard>();
                        break;
                    case OperationCode::IsCardPresent:
                        validator = std::make_shared<IsCardPresent>();
                        break;
                    case OperationCode::UploadPending:
                        validator = std::make_shared<UploadPending>();
                        break;
                    case OperationCode::BonusBalance:
                        validator = std::make_shared<BonusBalance>();
                        break;
                    case OperationCode::GrabEjectCard:
                        validator = std::make_shared<GrabEjectCard>();
                        break;
                    default:
                        validator = std::make_shared<BasicValidator>();
                        break;
                }
                if (validator) {
                    validator->addSpecificFields();
                }
                return validator;
            }
        }//Response
    }
}//Lanter