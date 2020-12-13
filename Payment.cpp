//
// Created by user.v2.0 on 13.12.2020.
//

#include "Payment.h"

Payment::Payment(float sum, const std::string &payerAccount, const std::string &payerOrg,
                 const std::string &payeeAccount, const std::string &payeeOrg) : sum(sum), payer_account(payerAccount),
                                                                                 payer_org(payerOrg),
                                                                                 payee_account(payeeAccount),
                                                                                 payee_org(payeeOrg) {}

float Payment::getSum() const {
    return sum;
}

void Payment::setSum(float sum) {
    Payment::sum = sum;
}

const std::string &Payment::getPayerAccount() const {
    return payer_account;
}

void Payment::setPayerAccount(const std::string &payerAccount) {
    payer_account = payerAccount;
}

const std::string &Payment::getPayerOrg() const {
    return payer_org;
}

void Payment::setPayerOrg(const std::string &payerOrg) {
    payer_org = payerOrg;
}

const std::string &Payment::getPayeeAccount() const {
    return payee_account;
}

void Payment::setPayeeAccount(const std::string &payeeAccount) {
    payee_account = payeeAccount;
}

const std::string &Payment::getPayeeOrg() const {
    return payee_org;
}

void Payment::setPayeeOrg(const std::string &payeeOrg) {
    payee_org = payeeOrg;
}

Payment::~Payment() {

}
