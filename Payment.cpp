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

bool Payment::operator==(const Payment &rhs) const {
    return sum == rhs.sum &&
           payer_account == rhs.payer_account &&
           payer_org == rhs.payer_org &&
           payee_account == rhs.payee_account &&
           payee_org == rhs.payee_org;
}

bool Payment::operator!=(const Payment &rhs) const {
    return !(rhs == *this);
}

bool Payment::operator<(const Payment &rhs) const {
    return this->sum < rhs.sum;
}

bool Payment::operator>(const Payment &rhs) const {
    return this->sum > rhs.sum;
}

bool Payment::operator<=(const Payment &rhs) const {
    return *this < rhs || *this == rhs;
}

bool Payment::operator>=(const Payment &rhs) const {
    return *this > rhs || *this == rhs;
}

std::ostream &operator<<(std::ostream &os, const Payment &payment) {
    os << "sum: " << payment.sum << " payer_account: " << payment.payer_account << " payer_org: " << payment.payer_org
       << " payee_account: " << payment.payee_account << " payee_org: " << payment.payee_org;
    return os;
}

std::istream &operator>>(std::istream &input, Payment &payment) {
    std::string sum = std::to_string(payment.sum);
    input >>sum  >> payment.payee_account >> payment.payee_org >> payment.payer_account >> payment.payee_org ;
    payment.sum = std::stof(sum);
}


